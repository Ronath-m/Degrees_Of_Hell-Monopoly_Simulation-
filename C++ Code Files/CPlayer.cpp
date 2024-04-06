#include "CPlayer.h"
#include "Game.h"
#include <algorithm>
#include <iostream>

// Constructor
CPlayer::CPlayer( const std::string& playerName, int initialMotivation, int initialSuccess, int initialPosition, int initialYear ) 
    : mName( playerName ), 
    mMotivation( initialMotivation ),
    mSuccess( initialSuccess ), 
    mPosition( initialPosition ), 
    mYear( initialYear ) 
{
}

// Getter functions
std::string CPlayer::GetName() const 
{ 
    return mName; 
}

int CPlayer::GetMotivation() const 
{ 
    return mMotivation; 
}

int CPlayer::GetSuccess() const 
{ 
    return mSuccess; 
}

int CPlayer::GetPosition() const 
{ 
    return mPosition; 
}

int CPlayer::GetYear() const 
{ 
    return mYear; 
}

std::set<Assessment*>& CPlayer::GetCompletedAssessments() 
{
    return mpCompletedAssessments;
}

std::set<Assessment*>& CPlayer::GetDefferredAssessments() 
{
    return mpDefferredAssessments;
}

// Setter functions
void CPlayer::SetName( const std::string& playerName ) 
{ 
    mName = playerName; 
}

void CPlayer::SetMotivation( int newMotivation ) 
{ 
    mMotivation = newMotivation; 
}

void CPlayer::SetSuccess( int newSuccess ) 
{ 
    mSuccess = newSuccess; 
}

void CPlayer::SetPosition( int newPosition ) 
{
    mPosition = newPosition; 
}

void CPlayer::SetYear( int newYear ) 
{ 
    mYear = newYear; 
}

void CPlayer::IncreaseMotivation( int amount ) 
{
    mMotivation += amount;
}

void CPlayer::DecreaseMotivation( int amount ) 
{
    mMotivation -= amount;
}

void CPlayer::IncreaseSuccess( int amount ) 
{
    mSuccess += amount;
}

void CPlayer::IncrementYear( int increment ) 
{
    mYear += increment;
}

void CPlayer::DecreaseSuccess( int amount ) 
{
    mSuccess -= amount;
}

void CPlayer::GetDegreesReference( Degrees* gameRef ) 
{
    mpDegreesPtr = gameRef;
}

void CPlayer::MovePlayer( int newPos ) 
{
    mPosition = newPos;
}

bool CPlayer::CheckGameOver() 
{
    return mGameOver;
}

bool CPlayer::CheckGraduation( int targetYear ) 
{
    int count = 0;

    // Iterate over the set of completed assessments
    for ( const auto& assessmentPtr : mpCompletedAssessments ) 
    {
        // Check if the assessment's year matches the target year
        if ( assessmentPtr->GetYear() == targetYear ) 
        {
            // Increment the count
            count++;

            // If count reaches or exceeds 3, return true
            if ( count >= 3 ) 
            {
                return true;
            }
        }
    }
    return false;
}

void CPlayer::HandleDeferredAssessments() 
{
    // Create a custom comparator to sort assessments by motivational cost
    struct CompareByMotivationalCost 
    {
        bool operator()(const Assessment* a, const Assessment* b) const 
        {
            return a->GetMotivationalCost() < b->GetMotivationalCost();
        }
    };

    // Sort deferred assessments by motivational cost
    std::multiset<Assessment*, CompareByMotivationalCost> sortedAssessments(mpDefferredAssessments.begin(), mpDefferredAssessments.end());

    // Iterate through sorted assessments
    for ( auto assessment : sortedAssessments ) 
    {
        // Check if motivation is sufficient to complete the assessment
        if ( mMotivation >= assessment->GetMotivationalCost() ) 
        {
            // Complete the assessment
            DecreaseMotivation(assessment->GetMotivationalCost());
            IncreaseSuccess(assessment->GetSuccessScore());
            std::cout << mName << " submits deferred assessment " << assessment->GetSpaceName() << " for " << assessment->GetMotivationalCost() <<std::endl;
            // Remove the assessment from deferred assessments
            mpDefferredAssessments.erase(assessment);
            // Insert the assessment into completed assessments
            mpCompletedAssessments.insert(assessment);
            assessment->AddDefferrdPlayer(this);
        }
        else 
        {
            // Break out of the loop if motivation is not sufficient for further assessments
            break;
        }
    }
}


std::vector<Assessment*> CPlayer::SortCompletedAssessmentsByMotivationCost() 
{
    // Sort the completed assessments according to the motivation cost
    std::vector<Assessment*> sortedAssessments(mpCompletedAssessments.begin(), mpCompletedAssessments.end());

    std::sort(sortedAssessments.begin(), sortedAssessments.end(), CompareByMotivationalCost()); // Use the custom comparator to sort
    return sortedAssessments; // Return the sorted vector
}


// Method to complete an assessment and save its pointer
void CPlayer::CompleteAssessment( int motivationalCost, int successScore, Assessment* assessmentPtr ) 
{
    mMotivation -= motivationalCost; // Reduce the motivation cost
    mSuccess += successScore; // Increase success
    mpCompletedAssessments.insert( assessmentPtr ); // Record pointer to completed assessment
}


// Method to complete an extra-curricular activity and save its pointer
void CPlayer::CompleteExtraCurricular( int motivationalCost, int successScore, ExtraCurricular* extraCurricularPtr ) 
{
    mMotivation -= motivationalCost; // Reduce the motivation cost
    mSuccess += successScore; // Reduce the motivation cost
    mpCompletedExtraCurricular.insert( extraCurricularPtr ); // Record pointer to completed assessment
}


void CPlayer::HandleMovementResult( int previousPosition, int welcomeWeekSpaceIndex ) 
{
    // Check if the player passes over or lands on the Welcome Week space
    if ( previousPosition > mPosition || mPosition == welcomeWeekSpaceIndex ) 
    {

        // Check if the enough assessments have been completed
        if ( CheckGraduation( mYear ) ) 
        {
            // Check the graaduation from year 3
            if ( mYear >= 3 ) 
            {
                std::cout << mName << " successfully completed" << " year " << mYear << std::endl;
                std::cout << "Congratulations to " << mName << " on their Graduation Day!" << std::endl;
                std::cout << "GAME OVER"  << std::endl;
                std::cout << "=========" << std::endl;
                std::cout << mName << " wins!" << std::endl;
                mGameOver = true; // Player wins
            }
            if ( mGameOver == false ) 
            {
                // Increment player's year
                IncrementYear( 1 );
                // Increase player's motivation
                IncreaseMotivation( 250 );

                // Output message
                std::cout << mName << " successfully completed" << " year " << mYear - 1 << std::endl;
                std::cout << mName << " attends Welcome Week and starts Year " << mYear << std::endl;
            }
        }
        // Output message
        else 
        {
            // Increase player motivation
            IncreaseMotivation( 250 );
            std::cout << mName << " attends Welcome Week and starts year "<< mYear << " again" << std::endl;
        }
    }
}

// Method to ask for help with an assessment
CPlayer* CPlayer::GetHelpAssessment( int halfMotivationalCost, int halfSuccessScore ) 
{
    // Check if player has enough motivation to get help for the assessment
    if ( mMotivation >= halfMotivationalCost ) 
    { 
        mMotivation -= halfMotivationalCost; // Reduce motivation
        mSuccess += halfSuccessScore; // Increase success
        return this; // Return the player pointer
    }
    else 
    {
        return nullptr;
    }
}

bool CPlayer::CheckCompletedAssessment( const std::string& assessmentName ) 
{
    for ( const auto& completedAssessment : mpCompletedAssessments ) 
    {
        if ( completedAssessment->GetSpaceName() == assessmentName ) 
        {
            return true; // Found the assessment with the given name
        }
    }
    return false; // No assessment with the given name found
}

void CPlayer::HandleMitigatingCircumstances() 
{
    // Sort completed assessments by motivational cost
    std::vector<Assessment*> sortedAssessments = SortCompletedAssessmentsByMotivationCost();
    // Iterate through sorted assessments
    for ( auto assessment : sortedAssessments ) 
    {
        // Check if assessment's motivational cost can be deferred
        if ( mMotivation < 0 ) 
        {
            int motivationalCost = assessment->GetMotivationalCost();
            // Reduce player's success associated with the deferred assessment
            DecreaseSuccess(assessment->GetSuccessScore());
            IncreaseMotivation(assessment->GetMotivationalCost());
            // Output message
            std::cout << mName << " defers " << assessment->GetSpaceName() << " for " << motivationalCost << std::endl;
            // Remove deferred assessment from completed assessments set
            auto it = std::find_if(mpCompletedAssessments.begin(), mpCompletedAssessments.end(), [&assessment](const Assessment* ptr) 
                {
                    return ptr == assessment;
                }
            );
            if ( it != mpCompletedAssessments.end() ) 
            {
                mpCompletedAssessments.erase(it);
            }
            // Add deferred assessment to the deferred assessments set
            mpDefferredAssessments.insert(assessment);
            for ( auto assessment : mpDefferredAssessments ) 
            {
                assessment->RemoveDefferrdPlayer(this);
            }
        }
        else 
        {
            // Player's motivation is positive, exit loop
            break;
        }
    }

    // Check if player's motivation is still negative
    if ( mMotivation < 0 ) 
    {
        // Player quits the course if unable to reach positive motivation
        mpDegreesPtr->RemovePlayer( GetName() );
    }
}


// CAssessment.cpp
#include "Assessment.h"
#include "CPlayer.h"
#include <iostream>
#include <set>

// Constructor
Assessment::Assessment( int type, const std::string& name, int motivationalCost, int successScore, int assessmentYear )
    : CSpace( type, name ), 
    mMotivationalCost( motivationalCost ), 
    mSuccessScore( successScore ), 
    mAssessmentYear( assessmentYear ), 
    mCompleted( false ) 
{
}

// Getter functions
int Assessment::GetMotivationalCost() const 
{
    return mMotivationalCost;
}

int Assessment::GetSuccessScore() const 
{
    return mSuccessScore;
}

int Assessment::GetYear() const 
{
    return mAssessmentYear;
}

bool Assessment::CheckCompleted() const 
{
    return mCompleted;
}

void Assessment::MarkCompleted( CPlayer* player ) 
{
    mCompleted = true; // Mark the completed flag true
    mpCompletedPlayers.insert( player ); // Insert the player to the completed players set for the assessment
}

const std::set<CPlayer*>& Assessment::GetCompletedPlayers() const 
{
    return mpCompletedPlayers;
}

void Assessment::RemoveDefferrdPlayer( CPlayer* player ) 
{
    mpCompletedPlayers.erase( player ); // Removes the player from the Completed players set
}

void Assessment::AddDefferrdPlayer( CPlayer* player ) 
{
    mpCompletedPlayers.insert( player ); // Add the the once defferred player to the completed players
}

void Assessment::GetHelpWithAssessment( CPlayer* currentPlayer ) 
{
    if ( currentPlayer -> GetMotivation() >= mMotivationalCost / 2 ) 
    {
        int numCompletedPlayers = mpCompletedPlayers.size() + 1; // Add 1 for the current player
        if ( numCompletedPlayers == 0 ) 
        {
            return; // Return if no one has completed the assessment
        }

        int scorePerPlayer = mSuccessScore / numCompletedPlayers; // Calculate the Success Score based on the number of completed players

         // Output completion message for the current player
        std::cout << currentPlayer->GetName() << " completes " << GetSpaceName() << " for " << mMotivationalCost / 2 << " and achieves " << scorePerPlayer << std::endl;

        // Increase success for previously completed players
        for ( CPlayer* completedPlayer : mpCompletedPlayers ) 
        {
            completedPlayer->IncreaseSuccess( scorePerPlayer );
            // Display the success increase of the helpers
            std::cout << completedPlayer->GetName() << " helps and achieves " << scorePerPlayer << std::endl;
        }

        // Add the current player to the completedBy set
        mpCompletedPlayers.insert( currentPlayer );

        // Complete the assessment for the current player
        currentPlayer -> CompleteAssessment( mMotivationalCost / 2, scorePerPlayer, this );
    }
    else 
    {
        // If the player doesnt have enough motivation to get help
        std::cout << currentPlayer -> GetName() << " does not have enough motivation to complete the assessment." << std::endl;
    }
}

bool Assessment::CheckPlayerCompleted( const CPlayer* player ) const 
{
    // Iterate over the set of completed players
    for ( const auto& completedPlayer : mpCompletedPlayers ) 
    {
        // Check if the pointer matches the player pointer
        if ( completedPlayer == player) 
        {
            // Player found in the set, return true
            return true;
        }
    }
    // Player not found in the set, return false
    return false;
}

void Assessment::LandOn( CPlayer& player ) 
{
    std::cout << player.GetName() << " lands on " << GetSpaceName() << std::endl;
        // Check if the assessment has been comppleted before
        if ( !CheckCompleted() ) 
        {
            // Check if the player has enough motivation to complete the assessment
            if ( player.GetMotivation() >= mMotivationalCost ) 
            {
                // If the player has motivation complete the assessment
                player.CompleteAssessment( mMotivationalCost, mSuccessScore, this );
                // Display the completion message
                std::cout << player.GetName() << " completes " << GetSpaceName() << " for " << mMotivationalCost << " and achieves " << mSuccessScore << std::endl;
                MarkCompleted( &player );
            }
            else 
            {
                // Display not enough motivation message
                std::cout << player.GetName() << " does not have enough motivation to complete the assessment." << std::endl;
            }
        }
        // If the assessment is completed, check if its completed by the current player
        else if ( !CheckPlayerCompleted( &player ) ) 
        {
            // If not completed by current player get help
            GetHelpWithAssessment( &player );
        }
        else 
        {
            std::cout << player.GetName() << " has already completed the " << GetSpaceName() << std::endl;
        }
}

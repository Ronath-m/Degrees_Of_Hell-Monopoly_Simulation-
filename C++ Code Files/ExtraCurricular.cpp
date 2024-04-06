#include "ExtraCurricular.h"
#include "CPlayer.h"
#include <iostream>


// Constructor
ExtraCurricular::ExtraCurricular( int type, const std::string& name )
    : CSpace(type, name) 
{
}


bool ExtraCurricular::CheckCompleted() const 
{
    return mCompleted;
}

void ExtraCurricular::MarkCompleted( CPlayer* player ) 
{
    mCompleted = true; // Mark the completed flag true
    mpCompletedPlayers.insert(player); // Insert the player to the completed players set for the extracurricular
}

const std::set<CPlayer*>& ExtraCurricular::GetCompletedPlayers() const 
{
    return mpCompletedPlayers;
}

void ExtraCurricular::HelpWithExtraCurricular( CPlayer* currentPlayer ) 
{
    int numCompletedPlayers = mpCompletedPlayers.size() + 1; // Add 1 for the current player
    if (numCompletedPlayers == 0) 
    {
        return; // Return if no one has completed the assessment
    }

    int scorePerPlayer = mkSuccessScore / numCompletedPlayers; ; // Calculate the Success Score based on the number of completed players

        // Output completion message for the current player
    std::cout << currentPlayer->GetName() << " undertakes " << GetSpaceName() << " for " << mkMotivationalCost / 2 << " and achieves " << scorePerPlayer << std::endl;

    // Increase success for previously completed players
    for ( CPlayer* completedPlayer : mpCompletedPlayers ) 
    {
        completedPlayer->IncreaseSuccess( scorePerPlayer );
        completedPlayer->IncreaseMotivation( mkMotivationalCost / 2 );
        // Display the success increase of the helpers
        std::cout << completedPlayer->GetName() << " motivates " << currentPlayer->GetName() << " by " << mkMotivationalCost / 2 << " by joining their activity" << std::endl;
        std::cout << completedPlayer->GetName() << " also achieves " << scorePerPlayer << std::endl;
    }

    // Add the current player to the completedBy set
    mpCompletedPlayers.insert( currentPlayer );

    // Complete the extra curricular activity for the current player
    currentPlayer->CompleteExtraCurricular( mkMotivationalCost / 2, scorePerPlayer, this );
}

bool ExtraCurricular::CheckPlayerCompleted( const CPlayer* player ) const 
{
    // Iterate over the set of completed players
    for ( const auto& completedPlayer : mpCompletedPlayers ) 
    {
        // Check if the pointer matches the player pointer
        if ( completedPlayer == player ) {
            // Player found in the set, return true
            return true;
        }
    }
    // Player not found in the set, return false
    return false;
}

void ExtraCurricular::LandOn( CPlayer& player ) 
{
    std::cout << player.GetName() << " lands on " << GetSpaceName() << std::endl;
    // Check if the extra curricular has been comppleted before
    if ( !CheckCompleted() ) 
    {
        // Check if the player has enough motivation to complete the extra curricular
        if ( player.GetMotivation() >= mkMotivationalCost ) 
        {
            // If the player has motivation complete the extra curricular
            player.CompleteExtraCurricular( mkMotivationalCost, mkSuccessScore, this );
            // Display the completion message
            std::cout << player.GetName() << " completes " << GetSpaceName() << " for " << mkMotivationalCost << " and achieves " << mkSuccessScore << std::endl;
            MarkCompleted(&player);
        }
        else 
        {
            // Display not enough motivation message
            std::cout << player.GetName() << " does not have enough motivation to complete the extra curricular activity." << std::endl;
        }
    }
    // If the extra curricular is completed, check if its completed by the current player
    else if ( !CheckPlayerCompleted(&player) ) 
    {
        // If not completed by current player get help
        HelpWithExtraCurricular( &player );
    }
    else 
    {
        std::cout << player.GetName() << " Already completed." << std::endl;
    }
}

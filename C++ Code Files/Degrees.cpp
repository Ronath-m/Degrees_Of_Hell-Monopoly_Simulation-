#include "Degrees.h"
#include <climits>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <random>

Degrees::Degrees( const std::vector<std::string>& playerNames, int initialMotivation, int initialSuccess, int initialPosition, int initialYear ) 
{
    // Create players with given names and initial attributes
    for ( const auto& name : playerNames ) 
    {
        mPlayers.push_back( std::make_unique<CPlayer>( name, initialMotivation, initialSuccess, initialPosition, initialYear ) );
    }
}

int Degrees::SpinnerSpin( std::string playerName ) 
{
    int spin =  static_cast<int>( static_cast<double> (rand()) / (RAND_MAX + 1) * 10.0f + 1 ); // Generates a random number between 1-10 and return
    std::cout << playerName << " spins " << spin << std::endl;
    return spin;
}

void Degrees::RemovePlayer( const std::string& playerName ) 
{
    // Remove a player from the players vector based on the player name passed
    auto it = std::remove_if(mPlayers.begin(), mPlayers.end(), [&](const auto& player) 
        {
            return player -> GetName() == playerName;
        });
    mPlayers.erase(it, mPlayers.end());
}

void Degrees::PlayGame( const std::vector<std::unique_ptr<CSpace>>& mBoardSpaces ) 
{
    std::cout << "Welcome to Scumbag College" << std::endl; // Display welcome message

    // Loop for the rounds
    for ( int round = 1; round <= 500; ++round ) 
    {
        // Check if the game if over
        if ( GameOver ) 
        {
            break;  // Break out of the round loop
        }
        std::cout << "ROUND " << round << std::endl; // Display round number
        std::cout << "=========" << std::endl;

        // Loop throuhg each player
        for ( auto& playerPtr : mPlayers ) 
        {
            CPlayer& player = *playerPtr;
            player.GetDegreesReference( this );
            int spin = SpinnerSpin( player.GetName() ); // Call the spinner
            int previousPosition = player.GetPosition(); // Save the previous position before updating
            // Move player on the board based on the modulus. Wrapping around if necessary to stay within bounds
            player.MovePlayer( ( player.GetPosition() + spin ) % mBoardSpaces.size() );
            player.HandleMovementResult( previousPosition, 0 ); // Checking if the welcome week space was passed

            // Check if the game if over
            if (player.CheckGameOver()) 
            {
                GameOver = true; // Change flag to true
                GraduatedPlayerName = player.GetName(); // Get the name of the player who grauated
                break;  // Break out of the player loop
            }


            // Get the space player lands on
            CSpace* space = mBoardSpaces[player.GetPosition()].get(); 

            // Land on the space and execute the functionality
            CSpace* board_space = space;
            board_space -> LandOn(player);

            // Handle defferred assessments when theres required motivation
            if ( !player.GetDefferredAssessments().empty() && player.GetMotivation() >= 0 ) 
            {
                player.HandleDeferredAssessments();
            }
            // Deffer assessments when theres not enough movivation
            if ( player.GetMotivation() < 0 ) 
            {
                player.HandleMitigatingCircumstances();

            }
            // Display motivation and success as each round
            std::cout << player.GetName() << "'s motivation is " << player.GetMotivation() << " and success is " << player.GetSuccess() << std::endl;
            std::cout << "" << std::endl;
        }
    }

    if ( GameOver == false ) 
    {
        std::cout << "Game Over" << std::endl;
        int maxSuccess = INT_MIN;
        std::string winner;
        for (const auto& playerPtr : mPlayers) 
        {
            CPlayer& player = *playerPtr;
            std::cout << player.GetName() << " has achieved " << player.GetSuccess() << std::endl;
            if (player.GetSuccess() > maxSuccess) 
            {
                maxSuccess = player.GetSuccess();
                winner = player.GetName();
            }
        }
        std::cout << winner << " wins." << std::endl;
    }
}

#pragma once // Header guard to prevent multiple inclusions

#include <vector>
#include "Board.h"
#include "Degrees.h"
#include "CPlayer.h"

/**
 * @brief Game class represents the main game object
 */
class Game 
{
    private:
        Board mBoard; // Instance of the game board
        Degrees mDegrees; // Instance of the degrees manager 
        Game* pGameReference; // Pointer to the current game instance

    public:
        /**
        * @brief Constructor for Game class
        *
        * @param[in] filePath The file path for initializing the game
        * @param[in] initialMotivation Initial motivation value for players
        * @param[in] initialSuccess Initial success value for players
        * @param[in] initialPosition Initial position value for players
        * @param[in] initialYear Initial year value for players
        * @param[in] gamePtr Pointer to the current game instance
        */
        Game( const std::string& filePath, int initialMotivation = 1000, int initialSuccess = 0, int initialPosition = 0, int initialYear = 1, Game* gamePtr = nullptr );

        /**
        * @brief Destructor for Game class
        */
        ~Game(); // Destructor

        /**
        * @brief Method to start playing the game
        */
        void PlayGame();

        /**
        * @brief Method to seed the spinner with a random number generator
        *
        * @param[in] fileName The name of the file to seed the spinner
        * @return The random number generated
        */
        int SeedSpinner( std::string fileName );
};

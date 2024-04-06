#pragma once // Header guard to prevent multiple inclusions

#include <iostream>
#include <vector>
#include "CSpace.h"
#include "CPlayer.h"

/**
 * @brief Degrees class represents the degree object managing the game
 */
class Degrees 
{
private:
    using PlayVector = std::vector<std::unique_ptr<CPlayer>>; // Vector to store smart pointers to players
    PlayVector mPlayers;
    bool GameOver = false; // Flag indicating if the game is over
    std::string GraduatedPlayerName = ""; // Name of the player who graduated

public:
    /**
     * @brief Constructor for Degrees class
     *
     * @param[in] playerNames Vector of player names
     * @param[in] initialMotivation Initial motivation value for players
     * @param[in] initialSuccess Initial success value for players
     * @param[in] initialPosition Initial position value for players
     * @param[in] initialYear Initial year value for players
     */
    Degrees( const std::vector<std::string>& playerNames, int initialMotivation = 100, int initialSuccess = 50, int initialPosition = 0, int initialYear = 1 );
   
    /**
     * @brief Method to start playing the game using board spaces vector
     *
     * @param[in] boardSpaces Vector of smart pointers to board spaces
     */
    void PlayGame( const std::vector<std::unique_ptr<CSpace>>& mBoardSpaces );
   
    /**
     * @brief Static method to spin the spinner and generate a random number 1-10
     *
     * @param[in] playerName The name of the player spinning the spinner
     * @return The random number generated
     */
    static int SpinnerSpin( std::string playerName );
    
    /**
     * @brief Method to remove the player in case of dropping out
     *
     * @param[in] playerName The name of the player to be removed
     */
    void RemovePlayer( const std::string& playerName );
};

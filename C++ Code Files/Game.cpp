#include "Game.h"
#include <iostream>

Game::Game( const std::string& filePath, int initialMotivation, int initialSuccess, int initialPosition, int initialYear, Game* gamePtr )
    : mBoard(filePath), 
    mDegrees( std::vector<std::string>{"Vyvyan", "Rick", "Neil", "Mike"}, initialMotivation, initialSuccess, initialPosition, initialYear ),
    pGameReference( gamePtr ) 
{
}

Game::~Game() {}

void Game::PlayGame() 
{
    auto& mBoardSpaces = mBoard.GetBoardSpaces();
    mDegrees.PlayGame(mBoardSpaces);
}
int Game::SeedSpinner( std::string fileName ) 
{
    // Use a default seed value in case of failure
    int seed = 666;
    // Read the file
    std::ifstream seedFile( fileName );

    if ( seedFile )
    {
        seedFile >> seed; // Read the seed value from the file
    }
    else
    {
        // Handle error if file cannot be opened

        std::cerr << "Error: Unable to open file " << fileName << std::endl;
        std::cout << "Seed set to default: 666" << std::endl;


    }
    // Close the file
    seedFile.close();
    // Return the seed
    return ( seed );

}

#include "Bonus.h"
#include "Degrees.h" // Include the header file for the Board class
#include <iostream>

Bonus::Bonus( int type, const std::string& name )
    : CSpace( type, name ) 
{
    // Initialize bonus messages
    mBonusMessages = 
    {
        { 1, "Receive some useful feedback" },
        { 2, "Win a hackathon" },
        { 3, "Get a free coffee with full loyalty card" },
        { 4, "Impress your lecturer in class" },
        { 5, "Motivational talk from course leader" },
        { 6, "Secure an industry placement" },
        { 7, "Attend an inspiring C++ lecture" },
        { 8, "Get your best ever assignment mark" },
        { 9, "Make a new romantic friend" },
        { 10, "Get elected School President" }
    };

    // Initialse bonus gains
    mBonusMotivationGains = 
    {
        { 1, 20 },
        { 2, 50 },
        { 3, 80 },
        { 4, 100 },
        { 5, 5 },
        { 6, 150 },
        { 7, 200 },
        { 8, 300 },
        { 9, 150 },
        { 10, 10 }
    };
}

void Bonus::LandOn( CPlayer& player ) 
{
    std::cout << player.GetName() << " lands on " << GetSpaceName() << std::endl;
    // Generate a random spin value using the Board's random number generator
    int spin = Degrees::SpinnerSpin( player.GetName() );

    // Get the bonus message and motivation gain based on the spin
    std::cout << mBonusMessages[spin] << ". Gain motivation of " << mBonusMotivationGains[spin] << std::endl;

    // Increase player's motivation
    player.IncreaseMotivation( mBonusMotivationGains[spin] );
}


#include "Bogus.h"
#include "Degrees.h"
#include <iostream>

Bogus::Bogus( int type, const std::string& name )
    : CSpace( type, name ) 
{
    // Initialize bogus messages
    mBogusMessages = 
    {
        { 1, "Fall asleep in a boring lecture" },
        { 2, "Meet with coach about poor attendance" },
        { 3, "Feel really tired after a night out" },
        { 4, "Get kicked out of lab for messing about" },
        { 5, "Get dumped before a big night out" },
        { 6, "Fail an assignment" },
        { 7, "Get caught skipping class" },
        { 8, "Your friend drops out of uni" },
        { 9, "Nobody turns up to teach your class" },
        { 10, "Lecturer changes assignment schedule" }
    };
    
    // Initialise motivation loss
    mBogusMotivationLoss = 
    {
        { 1, 20 },
        { 2, 50 },
        { 3, 80 },
        { 4, 100 },
        { 5, 150 },
        { 6, 200 },
        { 7, 50 },
        { 8, 200 },
        { 9, 300 },
        { 10, 20 }
    };
}

void Bogus::LandOn( CPlayer& player ) 
{
    std::cout << player.GetName() << " lands on " << GetSpaceName() << std::endl;
    // Generate a random spin value using the Board's random number generator
    int spin = Degrees::SpinnerSpin( player.GetName() );

    // Get the bogus message and motivation loss based on the spin
    std::cout << mBogusMessages[spin] << ". Loose motivation of " << mBogusMotivationLoss[spin] << std::endl;

    // decrease player's motivation
    player.DecreaseMotivation( mBogusMotivationLoss[spin] );
}


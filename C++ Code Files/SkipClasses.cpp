#include "SkipClasses.h"
#include <iostream>

// Constructor
SkipClasses::SkipClasses( int type, const std::string& name )
    : CSpace( type, name ) 
{
}

// Method to handle player landing on the space
void SkipClasses::LandOn( CPlayer& player ) 
{
    std::cout << player.GetName() << " lands on Skip Classes and hangs out with their dodgy mates" << std::endl;
    // No further action needed for Skip Classes space
}

// PlagiarismHearingSpace.cpp
#include <iostream>
#include "PlagarismHearing.h"

// Constructor
PlagiarismHearing::PlagiarismHearing( int type, const std::string& name )
    : CSpace( type, name ) 
{
}

// Method to handle player landing on Plagiarism Hearing space
void PlagiarismHearing::LandOn( CPlayer& player ) 
{
    std::cout << player.GetName() << " lands on " << GetSpaceName() << " and supports their friend." << std::endl;
}

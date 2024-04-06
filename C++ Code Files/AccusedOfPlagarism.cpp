#include "AccusedOfPlagarism.h"
#include <iostream>

// Constructor
AccusedOfPlagiarism::AccusedOfPlagiarism(int type, const std::string& name)
    : CSpace(type, name) 
{
}

// Method to handle player landing on the space
void AccusedOfPlagiarism::LandOn( CPlayer& player )  
{
    std::cout << player.GetName() << " lands on Accused of Plagiarism and goes to the hearing" << std::endl;
    std::cout << player.GetName() << " loses motivation" << std::endl;

    // Directing the player to the Plagiarism Hearing space
    player.SetPosition( 32 );

    // Reduce player's motivation by 50
    player.DecreaseMotivation( 50 );
}


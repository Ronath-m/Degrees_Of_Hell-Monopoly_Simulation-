#pragma once // Header guard to prevent multiple inclusions

#include "CSpace.h"
#include "CPlayer.h"

class AccusedOfPlagiarism : public CSpace 
{
    public:
        /**
        * @brief Constructor for AccusedOfPlagiarism class
        *
        * @param[in] type The type of the space
        * @param[in] name The name of the space
        */
        AccusedOfPlagiarism( int type, const std::string& name );

        /**
        * @brief Handles actions when a player lands on the AccusedOfPlagiarism space
        *
        * Executes actions related to a player landing on the AccusedOfPlagiarism space.
        * Moves the player to the plagiarism hearing index and deducts motivation.
        *
        * @param[in] player The player landing on the AccusedOfPlagiarism space
        */
        void LandOn( CPlayer& player ) override;
};

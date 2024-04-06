#pragma once // Header guard to prevent multiple inclusions

#include "CSpace.h"
#include "CPlayer.h"

/**
 * @brief PlagiarismHearing class represents a space on the game board that conducts a plagiarism hearing
 */
class PlagiarismHearing : public CSpace 
{
    public:
        /**
        * @brief Constructor for PlagiarismHearing class
        *
        * @param[in] type The type of the space
        * @param[in] name The name of the space
        */
        PlagiarismHearing( int type, const std::string& name );

        /**
        * @brief Method to handle player landing on Plagiarism Hearing space
        *
        * @param[in] player The player landing on the space
        */
        void LandOn( CPlayer& player ) override;
};

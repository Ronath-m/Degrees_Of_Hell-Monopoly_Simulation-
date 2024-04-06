#pragma once // Header guard to prevent multiple inclusions

#include "CSpace.h"
#include "CPlayer.h"

/**
 * @brief SkipClasses class represents a space on the game board where the player can skip classes
 */
class SkipClasses : public CSpace 
{
    public:
        /**
        * @brief Constructor for SkipClasses class
        *
        * @param[in] type The type of the space
        * @param[in] name The name of the space
        */
        SkipClasses( int type, const std::string& name );

        /**
        * @brief Method to handle player landing on the space
        *
        * @param[in] player The player landing on the space
        */
        void LandOn( CPlayer& player ) override;
};

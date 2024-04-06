#pragma once // Header guard to prevent multiple inclusions

#include "CSpace.h"
#include "CPlayer.h"
#include <iostream>

/**
 * @brief WelcomeWeek class represents a space on the game board where the player participates in Welcome Week activities
 */
class WelcomeWeek : public CSpace 
{
    public:
        /**
        * @brief Constructor for WelcomeWeek class
        *
        * @param[in] type The type of the space
        * @param[in] name The name of the space
        */
        WelcomeWeek( int type, const std::string& name );

        /**
        * @brief Method to handle player landing on the Welcome Week space
        *
        * @param[in] player The player landing on the space
        */
        void LandOn( CPlayer& player ) override;
};

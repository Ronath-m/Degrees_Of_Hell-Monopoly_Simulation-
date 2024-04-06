#pragma once // Header guard to prevent multiple inclusions

#include "CSpace.h"
#include "CPlayer.h"
#include <map>
#include <string>

/**
 * @brief Bogus class represents a space on the game board that serves as a Bogus space
 */

class Bogus : public CSpace
{
    private:
        std::map<int, std::string> mBogusMessages; // Map to store bonus messages associated with bogus types
        std::map<int, int> mBogusMotivationLoss; // Map to store motivation loss associated with bogus types

    public:
        /**
        * @brief Constructor for Bogus class
        *
        * @param[in] type The type of the space
        * @param[in] name The name of the space
        */
        Bogus( int type, const std::string& name );

        /**
        * @brief Method to handle landing on Bogus Space
        *
        * @param[in] player The player landing on the space
        */

        void LandOn( CPlayer& player ) override;
};

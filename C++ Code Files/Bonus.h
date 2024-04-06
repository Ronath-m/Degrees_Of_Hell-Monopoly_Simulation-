#pragma once // Header guard to prevent multiple inclusions

#include "CSpace.h"
#include "CPlayer.h"
#include <map>
#include <string>

/**
 * @brief Bonus class represents a space on the game board that serves as a Bonus space
 */

class Bonus : public CSpace 
{
private:
    std::map<int, std::string> mBonusMessages; // Map to store bonus messages associated with bonus types
    std::map<int, int> mBonusMotivationGains; // Map to motivation gains associated with bonus types

public:
    /**
     * @brief Constructor for Bonus class
     *
     * @param[in] type The type of the space
     * @param[in] name The name of the space
     */
    Bonus( int type, const std::string& name );

    /**
     * @brief Method to handle landing on Bonus Space
     *
     * @param[in] player The player landing on the space
     */
    void LandOn( CPlayer& player ) override;
};

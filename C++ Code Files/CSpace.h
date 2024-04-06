#pragma once // Header guard to prevent multiple inclusions

#include <string>

class CPlayer; // Forward declaration

/**
 * @brief CSpace class represents a space on the game board
 */

class CSpace 
{
    private:
        int mSpaceType = 0;
        std::string mSpaceName = "";

    public:
        /**
        * @brief Constructor for CSpace class
        *
        * @param[in] type The type of the space
        * @param[in] name The name of the space
        */
        CSpace( int type, const std::string& name );

        /**
        * @brief Virtual destructor for CSpace class
        */
        virtual ~CSpace();

        // Getter functions

        /**
        * @brief Get the type of the space
        *
        * @return The type of the space
        */
        int GetSpaceType() const;

        /**
        * @brief Get the name of the space
        *
        * @return The name of the space
        */
        std::string GetSpaceName() const;

        // Pure virtual method to handle player landing on the space

       /**
       * @brief Method to handle player landing on the space
       *
       * @param[in] player The player landing on the space
       */
        virtual void LandOn( CPlayer& player ) = 0;
};


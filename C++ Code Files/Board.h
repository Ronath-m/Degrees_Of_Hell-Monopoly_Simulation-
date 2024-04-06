#pragma once // Header guard to prevent multiple inclusions 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "CSpace.h"
#include "Assessment.h"
#include "PlagarismHearing.h"
#include "AccusedOfPlagarism.h"
#include "SkipClasses.h"
#include "ExtraCurricular.h"
#include "Bonus.h"
#include "Bogus.h"
#include "WelcomeWeek.h"

/**
 * @brief Board class represents the game board containing various spaces
 */
class Board 
{
    private:
        //Define the vector of smart pointers to CSpace Objects
        using BoardSpacesVector = std::vector<std::unique_ptr<CSpace>>;
        // Vector to hold the spaces of the board
        BoardSpacesVector mBoardSpaces;

    public:
        /**
        * @brief Constructor that initializes the board from a text file
        *
        * @param[in] fileName The name of the file containing board information
        */
        Board( const std::string& fileName );
    
        /**
        * @brief Destructor to clean up resources
        */

        ~Board();
   
        /**
        * @brief Returns a reference to the vector containing the board spaces
        *
        * @return Reference to the vector of board spaces
        */
        BoardSpacesVector& GetBoardSpaces();
};

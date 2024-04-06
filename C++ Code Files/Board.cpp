#include "Board.h"
#include "CPlayer.h"

//Constuctor initialising the Board object with the filename
Board::Board( const std::string& filename ) 
{
    std::ifstream file( filename ); // Opening the file
    // Checking if the file is open
    if ( !file.is_open() ) 
    {
        std::cerr << "Error: Unable to open " << filename << std::endl; // Error message if the opening fails
        exit(1);
    }

    // Read each line of the file
    std::string line = "";
    while ( getline( file, line )) 
    {
        // Tokenize each line
        std::istringstream iss( line );
        std::vector<std::string> tokens;
        std::string token;
        while ( iss >> token ) 
        {
            tokens.push_back( token );
        }

        // Check if the line is empty
        if ( tokens.empty() ) 
        {
            std::cerr << "Error: Empty line encountered" << std::endl;
            continue;
        }

        // Determine the type of the space
        int type = std::stoi( tokens[0] );
        std::string mName = ""; // Name of the space
        // Considering token 1 and 2 as the name for type 1 and 3 spaces
        if ( type == 1 || type == 3 ) 
        {
            mName = tokens[1] + " " + tokens[2];

            // Creating assessment type objects for type 1 spaces
            if ( type == 1 ) 
            {
                int successScore = std::stoi( tokens[4] );
                int motivationalCost = std::stoi( tokens[3] );
                int year = std::stoi( tokens[5] );
                auto assessment = std::make_unique<Assessment>( type, mName, motivationalCost, successScore, year );
                mBoardSpaces.push_back( std::move( assessment ) );
            }
            // Creating ExtraCurricular type objects for type 3 spaces
            else if ( type == 3 ) 
            {
                auto space = std::make_unique<ExtraCurricular>( type, mName );
                mBoardSpaces.push_back( std::move( space ) );
            }
        }
        // Creating WelcomeWeek type objects for type 2 spaces
        else if ( type == 2 ) 
        {
            mName = tokens[1] + " " + tokens[2];
            auto space = std::make_unique<WelcomeWeek>( type, mName );
            mBoardSpaces.push_back( std::move(space ) );
        }
        // Creating SkipClasses type objects for type 8 spaces
        else if ( type == 8 ) 
        {
            mName = tokens[1] + " " + tokens[2];
            auto space = std::make_unique<SkipClasses>( type, mName );
            mBoardSpaces.push_back( std::move( space ) );
        }
        // Creating Bonus type objects for type 4 spaces
        else if ( type == 4 ) 
        {
            mName = tokens[1];
            auto space = std::make_unique<Bonus>( type, mName );
            mBoardSpaces.push_back( std::move( space ) );
        }
        // Creating Bogus type objects for type 5 spaces
        else if ( type == 5 ) 
        {
            mName = tokens[1];
            auto space = std::make_unique<Bogus>( type, mName );
            mBoardSpaces.push_back( std::move( space ) );
        }
        // Creating PlagiarismHearing type objects for type 6 spaces
        else if ( type == 6 ) 
        {
            mName = tokens[1] + " " + tokens[2];
            auto space = std::make_unique<PlagiarismHearing>( type, mName );
            mBoardSpaces.push_back( std::move( space ) );
        }
        // Creating AccussedOfPlagiarism type objects for type 7 spaces
        else if ( type == 7 ) 
        {
            mName = tokens[1] + " " + tokens[2] + " " + tokens[3];
            auto space = std::make_unique<AccusedOfPlagiarism>( type, mName );
            mBoardSpaces.push_back( std::move( space ) );
        }
    }
    // Close the file
    file.close();
}
// Destructor
Board::~Board() 
{
}

Board::BoardSpacesVector& Board::GetBoardSpaces() 
{
    return mBoardSpaces;
}

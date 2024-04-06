#include "CSpace.h"

// Constructor
CSpace::CSpace( int type, const std::string& name ) : 
    mSpaceType(type), 
    mSpaceName(name) 
{
}

// Destructor
CSpace::~CSpace() 
{} // Define virtual destructor

// Getter functions
int CSpace::GetSpaceType() const 
{
    return mSpaceType;
}

std::string CSpace::GetSpaceName() const 
{
    return mSpaceName;
}

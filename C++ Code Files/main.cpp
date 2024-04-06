#include <iostream>
#include "Game.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main() 
{
    Game game( "degrees.txt", 1000, 0, 0, 1 ); // Initialising game object
    srand( game.SeedSpinner("seed.txt") );
    game.PlayGame(); // Calling to the method to start the simulation
    return 0;
    _CrtDumpMemoryLeaks(); // Check memory leaks
}

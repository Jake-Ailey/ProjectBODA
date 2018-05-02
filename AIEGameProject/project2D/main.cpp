#include "Application2D.h"
#include <crtdbg.h>

int main() 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);		//Check for memory leaks

	// allocation
	auto app = new Application2D();

	// initialise and loop
	app->run("AIE", 1920, 1080, false);	//Creating the main gameplay screen

	// deallocation
	delete app;

	return 0;
}
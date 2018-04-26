#include "Application2D.h"

int main() {
	
	// allocation
	auto app = new Application2D();

	// initialise and loop
	app->run("AIE", 1280, 800, false);	//Creating the main gameplay screen

	// deallocation
	delete app;

	return 0;
}
// Template, 2024 IGAD Edition
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2024

#include "precomp.h"
#include "game.h"
#include <Jackpot.h>

Timer myTimer;
Jackpot myJackpot(int2(50, 50), int2(1500, 1000));

// -----------------------------------------------------------
// Initialize the application
// -----------------------------------------------------------
void Game::Init()
{
	// anything that happens only once at application start goes here
}

// -----------------------------------------------------------
// Main application tick function - Executed once per frame
// -----------------------------------------------------------
void Game::Tick( float deltaTime )
{
	// Clear screen to black
	screen->Clear(0x000000);

	myJackpot.Update(deltaTime);
	myJackpot.Draw(screen);

	// Print FPS to screen
	char buf[64]; sprintf(buf, "%Lf", 1000.f / deltaTime); screen->Print(buf, 10, 10, 0xffffff);
}
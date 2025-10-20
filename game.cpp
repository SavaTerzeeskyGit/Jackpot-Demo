// Template, 2024 IGAD Edition
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2024

#include "precomp.h"
#include "game.h"
#include <Jackpot.h>
#include "SlotEntry.h"
#include "JackpotSlot.h"

Timer myTimer;
Jackpot myJackpot;
SlotEntry myEntry(int2(75, 50), int2(50, 50));
JackpotSlot mySlot;

const std::unique_ptr<Surface> m_Border = std::make_unique<Surface>("assets/Border.png");
const std::unique_ptr<Surface> m_Ball = std::make_unique<Surface>("assets/ball.png");
const std::unique_ptr<Surface> m_X = std::make_unique<Surface>("assets/x.png");
const std::unique_ptr<Surface> m_Heart = std::make_unique<Surface>("assets/heart.png");
const std::unique_ptr<Surface> m_Lightning = std::make_unique<Surface>("assets/lightning.png");
const std::unique_ptr<Surface> m_Star = std::make_unique<Surface>("assets/star.png");

Sprite m_JackpotBorder = Sprite(m_Border.get(), 1);
Sprite m_SpriteBall = Sprite(m_Ball.get(), 1);
Sprite m_SpriteX = Sprite(m_X.get(), 1);
Sprite m_SpriteHeart = Sprite(m_Heart.get(), 1);
Sprite m_SpriteLightning = Sprite(m_Lightning.get(), 1);
Sprite m_SpriteStar = Sprite(m_Star.get(), 1);

std::array<Sprite, 5> mySprites;

// -----------------------------------------------------------
// Initialize the application
// -----------------------------------------------------------
void Game::Init()
{
	// anything that happens only once at application start goes here

	mySprites[0] = m_SpriteX;
	mySprites[1] = m_SpriteHeart;
	mySprites[2] = m_SpriteLightning;
	mySprites[3] = m_SpriteBall;
	mySprites[4] = m_SpriteStar;

	//mySlot.Initialize(int2(100, 50), int2(50, 1050), int2(150, 150), 300, mySprites);
	myJackpot.Initialize(int2(50, 50), int2(1500, 1000), int2(50, 1050), int2(150, 150), 300, mySprites);
}

// -----------------------------------------------------------
// Main application tick function - Executed once per frame
// -----------------------------------------------------------
void Game::Tick( float deltaTime )
{
	// Clear screen to black
	screen->Clear(0x000000);

	// !!! This breaks score when held or even pressed normally, because it keeps accumulating score
	if (GetAsyncKeyState(VK_SPACE) & 1)
		myJackpot.Stop();

	if (GetAsyncKeyState(VK_RETURN) & 1)
		myJackpot.Start();

	myJackpot.Update(deltaTime);
	myJackpot.Draw(screen);

	// Print FPS to screen
	char buf[64]; sprintf(buf, "%Lf", 1000.f / deltaTime); screen->Print(buf, 10, 10, 0xffffff);

	int score = myJackpot.GetScore();
	char buf1[64]; sprintf(buf1, "%i", score); screen->Print(buf1, 1600, 600, 0xffffff);
}
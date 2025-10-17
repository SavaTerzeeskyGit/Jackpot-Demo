#pragma once
#include "JackpotSlot.h"

class Jackpot : public Base
{
public:
	Jackpot(int2 pos, int2 widthHeight);
	~Jackpot();

	void Spin();
	void Update(const float& deltaTime) override;
	void Draw(const Surface* screen) override;

private:
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

	//JackpotSlot slots[5];
	
	//const int m_PosX = 50;
	//const int m_PosY = 50;
	//const int m_Width = 1500;
	//const int m_Height = 1000;
};
#pragma once
#include "Base.h"
#include "JackpotSlot.h"
#include "array"

class Jackpot : public Base
{
public:
	Jackpot() = default;
	~Jackpot() override;

	Jackpot(const int2& pos, const int2& widthHeight);

	void Initialize(const int2& pos, const int2& widthHeight, const int2& slotWidthHeight, const int2& spriteWithHeight, const int& padding, const std::array<Sprite, 5>& sprites);

	void Update(const float& deltaTime) override;
	void Draw(const Surface* screen) override;

	void Stop();
	void Start();
	void CalculateScore();

	void SetSlots(int2 pos, int2 widthHeight);
	void UpdateSpritesToPass(const std::array<Sprite, 5>& sprites);
	void DrawWinningEntries(Surface* screen);

	int GetScore() { return m_Score; }

private:
	const std::unique_ptr<Surface> m_Border = std::make_unique<Surface>("assets/Border.png");
	Sprite m_JackpotBorder = Sprite(m_Border.get(), 1);


	std::array<JackpotSlot, 5> m_Slots{};
	std::array<Sprite, 5> m_Sprites{};
	std::array<Sprite, 3> m_SpritesToPass{};

	std::vector<SlotEntry*> m_WinningEntries;
	std::vector<Sprite> uniqueSprites;

	int2 m_Borders = int2(0);
	int m_Padding = 150;
	int m_Score = 0;
	bool m_StopSpinning = false;
};
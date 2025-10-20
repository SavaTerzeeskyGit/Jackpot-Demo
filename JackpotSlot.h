#pragma once
#include "Base.h"
#include "SlotEntry.h"
#include "array"

class JackpotSlot : public Base
{
public:
	JackpotSlot() = default;
	~JackpotSlot() override = default;

	JackpotSlot(const int2& pos, const int2& widthHeight);

	void Initialize(const int2& pos, const int2& widthHeight, const int2& spriteWithHeight, const int& padding, const std::array<Sprite, 3>& sprites);

	void Update(const float& deltaTime) override;
	void Draw(const Surface* screen) override;

	void SetPadding(const int& padding);
	void SetSprites(const std::array<Sprite, 3>& sprites);
	void SetTotalSprites(const std::array<Sprite, 5>& sprites);

	inline const std::array<SlotEntry, 3>& GetEntries() const { return m_Entries; };

private:
	std::array<SlotEntry, 3> m_Entries{};
	std::array<Sprite, 3> m_Sprites{};
	std::array<Sprite, 5> m_TotalSprites{};
	int2 m_Borders = int2(0);
	int m_Padding = 50;
	int m_PaddingInternal = 50;
};
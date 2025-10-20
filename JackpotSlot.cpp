#include "precomp.h"
#include "JackpotSlot.h"

JackpotSlot::JackpotSlot(const int2& pos, const int2& widthHeight)
{
	SetPos(pos);
	SetWidthHeight(widthHeight);
}

void JackpotSlot::Initialize(const int2& pos, const int2& widthHeight, const int2& spriteWithHeight, const int& padding, const std::array<Sprite, 3>& sprites)
{
	SetPos(pos);
	SetWidthHeight(widthHeight);

	m_Padding = padding;
	m_Sprites = sprites;
	m_Borders = widthHeight;

	for (int i = 0; i < m_Entries.size(); i++) {
		m_Entries[i] = SlotEntry(int2(pos.x + m_PaddingInternal, pos.y + i * m_Padding), spriteWithHeight);
		m_Entries[i].SetSprite(m_Sprites[i]);
		m_Entries[i].SetSpeed(1.2f);
		m_Entries[i].SetBorders(m_Borders);
	}
}

void JackpotSlot::Update(const float& deltaTime)
{
	for (auto& entries : m_Entries) {
		if (entries.GetHitEdge()) {
			int randomNumber = rand() % 5;
			entries.SetSprite(m_TotalSprites[randomNumber]);
			entries.SetHitEdge(false);
		}
		entries.Update(deltaTime);
	}
}

void JackpotSlot::Draw(const Surface* screen)
{
	for (auto& entries : m_Entries) {
		entries.Draw(screen);
	}
}

void JackpotSlot::SetPadding(const int& padding)
{
	m_Padding = padding;
}

void JackpotSlot::SetSprites(const std::array<Sprite, 3>& sprites)
{
	m_Sprites = sprites;
}

void JackpotSlot::SetTotalSprites(const std::array<Sprite, 5>& sprites)
{
	m_TotalSprites = sprites;
}

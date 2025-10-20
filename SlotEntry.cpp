#include "precomp.h"
#include "SlotEntry.h"
#include "template/common.h"

SlotEntry::SlotEntry(const int2& pos, const int2& widthHeight)
{
	SetPos(pos);
	SetWidthHeight(widthHeight);
}

void SlotEntry::Update(const float& deltaTime)
{
	m_Pos.y += deltaTime * m_Speed;

	// Check to see if the entry has reached the jackpot border so that it resets back to the top
	if (m_Pos.y + m_WidthHeight.y + 5 >= m_Borders.y) {
		//m_Pos.y = m_Borders.x;
		m_HitEdge = true;
	}
}

void SlotEntry::Draw(const Surface* screen)
{
	m_EntrySprite.DrawScaled(m_Pos.x, m_Pos.y, m_WidthHeight.x, m_WidthHeight.y, screen);
}

void SlotEntry::SetSprite(const Sprite& sprite)
{
	m_EntrySprite = sprite;
}

void SlotEntry::SetSpeed(float speed)
{
	m_Speed = speed;
}

void SlotEntry::SetBorders(int2 borders)
{
	m_Borders = borders;
}

void SlotEntry::SetHitEdge(const bool& hitEdge)
{
	m_HitEdge = hitEdge;

	// This is bad but it looks weird if this happens in the update
	m_Pos.y = m_Borders.x;
}

bool SlotEntry::GetHitEdge()
{
	return m_HitEdge;
}

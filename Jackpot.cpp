#include "precomp.h"
#include "Jackpot.h"

using namespace Tmpl8;

Jackpot::Jackpot(int2 pos, int2 widthHeight)
{
    //m_Border = std::make_unique<Surface>("assets/Border.png");
    //m_Jackpot = Sprite(m_Border.get(), 1);
    SetPos(pos);
    SetWidthHeight(widthHeight);
}

Jackpot::~Jackpot()
{
	m_Border.~unique_ptr();
}

void Jackpot::Spin()
{
}

void Jackpot::Update(const float& /* deltaTime */)
{
}

void Jackpot::Draw(const Surface* screen)
{
    m_JackpotBorder.DrawScaled(m_Pos.x, m_Pos.y, m_WidthHeight.x, m_WidthHeight.y, screen);
}

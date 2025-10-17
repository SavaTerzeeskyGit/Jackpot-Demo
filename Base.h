#pragma once
#include <iostream>


class Base
{
public:
	Base()
		: m_Pos(0, 0), m_WidthHeight(0, 0)
	{
		std::cout << "Base contructor" << endl;
	}
	virtual ~Base() = default;

	virtual void Update(const float& deltaTime) = 0;
	virtual void Draw(const Surface* screen) = 0;

	inline void SetPos(const int2& pos) { m_Pos = pos; }
	inline void SetPos(const int& posX, const int& posY) { m_Pos.x = posX; m_Pos.y = posY; }
	inline float2 GetPos() const { return m_Pos; }	

	inline void SetWidthHeight(const int2& widthHeight) { m_WidthHeight = widthHeight; }
	inline void SetWidthHeight(const int& width, const int& height) { m_WidthHeight.x = width; m_WidthHeight.y = height; }
	inline float2 GetWidthHeight() const { return m_WidthHeight; }

protected:
	int2 m_Pos;
	int2 m_WidthHeight;
};
#pragma once
#include "Base.h"
#include <tmpl8math.h>


class SlotEntry : public Base
{
public:
	SlotEntry() = default;
	~SlotEntry() override = default;

	SlotEntry(const int2& pos, const int2& widthHeight);

	void Update(const float& deltaTime) override;
	void Draw(const Surface* screen) override;

	void SetSprite(const Sprite& sprite);
	void SetSpeed(float speed);
	void SetBorders(int2 borders);

	void SetHitEdge(const bool& hitEdge);
	bool GetHitEdge();

	inline const Sprite& GetSprite() const { return m_EntrySprite; }

private:
	// Spite
	Sprite m_EntrySprite = Sprite();
	float m_Speed = 1.f;
	int2 m_Borders = int2(0);
	bool m_HitEdge = false;
};
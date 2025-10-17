#pragma once
#include "Base.h"

class SlotEntry : public Base
{
public:
	SlotEntry() = default;
	~SlotEntry() override = default;

	void Update(const float& deltaTime) override;
	void Draw(const Surface* screen) override;

private:
	// Spite
};

class JackpotSlot : public Base
{
public:
	JackpotSlot() = default;
	~JackpotSlot() override = default;

	void Update(const float& deltaTime) override;
	void Draw(const Surface* screen) override;

private:
	//SlotEntry entries[3];
};
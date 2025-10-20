#include "precomp.h"
#include "Jackpot.h"

#include <cstdlib> // include this header for the rand() function
#include <ctime> // include this header for the time() function

using namespace Tmpl8;

Jackpot::Jackpot(const int2& pos, const int2& widthHeight)
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

void Jackpot::Initialize(const int2& pos, const int2& widthHeight, const int2& slotWidthHeight, const int2& spriteWithHeight, const int& padding, const std::array<Sprite, 5>& sprites)
{
    SetPos(pos);
    SetWidthHeight(widthHeight);

    m_Padding = padding;
    m_Sprites = sprites;
    m_Borders = widthHeight;

    srand(time(0));

    for (int i = 0; i < m_Slots.size(); i++) {
        UpdateSpritesToPass(sprites);
        m_Slots[i].Initialize(int2(pos.x + i * m_Padding, pos.y), slotWidthHeight, spriteWithHeight, padding, m_SpritesToPass);
        m_Slots[i].SetTotalSprites(m_Sprites);
    }
}

void Jackpot::Update(const float& deltaTime)
{
    if (m_StopSpinning)
        return;

    for (auto& slots : m_Slots) {
        slots.Update(deltaTime);
    }
}

void Jackpot::Draw(const Surface* screen)
{
    if (m_StopSpinning) {
        DrawWinningEntries(const_cast<Surface*>(screen));
    }

    for (auto& slots : m_Slots) {
        slots.Draw(screen);
    }

    m_JackpotBorder.DrawScaled(m_Pos.x, m_Pos.y, m_WidthHeight.x, m_WidthHeight.y, screen);
}

void Jackpot::Stop()
{
    m_StopSpinning = true;
    CalculateScore();
}

void Jackpot::Start()
{
    m_StopSpinning = false;

    m_WinningEntries.clear();
}

void Jackpot::CalculateScore()
{
    // collect all sprites that appear anywhere
    uniqueSprites.reserve(16);

    for (const auto& slot : m_Slots) {
        const auto& entries = slot.GetEntries(); 

        for (const auto& entry : entries) {
            const Sprite& sprite = entry.GetSprite();
            bool seen = false;

            for (const auto& uniqueSprite : uniqueSprites) {
                if (uniqueSprite == sprite) { 
                    seen = true; 
                    break; 
                }
            }

            if (!seen) 
                uniqueSprites.push_back(sprite);
        }
    }

    // for each unique sprite, check if every slot has it at least once
    for (const auto& uniqueSprite : uniqueSprites) {
        bool presentInAllSlots = true;

        for (const auto& slot : m_Slots) {
            const auto& entries = slot.GetEntries();
            bool foundInSlot = false;

            for (const auto& entry : entries) {
                const Sprite& sprite = entry.GetSprite();

                if (sprite == uniqueSprite) { 
                    foundInSlot = true; 

                    const SlotEntry* newEntry = &entry;
                    m_WinningEntries.push_back(const_cast<SlotEntry*>(newEntry));
                    break; 
                }
            }

            if (!foundInSlot) { 
                presentInAllSlots = false;
                break; 
            }
        }

        if (presentInAllSlots) {
            m_Score += 100; // award once per sprite type
        }
    }
}

void Jackpot::SetSlots(int2 pos, int2 widthHeight)
{
 
}

void Jackpot::UpdateSpritesToPass(const std::array<Sprite, 5>& sprites)
{
    for (int i = 0; i < m_SpritesToPass.size(); i++) {
        int randomNum = rand() % 5;
        m_SpritesToPass[i] = sprites[randomNum];
    }
}

void Jackpot::DrawWinningEntries(Surface* screen)
{
    for (const auto& winner : m_WinningEntries) {
        screen->Box(winner->GetPos().x, winner->GetPos().y, winner->GetPos().x + winner->GetWidthHeight().x, winner->GetPos().y + winner->GetWidthHeight().y, 0x00FF00);
    }
}

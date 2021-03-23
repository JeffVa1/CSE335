/**
 * \file Aquarium.h
 *
 * \author Charles B. Owen
 *
 * Class that represents an aquarium.
 */
#pragma once

#include <memory>
#include <vector>

class CItem;

/**
 * Represents an aquarium
 */
class CAquarium
{
public:
    CAquarium();

    void OnDraw(Gdiplus::Graphics* graphics);

    void Add(std::shared_ptr<CItem> item);
    void SendToBack(std::shared_ptr<CItem> item);
    void CheckBashfulDist();

    std::shared_ptr<CItem> HitTest(int x, int y);

private:
    std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image to use

    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<CItem> > mItems;
};

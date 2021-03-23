/**
 * \file FishBashful.h
 *
 * \author Jeffrey Valentic
 *
 * Class the implements a Bashful fish
 */

#pragma once

#include <memory>

#include "Item.h"


 /**
  * Implements a Beta fish
  */
class CFishBashful : public CItem
{
public:
    CFishBashful(CAquarium* aquarium);

    /// Default constructor (disabled)
    CFishBashful() = delete;

    /// Copy constructor (disabled)
    CFishBashful(const CFishBashful&) = delete;


    virtual void Draw(Gdiplus::Graphics* graphics) override;


    bool HitTest(int x, int y);

    void ChangeColor(bool isBash) override;

private:
    /// Fish green image
    std::unique_ptr<Gdiplus::Bitmap> mFishImageGreen;
    /// Fish red image
    std::unique_ptr<Gdiplus::Bitmap> mFishImageRed;
    /// Fish green image
    std::unique_ptr<Gdiplus::Bitmap> mFishImage;
    /// True if fish is within 200px of another fish. Else false
    bool bash = false;
};

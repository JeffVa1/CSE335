/**
 * \file FishDory.h
 *
 * \author Jeffrey Valentic
 *
 * Class the implements a Dory fish
 */

#pragma once

#include <memory>

#include "Item.h"


 /**
  * Implements a Beta fish
  */
class CFishDory : public CItem
{
public:
    CFishDory(CAquarium* aquarium);

    /// Default constructor (disabled)
    CFishDory() = delete;

    /// Copy constructor (disabled)
    CFishDory(const CFishDory&) = delete;


    virtual void Draw(Gdiplus::Graphics* graphics) override;


    bool HitTest(int x, int y);


private:
    /// Fish image
    std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};

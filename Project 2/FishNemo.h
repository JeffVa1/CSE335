/**
 * \file FishNemo.h
 *
 * \author Jeffrey Valentic
 *
 * Class the implements a Nemo fish
 */

#pragma once

#include <memory>

#include "Item.h"


 /**
  * Implements a Beta fish
  */
class CFishNemo : public CItem
{
public:
    CFishNemo(CAquarium* aquarium);

    /// Default constructor (disabled)
    CFishNemo() = delete;

    /// Copy constructor (disabled)
    CFishNemo(const CFishNemo&) = delete;


    virtual void Draw(Gdiplus::Graphics* graphics) override;


    bool HitTest(int x, int y);


private:
    /// Fish image
    std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};

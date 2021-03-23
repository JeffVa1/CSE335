/**
 * \file FishBeta.h
 *
 * \author Jeffrey Valentic
 *
 * Class the implements a Beta fish
 */

#pragma once

#include <memory>

#include "Item.h"


 /**
  * Implements a Beta fish
  */
class CFishBeta : public CItem
{
public:
    CFishBeta(CAquarium* aquarium);

    /// Default constructor (disabled)
    CFishBeta() = delete;

    /// Copy constructor (disabled)
    CFishBeta(const CFishBeta&) = delete;


    virtual void Draw(Gdiplus::Graphics* graphics) override;


    bool HitTest(int x, int y);


private:
    /// Fish image
    std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};

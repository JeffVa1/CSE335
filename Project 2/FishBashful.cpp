/**
 * \file FishBashful.cpp
 *
 * \author Jeffrey Valentic
 */

#include "pch.h"
#include <string>
#include "FishBashful.h"
#include "Item.h"

using namespace std;
using namespace Gdiplus;

/// Fish green filename 
const wstring FishBashfulGreenImageName = L"images/bashful-green.png";
/// Fish red filename 
const wstring FishBashfulRedImageName = L"images/bashful-red.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishBashful::CFishBashful(CAquarium* aquarium) : CItem(aquarium)
{
    /// Fish green image
    mFishImageGreen = unique_ptr<Bitmap>(Bitmap::FromFile(FishBashfulGreenImageName.c_str()));
    /// Fish red image
    mFishImageRed = unique_ptr<Bitmap>(Bitmap::FromFile(FishBashfulRedImageName.c_str()));
    /// Fish green image
    mFishImage = unique_ptr<Bitmap>(Bitmap::FromFile(FishBashfulGreenImageName.c_str()));
    if (mFishImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += FishBashfulGreenImageName;
        AfxMessageBox(msg.c_str());
    }
}

/**
 * Draw our fish
 * \param graphics The graphics context to draw on
 */
void CFishBashful::Draw(Gdiplus::Graphics* graphics)
{
    if (bash) {
        double wid = mFishImageRed->GetWidth();
        double hit = mFishImageRed->GetHeight();
        graphics->DrawImage(mFishImageRed.get(),
            float(GetX() - wid / 2), float(GetY() - hit / 2),
            (float)mFishImageRed->GetWidth(), (float)mFishImageRed->GetHeight());
    }
    else {
        double wid = mFishImageGreen->GetWidth();
        double hit = mFishImageGreen->GetHeight();
        graphics->DrawImage(mFishImageGreen.get(),
            float(GetX() - wid / 2), float(GetY() - hit / 2),
            (float)mFishImageGreen->GetWidth(), (float)mFishImageGreen->GetHeight());
    }
}

/**
 * Test to see if we hit this object with a mouse.
 * \param x X position to test
 * \param y Y position to test
 * \return true if hit.
 */
bool CFishBashful::HitTest(int x, int y)
{
    double wid = mFishImage->GetWidth();
    double hit = mFishImage->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to theimage top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    auto format = mFishImage->GetPixelFormat();
    if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
    {
        // This image has an alpha map, which implements the 
        // transparency. If so, we should check to see if we
        // clicked on a pixel where alpha is not zero, meaning
        // the pixel shows on the screen.
        Color color;
        mFishImage->GetPixel((int)testX, (int)testY, &color);
        return color.GetAlpha() != 0;
    }
    else {
        return true;
    }
}

/** Function to update the isBash boolean for bashful fish
* \param isBash true if within 200px of another fish, else false.
*/
void CFishBashful::ChangeColor(bool isBash)
{
    bash = isBash;
}
/**
 * \file Aquarium.cpp
 *
 * \author Jeffrey Valentic
 */

#include "pch.h"
#include "Aquarium.h"
#include "Item.h"
#include "FishBeta.h"
#include <algorithm>
#include "DoubleBufferDC.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 */
CAquarium::CAquarium()
{
    mBackground = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/background1.png"));
    if (mBackground->GetLastStatus() != Ok)
    {
        AfxMessageBox(L"Failed to open images/background1.png");
    }
}


/** Draw the aquarium
* \param graphics The GDI+ graphics context to draw on
*/
void CAquarium::OnDraw(Gdiplus::Graphics* graphics)
{
    graphics->DrawImage(mBackground.get(), 0, 0,
        mBackground->GetWidth(), mBackground->GetHeight());

    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 16);

    SolidBrush green(Color(0, 64, 0));
    graphics->DrawString(L"Under the Sea!", -1, &font, PointF(2, 2), &green);

    for (auto item : mItems)
    {
        item->Draw(graphics);
    }
}

/**
 * Add an item to the aquarium
 * \param item New item to add
 */
void CAquarium::Add(std::shared_ptr<CItem> item)
{
    mItems.push_back(item);
}

/** Test an x,y click location to see if it clicked
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> CAquarium::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }

    return  nullptr;
}

/** Send last clicked fish to the back of the items array
* \param item is the fish to send to the back of array
*/
void CAquarium::SendToBack(std::shared_ptr<CItem> item)
{
    auto loc = find(begin(mItems), end(mItems), item);
    std::shared_ptr<CItem> itemCopy = item;
    if (loc != end(mItems))
    {
        mItems.erase(loc);
    }

    mItems.push_back(itemCopy);

}

/** A function to check the distance between fish
* changes bashful fish boolean bash true if within 200 px
*/
void CAquarium::CheckBashfulDist()
{
    for (auto item : mItems) {
        double itemX = item->GetX();
        double itemY = item->GetY();
        double smallestDist = 1000000;
        for (auto otherFish : mItems)
        {
            double otherX = otherFish->GetX();
            double otherY = otherFish->GetY();
            double dx = itemX - otherX;
            double dy = itemY - otherY;

            double distance = sqrt(dx * dx + dy * dy);
            auto loc1 = find(begin(mItems), end(mItems), item);
            auto loc2 = find(begin(mItems), end(mItems), otherFish);
            if (loc1 != loc2) {
                if (distance < smallestDist) {
                    smallestDist = distance;
                }
            }
        }

        if (smallestDist <= 200) {
            item->ChangeColor(true);
        }
        else {
            item->ChangeColor(false);
        }
    }
}
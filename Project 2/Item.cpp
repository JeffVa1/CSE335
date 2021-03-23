/**
 * \file Item.cpp
 *
 * \author Jeffrey Valentic
 */

#include "pch.h"
#include "Item.h"
#include "Aquarium.h"


 /** Constructor
 * \param aquarium The aquarium this item is a member of
 */
CItem::CItem(CAquarium* aquarium) : mAquarium(aquarium)
{
}


/**
 * Destructor
 */
CItem::~CItem()
{
}

/** virtual function to provide color changeing ability to bashful fish
* \param isBash not used for fish other than bashful.
*/
void CItem::ChangeColor(bool isBash)
{
}
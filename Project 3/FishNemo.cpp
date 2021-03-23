/**
 * \file FishNemo.cpp
 *
 * \author Jeffrey Valentic
 */

#include "pch.h"
#include <string>
#include "FishNemo.h"
#include "Item.h"
#include "Fish.h"

using namespace std;
using namespace Gdiplus;

/// Maximum speed in the x direction
const double MaxSpeedX = 80;

/// Maximum speed in the y direction
const double MaxSpeedY = 80;

/// Minimum speed in the x direction
const double MinSpeedX = 25;

/// Minimum speed in the y direction
const double MinSpeedY = 25;

/// Fish filename 
const wstring FishNemoImageName = L"images/nemo.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishNemo::CFishNemo(CAquarium* aquarium) :
    CFish(aquarium, FishNemoImageName)
{
    CFish::SetSpeedX(MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX));
    CFish::SetSpeedY(MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY));
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishNemo::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);
    itemNode->SetAttribute(L"type", L"nemo");
    return itemNode;
}
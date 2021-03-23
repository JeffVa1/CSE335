/**
 * \file FishDory.cpp
 *
 * \author Jeffrey Valentic
 */

#include "pch.h"
#include <string>
#include "FishDory.h"
#include "Item.h"
#include "Fish.h"

using namespace std;
using namespace Gdiplus;

/// Maximum speed in the x direction
const double MaxSpeedX = 200;

/// Maximum speed in the y direction
const double MaxSpeedY = 200;

/// Minimum speed in the x direction
const double MinSpeedX = 100;

/// Minimum speed in the y direction
const double MinSpeedY = 10;

/// Fish filename 
const wstring FishDoryImageName = L"images/dory.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishDory::CFishDory(CAquarium* aquarium) :
    CFish(aquarium, FishDoryImageName)
{
    CFish::SetSpeedX(MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX));
    CFish::SetSpeedY(MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY));
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishDory::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);
    itemNode->SetAttribute(L"type", L"dory");
    return itemNode;
}
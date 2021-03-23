#include "pch.h"
#include "Fish.h"
#include "Item.h"
#include "Aquarium.h"
#include "XmlNode.h"

using namespace std;
using namespace xmlnode;
/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;

/**
 * Constructor
 * \param aquarium The aquarium we are in
 * \param filename Filename for the image we use
 */
CFish::CFish(CAquarium* aquarium, const std::wstring& filename):CItem(aquarium, filename)
{
	mSpeedX = ((double)rand() / RAND_MAX) * MaxSpeedX;
	mSpeedY = ((double)rand() / RAND_MAX) * MaxSpeedX;
}

/**
*Handle updates in time of our fish
*
* This is called before we drawand allows us to
* move our fish.We add our speed times the amount
* of time that has elapsed.
* \param elapsed Time elapsed since the class call
*/
void CFish::Update(double elapsed)
{
	SetLocation(GetX() + mSpeedX * elapsed,
		GetY() + mSpeedY * elapsed);

	if (mSpeedX > 0 && GetX() >= GetAquarium()->GetWidth() - 10 - GetWidth()/2)
	{
		mSpeedX = -mSpeedX;
		mSpeedY = ((double)rand() / RAND_MAX) * MaxSpeedX;
		SetMirror(mSpeedX < 0);
	}
	if (mSpeedX < 0 && GetX() <= GetWidth()/2)
	{
		mSpeedY = ((double)rand() / RAND_MAX) * MaxSpeedX;
		mSpeedX = -mSpeedX;
		SetMirror(mSpeedX < 0);
	}

	if (mSpeedY > 0 && GetY() >= GetAquarium()->GetHeight() - 10 - GetHeight()/2)
	{
		mSpeedY = -mSpeedY;
	}
	if (mSpeedY < 0 && GetY() <= GetHeight()/2 + 10)
	{
		mSpeedY = -mSpeedY;
	}
}

/**
* Save this fish to an XML node
* \param node The node we are going to be a child of
*/
shared_ptr<CXmlNode> CFish::XmlSave(const shared_ptr<CXmlNode>& node)
{
	auto itemNode = node->AddChild(L"item");

	itemNode->SetAttribute(L"x", GetX());
	itemNode->SetAttribute(L"y", GetY());
	itemNode->SetAttribute(L"speedx", mSpeedX);
	itemNode->SetAttribute(L"speedy", mSpeedY);

	return itemNode;
}

/**
* Load the attributes for a fish node.
*
* \param node The Xml node we are loading the fish from
*/
void CFish::XmlLoad(const shared_ptr<CXmlNode>& node)
{
	CItem::XmlLoad(node);
	mSpeedX = node->GetAttributeDoubleValue(L"speedx", 0);
	mSpeedY = node->GetAttributeDoubleValue(L"speedy", 0);
	SetMirror(mSpeedX < 0);
}
/**
 * \file Aquarium.h
 *
 * \author Charles B. Owen
 *
 * Class that represents an aquarium.
 */
#pragma once

#include "XmlNode.h"
#include <memory>
#include <vector>
#include <string>

using namespace xmlnode;

class CItem;

/**
 * Represents an aquarium
 */
class CAquarium
{
public:
    CAquarium();

    void OnDraw(Gdiplus::Graphics* graphics);

    void Add(std::shared_ptr<CItem> item);
    void SendToBack(std::shared_ptr<CItem> item);

    std::shared_ptr<CItem> HitTest(int x, int y);

    void Save(const std::wstring& filename);

    void Load(const std::wstring& filename);

    void Clear();

    void Update(double elapsed);

    /// Get the width of the aquarium
    /// \returns Aquarium width
    int GetWidth() const { return mBackground->GetWidth(); }

    /// Get the height of the aquarium
    /// \returns Aquarium height
    int GetHeight() const { return mBackground->GetHeight(); }

private:
    std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image to use

    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<CItem> > mItems;

    void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);
};

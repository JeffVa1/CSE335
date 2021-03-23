/**
 * \file FishDory.h
 *
 * \author Jeffrey Valentic
 *
 * Class the implements a Dory fish
 */

#pragma once

#include <memory>
#include "Fish.h"
#include "Item.h"


 /**
  * Implements a Beta fish
  */
class CFishDory : public CFish
{
public:
    CFishDory(CAquarium* aquarium);

    /// Default constructor (disabled)
    CFishDory() = delete;

    /// Copy constructor (disabled)
    CFishDory(const CFishDory&) = delete;

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
};

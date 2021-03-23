/**
 * \file FishNemo.h
 *
 * \author Jeffrey Valentic
 *
 * Class the implements a Nemo fish
 */

#pragma once

#include <memory>
#include "Fish.h"
#include "Item.h"


 /**
  * Implements a Beta fish
  */
class CFishNemo : public CFish
{
public:
    CFishNemo(CAquarium* aquarium);

    /// Default constructor (disabled)
    CFishNemo() = delete;

    /// Copy constructor (disabled)
    CFishNemo(const CFishNemo&) = delete;

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
};

/**
 * \file Chicken.h
 *
 * \author Jeffrey Valentic
 *
 * Declaration of the CChicken class.
 */

#pragma once

#include <string>
#include "Animal.h"

 /**
  * Class that describes a chicken.
  *
  * Holds information about a chicken such as
  * mId (the ID of the chicken)
  */
class CChicken : public CAnimal
{
public:
    /** Obtain a chicken description from the user.
     */
    void ObtainChickenInformation();
    /** Display the chicken.
     */
    void DisplayAnimal();

private:
    /// The chicken's ID
    std::string mId;
};

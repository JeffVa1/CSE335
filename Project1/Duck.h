/**
 * \file Duck.h
 *
 * \author Jeffrey Valentic
 *
 *Declaration of CDuck class.
 */

#pragma once
#include <string>
#include "Animal.h"

 /**
  * Class that describes a duck.
  *
  * Holds information about a duck such as
  * Name and Type of duck.
  */
class CDuck : public CAnimal
{
public:
    /// The types of cow we can have on our farm
    enum class Type { MallardDuck, WoodDuck, DisneyDuck, WarnerBrothersDuck };
    void ObtainDuckInformation();
    void DisplayAnimal();
    /**
     * \return true or false based on
     * if the duck is witch weight.
     */
    bool IsWitchWeight();

private:
    /// The cow's name
    std::string mName;

    /// The type of duck
    Type mType = Type::MallardDuck;
};


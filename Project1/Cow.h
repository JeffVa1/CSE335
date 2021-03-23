/**
 * \file Cow.h
 *
 * \author Jeffrey Valentic
 *
 * Declaration of CCow class.
 * 
 */

#pragma once
#include <string>
#include "Animal.h"

 /**
  * Class that describes a cow.
  *
  * Holds information about a cow such as
  * Name, Type of cow, and milk production.
  */
class CCow : public CAnimal
{
public:
	/// The types of cow we can have on our farm
	enum class Type { Bull, BeefCow, MilkCow };
    /**
     * Obtain information from the user about this cow.
     *
     * Asks the user for the information that describes a cow.
     */
    void ObtainCowInformation();
    /**
     * Display information about this cow.
     */
    void DisplayAnimal();

private:
    /// The cow's name
    std::string mName;

    /// The type of cow: Bull, BeefCow, or MilkCow
    Type mType = Type::MilkCow;

    /// The milk production for a cow in gallons per day
    double mMilkProduction = 0;
};


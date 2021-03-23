/**
 * \file Farm.h
 *
 * \author Jeffrey Valentic
 *
 * Class that describes a Farm.
 *
 * This class holds a collection of animals that make
 * up the inventory of a farm.
 */

#pragma once
#include <iostream>
#include <vector>
#include "Animal.h"
using namespace std;

/**
 * Class that describes a farm.
 *
 * Holds a collection of animals that make up the farm
 * inventory.
 */
class CFarm
{   
public:
    ~CFarm();
    void AddAnimal(CAnimal* animal);
    void DisplayInventory();

    /** WitchWeightCount
     * \return int, the number of animals on the
     * farm that weight the same as a witch.
     */
    int WitchWeightCount();

private:
    /// A list with the inventory of all animals on the farm
    std::vector<CAnimal*> mInventory;
};


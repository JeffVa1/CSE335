/**
 * \file Farm.cpp
 *
 * \author Jeffrey Valentic
 */

#include "Farm.h"
#include "leak.h"

 /**
  * CFarm destructor
  */
CFarm::~CFarm()
{
    // Iterate over all of the animals, destroying 
    // each one.
    for (auto animal : mInventory)
    {
        delete animal;
    }

    // And clear the list
    mInventory.clear();
}

 /** Add an animal to the farm inventory.
  *
  * \param animal an animal to add to the inventory
  */
void CFarm::AddAnimal(CAnimal* animal)
{
    mInventory.push_back(animal);
}

/**
 * Display the farm inventory.
 */
void CFarm::DisplayInventory()
{
    for (auto animal : mInventory)
    {
        animal->DisplayAnimal();
    }
}

/** Returns the number of animals on the
 * farm that weight the same as a witch.
 */
int CFarm::WitchWeightCount()
{
    int wwCount = 0;
    for (auto animal : mInventory)
    {
        if (animal->IsWitchWeight()) {
            wwCount++;
        }
    }
    return wwCount;
}
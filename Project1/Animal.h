/**
 * \file Animal.h
 *
 * \author Jeffrey Valentic
 *
 * Declaration of CAnimal class.
 *
 */

#pragma once

/**
 * Class that describes a general animal.
 * Contains functions to display the animal info
 * and to check if the animal is witch weight.
*/
class CAnimal
{
public:
    virtual ~CAnimal();
    /** Display an animal. */
    virtual void DisplayAnimal() {}
    /**
     * Function to tell if animal weights the
     * same as a witch.
     * 
     * \return bool false for all animals other than ducks.
     */
    virtual bool IsWitchWeight() { return false; }
};
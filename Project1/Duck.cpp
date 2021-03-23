/**
 * \file Duck.cpp
 *
 * \author Jeffrey Valentic
 */

#include "Duck.h"
#include "leak.h"
#include <iostream>

using namespace std;

/**
 * Obtain information from the user about this cow.
 *
 * Asks the user for the information that describes a cow.
 */
void CDuck::ObtainDuckInformation()
{
    cout << endl;
    cout << "Input information about the duck" << endl;

    // Obtain the name. This is easy, since it's just a
    // string.
    bool validName = false;
    while (!validName) {
        cout << "Name: ";
        cin.ignore();
        getline(cin, mName);

        if (mName.empty()) {
            cin.clear();
            continue;
        }
        else if (isspace(mName[0])) {
            cin.clear();
            continue;
        }
        else {
            validName = true;
        }
    }

    // Obtain the type using a menu. We have a loop so
    // we can handle errors.
    bool valid = false;
    while (!valid)
    {
        cout << "1: Mallard Duck" << endl;
        cout << "2: Wood Duck" << endl;
        cout << "3: Disney Duck" << endl;
        cout << "4: Warner Brothers Duck" << endl;
        cout << "Enter selection and return: ";
        int option;
        cin >> option;
        if (!cin)
        {
            // We have an error. Clear the input and try again
            cin.clear();
            cin.ignore();
            continue;
        }

        switch (option)
        {
        case 1:
            mType = Type::MallardDuck;
            valid = true;
            break;

        case 2:
            mType = Type::WoodDuck;
            valid = true;
            break;

        case 3:
            mType = Type::DisneyDuck;
            valid = true;
            break;

        case 4:
            mType = Type::WarnerBrothersDuck;
            valid = true;
            break;
        }
    }
}

/**
 * Display information about this duck.
 */

void CDuck::DisplayAnimal()
{
    cout << mName << ": ";
    switch (mType)
    {
    case Type::MallardDuck:
        cout << "Mallard Duck" << endl;
        break;

    case Type::WoodDuck:
        cout << "Wood Duck" << endl;
        break;

    case Type::DisneyDuck:
        cout << "Disney Duck" << endl;
        break;

    case Type::WarnerBrothersDuck:
        cout << "Warner Brothers Duck" << endl;
        break;
    }
}

/**
 * Function to tell if a duck is witch weight.
 * Returns true if witch weight, false otherwise.
 */
bool CDuck::IsWitchWeight()
{
    if (mType != Type::DisneyDuck) {
        return true;
    }
    else {
        return false;
    }
}
//
//  Contacts.h
//  pg5
//
//  Created by Alex Sharata on 10/26/14.
//  Copyright (c) 2014 Alex Sharata. All rights reserved.
//

#ifndef __pg5__Contacts__
#define __pg5__Contacts__

#include <stdio.h>
#include <string>
#include <iostream>
#include <map>

using std::string;
using std::map;

typedef struct {
    string name;
    map<int, string> phoneNumberPairs;
    bool isFav;
} Contact;

// Vector methods
void displayAll();
void displayFavs();
void displayContact();

// With vectors, must implement alphabetical sort
void sortContacts(); // called after each addContactToFull();
void swapFavorites(); // 'rearranges' favorites (just moves a favorite to a new position)

// Contact methods
// Return true/false if process was completed succesfully
bool addContactToFull(string, bool);
bool addContactToFavs();
bool deleteContactFromFull();   // This method should delete from full (and from favorites if contact is also in favorites
bool deleteContactFromFavs();   // This method deletes solely from favorites

// Map methods (Phone Number Pair)
void addPhoneNumberPair(int, string);
void deletePhoneNumberPair(int, string);

// Simulates clear screen
void clearScreen();

#endif /* defined(__pg5__Contacts__) */

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
void swapFavorites(); // 'rearranges' favorites (just swaps 2 around)

// Contact methods
bool addContactToFull(string, bool);
bool addContactToFav();
bool deleteContact();   // Returns true/false if contact was deleted successfully

// Map methods (Phone Number Pair)
void addPhoneNumberPair(int, string);
void deletePhoneNumberPair(int, string);

#endif /* defined(__pg5__Contacts__) */

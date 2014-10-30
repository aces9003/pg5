//
//  Contacts.h
//  pg5
//  Course: 600.120
//  Assignment 1
//  Created by Alex Sharata and Matthias Philippine on 10/26/14.
//  Copyright (c) 2014 Alex Sharata and Matthias Philippine. All rights reserved.
//  Matthias Philippine: 5106440780, mphili11, twinmat@gmail.com
//  Alex Sharata: 5712304745, asharat1, asharata18@gmail.com

#ifndef __pg5__Contacts__
#define __pg5__Contacts__

#include <stdio.h>
#include <string>
#include <strings.h>
#include <iostream>
#include <map>

using std::string;
using std::map;

typedef struct {
    string firstName;
    string lastName;
    bool isFav;
    map<string, string> phoneNumberPairs;
} Contact;

// Vector methods
void displayAllUnalphabetized();
void displayFavs();

void displayPhoneNumberPairs(int);
void displaySortedPhoneNumberPairs(int);
void displayFavPhoneNumberPairs(int);

void displayContact(int);   // Parameter specifies index in vector
void displaySortedContact(int);
void displayFavContact(int);

// With vectors, must implement alphabetical sort
void sortContactsFirstName(); // called after each change to contacts vector
void sortConcatctsLastName();
bool compFunctionFirstName(const Contact&, const Contact&);   // Comparison function for sort
bool compFunctionLastName(const Contact&, const Contact&);
void rearrangeFavorite(int, int); // 'rearranges' favorites (just moves a favorite to a new position)

// Contact methods
// Return true/false if process was completed succesfully
bool addContactToFull(string, string, bool);    // Runs addPhoneNumberPair() n times within
bool addContactToFavs(int);
bool deleteContactFromFull(int);   // This method should delete from full (and from favorites if contact is also in favorites)
bool deleteContactFromFavs(int);   // This method deletes solely from favorites

// Map methods (Phone Number Pair)
void addPhoneNumberPair(int, string, string);
void deletePhoneNumberPair(int, string);
void deletePhoneNumberPairViaIndex(int, int);

#endif /* defined(__pg5__Contacts__) */

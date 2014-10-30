//
//  Contacts.cpp
//  pg5
//  Course: 600.120
//  Assignment 1
//  Created by Alex Sharata and Matthias Philippine on 10/26/14.
//  Copyright (c) 2014 Alex Sharata and Matthias Philippine. All rights reserved.
//  Matthias Philippine: 5106440780, mphili11, twinmat@gmail.com
//  Alex Sharata: 5712304745, asharat1, asharata18@gmail.com

#include <vector>
#include <algorithm>
#include <strings.h>
#include "Contacts.h"

using std::string;	using std::cin;		using std::vector;		using std::endl;
using std::map;		using std::cout;	using std::iterator;    using std::sort;

vector<Contact> contacts;
vector<Contact> sortedContacts;
vector<Contact*> favorites;

//cout all contacts
void displayAllUnalphabetized(){
    int index=0;
    for(auto i = contacts.begin(); i != contacts.end(); ++i){
        cout << " ["<< index << "] " << '\t' << i->firstName << " " << i->lastName << endl;
        index++;
    }
}

//cout favorites vector
void displayFavs(){
    int index=0;
    for(auto i = favorites.begin(); i != favorites.end(); ++i){
        cout << " ["<< index << "] " << '\t' << (*i)->firstName << " " << (*i)->lastName << endl;
        index++;
    }
}

//cout phone number pair based on vector index and int pair index in map
void displayPhoneNumberPairs(int cInd){
    int index=0;
    for (auto i = contacts.at(cInd).phoneNumberPairs.begin(); i != contacts.at(cInd).phoneNumberPairs.end(); i++) {
        cout << '\t' << "["<< index << "] " << i->first << " " << i->second << endl;
        index++;
    }
}

//cout phone number pair based on vector index and int pair index in map
void displaySortedPhoneNumberPairs(int cInd){
    int index=0;
    for (auto i = sortedContacts.at(cInd).phoneNumberPairs.begin(); i != sortedContacts.at(cInd).phoneNumberPairs.end(); i++) {
        cout << '\t' << "["<< index << "] " << i->first << " " << i->second << endl;
        index++;
    }
}

//cout fav phone number pair based on vector index and int pair index in map
void displayFavPhoneNumberPairs(int fInd){
    int index=0;
    for (auto i = favorites.at(fInd)->phoneNumberPairs.begin(); i != favorites.at(fInd)->phoneNumberPairs.end(); i++) {
        cout << '\t' << "["<< index << "] " << i->first << " " << i->second << endl;
        index++;
    }
}

//cout specific contact based on index
void displayContact(int ind){
    cout << contacts.at(ind).firstName << " " << contacts.at(ind).lastName << endl;
    displayPhoneNumberPairs(ind);
}

void displaySortedContact(int ind){
    cout << sortedContacts.at(ind).firstName << " " << sortedContacts.at(ind).lastName << endl;
    displaySortedPhoneNumberPairs(ind);
}

void displayFavContact(int ind){
    cout << favorites.at(ind)->firstName << " " << favorites.at(ind)->lastName << endl;
    displayFavPhoneNumberPairs(ind);
}

//sort contact vector alphabetically -- by first name
void sortContactsFirstName(){
    sort(sortedContacts.begin(), sortedContacts.end(), compFunctionFirstName);
}

bool compFunctionFirstName(const Contact& cont1, const Contact& cont2)
{
    bool comp = false;
    if(strcasecmp(cont1.firstName.c_str(), cont2.firstName.c_str()) > 0){
        comp = false;
    }
    else if (strcasecmp(cont1.firstName.c_str(), cont2.firstName.c_str()) < 0){
        comp = true;
    }
    else if(strcasecmp(cont1.firstName.c_str(), cont2.firstName.c_str()) == 0){
        if ((cont1.lastName.c_str(), cont2.lastName.c_str()) > 0){
            comp = false;
        }
        else if((cont1.lastName.c_str(), cont2.lastName.c_str()) < 0){
            comp = true;
        }
        else{
            comp = false;
        }
    }
    return comp;
}

//sort contact vector alphabetically -- by last name
void sortContactsLastName(){
    sort(sortedContacts.begin(), sortedContacts.end(), compFunctionLastName);
}

bool compFunctionLastName(const Contact& cont1, const Contact& cont2)
{
    bool comp = false;
    if(strcasecmp(cont1.lastName.c_str(), cont2.lastName.c_str()) > 0){
        comp = false;
    }
    else if (strcasecmp(cont1.lastName.c_str(), cont2.lastName.c_str()) < 0){
        comp = true;
    }
    else if(strcasecmp(cont1.lastName.c_str(), cont2.lastName.c_str()) == 0){
        if ((cont1.firstName.c_str(), cont2.firstName.c_str()) > 0){
            comp = false;
        }
        else if((cont1.firstName.c_str(), cont2.firstName.c_str()) < 0){
            comp = true;
        }
        else{
            comp = false;
        }
    }
    return comp;
}
 
//rearange method given index 1 of contact and index 2 of insert
void rearrangeFavorites(int ind1, int ind2){
    Contact *cptr = favorites.at(ind1);
    favorites.erase(favorites.begin() + ind1);
    favorites.insert(favorites.begin() + ind2, cptr);
}

//add name into new contact struct
bool addContactToFull(string fname, string lname, bool fav){
    Contact nContact = {fname, lname, fav, *new map<string, string>};
    contacts.push_back(nContact);
    if (fav){
        addContactToFavs((int)contacts.size()-1);
    }
    return true;
}

// add contact from vector to favorites based on index
bool addContactToFavs(int ind){
    for (auto i = favorites.begin(); i != favorites.end(); i++)
        if ((contacts.at(ind).firstName == (*i)->firstName) && (contacts.at(ind).lastName == (*i)->lastName))
            return false;
    contacts.at(ind).isFav = true;
    Contact* cptr = &contacts.at(ind);
    favorites.push_back(cptr);
    return true;
}

// delete contact from vector contacts based on index
bool deleteContactFromFull(int ind){
    int fIndex = 0;
    if (contacts.at(ind).isFav){
        for (auto i = favorites.begin();i != favorites.end();i++) {
            if ((contacts.at(ind).firstName == (*i)->firstName) && (contacts.at(ind).lastName == (*i)->lastName)){
                break;
            }
            fIndex++;
        }
    }
    
    if (contacts.at(ind).isFav) {
        deleteContactFromFavs(fIndex);
    }
    
    contacts.erase(contacts.begin()+ind);
    return true;
}

// delete contact from vector favorites based on index
bool deleteContactFromFavs(int ind){
    int cIndex = 0;
    for (auto i = contacts.begin(); i != contacts.end(); i++) {
        if ((favorites.at(ind)->firstName == (*i).firstName) && (favorites.at(ind)->lastName == (*i).lastName)){
            break;
        }
        cIndex++;
    }
    // Changes original contact's isFav back to false
    contacts.at(cIndex).isFav = false;
    favorites.erase(favorites.begin()+ind);
    return true;
}

// Map methods (Phone Number Pair)
void addPhoneNumberPair(int ind, string num, string type){
    contacts.at(ind).phoneNumberPairs.emplace(num,type);
}

// Map methods (Phone Number Pair)
void deletePhoneNumberPair(int ind, string key){
    auto i=contacts.at(ind).phoneNumberPairs.find(key);
    contacts.at(ind).phoneNumberPairs.erase(i);
}

void deletePhoneNumberPairViaIndex(int ind, int mapIndex){
    int index = 0;
    for (auto i=contacts.at(ind).phoneNumberPairs.begin(); i != contacts.at(ind).phoneNumberPairs.end(); i++) {
        if (index == mapIndex) {
            contacts.at(ind).phoneNumberPairs.erase(i);
            return;
        }
        index++;
    }
}

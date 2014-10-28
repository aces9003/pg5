//
//  Contacts.cpp
//  pg5
//
//  Created by Alex Sharata on 10/26/14.
//  Copyright (c) 2014 Alex Sharata. All rights reserved.
//

#include <vector>
#include "Contacts.h"

using std::string;	using std::cin;		using std::vector;		using std::endl;
using std::map;		using std::cout;		using std::iterator;

vector<Contact> contacts;
vector<Contact*> favorites;

//cout all contacts
void displayAll(){
    int index=0;
    for(auto i = contacts.begin(); i != contacts.end(); ++i){
        cout << "["<< index << "] " << i->firstName << " " << i->lastName << endl;
        index++;
    }
}

//cout favorites vector
void displayFavs(){
    int index=0;
    for(auto i = favorites.begin(); i != favorites.end(); ++i){
        cout << "["<< index << "] " << (*i)->firstName << " " << (*i)->lastName << endl;
        index++;
    }
}

//cout phone number pair based on vector index and int pair index in map
void displayPhoneNumberPairs(int cInd){
    int index=0;
    for (auto i = contacts.at(cInd).phoneNumberPairs.begin(); i != contacts.at(cInd).phoneNumberPairs.end(); i++) {
        cout << "["<< index << "] " << i->first << " " << i->second <<endl;
        index++;
    }
}

//cout specific contact based on index
void displayContact(int ind){
    cout << contacts.at(ind).firstName << " " << contacts.at(ind).lastName << endl;
    displayPhoneNumberPairs(ind);
}

//sort contact vector alphabetically
void sortContacts(){
    
}

//rearange method given index 1 of contact and index 2 of insert
void rearrangeFavorites(int ind1, int ind2){
    
}

// add contact from vector to favorites based on index
bool addContactToFav(int ind){
    for (auto i = favorites.begin(); i != favorites.end(); i++)
        if ((contacts.at(ind).firstName == (*i)->firstName) && (contacts.at(ind).lastName == (*i)->lastName))
            return false;
    Contact* cptr = &contacts.at(ind);
    favorites.push_back(cptr);
    return true;
}

//add name into new contact struct
bool addContactToFull(string fname, string lname, bool fav){
    Contact nContact = {fname, lname, fav, *new map<string, string>};
    contacts.push_back(nContact);
    if (fav){
        addContactToFav((int)contacts.size() -1);
    }
    sortContacts();
    return true;
    //return false when?
}

// delete contact from vector contacts based on index
bool deleteContactFromFull(int ind){
    if (contacts.at(ind).isFav){
        for (auto i = favorites.begin();i != favorites.end();i++)
            if ((contacts.at(ind).firstName == (*i)->firstName) && (contacts.at(ind).lastName == (*i)->lastName)){
                favorites.erase(i);
            }
    }
    contacts.erase(contacts.begin()+ind);
    return true;
}

// delete contact from vector favorites based on index
bool deleteContactFromFavs(int ind){
    //for (auto i = favorites.begin(); i != favorites.end(); i++)
    //	if (*(favorites.at(ind)) == *i){
    favorites.erase (favorites.begin()+ind);
    return true;
    //	}
    //return false;
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


//
//  Contacts.cpp
//  pg5
//
//  Created by Alex Sharata on 10/26/14.
//  Copyright (c) 2014 Alex Sharata. All rights reserved.
//

#include <vector>
#include <algorithm>
#include "Contacts.h"

using std::string;	using std::cin;		using std::vector;		using std::endl;
using std::map;		using std::cout;	using std::iterator;    using std::sort;

vector<Contact> contacts;
vector<Contact*> favorites;

//cout all contacts
void displayAll(){
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

void displayFavContact(int ind){
    cout << favorites.at(ind)->firstName << " " << favorites.at(ind)->lastName << endl;
    displayFavPhoneNumberPairs(ind);
}

//sort contact vector alphabetically
void sortContacts(){
    sort(contacts.begin(), contacts.end(), compFunction);
}

bool compFunction(const Contact& cont1, const Contact& cont2)
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
 
//rearange method given index 1 of contact and index 2 of insert
void rearrangeFavorites(int ind1, int ind2){
    Contact *cptr = favorites.at(ind1);
    favorites.erase(favorites.begin() + ind1);
    favorites.insert(favorites.begin() + ind2, cptr);
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

//add name into new contact struct
bool addContactToFull(string fname, string lname, bool fav){
    Contact nContact = {fname, lname, fav, *new map<string, string>};
    contacts.push_back(nContact);
    if (fav){
        addContactToFavs((int)contacts.size()-1);
    }
    return true;
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


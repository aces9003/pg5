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

extern vector<Contact> contacts;
extern vector<Contact*> favorites;

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
    	cout << "["<< index << "] " << i->firstName << " " << i->lastName << endl;
    	index++;
    }
}

//cout phone number pair based on vector index and int pair index in map
void displayPhoneNumberPairs(int cInd){
	int index=0;
	for (auto i = contacts.at(ind).phoneNumberPairs.begin(); i != contacts.at(ind).phoneNumberPairs.end(); i++) {
    	cout << "["<< index << "] " << i->first << " " << i->second <<endl;
    	index++;
	}
}

//cout specific contact based on index
void displayContact(int ind){
	int index=0;
	cout << contacts.at(ind).firstName << " " << contacts.at(ind).lastName << endl;
	displayPhoneNumberPairs(ind);
}

//sort contact vector alphabetically
void sortContacts(){

}

//rearange method given index 1 of contact and index 2 of insert
void rearrangeFavorites(int ind1, int ind2){

}

//add name into new contact struct
bool addContactToFull(string fname, string lname, bool fav){
	Contact nContact = {fname, lname, fav};
	contacts.pushBack(nContact);
	if (fav){
		addContactToFav(contacts.size()-1);
	}
	return true;
	//return false when
    // it'll return false if something goes wrong up above, no need to worry about setting condition for returning false
}

// add contact from vector to favorites based on index
bool addContactToFav(int ind){
	for (auto i = favorites.begin(); i != favorites.end(); i++)
		if (contacts.at(ind) == *i)
			return false;
	Contact* cptr = contacts.at(ind);
	favorites.pushBack(cptr); //add * or not?
	return true;
}

//add name into new contact struct
bool addContactToFull(string fname, string lname, bool fav){
	Contact nContact = {fname, lname, fav};
	contacts.pushBack(nContact);
	if (fav){
		addContactToFav(contacts.size() -1);
	}
	return true;
	//return false when?
}

// delete contact from vector contacts based on index
bool deleteContactFromFull(int ind){
	for (auto i = contacts.begin(); i != contacts.end(); i++)
		if (contacts.at(ind) == *i){
			contacts.erase(contacts.begin()+ind);
			return true;
		}
	return false;
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
void addPhoneNumberPair(int ind, int num, string type){
	contacts.at(ind).phoneNumberPairs.emplace(num,type);
}

// Map methods (Phone Number Pair)
void deletePhoneNumberPair(int ind, int key){
	std::map<int,string>::iterator i;
	i=contacts.at(ind).phoneNumberPairs.find(key);
  	contacts.at(ind).phoneNumberPairs.erase(i);  
}

// Simulates clear screen
void clearScreen(){
		for (int i = 0; i < 1000; i++)  {cout << endl;} // Mimics clear screen
}
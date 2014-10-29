//
//  main.cpp
//  pg5
//
//  Created by Alex Sharata on 10/26/14.
//  Copyright (c) 2014 Alex Sharata. All rights reserved.
//

#include "Contacts.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    
    Contact newContact;
    
    newContact.firstName = "Test";
    newContact.lastName = "Person";
    newContact.phoneNumberPairs["1234567890"] = "CELL";
    
    cout << newContact.firstName << " " << newContact.lastName << endl;
    
    // Accesses individual key->val pair
    cout << newContact.phoneNumberPairs["1234567890"] << endl;
    
    // Iterate through map using const_iterator and print all key value pairs
    //for ( std::map< string, string >::const_iterator iter = newContact.phoneNumberPairs.begin(); iter != newContact.phoneNumberPairs.end(); ++iter ) {
    for (auto iter = newContact.phoneNumberPairs.begin(); iter != newContact.phoneNumberPairs.end(); iter++) {
        cout << iter->first << '\t' << iter->second << '\n';
    }

    
    cout << endl;
    
    return 0;
}

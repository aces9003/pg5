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
    
    newContact.name = "Test Person";
    newContact.phoneNumberPairs[1234567890] = "CELL";
    
    cout << newContact.name << endl;
    cout << newContact.phoneNumberPairs[1234567890] << endl;
    
    return 0;
}

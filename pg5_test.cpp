//
//  pg5_test.cpp
//  pg5
//
//  Created by Alex Sharata on 10/28/14.
//  Copyright (c) 2014 Alex Sharata. All rights reserved.
//

#include "Contacts.cpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <sstream>

using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

//int main(int argc, char *argv[]) {
int main() {
    
    system("clear");

    while(true) {
    startMainMenu:
        string mainMenuInput;
        mainMenuInput.clear();
        char singleCharInput = '\0';
        
        cout << "::Main Menu::PhoneList\n\n"
        << " 1) Edit Contacts List\n"
        << " 2) Edit Favorites List\n"
        << " 3) Display All Contacts\n"
        << " 4) Display Favorites\n"
        << " 5) Exit PhoneList\n\n"
        << "Selection: ";
        getline(cin, mainMenuInput);
        
        // Check to make sure only one character was input by user
        if (mainMenuInput.length() > 1) {
            system("clear");
            cout << "Invalid Input Entered\n\n";
            system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
            system("clear");
            goto startMainMenu;
        } else {
            singleCharInput = mainMenuInput[0];
        }
        
        system("clear");
        
        startSwitch:
        switch (singleCharInput) {
            case '1': {
                // First display contacts, names and indexes only
                system("clear");
                
                char editContactsList;
                cout << "::Contacts List::\n\n"
                << "INDEX" << '\t' << "CONTACT NAME\n";
                displayAll();
                cout << "=============================================\n\n"
                << "::Edit Contacts List::\n\n"
                << " 1) Add New Contact\n"
                << " 2) Edit Existing Contact\n"
                << " 3) Return to Main Menu\n\n"
                << "Selection: ";
                cin >> editContactsList;
                cout << endl;
                
                if (editContactsList > '4' || editContactsList < '1') {
                    cout << "Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '1';
                    system("clear");
                    goto startSwitch;
                } else if (editContactsList == '1') {
                    // Prompt user for data to create a new contact and add it to the full contacts list
                    system("clear");
                    
                    string newFirstName;
                    string newLastName;
                    char setIsFav;
                    bool isFav;
                    string newPNString;  // Really no need to convert it to int later...
                    string newPhoneType;
                    char continueAddingNewPNPairs;
                    
                    // Prompt for new contact's info
                    cout << "First name of new contact:  ";
                    cin >> newFirstName;
                    
                    cout << "Last name of new contact:  ";
                    cin >> newLastName;
                    
                    cout << "Is contact a favorite? (y/n):  ";
                    cin >> setIsFav;
                    
                    if (tolower(setIsFav) == 'y') {
                        isFav = true;
                    } else isFav = false;
                    
                    // Add new contact here
                    addContactToFull(newFirstName, newLastName, isFav);
                    
                moreNewPNPairs: // Execution jumps here if user wants to add more PN pairs to new contact
                    newPNString.clear();
                    newPhoneType.clear();
                    
                    cout << "Contact's phone number: ";
                    cin >> newPNString;
                    
                    cout << "Phone number type (for example, CELL, HOME, WORK, FAX, etc.): ";
                    cin >> newPhoneType;
                    
                    // Add PN pairs here
                    addPhoneNumberPair((int)contacts.size() - 1, newPNString, newPhoneType);
                    
                    cout << "Continue adding phone number pairs? (y/n): ";
                    cin >> continueAddingNewPNPairs;
                    
                    if (tolower(continueAddingNewPNPairs) == 'y') {
                        goto moreNewPNPairs;
                    }
                    
                    // Sort all contacts after the entire new contact is added
                    sortContacts();
                    
                    // store index and pass to method below
                    // addContactToFavs();
                    cout << "Done.\n";
                    system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                    system("clear");
                } else if (editContactsList == '2') {
                    // Delete contact from favorites
                    char editContactFromFullChar;
                    int editContactFromFullInt;
                    
                    cout << "Enter the index of the contact you wish to edit:  ";
                    cin >> editContactFromFullChar;
                    editContactFromFullInt = editContactFromFullChar - '0';
                    
                    char editContactsList;
                    cout << "::Contacts List::\n\n"
                    << " [X] contact name\n"
                    << " [X] contact name\n"
                    << " [X] contact name\n"
                    << " [X] contact name\n"
                    << " [X] contact name\n"
                    << "=============================================\n\n"
                    << "::Edit Contacts List::\n\n"
                    << " 1) Add New Contact\n"
                    << " 2) Edit Existing Contact\n"
                    << " 3) Return to Main Menu\n\n"
                    << "Selection: ";
                    cin >> editContactsList;
                    cout << endl;
                    
                    //cout << "Deleting contact at ["<< deleteContactFromFavsInt <<"] from favs...\n";
                    // store name OR index and pass to method below
                    // deleteContactFromFavs();
                    cout << "Done.\n";
                    system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                    system("clear");
                } else if (editContactsList == '3') {
                    system("clear");
                    goto startMainMenu;
                } else {
                    cout << "Edit contacts menu: Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '1';
                    system("clear");
                    goto startSwitch;
                }
            } break;
                
            case '2': {
                // First display favorites, names and indexes only
                system("clear");
                
                char editFavsList;
                cout << "::Favorites List::\n\n"
                << "INDEX" << '\t' << "CONTACT NAME\n";
                displayFavs();
                cout << "=============================================\n\n"
                << "::Edit Favorites List::\n\n"
                << " 1) Add Contact to Favorites\n"
                << " 2) Delete Contact from Favorites\n"
                << " 3) Rearrange Favorites\n"
                << " 4) Return to Main Menu\n\n"
                << "Selection: ";
                cin >> editFavsList;
                cout << endl;
                
                if (editFavsList > '4' || editFavsList < '1') {
                    cout << "Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '2';
                    system("clear");
                    goto startSwitch;
                } else if (editFavsList == '1') {
                    // Add contact from full list to favorites
                    // Print full contacts, names and indexes only
                    char addContactToFavsChar;
                    int addContactToFavsInt;
                    
                    // Print all contacts that have isFav == false;
                    cout << "::Contacts Not in Favorites::\n\n"
                    << "INDEX" << '\t' << "CONTACT NAME\n";
                    
                    int nonFavIndex=0;
                    for(auto i = contacts.begin(); i != contacts.end(); ++i){
                        if (!i->isFav) {
                            cout << " ["<< nonFavIndex << "] " << '\t' << i->firstName << " " << i->lastName << endl;
                        }
                        nonFavIndex++;
                    }
                    
                    /*
                    // If all contacts are already in favorites and there are none left to add to favorites:
                    if (nonFavIndex+1 == (int)favorites.size()) {
                        cout << "There are no contacts left to add to your favorites list.\n\n";
                        system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                        singleCharInput = '2';
                        system("clear");
                    }
                    */
                     
                    cout << "=============================================\n\n";
                    cout << "Enter the index of the contact you wish to add to your favorites list:  ";
                    cin >> addContactToFavsChar;
                    addContactToFavsInt = addContactToFavsChar - '0';
                    addContactToFavs(addContactToFavsInt);
                    cout << "Adding contact at [" << addContactToFavsInt << "] to favs...\n";
                    cout << "Done.\n";
                    system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                    system("clear");
                } else if (editFavsList == '2') {
                    // Delete contact from favorites
                    char deleteContactFromFavsChar;
                    int deleteContactFromFavsInt;
                    
                    cout << "Enter the index of the contact you wish to delete from your favorites list:  ";
                    cin >> deleteContactFromFavsChar;
                    deleteContactFromFavsInt = deleteContactFromFavsChar - '0';
                    cout << "Deleting contact at ["<< deleteContactFromFavsInt <<"] from favs...\n";
                    // store name OR index and pass to method below
                    // deleteContactFromFavs();
                    cout << "Done.\n";
                    system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                    system("clear");
                } else if (editFavsList == '3') {
                    // Rearrange favorites
                    char origIndexChar, destIndexChar;
                    int origIndexInt, destIndexInt;
                    
                    cout << "What is the favorite's current index?: ";
                    cin >> origIndexChar;
                    origIndexInt = origIndexChar - '0';
                    
                    cout << "What is the favorite's desired index?: ";
                    cin >> destIndexChar;
                    destIndexInt = destIndexChar - '0';
                    
                    cout << "Moving favorite from [" << origIndexInt <<"] to [" << destIndexInt << "]...\n";
                    // store both ints and pass to rearrangeFavorite()
                    // rearrangeFavorites(dest, orig);
                    // print possible success message: Done.
                    cout << "Done.\n";
                    system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                    system("clear");
                } else if (editFavsList == '4') {
                    system("clear");
                    goto startMainMenu;
                } else {
                    cout << "Edit favs menu: Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '2';
                    system("clear");
                    goto startSwitch;
                }
            } break;
                
            case '3': {
                // Display all contacts with number pairs
                system("clear");
                cout << "::Contacts List::\n\n";
                int cIndex = 0;
                for (auto i = contacts.begin(); i != contacts.end(); i++) {
                    displayContact(cIndex);
                    cIndex++;
                }
                cout << "=============================================\n\n";
                // displayAll();
                system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                system("clear");
            } break;
                
            case '4': {
                // Display all favorites with number pairs
                system("clear");
                cout << "::Favorites List::\n\n";
                int fIndex = 0;
                for (auto i = favorites.begin(); i != favorites.end(); i++) {
                    displayFavContact(fIndex);
                    fIndex++;
                }
                cout << "=============================================\n\n";
                // dispalyFavs();
                system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                system("clear");
            } break;
                
            case '5': {
                system("clear");
                cout << "\nThanks for using Matthias and Alex's PhoneList.\n\n";
                return 0;
            } break;
                
                /*
                 default:
                 cout << "main 1<input<5: Invalid Input Entered\n\n";
                 system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                 system("clear");
                 break;
                 */
        }
    }
}

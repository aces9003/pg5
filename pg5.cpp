//
//  pg5.cpp
//  pg5
//  Course: 600.120
//  Assignment 1
//  Created by Alex Sharata and Matthias Philippine on 10/26/14.
//  Copyright (c) 2014 Alex Sharata and Matthias Philippine. All rights reserved.
//  Matthias Philippine: 5106440780, mphili11, twinmat@gmail.com
//  Alex Sharata: 5712304745, asharat1, asharata18@gmail.com

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
        char editContactsList = '\0';
        
        cout << "::Main Menu::PhoneList\n\n"
        << " 1) Edit Contacts List\n"
        << " 2) Edit Favorites List\n"
        << " 3) Display All Contacts (Alphabetized)\n"
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
                
                cout << "::Unalphabetized Contacts List::\n\n"
                << "INDEX" << '\t' << "CONTACT NAME\n";
                if (contacts.size() == 0) {
                    cout << "Your contacts list is currently empty.\n";
                } else displayAllUnalphabetized();
                cout << "=============================================\n\n"
                << "::Edit Contacts List::\n\n"
                << " 1) Add New Contact\n"
                << " 2) Edit Existing Contact\n"
                << " 3) Return to Main Menu\n\n"
                << "Selection: ";
                cin >> editContactsList;
                cout << endl;
                
                if (editContactsList > '3' || editContactsList < '1') {
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
                    bool isFav;
                    string newPNString;  // Really no need to convert it to int later...
                    string newPhoneType;
                    char continueAddingNewPNPairs;
                    
                    // Prompt for new contact's info
                    cout << "First name of new contact:  ";
                    cin >> newFirstName;
                    
                    cout << "Last name of new contact:  ";
                    cin >> newLastName;
                    
                    // Always init isFav to false - favorite can be added later
                    isFav = false;
                    
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
                    sortedContacts = contacts;
                    sortContactsFirstName();
                    
                    cout << "Done.\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '1';
                    system("clear");
                    goto startSwitch;
                } else if (editContactsList == '2') {
                    // Edit existing contact
                    string existingContactIndexString;
                    int existingContactIndex;
                    
                    cout << "Enter the index of the contact you wish to edit:  ";
                    cin >> existingContactIndexString;
                    existingContactIndex = stoi(existingContactIndexString);
                    cout << endl;
                    
                    char editExistingContact;
                    cout << "::Selected Contact's Info::\n\n";
                    if (contacts.size() == 0) {
                        cout << "Your contacts list is currently empty.\n";
                    } else displayContact(existingContactIndex);
                    cout << "=============================================\n\n"
                    << "::Edit Existing Contact::\n\n"
                    << " 1) Delete Contact\n"
                    << " 2) Add Phone Number Pair\n"
                    << " 3) Edit Phone Number Pair(s)\n"
                    << " 4) Change Contact's Name\n"
                    << " 5) Return to Previous Menu\n\n"
                    << "Selection: ";
                    cin >> editExistingContact;
                    cout << endl;
                    
                    // NEW IF STATEMENT STRUCTURE
                    if (editExistingContact > '5' || editExistingContact < '1') {
                        cout << "Invalid Input Entered\n\n";
                        system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                        singleCharInput = '1';
                        editContactsList = '2';
                        system("clear");
                        goto startSwitch;
                    } else if (editExistingContact == '1') {
                        // Delete existing contact
                        
                        if (contacts.size() == 0) {
                            cout << "There are no contacts in your contacts list.\n\n";
                            system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                            singleCharInput = '1';
                            editContactsList = '2';
                            system("clear");
                            goto startSwitch;
                        }
                        
                        cout << "Deleting contact at ["<< existingContactIndex <<"] from contacts...\n";
                        // Store index and pass to method below
                        deleteContactFromFull(existingContactIndex);
                        cout << "Done.\n";
                        
                        sortedContacts = contacts;
                        sortContactsFirstName();
                        
                        system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                        singleCharInput = '1';
                        editContactsList = '2';
                        system("clear");
                        goto startSwitch;
                    } else if (editExistingContact == '2') {
                        // Add Phone Number Pair
                        string newPhoneNumber;
                        string newPhoneType;
                        
                        cout << "Enter the the new phone number:  ";
                        cin >> newPhoneNumber;
                        
                        cout << "Enter the new phone type (for example, CELL, HOME, WORK, FAX, etc.): ";
                        cin >> newPhoneType;
                        
                        cout << "Adding new phone number pair to contact at [" << existingContactIndex << "]\n";
                        addPhoneNumberPair(existingContactIndex, newPhoneNumber, newPhoneType);
                        
                        cout << "Done.\n";
                        
                        sortedContacts = contacts;
                        sortContactsFirstName();
                        
                        system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                        singleCharInput = '1';
                        editContactsList = '2';
                        system("clear");
                        goto startSwitch;
                    } else if (editExistingContact == '3') {
                        
                        ////////////////////////////
                        // Edit Phone Number Pair //
                        string existingPNPairString;
                        int existingPNPairIndex;
                        
                        string PNPairKey;
                        
                        cout << "Enter the index of the phone number pair you wish to edit:  ";
                        cin >> existingPNPairString;
                        existingPNPairIndex = stoi(existingPNPairString);
                        cout << endl;
                        
                        char editExistingPN;
                        cout << "::Selected Phone Number Pair's Info::\n\n";
                        if (contacts.size() == 0) {
                            cout << "Your contacts list is currently empty.\n";
                        } else {
                            int index=0;
                            for (auto i = contacts.at(existingContactIndex).phoneNumberPairs.begin(); i != contacts.at(existingContactIndex).phoneNumberPairs.end(); i++) {
                                if (index == existingPNPairIndex) {
                                    cout << '\t' << "["<< existingPNPairIndex << "] " << i->first << " " << i->second << endl;
                                    PNPairKey = i->first;
                                }
                                index++;
                            }
                        }
                        cout << "=============================================\n\n"
                        << "::Edit Existing Phone Number Pair::\n\n"
                        << " 1) Delete Phone Number Pair\n"
                        << " 2) Change Phone Number\n"
                        << " 3) Change Phone Type\n"
                        << " 4) Return to Previous Menu\n\n"
                        << "Selection: ";
                        cin >> editExistingPN;
                        cout << endl;
                        
                        // NEW IF STATEMENT STRUCTURE
                        if (editExistingPN > '4' || editExistingPN < '1') {
                            cout << "Invalid Input Entered\n\n";
                            system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                            singleCharInput = '1';
                            editContactsList = '2';
                            editExistingContact = '3';
                            system("clear");
                            goto startSwitch;
                        } else if (editExistingPN == '1') {
                            // Delete Phone Number Pair
                            
                            if (contacts.size() == 0) {
                                cout << "There are no contacts in your contacts list.\n\n";
                                system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                                singleCharInput = '1';
                                editContactsList = '2';
                                editExistingPN = '3';
                                system("clear");
                                goto startSwitch;
                            }
                            
                            cout << "Deleting phone number pair at ["<< existingPNPairIndex <<"] from contact...\n";
                            // Store index and pass to method below
                            //deletePhoneNumberPairViaIndex(existingContactIndex, existingPNPairIndex);
                            deletePhoneNumberPair(existingContactIndex, PNPairKey);
                            cout << "Done.\n";
                            
                            sortedContacts = contacts;
                            sortContactsFirstName();
                            
                            system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                            singleCharInput = '1';
                            editContactsList = '2';
                            editExistingPN = '3';
                            system("clear");
                            goto startSwitch;
                        } else if (editExistingPN == '2') {
                            // Change Phone Number
                            string newNum;
                            string tempType;
                            
                            // Store phone number in string temp
                            int index=0;
                            for (auto i = contacts.at(existingContactIndex).phoneNumberPairs.begin(); i != contacts.at(existingContactIndex).phoneNumberPairs.end(); i++) {
                                if (index == existingPNPairIndex) {
                                    tempType = i->second;
                                }
                                index++;
                            }
                            
                            // Delete old PN Pair
                            //deletePhoneNumberPairViaIndex(existingContactIndex, existingPNPairIndex);
                            deletePhoneNumberPair(existingContactIndex, PNPairKey);
                            
                            // Get new phone type
                            cout << "Enter new phone number: ";
                            cin >> newNum;
                            
                            // create new PN pair with new phone number and temp string
                            addPhoneNumberPair(existingContactIndex, newNum, tempType);
                            cout << "Done.\n";
                            
                            sortedContacts = contacts;
                            sortContactsFirstName();
                            
                            system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                            singleCharInput = '1';
                            editContactsList = '2';
                            system("clear");
                            goto startSwitch;
                        } else if (editExistingPN == '3') {
                            // Change Phone Type
                            string tempNum;
                            string newType;
                            
                            // Store phone number in string temp
                            int index=0;
                            for (auto i = contacts.at(existingContactIndex).phoneNumberPairs.begin(); i != contacts.at(existingContactIndex).phoneNumberPairs.end(); i++) {
                                if (index == existingPNPairIndex) {
                                    tempNum = i->first;
                                }
                                index++;
                            }
                            
                            // Delete old PN Pair
                            //deletePhoneNumberPairViaIndex(existingContactIndex, existingPNPairIndex);
                            deletePhoneNumberPair(existingContactIndex, PNPairKey);
                            
                            // Get new phone type
                            cout << "Enter new phone type: ";
                            cin >> newType;
                            
                            // create new PN pair with temp string and new phone type
                            addPhoneNumberPair(existingContactIndex, tempNum, newType);
                            cout << "Done.\n";
                            
                            sortedContacts = contacts;
                            sortContactsFirstName();
                            
                            system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                            singleCharInput = '1';
                            editContactsList = '2';
                            system("clear");
                            goto startSwitch;
                        } else if (editExistingPN == '4') {
                            singleCharInput = '1';
                            editContactsList = '2';
                            system("clear");
                            goto startSwitch;
                        } else {
                            cout << "Invalid Input Entered\n\n";
                            system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                            singleCharInput = '1';
                            editContactsList = '2';
                            editExistingContact = '3';
                            system("clear");
                            goto startSwitch;
                        }
                    } else if (editExistingContact == '4') {
                        // Change Contact's Name
                        string newFirstName, newLastName;
                        
                        cout << "Enter new first name:  ";
                        cin >> newFirstName;
                        
                        cout << "Enter new last name: ";
                        cin >> newLastName;
                        
                        cout << "Changing name of existing contact at [" << existingContactIndex <<"]...\n";
                        
                        contacts.at(existingContactIndex).firstName = newFirstName;
                        contacts.at(existingContactIndex).lastName = newLastName;
                        
                        cout << "Done.\n";
                        
                        sortedContacts = contacts;
                        sortContactsFirstName();
                        
                        system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                        singleCharInput = '1';
                        editContactsList = '2';
                        system("clear");
                        goto startSwitch;
                    } else if (editExistingContact == '5') {
                        singleCharInput = '1';
                        system("clear");
                        goto startSwitch;
                    } else {
                        cout << "Invalid Input Entered\n\n";
                        system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                        singleCharInput = '1';
                        editContactsList = '2';
                        system("clear");
                        goto startSwitch;
                    }
                } else if (editContactsList == '3') {
                    system("clear");
                    goto startMainMenu;
                } else {
                    cout << "Invalid Input Entered\n\n";
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
                if (favorites.size() == 0) {
                    cout << "Your favorites list is currently empty.\n";
                } else displayFavs();
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
                    string addContactToFavsString;
                    int addContactToFavsInt;
                    
                    // Print all contacts that have isFav == false;
                    cout << "::Unalphabetized Contacts Not in Favorites::\n\n"
                    << "INDEX" << '\t' << "CONTACT NAME\n";
                    
                    int nonFavIndex=0;
                    for(auto i = contacts.begin(); i != contacts.end(); ++i){
                        if (!i->isFav) {
                            cout << " ["<< nonFavIndex << "] " << '\t' << i->firstName << " " << i->lastName << endl;
                        }
                        
                        // If all contacts are already in favorites and there are none left to add to favorites:
                        if (favorites.size() == contacts.size()) {
                            cout << "There are no contacts left to add to your favorites list.\n\n";
                            system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                            singleCharInput = '2';
                            system("clear");
                            goto startSwitch;
                        }
                        
                        nonFavIndex++;
                    }
                    
                    cout << "=============================================\n\n";
                    cout << "Enter the index of the contact you wish to add to your favorites list:  ";
                    cin >> addContactToFavsString;
                    //addContactToFavsInt = addContactToFavsChar - '0';
                    addContactToFavsInt = stoi(addContactToFavsString);
                    addContactToFavs(addContactToFavsInt);
                    cout << "Adding contact at [" << addContactToFavsInt << "] to favs...\n";
                    cout << "Done.\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '2';
                    system("clear");
                    goto startSwitch;
                } else if (editFavsList == '2') {
                    // Delete contact from favorites
                    string deleteContactFromFavsChar;
                    int deleteContactFromFavsInt;
                    
                    if (favorites.size() == 0) {
                        cout << "There are no contacts in your favorites list.\n\n";
                        system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                        singleCharInput = '2';
                        system("clear");
                        goto startSwitch;
                    }
                    
                    cout << "Enter the index of the contact you wish to delete from your favorites list:  ";
                    cin >> deleteContactFromFavsChar;
                    //deleteContactFromFavsInt = deleteContactFromFavsChar - '0';
                    deleteContactFromFavsInt = stoi(deleteContactFromFavsChar);
                    cout << "Deleting contact at ["<< deleteContactFromFavsInt <<"] from favs...\n";
                    // Store index and pass to method below
                    deleteContactFromFavs(deleteContactFromFavsInt);    // !!!!! MUST CHANGE isFav back to false
                    cout << "Done.\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '2';
                    system("clear");
                    goto startSwitch;
                } else if (editFavsList == '3') {
                    // Rearrange favorites
                    string origIndexChar, destIndexChar;
                    int origIndexInt, destIndexInt;
                    
                    if (favorites.size() == 0) {
                        cout << "There are no contacts in your favorites list.\n\n";
                        system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                        singleCharInput = '2';
                        system("clear");
                        goto startSwitch;
                    }
                    
                    cout << "What is the favorite's current index?: ";
                    cin >> origIndexChar;
                    //origIndexInt = origIndexChar - '0';
                    origIndexInt = stoi(origIndexChar);
                    
                    cout << "What is the favorite's desired index?: ";
                    cin >> destIndexChar;
                    //destIndexInt = destIndexChar - '0';
                    destIndexInt = stoi(destIndexChar);
                    
                    cout << "Moving favorite from [" << origIndexInt <<"] to [" << destIndexInt << "]...\n";
                    // Store both ints and pass to rearrangeFavorite()
                    rearrangeFavorites(origIndexInt, destIndexInt);
                    cout << "Done.\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '2';
                    system("clear");
                    goto startSwitch;
                } else if (editFavsList == '4') {
                    system("clear");
                    goto startMainMenu;
                } else {
                    cout << "Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    singleCharInput = '2';
                    system("clear");
                    goto startSwitch;
                }
            } break;
                
            case '3': {
                system("clear");
                
                char displayAllOptions;
                
                cout << "How do you want your contacts alphabetized?\n\n"
                << " 1) Sorted by first name\n"
                << " 2) Sorted by last name\n\n"
                << "Selection: ";
                cin >> displayAllOptions;
                
                if(displayAllOptions > '2' || displayAllOptions < '1') {
                    cout << "Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    system("clear");
                } else if (displayAllOptions == '1') {
                    // Display all contacts with number pairs alphabetized by first name
                    system("clear");
                    
                    sortedContacts = contacts;
                    sortContactsFirstName();
                    
                    cout << "::Alphabetized by First Name::Contacts List::\n\n";
                    int cIndex = 0;
                    if (sortedContacts.size() == 0) {
                        cout << "Your contacts list is currently empty.\n";
                    }
                    else {
                        for (auto i = sortedContacts.begin(); i != sortedContacts.end(); i++) {
                            displaySortedContact(cIndex);
                            cIndex++;
                        }
                    }
                    cout << "=============================================\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                    system("clear");
                } else if (displayAllOptions == '2') {
                    // Display all contacts with number pairs alphabetized by last name
                    system("clear");
                    
                    sortedContacts = contacts;
                    sortContactsLastName();
                    
                    cout << "::Alphabetized by Last Name::Contacts List::\n\n";
                    int cIndex = 0;
                    if (sortedContacts.size() == 0) {
                        cout << "Your contacts list is currently empty.\n";
                    }
                    else {
                        for (auto i = sortedContacts.begin(); i != sortedContacts.end(); i++) {
                            displaySortedContact(cIndex);
                            cIndex++;
                        }
                    }
                    cout << "=============================================\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                    system("clear");
                } else {
                    cout << "Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the previous menu...\"" );
                    system("clear");
                }
                
            } break;
                
            case '4': {
                // Display all favorites with number pairs
                system("clear");
                cout << "::Favorites List::\n\n";
                int fIndex = 0;
                if (favorites.size() == 0) {
                    cout << "Your favorites list is currently empty.\n";
                }
                else {
                    for (auto i = favorites.begin(); i != favorites.end(); i++) {
                        displayFavContact(fIndex);
                        fIndex++;
                    }
                }
                cout << "=============================================\n\n";
                
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

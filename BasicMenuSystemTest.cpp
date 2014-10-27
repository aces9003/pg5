#include <iostream>
#include <cstdlib>

void clearScreen(); // Mimcs clear screen by printing out many lines

using namespace std;
//int main(int argc, char *argv[]) {
int main() {
	
	clearScreen();
	
	while(true) {
		char mainMenuChoice;
		// char name[x];
		
		cout << "Main Menu::PhoneList\n\n"
			 << " 1) Edit Contacts List\n"
			 << " 2) Edit Favorites List\n"
			 << " 3) Display All Contacts\n"
			 << " 4) Display Favorites\n"
			 << " 5) Exit PhoneList\n\n"
			 << "Selection: ";
		cin >> mainMenuChoice;
		clearScreen();

        switch (mainMenuChoice) {
            case '1':
                // First display contacts, names and indexes only
                break;
                
            case '2':
                // First display favorites, names and indexes only
                clearScreen();
                
                char editFavsList;
                cout << "**All favorites + indexes (no number pairs)**\n\n"
                << " 1) Add Contact to Favorites\n"
                << " 2) Delete Contact from Favorites\n"
                << " 3) Rearrange Favorites\n"
                << " 4) Exit PhoneList\n\n"
                << "Selection: ";
                cin >> editFavsList;
                cout << endl;
                
                if (editFavsList > '4' || editFavsList < '1') {
                    cout << "Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                } else if (editFavsList == '1') {
                    // Add contact from full list to favorites
                    // Print full contacts, names and indexes only
                    cout << "**prompt for index or name: << **\n\n";
                    // store name OR index and pass to method below
                    // addContactToFav();
                    // print possible success message: Done.
                    system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                    clearScreen();
                } else if (editFavsList == '2') {
                    // Delete contact from favorites
                    cout << "**prompt for index or name: << **\n\n";
                    // store name OR index and pass to method below
                    // deleteContactFromFavs();
                    // print possible success message: Done.
                    system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                    clearScreen();
                } else if (editFavsList == '3') {
                    // Rearrange favorites
                    cout << "**prompt for contact's current index: << **\n";
                    // store current index --> pass to swapFavorites()
                    cout << "**promt for desired index: << **\n\n";
                    // store desired index --> pass to swapFavorites()
                    // swapFavorites(dest, orig);
                    // print possible success message: Done.
                    system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                    clearScreen();
                } else if (editFavsList == '4') {
                    clearScreen();
                    cout << "Thanks for using PhoneList.\n\n";
                    mainMenuChoice = '5';
                } else {
                    cout << "Invalid Input Entered\n\n";
                    system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                    mainMenuChoice = '5';
                    clearScreen();
                }
                break;
                
            case '3':
                // Display all contacts with number pairs
                clearScreen();
                cout << "**All contacts + number pairs go here**\n\n";
                // displayAll();
                system( "read -n 1 -s -p \"Press any key to return to Main Menu...\"" );
                clearScreen();
                break;
            
            case '4':
                // Display all favorites with number pairs
                clearScreen();
                cout << "**All favorites + number pairs go here**\n\n";
                // dispalyFavs();
                system( "read -n 1 -s -p \"Press any key to return to Main Menu...\"" );
                clearScreen();
                break;
            
            case '5':
                clearScreen();
                cout << "Thanks for using PhoneList.\n\n";
                return 0;
                break;
                
            default:
                cout << "Invalid Input Entered\n\n";
                system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                clearScreen();
                break;
        }
        
        // Old if-statement structure:
        /*
		if (mainMenuChoice > '5' || mainMenuChoice < '1') { // Validates user input
			//system("CLS"); // Clears screen
			//cout << "Invalid Input Entered\n\n";
			//system("PAUSE"); // Pauses until any key pressed
			//system("CLS");
			//clearScreen();
			cout << "Invalid Input Entered\n\n";
			system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
			clearScreen();
		} else if (mainMenuChoice == '1') {
            // First display contacts, names and indexes only
		} else if (mainMenuChoice == '2') {
            // First display favorites, names and indexes only
            clearScreen();
            
            char editFavsList;
            cout << "**All favorites + indexes (no number pairs)**\n\n"
                 << " 1) Add Contact to Favorites\n"
                 << " 2) Delete Contact from Favorites\n"
                 << " 3) Rearrange Favorites\n"
                 << " 4) Exit PhoneList\n\n"
                 << "Selection: ";
            cin >> editFavsList;
            cout << endl;
            
            if (editFavsList > '4' || editFavsList < '1') {
                cout << "Invalid Input Entered\n\n";
                system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
            } else if (editFavsList == '1') {
                // Add contact from full list to favorites
                // Print full contacts, names and indexes only
                cout << "**prompt for index or name: << **\n\n";
                // store name OR index and pass to method below
                // addContactToFav();
                // print possible success message: Done.
                //system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                break;
                mainMenuChoice = '2';
                //clearScreen();
            } else if (editFavsList == '2') {
                // Delete contact from favorites
                cout << "**prompt for index or name: << **\n\n";
                // store name OR index and pass to method below
                // deleteContactFromFavs();
                // print possible success message: Done.
                system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                clearScreen();
            } else if (editFavsList == '3') {
                // Rearrange favorites
                cout << "**prompt for contact's current index: << **\n";
                // store current index --> pass to swapFavorites()
                cout << "**promt for desired index: << **\n\n";
                // store desired index --> pass to swapFavorites()
                // swapFavorites(dest, orig);
                // print possible success message: Done.
                system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                clearScreen();
            } else if (mainMenuChoice == '4') {
                clearScreen();
                cout << "Thanks for using PhoneList.\n\n";
                mainMenuChoice = '5';
            } else {
                cout << "Invalid Input Entered\n\n";
                system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
                mainMenuChoice = '5';
                clearScreen();
            }
            
            
		} else if (mainMenuChoice == '3') {
			// Display all contacts with number pairs
            clearScreen();
            cout << "**All contacts + number pairs go here**\n\n";
            // displayAll();
            system( "read -n 1 -s -p \"Press any key to return to Main Menu...\"" );
            clearScreen();
		} else if (mainMenuChoice == '4') {
            // Display all favorites with number pairs
            clearScreen();
            cout << "**All favorites + number pairs go here**\n\n";
            // dispalyFavs();
            system( "read -n 1 -s -p \"Press any key to return to Main Menu...\"" );
            clearScreen();
        } else if (mainMenuChoice == '5') {
            clearScreen();
            cout << "Thanks for using PhoneList.\n\n";
            return 0;
		} else {
			cout << "Invalid Input Entered\n\n";
            system( "read -n 1 -s -p \"Press any key to return to the main menu...\"" );
			clearScreen();
		}
        */
    }
}

void clearScreen() {
	for (int i = 0; i < 1000; i++)  {cout << endl;} // Mimics clear screen
}

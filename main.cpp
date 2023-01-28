#include "product.h"

#include <vector>
#include <iomanip>
#include <string>
#include <memory>
#include<limits>

using namespace std;


void DisplayMenu();
void CreatingItem(vector<Product>&inventory);
void displayProd(const vector<Product> &inventory);
void Find (const vector<Product>&);

int main() ////
{   system("CLS");

    const auto max_size = std::numeric_limits<std::streamsize>::max ();


    /// Variables

    vector <int> lista {}; /////////
    char opt {};

    vector<Product>inventory{};

    /// Initializing Program
    cout << "Welcome to my Inventory Management" << endl;
    do{
        /// Menu
        DisplayMenu ();
        cin >> opt;
        cin.ignore(max_size, '\n');
        opt = tolower (opt);

        switch(opt)
        {
        case 'd':
            /// Display inventory
            displayProd (inventory);
            break;
        case 'c':
            /// Creating an item to inventory
            CreatingItem (inventory);
            break;

        case 'f':
            /// Finding item in inventory
            Find(inventory);
            break;

        case 'q':
            ///  Exiting program :(
            system("CLS");
            cout << "\n\n\n\n"
                    "Goodbye...... "
                    "\n\n\n\n";
            break;

        default:
            /// what fuck u doing ?
            cout << "Something is wrong \n\n" << endl;
            break;
        }
    } while (opt != 'q');

    return 0;  }  //// End Main


//// Functions in product.cpp

void DisplayMenu()
{
    cout << "Select an option: \n";
    cout << "D - Display inventory \n"
            "C - Create an item  \n"
            "F - Find a number in list \n"
            "Q - Quit " << endl;
}



#include "product.h"

void DisplayMenu();
void CreatingItem(std::vector<Product>&inventory);
void displayProd(const std::vector<Product> &inventory);
void Find (const std::vector<Product>&);
void Save(std::vector<Product>&inventory);

int main() ////
{   system("CLS");
    QCoreApplication a();
    const auto max_size = std::numeric_limits<std::streamsize>::max ();


    /// Variables

    std::vector <int> lista {}; /////////
    char opt {};

    std::vector<Product>inventory{};
    /// Initializing Program
    std::cout << "Welcome to my Inventory Management" << std::endl;
    do{
        /// Menu
        DisplayMenu ();
        std::cin >> opt;
        std::cin.ignore(max_size, '\n');
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

        case 's':
            /// Saving the full inventory in .csv
            Save(inventory);

            break;

        case 'q':
            ///  Exiting program :(
            system("CLS");
            std::cout << "\n\n\n\n"
                    "Goodbye...... "
                    "\n\n\n\n";
            break;

        default:
            /// what fuck u doing ?
            std::cout << "Something is wrong \n\n" << std::endl;
            break;
        }
    } while (opt != 'q');

    return 0;  }  //// End Main


//// Functions in product.cpp

void DisplayMenu()
{
    std::cout << "Select an option: \n";
    std::cout << "D - Display inventory \n"
            "C - Create an item  \n"
            "F - Find a number in list \n"
            "S - Save inventory \n"
            "Q - Quit " << std::endl;
}

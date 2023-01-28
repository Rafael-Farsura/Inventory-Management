#include "product.h"

std::string Product::getItem() const
{
    return item;
}

int Product::getCod ()
{
    return cod;
}

int Product::getQtt ()
{
    return qtt;
}

std::string Product::getDate()
{
    return date;
}

std::string Product::getStatus()
{
    return status;
}

std::string Product::getRecipient()
{
    return recipient;
}

////////////////////////////////////////////////
///  Get //// Set
///////////////////////////////////////////////

void Product::setCod(int cod)
{
    this->cod = cod;
}

void Product::setQtt (int qtt)
{
    this->qtt = qtt;
}

void Product::setItem(std::string item)
{
    this->item = item;
}

void Product::setDate(std::string date)
{
    this->date = date;
}

void Product::setStatus(std::string status)
{
    this->status = status;
}

void Product::setRecipient(std::string recipient)
{
    this->recipient = recipient;
}

//////////////////////////////////////////////////
/// Set  ///  Constructor
//////////////////////////////////////////////////

Product::Product(int cod, int qtt, std::string item, std::string date, std::string status, std::string recipient)
     :cod{cod}, qtt{qtt}, item{item}, date{date}, status{status}, recipient{recipient}
 { }

//////////////////////////////////////////////////
///  Constructor /// Functions for Main
//////////////////////////////////////////////////
void displayProd(const std::vector<Product> &inventory)
{
    system ("CLS");
    if(!inventory.empty ()){
        for(auto it:inventory)
        {
            std::cout << "Item code [ " << it.getCod() << " ]" << std::endl;
            std::cout << "Item Quantity [ " << it.getQtt() << " ]" << std::endl;
            std::cout << "Item name [ " << it.getItem() << " ]" << std::endl;
            std::cout << "Last Atualization [ " << it.getDate() << " ]" << std::endl;
            std::cout << "Receiver name [ " << it.getRecipient() << " ]" << std::endl;
            std::cout << "Item status [ " << it.getStatus() << " ]" << std::endl;
            std::cout << "\n\n\n\n";
        }
    } else
    {
        std::cout << "The inventory is empty, follow the format of items from inventory !" << std::endl;
        Product obj{};
        std::cout << "Item code [ " << obj.getCod() << " ]" << std::endl;
        std::cout << "Item Quantity [ " << obj.getQtt() << " ]" << std::endl;
        std::cout << "Item name [ " << obj.getItem() << " ]" << std::endl;
        std::cout << "Last Atualization [ " << obj.getDate() << " ]" << std::endl;
        std::cout << "Receiver name [ " << obj.getRecipient() << " ]" << std::endl;
        std::cout << "Item status [ " << obj.getStatus() << " ]" << std::endl;
        std::cout << "\n\n\n\n";
    }
}

void CreatingItem(std::vector<Product>&inventory)
{
    system("CLS");

    Product prod;
    std::string name{};
    std::string date{};
    std::string receiver{};
    std::string stts{};
    int code{};
    int qty{};

    std::cout << "Code of item: ";
    std::cin >> code;
    prod.setCod (code);

    std::cout << "Quantity of items: ";
    std::cin >> qty;
    prod.setQtt (qty);

    std::cout << "Type the name of item: ";
    std::cin.ignore ();
    std::getline(std::cin, name);
    prod.setItem (name);

    std::cout << "Date of receiver (dd/mm/yy):  ";
    std::getline(std::cin, date);
    prod.setDate (date);

    std::cout << "Name of receiver: ";
    std::getline(std::cin,receiver);
    prod.setRecipient (receiver);

    std::cout << "Status of Item: ";
    std::getline(std::cin, stts);
    prod.setStatus (stts);

    inventory.push_back (prod);

    system("CLS");
}

void Find (const std::vector<Product> &inventory)
{
    system("CLS");
    int code{};
    std::cout << "Please, input the code '[00]' of item what do u want to find" << std::endl;
    std::cin >> code;

    if(!inventory.empty ()){
        for(auto it2:inventory)
        {
            if(it2.getCod () == code)
            {   std::cout << "\n\nItem found!!! \n"<< std::endl;
                std::cout << "Item code [ " << it2.getCod() << " ]" << std::endl;
                std::cout << "Item Quantity [ " << it2.getQtt() << " ]" << std::endl;
                std::cout << "Item name [ " << it2.getItem() << " ]" << std::endl;
                std::cout << "Last Atualization [ " << it2.getDate() << " ]" << std::endl;
                std::cout << "Receiver name [ " << it2.getRecipient() << " ]" << std::endl;
                std::cout << "Item status [ " << it2.getStatus() << " ]" << std::endl;
                std::cout << "\n\n\n\n";     }
            else
            {   system ("CLS");
                std::cout << "This code is invalid !!! \n"
                      "Please, check if this code is added in inventory in menu \n\n\n" << std::endl;   }
        }
    } else
    {   system ("CLS");
        std::cout << "The inventory is empty!! Please add an item inside that \n\n\n" << std::endl;  }
}

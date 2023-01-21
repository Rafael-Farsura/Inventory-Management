#include "item.h"

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <windows.h>
#include <string>

using namespace std;

bool isStringNumber(string str)
{
    for (char c : str)
    {
        if (!isdigit(c))
        return false;
    }
    return true;
}

string setcolor(unsigned short color){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    return "";
}

void DisplayMenu()
{
    cout << "Select an option: \n";
    setcolor (10);
    cout << "P - Print numbers \n"
            "A - Add a number  \n"
            "M - Display mean of the number \n"
            "S- Display the smallest number \n"
            "L - Display the largest number \n"
            "F - Find a number in list \n"
            "Q - Quit " << endl;
    setcolor(14);
}

void Printing(vector<int>*vecOfInts)
{
    system("CLS");
    cout << "Printing numbers..." << endl;
    if(!vecOfInts->empty ())
    {
        cout << " [ " ;
        for(auto it:*vecOfInts)
        {
            cout << " " << it << " ";
        }
        cout << " ] \n\n" << endl;
    }else {
        cout << " []- the list is empty \n\n" << endl;
    }
}

void Adding(vector<int>*vecOfInts)
{
    system("CLS");

    string add{};

    do {
        cout << "Enter ur number:"
                "\n//If u want add more than one number at same time u need put spaces between " << endl;
        cout << "Example : 1 2 3 4 5" << endl;
        cin >> add;

        if(!isStringNumber (add) )
        {
            if(add == "q" ||  add == "Q")
                break;
            else
                cout << "Not a number!" << endl;
        }
        else
        {
            auto adding = stoi(add);

            vecOfInts->push_back(adding);
            cout << "The number " << add << " added \n" << endl;
        }

        setcolor(12);
        cout << "\n If don't want add more numbers press 'Q' \n\n" << endl;
        setcolor (14);

    }   while (add != "q");

    system("CLS");
}

double CalculateAverage(vector<int> *vecOfInts)
{
    int sum{};

    auto ite = vecOfInts->begin ();
    auto iteEnd = vecOfInts->end ();

    for(ite; ite != iteEnd; ++ite)
    {
        sum += *ite;
    }

    double average{};

    if (!vecOfInts->empty ()){
        average = static_cast<double>(sum)/ vecOfInts->size ();
    }

    return average;
}

void DisplayAverage(vector<int> *vecOfInts)
{
    system("CLS");

    if( !vecOfInts->empty ())
    {
        cout << "The average of the list is: " << setprecision (4) << CalculateAverage(vecOfInts) << "\n\n" << endl;
    }else
    {
        cout << "Unable to calculate the mean - NO DATA \n\n" << endl;
    }
}

void Smallest(vector<int> *vecOfInts)
{
    system("CLS");

    if(!vecOfInts->empty())
    {
        cout << "The smallest number is: " << *min_element(vecOfInts->begin (), vecOfInts->end ()) << "\n\n" << endl;
    }
    else
    {
        cout << "Unable to determine the smallest number - List is empty \n\n" << endl;
    }
}

void Largest(vector<int> *vecOfInts)
{
    system("CLS");

    if (!vecOfInts->empty())
    {
        cout << "The largest number is: " << *max_element(vecOfInts->begin (), vecOfInts->end ()) << "\n\n" << endl;
    }
    else
    {
        cout << "Unable to determine the largest number - List is empty \n\n" << endl;
    }
}

void Find (vector<int> *vecOfInts)
{
    system("CLS");

    int number{};
    cout << "Please, input the number u want to find" << endl;
    cin >> number;

    auto element = find(vecOfInts->begin (), vecOfInts->end (), number);

    auto index = distance(vecOfInts->begin(), element);

    if(element != vecOfInts->end ())
    {
        cout << "We find your number: " << *element
             << "\n Find at index: [ " << index << " ]" << endl;
    }else
    {
        cout << "This number doesn't exist in list" << endl;
    }
}

int main()
{
     system("CLS");
    /// Variables
    setcolor(14);
    vector <int> lista {};
    char opt {};

    /// Initializing Program
    cout << "Welcome to my list management" << endl;

    do{
        /// Menu
        DisplayMenu ();

        cin >> opt;
        opt = tolower (opt);

        switch(opt)
        {
        case 'p':
            /// Printing list
            Printing (&lista);

            break;

        case 'a':
            /// Adding a number to list
            Adding (&lista);

            break;

        case 'm':
            /// Displaying the average of elements in list
            DisplayAverage (&lista);

            break;

        case 's':
            /// Displaying the smallest number in list
            Smallest(&lista);

            break;

        case 'l':
            /// Displaying the largest number in list
            Largest(&lista);

            break;
        case 'f':
            Find(&lista);

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

    return 0;
}

//
// main.cpp
// koisochukwu Nwambuonwor 
// 05-25-2023
// COMP 121
// EXAM 3
// This program is a menu driven program that displays STL (Standard Template Library) Containers and Container Adaptors
//


#include <iostream>
#include <iomanip>
#include <string>
#include "input.h"
#include "Rational.h"
#include "Vector.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

// function prototypes
void stackOption();
void displayStack(Stack& stack);
void queueOption();
void vectorOption();
void listOption();
void displayQueue(Queue& q);

int main()
{
    system("cls");
    // variable decalare
    char option;
    do
    {
        cout << endl << endl;
        cout << setw(100) << "A container is a holder object that stores a collection of other objects (its elements). They\n";
        cout << setw(99) << "are implemented as class templates, which allows great flexibility in the types supported as\n";
        cout << setw(103) << "elements. The container manages the storage space for its elements and provides member functions\n";
        cout << setw(101) << "to access them, either directly or through iterators (reference objects with similar properties\n";
        cout << setw(20) << "to pointers).\n";
        cout << endl;
        cout << setw(96) << "CMPR121 Exam3: STL (Standard Template Library) Containers and Container Adaptors by Kosi N" << endl;

        cout << setw(7);
        for (int i = 0; i < 97; i++)
            cout << (char)205;
        cout << endl;

        // Display menu options
        cout << setw(34) << "V. Vector Container\n";
        cout << setw(32) << "L. List Container\n";
        cout << setw(41) << "S. Stack Container Adaptor\n";
        cout << setw(40) << "Q. Queue Container Adaptor" << endl;

        
        cout << setw(7);
        for (int i = 0; i < 97; i++)
            cout << (char)196;
        cout << endl;

        cout << setw(21) << "X. Exit";
        cout << endl;

       
        cout << setw(7);
        for (int i = 0; i < 97; i++)
            cout << (char)205;

        cout << endl;

        string options = "vlsqx";
        option = inputChar("            Option: ", options);

        switch (option)
        {
        case 'V':
            vectorOption(); // Handle the Vector Container option
            break;
        case 'L':
            listOption(); // Handle the List Container option
            break;
        case 'S':
            stackOption(); // Handle the Stack Container Adaptor option
            break;
        case 'Q':
            queueOption(); // Handle the Queue Container Adaptor option
            break;
        case 'X':
            return 0; // Exit the program
        default:
            break;
        }
    } while (true);
}


//The preconditions for the vectorOption() function are :
//
//None
//The postconditions for the vectorOption() function are :
//
//The function will continue executing in a loop until the user chooses to exit.
//Depending on the user's input, different operations will be performed on the Vector object v.
//The elements of the Vector object v may be modified or updated based on the user's input.
//Error conditions, such as division by zero or index out of range, will be handled appropriately by displaying error messages.
//The console screen will be cleared after each operation to present a clean interface for the next user input.

void vectorOption()
{
    system("cls");
    Vector v;
    do
    {
        cout << "\033[31m"; // Start red font color
        cout << setw(97) << "Vectors are same as dynamic arrays with the ability to resize itself automatically when an\n";
        cout << setw(103) << "element is inserted or deleted, with their storage being handled automatically by the container.\n";
        cout << setw(99) << "Vector elements are placed in contiguous storage so that they can be accessed and traversed\n";
        cout << setw(34) << "using iterators or indexes.\n";
        cout << "\033[0m"; // Reset font color to default

        cout << endl;
        if (v.isEmpty())
        {
            cout << setw(34) << "The current vector is empty.";
            cout << "\n\n\n\n";
        }
        else
        {
            cout << setw(34) << "The current vector contains " << v.size() << " element(s):\n";
            cout << setw(15);
            for (int i = 0; i < v.size(); i++)
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191;
            cout << endl;
            cout << setw(15);
            for (int i = 0; i < v.size(); i++)
                cout << static_cast<char>(179) << " " << v.get(i) << static_cast<char>(179);
            cout << endl;
            cout << setw(15);
            for (int i = 0; i < v.size(); i++)
                cout << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217;
            cout << endl;
            cout << setw(12) << "index:";
            for (int i = 0; i < v.size(); i++)
                cout << "  " << i << "  ";
            cout << endl;
            cout << setw(15) << "ADDRESS: " << &v;
        }
        cout << "\n\n";
        cout << setw(34) << "Vector Menu Options\n";
        cout << setw(7);
        for (int i = 0; i < 97; i++)
            cout << (char)205;
        cout << endl;

        // display menu
        cout << setw(44) << "1. Add an element to the back\n";
        cout << setw(47) << "2. Insert an element at an index\n";
        cout << setw(49) << "3. Retrieve an element at an index\n";
        cout << setw(34) << "4. Erase element(s)\n";
        cout << setw(54) << "5. Sort the elements in ascending order\n";
        cout << setw(35) << "6. Clear all elements";
        cout << endl;

        cout << setw(7);
        for (int i = 0; i < 97; i++)
            cout << (char)196;
        cout << endl;
        cout << setw(21) << "0. Exit";
        cout << endl;

        cout << setw(7);
        for (int i = 0; i < 97; i++)
            cout << (char)205;
        cout << endl;

        // user choice 
        int option = inputInteger("            Option: ", 0, 6);
        switch (option)
        {
        case 0: main(); break;

            case 1: // Adding a rational number to the vector
        {
            // Prompt the user to input a rational number
            int numerator;
            int denominator;
            cout << setw(45) << "Input a Rational number to be added...\n";
            cout << setw(44);
            numerator = inputInteger("Enter a numerator(-9...9)   : ", -9, 9);
            cout << setw(46);
            denominator = inputInteger("Enter a denominator(-9...9)   : ", -9, 9);

            if (denominator == 0) {
                cout << "Error: Denominator cannot be zero." << endl;
                // Handle the error condition appropriately
                // You can choose to exit the program or take other actions
            }
            else {
                try {
                    Rational r(numerator, denominator); // Creating the Rational object

                    string element = r.toString();
                    v.append(element);

                    // Display information about the added rational number
                    cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                        << endl;
                    cout << setw(15) << (char)179 << " " << element << (char)179
                        << " will be added to the back of the vector." << endl;
                    cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                        << endl;

                    cout << endl;
                    system("pause");
                    system("cls");
                }
                catch (const Rational::ZeroDenominatorException& ex) {
                    cout << "Error: " << ex.what() << endl;
                    // Handle the error condition appropriately
                    // You can choose to exit the program or take other actions
                }
            }
            break;
        }



         case 2: // Inserting a rational number into the vector
        {
            // Prompt the user to input a rational number and the index to insert
            int numerator;
            int denominator;
            int index;
            cout << setw(48) << "Input a Rational number to be inserted...\n";
            cout << setw(44) << "Enter a numerator(-9...9)   : ";
            numerator = inputInteger("", -9, 9);
            cout << setw(46) << "Enter a denominator(-9...9)   : ";
            denominator = inputInteger("", -9, 9);
            string prompt = "Insert the element at index (0..." + to_string(v.size()) + ") of the vector: ";
            cout << setw(39);
            index = inputInteger(prompt, 0, v.size());
            cout << endl;

            try {
                string element = Rational(numerator, denominator).toString();

                // Display information about the inserted rational number
                cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                    << endl;
                cout << setw(15) << (char)179 << " " << element << (char)179
                    << " will be inserted at index " << index << " to the vector." << endl;
                cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                    << endl;

                v.insert(index, element);

                cout << endl;
                system("pause");
                system("cls");
            }
            catch (const Rational::ZeroDenominatorException& ex) {
                cout << "Error: " << ex.what() << endl;
                // Handle the error condition appropriately
                // You can choose to exit the program or take other actions
            }
            catch (const out_of_range& ex) {
                cout << "Error: " << ex.what() << endl;
                // Handle the error condition appropriately
                // You can choose to exit the program or take other actions
            }

            break;
        }

         case 3:
         {
             if (v.size() <= 0) {
                 // Check if the vector is empty
                 cout << "Error: Must have at least 1 element in the vector." << endl;
                 break;
             }

             int index;
             cout << setw(70);

             // Prompt the user to enter an index within the valid range
             string prompt = " Enter an index (0..." + to_string(v.size() - 1) + ") of Rational number to be retrieved:";
             index = inputInteger(prompt, 0, v.size() - 1);
             string element;

             try {
                 // Retrieve the element at the specified index
                 element = v.get(index);

                 // Display the retrieved element and its index
                 cout << endl;
                 cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191 << endl;
                 cout << setw(15) << (char)179 << " " << element << (char)179
                     << " is located at index " << index << " from the vector." << endl;
                 cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217 << endl;

                 cout << endl;

                 // Pause the program execution until the user presses a key
                 system("pause");

                 // Clear the console screen
                 system("cls");
             }
             catch (const std::out_of_range& ex) {
                 // Handle the case where the index is out of range
                 cout << "Error: " << ex.what() << endl;
                 // Handle the error condition appropriately
                 // You can choose to exit the program or take other actions
             }

             break;
         }

         case 4:
         {
             if (v.size() <= 0) {
                 // Check if the vector is empty
                 cout << endl;
                 cout << setw(69) << "Erase operation cannot be performed on an empty vector.";
                 system("cls");
                 break;
             }

             int numerator;
             int denominator;
             cout << setw(51) << "Input a Rational number to be added...\n";

             // Prompt the user to enter a numerator within the valid range
             cout << setw(50) << "Enter a numerator(-9...9)   : ";
             numerator = inputInteger("", -9, 9);

             // Prompt the user to enter a denominator within the valid range
             cout << setw(52) << "Enter a denominator(-9...9)   : ";
             denominator = inputInteger("", -9, 9);

             // Create a Rational object and convert it to a string representation
             string element = Rational(numerator, denominator).toString();

             // Check if the element is present in the vector
             bool present = v.containsElement(element);

             if (!present) {
                 // Element not found in the vector
                 cout << endl;
                 cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191 << endl;
                 cout << setw(15) << (char)179 << " " << element << (char)179
                     << " cannot be found from the vector." << endl;
                 cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217 << endl;
                 system("pause");
                 system("cls");
             }
             else {
                 // Element found in the vector
                 cout << endl;
                 char answer;
                 string criteria = "oa";

                 // Prompt the user to choose to remove one or all elements
                 cout << setw(63);
                 answer = inputChar("Do you want to remove (O-one or A-all) element(s): ", criteria);

                 if (answer == 'A') {
                     // Remove all occurrences of the element from the vector
                     vector<int> indicesToDelete;

                     for (int i = 0; i < v.size(); i++) {
                         if (v.get(i) == element) {
                             indicesToDelete.push_back(i);
                         }
                     }

                     // Remove the elements from the vector in reverse order
                     for (int i = indicesToDelete.size() - 1; i >= 0; i--) {
                         v.deleteElementAt(indicesToDelete[i]);
                     }

                     cout << endl;
                     cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191 << endl;
                     cout << setw(15) << (char)179 << " " << element << (char)179
                         << " has been removed from the vector." << endl;
                     cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217 << endl;
                     system("pause");
                     system("cls");
                 }
                 else {
                     // Remove only one occurrence of the element from the vector
                     v.deleteElement(element);
                     cout << endl;
                     cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191 << endl;
                     cout << setw(15) << (char)179 << " " << element << (char)179
                         << " will be removed from the vector." << endl;
                     cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217 << endl;
                     cout << endl;
                     system("pause");
                     system("cls");
                 }
             }
             break;
         }

         case 5:
         {
             if (v.size() <= 0)
             {
                 // Check if the vector is empty
                 cout << endl;
                 cout << setw(66) << "Sort operation cannot be performed on an empty vector.";
                 cout << "\n\n";
                 system("pause");
                 system("cls");
                 break;
             }

             // Sort the vector in ascending order
             cout << endl;
             cout << setw(57) << "The vector will be sorted in ascending order.";
             v.sort();
             cout << "\n\n";
             system("pause");
             system("cls");
             break;
         }


         case 6:
         {
             if (v.size() <= 0)
             {
                 // Check if the vector is empty
                 cout << endl;
                 cout << setw(67) << "Clear operation cannot be performed on an empty vector.";
                 cout << "\n\n";
                 system("pause");
                 system("cls");
                 break;
             }

             // Clear all elements from the vector
             cout << endl;
             cout << setw(55) << "The vector will be cleared of all elements.";
             v.clear();
             cout << "\n\n";
             system("pause");
             system("cls");
             break;
         }

        default:
            break;
        }
    } while (true);
}


//Pre - condition comment :
//
//None 
//Post - condition comment :
//
//The state of the List object l may be modified based on the user's input and the operations performed in the listOption() function.
//The output displayed on the console includes information about the elements in the list and the actions performed on them.
//The console screen is cleared after each action and the user is prompted to continue with the next action.
//The function may return to the main() function when the user selects option 0.

void listOption()
{

    system("cls");
    List l;
    do
    {
        cout << endl;

        cout << "\033[35m"; // Start purple font color
        cout << setw(97) << "Lists are sequence containers that allow non-contiguous memory allocation. As compared to\n";
        cout << setw(94) << "vector, the list has slow traversal, but once a position has been found, insertion and\n";
        cout << setw(29) << "deletion are quicker.\n";
        cout << "\033[0m"; // Reset font color to default

        cout << endl;
        if (l.isEmpty())
        {
            cout << setw(34) << "The current list is empty.";
            cout << "\n\n\n\n";
        }
        else if (l.size() > 1)
        {
            cout << setw(34) << "The current vector contains " << l.size() << " element(s):\n";
            cout << setw(7);
            for (int i = 0; i < l.size(); i++)
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191 << " ";
            cout << endl;
            cout << setw(7);
            for (int i = 0; i < l.size(); i++)
                cout << static_cast<char>(179) << " " << l.get(i) << static_cast<char>(179) << static_cast<char>(175);
            cout << endl;
            cout << setw(7);

            for (int i = 0; i < l.size(); i++)
                cout << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217 << " ";
            cout << endl;
            cout << setw(15) << "ADDRESS: " << &l;
        }
        else
        {
            cout << setw(34) << "The current vector contains " << l.size() << " element(s):\n";
            cout << setw(7);
            for (int i = 0; i < l.size(); i++)
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191;
            cout << endl;
            cout << setw(7);
            for (int i = 0; i < l.size(); i++)
                cout << static_cast<char>(179) << " " << l.get(i) << static_cast<char>(179);
            cout << endl;
            cout << setw(7);
            for (int i = 0; i < l.size(); i++)
                cout << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217;
            cout << endl;
            cout << setw(15) << "ADDRESS: " << &l;
        }
        cout << "\n\n";
        cout << setw(32) << "List Menu Options\n";
        cout << setw(7);
        for (int i = 0; i < 97; i++)
            cout << (char)205;
        cout << endl;

        // display menu
        cout << setw(44) << "1. Add an element to the back\n";
        cout << setw(47) << "2. Insert an element at an index\n";
        cout << setw(34) << "3. Erase element(s)\n";
        cout << setw(54) << "4. Sort the elements in ascending order\n";
        cout << setw(35) << "5. Clear all elements";
        cout << endl;
        cout << setw(7);
        for (int i = 0; i < 97; i++)
            cout << (char)196;
        cout << endl;
        cout << setw(23) << "0. Return";
        cout << endl;
        cout << setw(7);
        for (int i = 0; i < 97; i++)
            cout << (char)205;
        cout << endl;
        int option = inputInteger("            Option: ", 0, 5);
        switch (option)
        {
        case 0: main(); 
            break;

        case 1:
        {
            int numerator;
            int denominator;
            char choice;
            string criteria = "fb";

            // Prompt the user to input a rational number
            cout << setw(45) << "Input a Rational number to be added...\n";
            cout << setw(44);
            numerator = inputInteger("Enter a numerator(-9...9)   : ", -9, 9);
            cout << setw(46);
            denominator = inputInteger("Enter a denominator(-9...9)   : ", -9, 9);

            try {
                // Create a Rational object using the input numerator and denominator
                Rational r(numerator, denominator);

                string element = r.toString();
                cout << setw(57);

                // Prompt the user to choose whether to add the element to the front or back of the list
                choice = inputChar("Add to the (F-front) or from the (B-back): ", criteria);
                cout << endl;

                if (choice == 'F') {
                    // Add the element to the front of the list
                    l.add(element, true);
                    cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                        << endl;
                    cout << setw(15) << (char)179 << " " << element << (char)179
                        << " will be pushed to the front of the list." << endl;
                    cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                        << endl;
                }
                else {
                    // Add the element to the back of the list
                    l.add(element, false);
                    cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                        << endl;
                    cout << setw(15) << (char)179 << " " << element << (char)179
                        << " will be pushed to the back of the list." << endl;
                    cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                        << endl;
                }

                cout << endl;
                system("pause");
                system("cls");
            }
            catch (const Rational::ZeroDenominatorException& ex) {
                cout << "Error: " << ex.what() << endl;
                // Handle the error condition appropriately
                // You can choose to exit the program or take other actions
            }

            break;
        }

        case 2:
        {
            int numerator;
            int denominator;
            int numerator1;
            int denominator1;
            char choice;
            string criteria = "fb";
            cout << setw(48) << "Input a Rational number to be inserted...\n";
            cout << setw(44);
            numerator = inputInteger("Enter a numerator(-9...9)   : ", -9, 9);
            cout << setw(46);
            denominator = inputInteger("Enter a denominator(-9...9)   : ", -9, 9);
            cout << endl;

            try {
                string element = Rational(numerator, denominator).toString();
                cout << setw(78) << "Input an existing Rational number as the insert position to be added...\n";
                cout << setw(44);
                numerator1 = inputInteger("Enter a numerator(-9...9)   : ", -9, 9);
                cout << setw(46);
                denominator1 = inputInteger("Enter a denominator(-9...9)   : ", -9, 9);
                cout << setw(57);
                string element1 = Rational(numerator1, denominator1).toString();
                bool present = l.containsElement(element1);

                if (!present)
                {
                    cout << endl;
                    cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                        << endl;
                    cout << setw(15) << (char)179 << " " << element1 << (char)179
                        << " cannot be found from the list." << endl;
                    cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                        << endl;
                    system("pause");
                    system("cls");
                }
                else
                {
                    choice = inputChar("Add to the (F-front) or from the (B-back): ", criteria);
                    cout << endl;

                    if (choice == 'F')
                    {
                        l.add(element, true);
                        cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                            << endl;
                        cout << setw(15) << (char)179 << " " << element << (char)179
                            << " will be pushed to the front of the list." << endl;
                        cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                            << endl;
                    }
                    else
                    {
                        l.add(element, false);
                        cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                            << endl;
                        cout << setw(15) << (char)179 << " " << element << (char)179
                            << " will be pushed to the back of the list." << endl;
                        cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                            << endl;
                    }
                    system("pause");
                    system("cls");
                }
            }
            catch (const Rational::ZeroDenominatorException& ex) {
                cout << "Error: " << ex.what() << endl;
                // Handle the error condition appropriately
                // You can choose to exit the program
            }
            break;
        }
        case 3:
        {
            if (l.size() <= 0)
            {
                cout << endl;
                cout << setw(69) << "Erase operation cannot be performed onto an empty vector.";
                system("cls");
                break;
            }
            int numerator;
            int denominator;

            // Prompt the user to input a rational number
            cout << setw(51) << "Input a Rational number to be added...\n";
            cout << setw(50) << "Enter a numerator(-9...9)   : ";
            numerator = inputInteger("", -9, 9);
            cout << setw(52) << "Enter a denominator(-9...9)   : ";
            denominator = inputInteger("", -9, 9);

            try {
                // Create a Rational object using the input numerator and denominator
                Rational r(numerator, denominator);

                string element = r.toString();
                bool present = l.containsElement(element);
                if (!present)
                {
                    // The element is not found in the list
                    cout << endl;
                    cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                        << endl;
                    cout << setw(15) << (char)179 << " " << element << (char)179
                        << " cannot be found from the vector." << endl;
                    cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                        << endl;
                    system("pause");
                    system("cls");
                }
                else
                {
                    cout << endl;
                    char answer;
                    string criteria = "oa";

                    // Prompt the user to choose whether to remove one or all occurrences of the element
                    cout << setw(63);
                    answer = inputChar("Do you want to remove (O-one or A-all) element(s): ", criteria);

                    if (answer == 'A')
                    {
                        // Remove all occurrences of the element from the list
                        for (int i = 0; i < l.size(); i++)
                            l.deleteElement(element);

                        cout << endl;
                        cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                            << endl;
                        cout << setw(15) << (char)179 << " " << element << (char)179
                            << " has been removed all from the list." << endl;
                        cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                            << endl;
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        // Remove one occurrence of the element from the list
                        l.deleteElement(element);

                        cout << endl;
                        cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                            << endl;
                        cout << setw(15) << (char)179 << " " << element << (char)179
                            << " has been removed once from the list." << endl;
                        cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                            << endl;
                        cout << endl;
                        system("pause");
                        system("cls");
                    }
                }
            }
            catch (const Rational::ZeroDenominatorException& ex) {
                cout << "Error: " << ex.what() << endl;
                system("pause");
                system("cls");
            }

            break;
        }


        case 4:
        {
            if (l.size() <= 0)
            {
                cout << endl;
                cout << setw(66) << "Sort operation cannot be performed on an empty list.";
                cout << "\n\n";
                system("pause");
                system("cls");
                break;
            }
            cout << endl;
            cout << setw(57) << "The list will be sorted in ascending order.";

            // Sort the list in ascending order
            l.sort();

            cout << "\n\n";
            system("pause");
            system("cls");
            break;
        }

        case 5:
        {
            if (l.size() <= 0)
            {
                cout << endl;
                cout << setw(67) << "Clear operation cannot be performed on an empty list.";
                cout << "\n\n";
                system("pause");
                system("cls");
                break;
            }
            cout << endl;
            cout << setw(55) << "The list will be cleared of all element(s).";

            // Clear all elements from the list
            l.clear();

            cout << "\n\n";
            system("pause");
            system("cls");
            break;
            break;
        }

        default:
            break;
}

    } while (true);
}
//
//The preconditions for the stackOption() function are :
//
//The Stack and Rational classes are defined and implemented correctly.
//The displayStack() function is defined and implemented.
//The postconditions for the stackOption() function are :
//
//The function modifies the state of the s stack based on the user's input.
//The stack s may have elements pushed onto it or popped from it.
//The function continues to display the menu and perform stack operations until the user chooses to return to the main menu(option 0).
//The screen is cleared after each operation, and the loop continues.

void stackOption()
{
    system("cls");
    Stack tempStack;
    Stack s;
 
    do
    {
        cout << endl;
        cout << "\033[38;5;81m"; // Start Tiffany Blue font color
        cout << setw(97) << "Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, where\n";
        cout << setw(95) << "a new element is added(push) at one end(top) and an element is removed(pop) from that end\n";
        cout << setw(103) << "only. Stack uses an encapsulated object of either vector or deque(by default) or list (sequential\n";
        cout << setw(98) << "container class) as its underlying container,providing a specific set of member functions to\n";
        cout << setw(26) << "access its elements.\n";
        cout << "\033[0m"; // Reset font color to default

        cout << endl;
        if (s.isEmpty())
        {
            cout << setw(34) << "The current stack is empty.";
            cout << "\n\n\n\n";
        }
        else
        {
            cout << setw(34) << "The current stack contains contains " << s.size() << " element(s):\n";
            cout << setw(15);
            for (int i = 0; i < s.size(); i++)
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191;
            cout << endl;
            cout << setw(11) << "top " << static_cast<char>(175);
            cout << setw(3);
            displayStack(s);
            cout << endl;
            cout << setw(15);
            for (int i = 0; i < s.size(); i++)
                cout << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217;
            cout << endl;
        }
        cout << "\n\n";
        cout << setw(33) << "Stack Menu Options\n";
        cout << setw(7);
        for (int i = 0; i < 97; i++)
            cout << (char)205;
        cout << endl;

        cout << setw(22) << "1. Push\n";
        cout << setw(21) << "2. Top\n";
        cout << setw(21) << "3. Pop\n";
        cout << setw(7);
        for (int i = 0; i < 97; i++)
            cout << (char)196;
        cout << endl;

        cout << setw(23) << "0. Return";
        cout << endl;
        cout << setw(7);
        for (int i = 0; i < 97; i++)
            cout << (char)205;
        cout << endl;
        int option = inputInteger("              Option: ", 0, 3);
        switch (option)
        {
        case 0: main();
            break;
        case 1:
        {
            int numerator;
            int denominator;
            cout << setw(45) << "Input a Rational number to be pushed...\n";
            cout << setw(44);
            numerator = inputInteger("Enter a numerator(-9...9)   : ", -9, 9);
            cout << setw(46);
            denominator = inputInteger("Enter a denominator(-9...9)   : ", -9, 9);

            try {
                Rational r(numerator, denominator); // Creating the Rational object

                string element = r.toString(); // Convert the rational number to a string
                s.push(element); // Push the string element onto the stack

                // Display a message indicating the element that was pushed onto the stack
                cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                    << endl;
                cout << setw(15) << (char)179 << " " << element << (char)179
                    << " will be pushed onto the stack." << endl;
                cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                    << endl;

                cout << endl;
                system("pause");
                system("cls");

                break;
            }
            catch (const Rational::ZeroDenominatorException& ex) {
                // Handle the exception when the denominator is zero
                cout << "Error: " << ex.what() << endl;
                system("pause");
                system("cls");
                break;
            }
        }


        case 2:
        {
            if (s.isEmpty())
            {
                cout << setw(74) << "No top element can be retrieved from an empty stack.";
                cout << "\n\n";
            }
            else
            {
                // Display the top element of the stack
                cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                    << endl;
                cout << setw(15) << (char)179 << " " << s.top() << (char)179
                    << " is at the top of the stack." << endl;
                cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                    << endl;

                cout << endl;
            }
            system("pause");
            system("cls");
            break;
        }

        case 3:
        {
            if (s.isEmpty())
            {
                cout << setw(74) << "No pop operation can be performed from an empty stack.";
                cout << "\n\n";
            }
            else
            {
                // Display the element that will be popped from the stack
                cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                    << endl;
                cout << setw(15) << (char)179 << " " << s.get(0) << (char)179
                    << " will be popped from the stack." << endl;
                cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                    << endl;

                s.pop(); // Pop the element from the stack
            }
            system("pause");
            system("cls");
            break;
        }
        default:
            break;
        }
    } while (true);
}

//
//Pre - condition:
//
//A queue object named q must be declared and initialized before calling the queueOption() function.
//Post - condition :
//
//    The queueOption() function provides a menu - based interface for interacting with the queue.
//    The function displays information about the current state of the queue.
//    The user can enqueue elements, access the front and back elements, and dequeue elements from the queue based on the chosen menu option.
//    The function handles exceptions when attempting to enqueue a Rational number with a zero denominator.
//    The function clears the screen after each operation and continues to display the menu until the user chooses to exit by selecting option 0.
//    The function returns control to the main() function once the user selects option 0.
void queueOption()
{
    system("cls");
    Queue q;
    do {
        cout << endl;

        cout << "\033[32m"; // Start green font color
        cout << endl;
        cout << setw(97) << "Queues are a type of container adaptors that operate in a first in first out (FIFO) type of\n";
        cout << setw(98) << "arrangement. Elements are inserted(enqueued) at the back and are deleted (dequeued) from the\n";
        cout << setw(98) << "front. Queues use an encapsulated object of deque or list(sequential container class) as its\n";
        cout << setw(92) << "underlying container, providing a specific set of member functions to access elements.\n";
        cout << "\033[0m"; // Reset font color to default
        cout << endl;

        if (q.isEmpty())
        {
            cout << setw(34) << "The current stack is empty.";
            cout << "\n\n\n\n";
        }
        else
        {
            cout << setw(41) << "The current queue contains contains " << q.size() << " element(s):\n";
            cout << setw(14);
            for (int i = 0; i < q.size(); i++)
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191;
            cout << endl;
            cout << setw(11) << "back " << static_cast<char>(175);
            cout << setw(2);
            //            for (int i = 0; i < q.size(); i++)
            //                cout << static_cast<char>(179) << " " << q.get((q.size() - 1) - i) << static_cast<char>(179);
            displayQueue(q);
            cout << " " << static_cast<char>(174) << " front";
            cout << endl;
            cout << setw(14);
            for (int i = 0; i < q.size(); i++)
                cout << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217;
            cout << endl;
        }
        cout << "\n\n";
        cout << setw(33) << "Queue Menu Options\n";
        cout << setw(7);
        for (int i = 0; i < 97; i++)
            cout << (char)205;
        cout << endl;

        // menu option
        cout << setw(49) << "1. Enqueue (push in from the back)\n";
        cout << setw(23) << "2. Front\n";
        cout << setw(22) << "3. Back\n";
        cout << setw(46) << "4. Dequeue (pop from the front)\n";
        cout << setw(7);
        for (int i = 0; i < 97; i++)
            cout << (char)196;
        cout << endl;

        cout << setw(23) << "0. Return";

        cout << endl;
        cout << setw(7);
        for (int i = 0; i < 97; i++)
            cout << (char)205;
        cout << endl;
        int option = inputInteger("              Option: ", 0, 4);
        switch (option) {
        case 0:
            main();
            break;
        case 1:
        {
            int numerator;
            int denominator;
            cout << setw(45) << "Input a Rational number to be enqueued...\n";
            cout << setw(44);
            numerator = inputInteger("Enter a numerator(-9...9)   : ", -9, 9);
            cout << setw(46);
            denominator = inputInteger("Enter a denominator(-9...9)   : ", -9, 9);

            try {
                Rational r(numerator, denominator); // Creating the Rational object

                string element = r.toString();
                q.enqueue(element); // Enqueue the element onto the queue

                cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                    << endl;
                cout << setw(15) << (char)179 << " " << element << (char)179
                    << " will be enqueued (pushed) onto the queue." << endl;
                cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                    << endl;

                cout << endl;
                system("pause");
                system("cls");

                break;
            }
            catch (const Rational::ZeroDenominatorException& ex) {
                cout << "Error: " << ex.what() << endl;
                system("pause");
                system("cls");
                break;
            }
        }


        case 2:
        {
            if (q.isEmpty())
            {
                cout << setw(68) << "No front element can be retrieved from an empty queue.";
                cout << "\n\n";
            }
            else
            {
                cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                    << endl;
                cout << setw(15) << (char)179 << " " << q.front() << (char)179
                    << " is at the front of the queue." << endl;
                cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                    << endl;

                cout << endl;
            }
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            if (q.isEmpty()) {
                cout << setw(67) << "No back element can be retrieved from an empty queue.";
                cout << "\n\n";
            }
            else {
                cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                    << endl;
                cout << setw(15) << (char)179 << " " << q.back() << (char)179
                    << " is at the back of the queue." << endl;
                cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                    << endl;

                cout << endl;
            }
            system("pause");
            system("cls");
            break;
        }

        case 4:
        {
            if (q.isEmpty())
            {
                cout << setw(76) << "No dequeue (pop) operation can be performed on an empty stack.";
                cout << "\n\n";
            }
            else
            {
                cout << setw(15) << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191
                    << endl;
                cout << setw(15) << (char)179 << " " << q.get(0) << (char)179
                    << " will be dequeued (popped) from the queue." << endl;
                cout << setw(15) << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217
                    << endl;
                q.dequeue();
            }
            system("pause");
            system("cls");
            break;
        }
        default:
            break;
        }
    } while (true);
}

void displayQueue(Queue& q)
{
    // Check if the queue is empty
    if (q.isEmpty()) {
        return; // If empty, return and exit the function
    }
    else {
        // If the queue is not empty
        string topElement = q.front(); // Get the front element of the queue
        q.dequeue(); // Remove the front element from the queue

        // Display the top element
        cout << static_cast<char>(179) << " " << topElement << static_cast<char>(179);

        displayQueue(q); // Recursively call the displayQueue function to display the remaining elements

        q.enqueue(topElement); // Enqueue the top element back into the queue
    }
}


void displayStack(Stack& s)
{
    if (s.isEmpty()) {
        return;
    }
    else {
        if (s.isEmpty()) {
            return;
        }
        string topElement = s.top();
        s.pop();

        cout << static_cast<char>(179) << " " << topElement << static_cast<char>(179);

        displayStack(s);

        s.push(topElement);
    }
}


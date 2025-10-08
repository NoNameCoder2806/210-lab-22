// COMSC-210 | Lab 22 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

// Constants
const int MIN_NR = 10;
const int MAX_NR = 99;
const int MIN_LS = 5;
const int MAX_LS = 20;

// Main function
int main()
{
    // Create a DoublyLinkedList
    DoublyLinkedList list;

    // Randomly generate the size of it
    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;

    // Add elements to the Linked list
    for (int i = 0; i < size; ++i)
    {
        list.push_back(rand() % (MAX_NR - MIN_NR + 1) + MIN_NR);
    }

    // Print the Linked list in forward direction
    cout << "List forward: ";
    list.print();

    // Print the Linked list in backward direction
    cout << "List backward: ";
    list.print_reverse();

    // Call the Destructor to destroy the Linked list
    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();

    // Print the Linked list again
    cout << "List forward: ";
    list.print();

    return 0;
}
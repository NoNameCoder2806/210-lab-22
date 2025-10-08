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

// Driver program
int main()
{
    DoublyLinkedList list;
    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;

    for (int i = 0; i < size; ++i)
    {
        list.push_back(rand() % (MAX_NR - MIN_NR + 1) + MIN_NR);
    }
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}
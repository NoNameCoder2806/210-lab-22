// COMSC-210 | Lab 22 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
using namespace std;

// DoublyLinkedList class
class DoublyLinkedList
{
private:
    // Node struct
    struct Node
    {
        int data;
        Node* prev;
        Node* next;

        // Constructor
        Node(int val, Node* p = nullptr, Node* n = nullptr)
        {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;        // The pointer to the head (the first element)
    Node* tail;        // The pointer to the tail (the last element)

public:
    // Constructor
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor
    ~DoublyLinkedList()
    {
        while (head)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Member functions
    /*
        push_back()
        Adds a value to the back (tail) of the doubly linked list.
        Arguments:
            - value: an integer representing the value to insert
        Return: none
    */
    void push_back(int value)
    {
        Node* newNode = new Node(value);

        if (!tail)  // if there's no tail, the list is empty
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    /*
        push_front()
        Adds a value to the front (head) of the doubly linked list.
        Arguments:
            - value: an integer representing the value to insert
        Return: none
    */
    void push_front(int value)
    {
        Node* newNode = new Node(value);

        if (!head)  // if there's no head, the list is empty
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    /*
        insert_after()
        Inserts a new value immediately after the specified position.
        Arguments:
            - value: an integer representing the value to insert
            - position: an integer (0-based index) where insertion occurs after
        Return: none
        Note: If position exceeds list size, insertion will fail with a message.
    */
    void insert_after(int value, int position)
    {
        if (position < 0)
        {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
        {
            temp = temp->next;
        }

        if (!temp)
        {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next)
        {
            temp->next->prev = newNode;
        }
        else
        {
            tail = newNode; // Inserting at the end
        }

        temp->next = newNode;
    }

    /*
        delete_node()
        Deletes the first node found with the specified value.
        Arguments:
            - value: an integer representing the value to delete
        Return: none
        Note: If the value is not found, no deletion occurs.
    */
    void delete_node(int value)
    {
        if (!head)
        {
            return; // Empty list
        }

        Node* temp = head;
        while (temp && temp->data != value)
        {
            temp = temp->next;
        }

        if (!temp)
        {
            return; // Value not found
        }

        if (temp->prev)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            head = temp->next; // Deleting the head
        }

        if (temp->next)
        {
            temp->next->prev = temp->prev;
        }
        else
        {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    void delete_pos(int pos)
    {
        if (!head)
        {
            return; // Empty list
        }

        // Create a Node to traverse
        Node* temp = head;

        // Delete the head
        if (pos == 0)
        {
            head = head->next;
            delete temp;
            return;
        }

        // Declare an int counter to traverse
        int count = 0;

        while (temp && count < pos)
        {
            temp = temp->next;
            count++;
        }

        if (!temp)
        {
            return; // Value not found
        }

        if (temp->prev)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            head = temp->next; // Deleting the head
        }

        if (temp->next)
        {
            temp->next->prev = temp->prev;
        }
        else
        {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    void pop_front()
    {
        // If the Linked list is empty
        if (!head)
        {
            return;      // Exit the function
        }

        // Declare a new Node
        Node* temp = head;

        // Advance the head
        head = head->next;

        // If the new head is not null (the list is empty)
        if (head)
        {
            head->prev = nullptr;      // Set the prev pointer to null
        }
        else      // Otherwise, if the Linked list is now empty
        {
            tail = nullptr;            // Set the tail to null
        }

        // Delete the temp Node
        delete temp;
    }

    /*
        print()
        Prints the linked list in forward order (head to tail).
        Arguments: none
        Return: none
    */
    void print()
    {
        Node* current = head;

        if (!current)
        {
            return;
        }

        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    /*
        print_reverse()
        Prints the linked list in reverse order (tail to head).
        Arguments: none
        Return: none
    */
    void print_reverse()
    {
        Node* current = tail;

        if (!current)        // If the Linked list is empty
        {
            return;
        }

        // While the current node is not null
        while (current)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

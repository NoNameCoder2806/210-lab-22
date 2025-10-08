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
        // Create a new Node from the given value
        Node* newNode = new Node(value);

        // If there's no tail, the Linked list is empty
        if (!tail)
        {
            // We let the head and tail both point to the new Node
            head = tail = newNode;
        }
        else        // Otherwise the Linked list is not empty
        {
            // Add the new Node to the tail of the Linked list
            tail->next = newNode;        // Add the new Node to the tail
            newNode->prev = tail;        // Let the prev pointer of it points to the previous tail

            // Let tail be the new Node
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
        // Create a new Node from the given value
        Node* newNode = new Node(value);

        // If there's no head, the list is empty
        if (!head)
        {
            // We let the head and tail both point to the new Node
            head = tail = newNode;
        }
        else        // Otherwise the Linked list is not empty
        {
            // Add the new Node to the head of the Linked list
            newNode->next = head;        // Add the new Node to the head
            head->prev = newNode;        // Let the next pointer of it points to the previous head

            // Let head be the new Node
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
        // If the position is a negative value
        if (position < 0)
        {
            // Display an error message
            cout << "Position must be >= 0." << endl;

            return;        // Exit the function
        }

        // Create a new Node from the given value
        Node* newNode = new Node(value);
        
        // If there's no head, the list is empty
        if (!head)
        {   
            // We add the new Node to the Linked list
            head = tail = newNode;

            return;        // Exit the function
        }

        // Create a new Node to be the head
        Node* temp = head;

        // Iterate until we reach the position or temp becomes null
        for (int i = 0; i < position && temp; ++i)
        {
            // Advance to the next node
            temp = temp->next;
        }

        // If temp becomes null, we have exceeded the Linked list
        if (!temp)
        {
            // Display a message
            cout << "Position exceeds list size. Node not inserted.\n";
            
            // Delete the new Node
            delete newNode;

            return;        // Exit the function
        }

        // Otherwise, we have reached the position we need to insert
        newNode->next = temp->next;        // Insert the Node
        newNode->prev = temp;

        // If the next Node is not null
        if (temp->next)
        {
            // We set its prev pointer to the new Node that we just inserted
            temp->next->prev = newNode;
        }
        else        // Otherwise, the next Node is null
        {
            tail = newNode;        // Inserting at the end (let tail be the new Node)
        }

        // Let temp->next points to the new Node
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
    void delete_val(int value)
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
            if (head)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }

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

    void pop_back()
    {
        if (!tail)
        {
            return;
        }

        Node* temp = tail;

        tail = tail->prev;

        if (tail)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }

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

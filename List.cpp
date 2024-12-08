//==============================================================
// Viet Nguyen
// December 2024
// List.cpp
// This file contains the class method definitions for
// the List class.
//==============================================================

#include <iostream>
#include <stdlib.h>
using namespace std;

//==============================================================
// default constructor
// Initializes an empty List object.
// PARAMETERS:
// none
// RETURN VALUE:
// none
//==============================================================
template <typename T>
List<T>::List ()
{
    head = nullptr; // Initialize an empty list by setting head to nullptr
}

//==============================================================
// copy constructor
// Creates a deep copy of the given List object.
// PARAMETERS:
// mylist - A reference to the List object to be copied.
// RETURN VALUE:
// none
//==============================================================
template <typename T>
List<T>::List ( const List<T> &mylist )
{
    Node *mylistCurrent = mylist.head; 
    Node *current = nullptr;
    // Check if the list to copy is empty
    if (mylistCurrent == nullptr)
    {
        head = nullptr;
    }
    else
    {
        head = new Node;
        head -> item = mylistCurrent -> item;
        head -> next = nullptr;
        current = head;
        mylistCurrent = mylistCurrent -> next;
        // Copy each node from the mylist to the new list
        while (mylistCurrent != nullptr) 
        {
            current -> next = new Node; 
            current = current -> next;  
            current -> item = mylistCurrent -> item;
            current -> next = nullptr;

            mylistCurrent = mylistCurrent -> next;
        }
    }
}

//==============================================================
// destructor
// Frees all allocated memory and deallocates all nodes in the List.
// PARAMETERS:
// none
// RETURN VALUE:
// none
//==============================================================
template <typename T>
List<T>::~List ()
{
    clear(); // Clears the list and deallocates memory
}

//==============================================================
// operator=
// Assigns the contents of one List to another, performing a deep copy.
// PARAMETERS:
// mylist - A reference to the List object to be assigned.
// RETURN VALUE:
// A reference to the updated List object.
//==============================================================
template <typename T>
List<T> List<T>::operator= ( const List<T> &mylist )
{
    if (this == &mylist) // Check for self-assignment
    {
        return *this; 
    }

    clear(); // Clear the current list before assigning

    Node *mylistCurrent = mylist.head; 
    Node *current = nullptr;

    // If the list to copy is empty, just return the empty list
    if (mylistCurrent == nullptr) 
    {
        head = nullptr;
        return *this;
    }
    else
    {
        head = new Node;
        head -> item = mylistCurrent -> item;
        head -> next = nullptr;
        current = head;
        mylistCurrent = mylistCurrent -> next;

        // Copy nodes from the source list to the new list
        while (mylistCurrent != nullptr) 
        {
            current -> next = new Node; 
            current = current -> next;  
            current -> item = mylistCurrent -> item;
            current -> next = nullptr;

            mylistCurrent = mylistCurrent -> next;
        }
        
        return *this;
    }
}

//==============================================================
// append
// Adds an item to the end of the List.
// PARAMETERS:
// item - The value to be appended to the List.
// RETURN VALUE:
// none
//==============================================================
template <typename T>
void List<T>::append ( const T &item )
{
    Node *itemNode = new Node;
    itemNode -> item = item;
    itemNode -> next = nullptr;

    if (head == nullptr)
    {
        head = itemNode; // Set the head if the list is empty
    }
    else
    {
        Node *current = head;
        while (current -> next != nullptr)
        {
            current = current -> next;

        }
        current -> next = itemNode; // Append at the end of the list
    }
} 

//==============================================================
// insert
// Inserts an item at the specified index in the List.
// PARAMETERS:
// item  - The value to be inserted into the List.
// index - The position at which the item is inserted (0-based).
// RETURN VALUE:
// none
//==============================================================
template <typename T>
void List<T>::insert ( const T &item, int index )
{
    // Check for invalid index
    if (index < 0 || index > length())
    {
        throw out_of_range("Index out of bounds.");
    }

    Node *itemNode = new Node;
    itemNode -> item = item;

    // If inserting at the beginning, update head
    if (index == 0)
    {
        itemNode -> next = head;
        head = itemNode;
    }
    else 
    {
        Node *current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current -> next;
        }
        itemNode -> next = current -> next;
        current -> next = itemNode;
    }
}

//==============================================================
// length
// Calculates the number of items in the List.
// PARAMETERS:
// none
// RETURN VALUE:
// The number of items in the List.
//==============================================================
template <typename T>
int List<T>::length	( ) const
{
    int length = 0;
    Node *current = head;
    
    // Traverse the list to count the nodes
    while (current != nullptr)
    {
        length = length + 1;
        current = current -> next;
    }
    return length;
}

//==============================================================
// operator[]
// Valid indices are 0 to size-1.   Invalid indices generate
// a run-time error and end the program.
// Accesses the item at the specified index in the List.
// PARAMETERS:
// index - The position of the item to be accessed (0-based).
// RETURN VALUE:
// A reference to the item at the specified index.
//==============================================================
template <typename T>
T & List<T>::operator[] ( int index )
{
    // Check for invalid index
    if (index < 0 || index > length() - 1)
    {
        throw out_of_range("Index out of bounds.");
    }
    
    Node *current = head;
    // Traverse to the specified index
    for (int i = 0; i < index; i++)
    {
        current = current -> next;
    }
    return current -> item;
}

//==============================================================
// remove
// Valid indices are 0 to size-1.   Invalid indices generate
// a run-time error and end the program.
// Removes the item at the specified index in the List.
// PARAMETERS:
// index - The position of the item to be removed.
// RETURN VALUE:
// none
//==============================================================
template <typename T>
void List<T>::remove (int index)
{
    // Check for invalid index
    if (index < 0 || index > length() - 1)
    {
        throw out_of_range("Index out of bounds.");
    }
    
    Node *current = head;

    // If removing the first node, update head
    if (index == 0)
    {
        head = head -> next;
        delete current;
    }
    else
    {
        // Traverse to the node before the one to be removed
        for (int i = 0; i < index - 1; i++)
        {
            current = current -> next;
        }

        Node *temp = current -> next;
        current -> next = temp -> next;
        delete temp;

    }
}

//==============================================================
// isEmpty
// Checks whether the List is empty.
// PARAMETERS:
// none
// RETURN VALUE:
// true if the List is empty, false otherwise.
//==============================================================
template <typename T>
bool List<T>::isEmpty() const
{
    return head == nullptr; // Check if head is nullptr, indicating an empty list
}

//==============================================================
// operator+
// Concatenates two Lists into a new List.
// PARAMETERS:
// mylist - A reference to the List to be concatenated with the current List.
// RETURN VALUE:
// A new List object containing items from both Lists.
//==============================================================
template <typename T>
List<T> List<T>::operator+ ( const List<T> &mylist ) const
{
    List<T> ret; 
    Node* current = head; 
    Node* mylistCurrent = mylist.head;
    Node* retCurrent = nullptr; 

    // Copy nodes from the first list
    while (current != nullptr) 
    {
        Node* newNode = new Node;
        newNode -> item = current -> item;
        newNode -> next = nullptr;
        if (ret.head == nullptr) 
        {
            ret.head = newNode; // Initialize head for the resulting list
            retCurrent = ret.head;
        } 
        else 
        {
            retCurrent -> next = newNode; 
            retCurrent = retCurrent -> next; 
        }

        current = current -> next;
    }

    // Copy nodes from the second list
    while (mylistCurrent != nullptr) 
    {
        Node* newNode1 = new Node; // Create a new node
        newNode1 -> item = mylistCurrent -> item;
        newNode1 -> next = nullptr;
        if (ret.head == nullptr) 
        {
            ret.head = newNode1; // Initialize head if empty
            retCurrent = ret.head;
        } 
        else 
        {
            retCurrent->next = newNode1; // Link the new node
            retCurrent = retCurrent -> next; // Advance to the new tail
        }

        mylistCurrent = mylistCurrent -> next;
    }

    return ret;
}

//==============================================================
// clear
// Removes all items from the List, freeing allocated memory.
// PARAMETERS:
// none
// RETURN VALUE:
// none
//==============================================================
template <typename T>
void List<T>::clear()
{
    while (head != nullptr)
    {
        Node *current = head;
        head = current -> next;
        delete current;
    }
}

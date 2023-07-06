#include <iostream>
using namespace std;

// Node class represents a single node in the linked list
class Node
{
private:
    /* data */
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the linked list

    Node()
    {
        data = 0;
        next = NULL;
    }
};

// Stack class represents a stack data structure
class Stack
{
    Node* top;      // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    Stack()
    {
        top = NULL;
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        Node* ptr = new Node();
        if (ptr == NULL)
        {
            cout << "The Stack is Full, cannot add more items \n";
        }
        
    }

    // Function to push an item onto the stack
    void push(int item)
    {
        Node* newnode = new Node();
        newnode->data = item;

        if (isEmpty())
        {
            newnode->next = NULL;
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
    }

    int pop()
    {
        int value;              // Variable to store the value of the popped item
        Node* delptr = top;     // Create a temporary pointer to the top node

        value = top->data;      // Store the data of the top node in the 'value' variable
        top = top->next;        // Move the 'top' pointer to the next node

        delete delptr;          // Delete the top node to free the memory
        return value;           // Return the value of the popped item
    }


    // Function to return the top item of the stack without removing it
    int Peek()
    {
        return top->data;
    }

    // Function to display the contents of the stack
    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to count the number of items in the stack
    int count()
    {
        int counter = 0;
        Node *temp = top;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    // Function to check if an item is present in the stack
    bool IsFound(int item)
    {
        bool found = false;
        Node* temp = top;
        while (temp != NULL)
        {
            if (temp->data == item)
            {
                found = true;
                temp = temp->next;
            }
        }
        // Missing return statement, should return found variable
    }
};

int main()
{
    int item;
    Stack s;

    // Pushing items onto the stack
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Item To Push: ";
        cin >> item;
        s.push(item);
        s.display();
    }

    // Popping items from the stack
    cout << s.pop() << " was deleted from stack \n";
    s.display();
    cout << s.pop() << " was deleted from stack \n";
    s.display();

    cout << "Enter Item to search for \n";
    cin >> item;

    if (s.IsFound(item))
        cout << "Is Found \n";
    else
        cout << "Not Found \n";
    
    cout << s.count() << endl;
    
}

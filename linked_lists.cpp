#include <iostream>
using namespace std;

class Node
{
private:
    /* data */
public:
    int data;
    Node* next;
};

class Linkedlist
{
public:
    Node* head;

    Linkedlist()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        // Check if the head is NULL
        // If head is NULL, the list is empty
        // Return true if empty, false otherwise
        return (head == NULL);
    }

   void insertFirst(int newValue)
   {
        // Create a new node by dynamically allocating memory for it
        Node* newNode = new Node();

        // Assign the input value (newValue) to the new node's data (newNode->data)
        newNode->data = newValue;

        // If the list is empty
        if (isEmpty())
        {
            // Set the next pointer of the new node to NULL
            // Since the list is empty, there are no other nodes to connect to
            // Therefore, we set the next pointer of the new node to NULL
            newNode->next = NULL;

            // Set the head to point to the new node
            // Since the list is empty, the new node becomes the first node in the list
            // Therefore, we update the head pointer to point to the new node
            head = newNode;

        }
        // If the list is not empty
        else
        {
            // Set the next pointer of the new node to the current head
            newNode->next = head;

            // Update the head to point to the new node
            head = newNode;
        }
}


 void display()
{
    // Start from the head of the linked list
    Node* temp = head;

    // Traverse the list until the end (temp becomes NULL)
    /* "Traverse" refers to the process of iterating or moving through a data structure*/
    while (temp != NULL)
    {
        // Print the data of the current node
        cout << temp->data << " ";

        // Move to the next node
        temp = temp->next;
    }

}

int count()
{
    // Initialize a counter variable to keep track of the number of nodes
    int counter;

    // Start from the head of the linked list
    Node* temp = head;

    // Traverse the list until the end (temp becomes NULL)
    while (temp != NULL)
    {
        // Increment the counter for each node visited
        counter++;

        // Move to the next node
        temp = temp->next;
    }

    // Return the total count of nodes in the linked list
    return counter;
}

bool isfound(int key)
{
    // Initialize a boolean variable to track if the key is found
    bool found = false;

    // Start from the head of the linked list
    Node* temp = head;

    // Traverse the list until the end (temp becomes NULL)
    while (temp != NULL)
    { 
        // Check if the data of the current node matches the key
        if (temp->data == key)
        {
            // If a match is found, update the found variable to true
            found = true;
        }
        
        // Move to the next node
        temp = temp->next;
    }

    // Return the boolean value indicating if the key was found
    return found;
}

void insertbefore(int item, int newValue)
{
    if (isEmpty())
    insertFirst(newValue);
    if(isfound(item)){
        Node* newnode = new Node();
        newnode->data = newValue;
        Node* temp = head;
        while(temp != NULL && temp->next->data != item){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        cout << "Sorry, Item Not Found \n";
    }

}   

void append (int newValue)
    {
        if (isEmpty())
            insertFirst(newValue);
        else

		{

		}
		Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node* newnode = new Node();
        newnode->data = newValue;
        temp->next = newnode;
        newnode->next = NULL;
        
    }

    void Delete(int item)
    {
        if(isEmpty())
            cout << "List is empty, no item to delete \n";

        Node* delptr = head;
        if (head->data == item)
        {
            head = head->next;
            delete delptr;
        }
        else
        {
            Node* prev = NULL;
            delptr = head;
            while(delptr->data != item){
                prev = delptr;
                delptr = delptr->next;
            }
            prev->next = delptr->next;
            delete delptr;
        }
        
    }

};

int main()
{
    // Main function where the code execution starts
    // Create an object of Linkedlist class
    Linkedlist lst;

    if (lst.isEmpty())
        cout << "The list is Empty \n";
    else
        cout << "The list contains " << lst.count() << " endl \n";


    int item;

    cout << "Enter an item to insert in the list: ";
    cin >> item;
    lst.insertFirst(item);
        
    // Perform operations on the linked list using the object
    // Display the linked list
    lst.display();

    cout << "Enter an item to insert in the list: ";
    cin >> item;
    lst.insertFirst(item);
    lst.display();

    cout << "Enter an item to insert in the list: ";
    cin >> item;
    lst.insertFirst(item);
    lst.display();

    cout << "The List Contains " << lst.count() << endl;

/*  cout << "Enter an item search for \n";
    cin >> item;
    if (lst.isfound(item))
        cout << "Item Found \n";
    else
       cout << "Item not Found \n";
*/    
    int newValue;
    //cout << "Enter Item and new value to insert \n";

    cin >> item;
    //cin >> newValue;
    /*lst.insertbefore(item, newValue);*/
    /*lst.append(newValue);*/
    cout << "Enter Item and new value to delete \n";
    lst.Delete(item);
    lst.display();

}

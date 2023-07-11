#include <iostream>
using namespace std;

// Node class represents a single node in the linked list
class Node
{
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the linked list

    Node()
    {
        data = 0;
        next = NULL;
    }
};

class Queue
{
public:
    Node* front;    // Pointer to the front of the queue
    Node* rear;     // Pointer to the rear of the queue

    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        if (front == NULL)
            return true;
        else
            return false;
    }

	/*The Enqueue function is used to add an item to the rear of the queue. 
	Here's a breakdown of what it does:*/

    void Enqueue(int item)
    {
        Node* newnode = new Node();
        newnode->data = item;

        if (isEmpty())                  // If the queue is empty
            front = rear = newnode;     // Set both front and   rear to the new node
        else
        {
            rear->next = newnode;       // Set the next pointer of the current rear to the new node
            rear = newnode;             // Update the rear pointer to the new node
        }
    }

    void display()
    {
		if (isEmpty())
			cout <<"";
		else{
		
        Node* temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";   // Print the data of the current node
            temp = temp->next;           // Move to the next node
        }
        cout << endl;
    }
	}
	/*
	The Dequeue function is used to remove 
	an item from the front of the queue.:
	*/
    int Dequeue()
    {
        int delvalue = -1;
        if (isEmpty())
            cout << "The queue is empty \n";
        else if (front == rear)         // If there is only one node in the queue
        {
            delete front;               // Delete the node
            front = rear = NULL;        // Set both front and rear to NULL
        }
        else
        {
            Node* delptr = front;       // Store the front node in a temporary pointer
            front = front->next;        // Move the front pointer to the next node
            delvalue = delptr->data;    // Get the data of the deleted node
            delete delptr;              // Delete the node
        }

        return delvalue;                // Return the deleted value (or -1 if queue is empty)
    }

	int getFront()
	{
		return front->data;
	}

	
	int getRear()
	{
		return rear->data;
	}

	void Clear()
	{
		while (!isEmpty())
		{
			Dequeue();
		}
		
	}
	
	int count()
	{
		int counter = 0;
		Node* temp = front;
		while (temp != NULL)
		{
			counter ++;
			temp = temp -> next;
		}
	return counter;	
	}

	bool isFound(int item)
	{
		bool found = false;
		Node* temp = front;
		while(temp != NULL)
		{
			if (temp->data == item)
				found = true;
			temp = temp -> next;
			
		}
		return found;
	}
};

int main()
{
    Queue q;

    // Enqueue four items into the queue
    for (int i = 0; i <= 3; i++)
    {
        int item;
        cout << "Enter Items To Enqueue: ";
        cin >> item;
        q.Enqueue(item);
    }

    cout << "Queue Contents: ";
    q.display();

    // Dequeue two items from the queue
    q.Dequeue();
    cout << "After Dequeue: ";
    q.display();
    q.Dequeue();
    q.display();

    return 0;
}

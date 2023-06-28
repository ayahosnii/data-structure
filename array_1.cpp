#include <iostream>
using namespace std;

class Array
{
private:
    int size;
    int length;
    int * items;

public:
    // Constructor to initialize the Array object
    Array(int arrsize)
    {
        size = arrsize;
        length = 0;
        items = new int[arrsize]; // Dynamically allocate memory for the array
    }

    // Method to fill the array with user input
    void Fill()
    {
        int no_of_items;
        cout <<"How many items you want to fill? \n";
        cin >> no_of_items;
        if (no_of_items > size)
        {
            cout << "You cannot exceed the array size \n";
            return;
        }
        else
        {
            for (int i = 0; i < no_of_items; i++)
            {
                cout << "Enter item no " <<i<<endl;
                cin >> items[i];
                length ++;
            }
        }
    }
    
    // Method to display the content of the array
    void Display()
    {
         cout << "Display Array Content \n";
         for (int i = 0; i < length; i++)
         {
            cout << items[i] << "\t";
         }
         cout << endl;
    }

    // Method to get the size of the array
    int getSize()
    {
        return size;
    }

    // Method to get the current length of the array
    int getLength()
    {
        return length;
    }

    // Method to search for a given key in the array
      int Search(int key)
      {
        int index = -1;
        for (int i = 0; i < length; i++)
        {
            if (items[i] == key)
            {
                index = i;
                break;
            }

        }

  return index;
    }

    // Method to append a new item to the end of the array
    void Append(int newitem)
    {
        if (length < size)
        {
            items[length] = newitem;
            length++;            
        }
        else
        cout << "Array is full \n"; 
    }

    // Method to insert a new item at a specific index in the array
    void Insert(int index, int newitem)
    {
        if (index >= 0 && index < size)
        {
            for (int i = length; i > index; i--)
            {
                items[i] = items[i - 1];
            }
            items[index] = newitem;
            length++;
        }
        else
        {
            cout << "Error - index out of Range \n";
        }
    }

    void Delete(int index)
    {
        if (index >= 0 && index < size)
        {
            for (int i = index; i < length - 1; i++)
            {
                items[i] = items[i + 1];
            }
            length--;
        }
        else
        {
            cout << "Error - index out of Range \n";
        }
    }

    void Enlarge(int newsize)
    {
        if (newsize <= size)
        {
            cout << "New size must be larger than current size \n";
        }
        else
        {
            size = newsize;
            int * old = items;
            items = new int[newsize];
            for (int i = 0; i < length; i++)
            {
                items[i] = old[i];
            }
            delete[]old;
            
        }
        
    }
    
  void Merge(Array other)
{
    int newsize = size + other.getSize();  // Calculate the new size by adding the current size and the size of the other array
    size = newsize;  // Update the size of the current array

    int* old = items;  // Store the pointer to the old array

    items = new int[newsize];  // Create a new array with the updated size
    int i;

    // Copy the elements from the old array to the new array
    for (i = 0; i < length; i++)
    {
        items[i] = old[i];  
    }

    delete[] old;  // Deallocate the memory occupied by the old array

    int j = i;

    // Copy the elements from the other array to the new array
    for (int i = 0; i < other.getLength(); i++)
    {
       items[j++] = other.items[i];  // Copy the element from the other array to the new array and increment the index of the new array
       length++;  // Increase the length of the current array
    }
}

};


int main()
{
    cout << "Hello This is Array ADT demo \n";
    int arraysize;
    cout << "Enter the Array Size \n";
    cin >> arraysize;

    Array myarray(arraysize); // Create an Array object with the specified size

    myarray.Fill(); // Fill the array with user input
    
    cout << "The Array Size = " <<
             myarray.getSize() << 
             " While the length = " << 
             myarray.getLength() << "\n";


    myarray.Display(); // Display the content of the array

/*
    cout << "Enter the value to search for \n";
    int key;
    cin >> key;
    
    int index =   myarray.Search(key);
    if (index == -1)
        cout << "Item not found \n";
    else
        cout << "Item found @ position " << index << endl;
*/    
    int index;
    int newitem;
    cout << "Enter a new item to add to the array \n";
    cin >> newitem;
    myarray.Append(newitem); // Append the new item to the array
    myarray.Display(); // Display the updated array

   
    cout << "Enter an index and item to insert into the array";
    cin >> index;
    cin >> newitem;

    myarray.Insert(index, newitem); // Insert the item at the specified index in the array
    myarray.Display(); // Display the updated array

     cout << "Enter an index and item to delete into the array";
    cin >> index;
    myarray.Delete(index);
    myarray.Display(); // Display the updated array

    cout << "The Array Size = " <<
             myarray.getSize() << 
             " While the length = " << 
             myarray.getLength() << "\n";

    int newsize;
    cout << "Enter New Size \n";
    cin >> newsize;
    myarray.Enlarge(newsize);
     cout << "The Array Size = " <<
             myarray.getSize() << 
             " While the length = " << 
             myarray.getLength() << "\n";
    myarray.Display();

    Array other(3);
    other.Fill();
    myarray.Merge(other);
     cout << "The Array Size = " <<
             myarray.getSize() << 
             " While the length = " << 
             myarray.getLength() << "\n";
    
    myarray.Display();

}

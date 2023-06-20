#include <iostream>
using namespace std;

class Array
{
private:
    int size;
    int length;
    int* items;

public:
    Array(int arrsize)
    {
        size = arrsize;
        length = 0;
        items = new int(arrsize);
    }
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
}


int main()
{
    count << "Hello This is Array ADT demoin";
} 
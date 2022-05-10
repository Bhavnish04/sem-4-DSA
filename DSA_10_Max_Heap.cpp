#include<iostream>
using namespace std;

class Heap
{
    public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1; 
        size = 0;
    }

    void insert(int key)
    {
        // Insert Element at the end
        size++;
        arr[size] = key;

        int i = size;

        while(i > 1)
        {
            // Find Parent's Index
            int parent  = i/2;
            
            // Compare with Parent
            if(arr[parent] < arr[i])
            {
                swap(arr[parent], arr[i]);
                i = parent;
            }
            else
                return;
        }
    }

    void deleteFromRoot()
    {
        if(size == 0)
        {
            cout<<"Nothing to Delete..."<<endl;
            return; 
        }

        // Replace with Last Element
        arr[1] = arr[size];

        // Remove Last Element
        size--;


        int i = 1;
        while(i < size)
        {
            int leftchildindex = 2 * i;
            int rightchildindex = 2 * i + 1;

            if(leftchildindex < size && arr[i] < arr[leftchildindex])
            {
                swap(arr[i], arr[leftchildindex]);
                i = leftchildindex;
            }
            else if(rightchildindex < size && arr[i] < arr[rightchildindex])
            {
                swap(arr[i], arr[rightchildindex]);
                i = rightchildindex;
            }
            else
                return;
        }
    }

    void print()
    {
        for(int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

void heapify(int *arr, int size, int i)
{
    int largest = i;

    int leftchildindex = 2*i;
    int rightchildindex = 2*i + 1;

    if(leftchildindex <= size && arr[largest] < arr[leftchildindex])
    {
        largest = leftchildindex;        
    }
    
    if(rightchildindex <= size && arr[largest] < arr[rightchildindex])
    {
        largest = rightchildindex;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}


int main()
{
    Heap h;
    h.insert(58);
    h.insert(76);
    h.insert(67);
    h.insert(90);
    h.insert(56);
    h.insert(44);
    h.insert(72);
    h.insert(13);

    h.print();

    h.deleteFromRoot();

    h.print();

    int arr[9] = {-1, 58, 76, 67, 90, 56, 44, 72, 13};
    int n = 9;

    // In CBT Nodes from n/2 to n are all leaf nodes and the leaf node being a single entity by default follows
    // the heap rule. So we have to just check from n/2 to 1st node.

    for(int i = n/2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for(int i = 1; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
#include<iostream>
using namespace std;

void heapify(int *arr, int size, int i)
{
    int largest = i;
    int leftchild = 2*i;
    int rightchild = 2*i + 1;

    if(leftchild < size && arr[largest] < arr[leftchild])
    {
        largest = leftchild;
    }

    if(rightchild < size && arr[largest] < arr[rightchild])
    {
        largest = rightchild;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

void HeapSort(int *arr, int n)
{
    int size = n;

    while(size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int len = 6;

    // Converting Array to Heap
    for(int i = len/2; i > 0; i--)
    {
        heapify(arr, len, i);
    }

    cout<<"Heapified Array: ";

    for(int i = 1; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<len<<endl;
    // Heap Sort

    HeapSort(arr, len);
    cout<<len<<endl;

    cout<<"Sorted Array: ";

    for(int i = 1; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;




    return 0;
}
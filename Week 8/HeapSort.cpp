#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    // In max heap, Valid parent must be lager than its children.

    // initialize parent as largest
    int largestIndex = root;
    int leftChildIndex = 2 * root + 1;
    int rightChildIndex = 2 * root + 2;

    // if left child is larger than parent
    if (leftChildIndex < n && arr[leftChildIndex] > arr[largestIndex])
        // left child is the largest for now
        largestIndex = leftChildIndex;

    // if right child is larger than both left and parent
    if (rightChildIndex < n && arr[rightChildIndex] > arr[largestIndex])
        // right child is the largest
        largestIndex = rightChildIndex;

    // if parent is valid ( parent is the largest)
    if(largestIndex==root) return;

    // if parent is not valid
    swap(arr[root], arr[largestIndex]);

    // now parent has moved to one of its child's location
    // check the validity of the parent in new position
    heapify(arr, n, largestIndex);

}


// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap

    // for a give array, validity of the parents should be checked
    // parents must be lager than its children.
    // heapify only the parents.

    int smallestParentIndex = (n/2) -1;

    // iterating through the parents
    for (int i = smallestParentIndex; i >= 0; i--) {
        // make them valid
        heapify(arr, n, i);
    }


    // extracting elements from heap one by one


    // In a max heapified array first element is the largest

    for (int i = n - 1; i > 0; i--) {

        //swapping first element with its sorted position.
        swap(arr[0], arr[i]);

        // heapify again to get the next largest value as the first element of the array
        heapify(arr, i, 0);
    }

}

/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main()
{
    /* Here input is getting as a string and convert and store it
      as int by using string stream and vector array.
      Then vector array is being copied to a normal array */

    string input;
    cout<<"Input Array :";
    getline(cin, input);

    vector<int> arr;
    int number;
    stringstream ss(input);
    while (ss >> number)
        arr.push_back(number);

    int arrSize = arr.size();

    int heap_arr[arrSize];
    copy(arr.begin(), arr.end(), heap_arr);

    cout<<"\nYou have input"<<endl;

    displayArray(heap_arr,arrSize);
    heapSort(heap_arr, arrSize);

    cout << "\nSorted array"<<endl;
    displayArray(heap_arr, arrSize);
}
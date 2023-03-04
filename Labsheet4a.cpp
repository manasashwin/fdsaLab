#include <iostream> 
#include "timer.h"
using namespace std;



bool isSortedRecursive(int *arr, int n, int idx)
{
    
    
    // base case
    if (idx >= n)
        return true;

    // Case 1: Compare with item to the Left
    if (arr[idx] < arr[idx - 1])
        return false;

    // Case 2: Compare with item to the right 
    if (idx < n - 1 && arr[idx] > arr[idx + 1])
        return false;   

// recur for the remaining items 
    return isSortedRecursive (arr, n, idx + 2);
}

bool isSorted(int *arr, int n){

    return isSortedRecursive(arr, n, 1);
}

int main(){
    Timer* timer = new Timer();
    int n;
    cout << "ENTER THE SIZE OF THE ARRAY";
    cin >> n;
    int *arr = new int[n];

    cout << "ENTER " << n << " ELEMENTS";
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    timer->start();
    if (isSorted(arr, n)){
        cout << "SORTED";
    }
    else {
        cout << "NOT SORTED";
    }
    timer->stop();
    cout << "THE TIME TAKEN IS " << timer->getDurationInMilliSeconds();
    return 1; 
}
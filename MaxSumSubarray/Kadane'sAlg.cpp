
/*
Kadane’s algorithm looks for all contiguous segments of an array, 
and keeps track of the maximum sum of contiguous segment among all segments 
*/

#include <iostream>
using namespace std;

//will return zero if array contains no positive elements
int max_sum_positives(int arr[], int size){
    int maxSoFar = 0;
    int currentSum = 0;

    for (int i = 0; i < size; i++){
        currentSum += arr[i];
        if (currentSum > maxSoFar){
            maxSoFar = currentSum;
        }
        if (currentSum < 0){
            currentSum = 0;
        }
    }    
    return maxSoFar;
}
//disallows empty subarrays, returns value of largest element, the least negative val
int max_sum_any(int arr[], int size){
    int maxSoFar = -99999999;
    int currentSum = 0;

    for (int i = 0; i < size; i++){
        currentSum += arr[i];
        currentSum = (arr[i] > currentSum) ? arr[i]: currentSum;
        //currentSum = max(arr[i], currentSum + arr[i]); also works
        if (currentSum > maxSoFar){
            maxSoFar = currentSum;
        }

    }    
    return maxSoFar;
}

int main(int argc, char const *argv[])
{
    const int SIZE = 8;
    int arr[SIZE] = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "Only Positives: " << max_sum_positives(arr, SIZE) << endl;
    cout << "Any: " << max_sum_any(arr, SIZE) << endl;

    return 0;
}

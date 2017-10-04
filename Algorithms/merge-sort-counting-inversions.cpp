#include <bits/stdc++.h>

using namespace std;

long long merge(vector <int> &arr, int low, int high)
{
    // Create relevant counting indices
    int middle = (low + high) / 2;
    long long numSwaps = 0;
    int i = low;
    int j = middle + 1;
    int k = 0;
    
    // Create placeholder array to hold new array values before we copy them over
    int placeholder[high - low + 1];
    
    // Merge
    while (i <= middle && j <= high)
    {
        if (arr[j] < arr[i])
        {
            numSwaps += (middle - i) + 1; // Incremented by the number of remaining elements in left/low half
            placeholder[k] = arr[j];
            j++;
        }
        else
        {
            placeholder[k] = arr[i];
            i++;
        }
        k++;
    }
    
    // Add any remaining values in both halves to placeholder
    while (i <= middle)
    {
        placeholder[k] = arr[i];
        i++;
        k++;
    }
    
    while (j <= high)
    {
        placeholder[k] = arr[j];
        j++;
        k++;
    }
    
    // Copy placeholder contents into output array
    k = 0;
    for (int m = low; m <= high; m++)
    {
        arr[m] = placeholder[k];
        k++;
    }
  
    return numSwaps;
}

long long merge_sort_and_count_swaps(vector <int> &arr, int low, int high)
{
    // Divide: Get middle point
    int middle = (low + high) / 2;
    long long numSwaps = 0;
    
    // Base case: one element array is already sorted -> no swaps required
    if (low >= high)
        return 0;
    else
    {
        // Conquer: recursively split the array
        numSwaps += merge_sort_and_count_swaps(arr, low, middle); // Left Inversions
        numSwaps += merge_sort_and_count_swaps(arr, middle + 1, high); // Right Inversions
        
        // Merge
        numSwaps += merge(arr, low, high); // Split Inversions 
    }
    return numSwaps;
}


long long countInversions(vector <int> &arr) {
    
    // No swaps required if it's already sorted
    if (is_sorted(arr.begin(), arr.end()))
        return 0;
    
    // Merge sort
    return merge_sort_and_count_swaps(arr, 0, arr.size() - 1);
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        long long result = countInversions(arr);
        cout << result << endl;
    }
    return 0;
}
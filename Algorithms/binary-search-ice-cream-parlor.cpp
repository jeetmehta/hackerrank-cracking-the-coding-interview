#include <bits/stdc++.h>
using namespace std;

class IceCream {
    
    public: 
        int cost; 
        int index;

        IceCream(int cost, int index) {
            this->cost = cost;
            this->index = index;
       }
};

bool compare(IceCream a, IceCream b)
{
    if (a.cost == b.cost)
        return a.index < b.index;
    return a.cost < b.cost;
}
    
int binarySearch(int first, int last, vector<IceCream> arr, int search)
{   
    // Base case: make sure array can still be halved
    if (first <= last)
    {
        int middle = (first + last) / 2;
            
        // Base case: found search value @ current point
        if (arr[middle].cost == search)
            return arr[middle].index;
        
        // Check left half
        if (search < arr[middle].cost)
            return binarySearch(first, middle-1, arr, search);
        
        // Check right half
        else if (search > arr[middle].cost)
            return binarySearch(middle+1, last, arr, search);
    }
    return -1;
}

int main() {
    int t;
    int n, m;
    cin >> t;
    for(int test = 0; test < t; test++) {       
        cin >> m >> n;
        vector<IceCream> arr;
        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }
        sort(arr.begin(), arr.end(), compare);
        int firstIndex = 100000, secondIndex = 100000;
        for(int i = 0; i < n - 1 ; i++) {
            int search = m - arr[i].cost;
            if(search >= arr[i].cost) {
                int index = binarySearch(i + 1, n - 1, arr, search);
                if( index != -1 ) {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                    break;
                }
            }
        }
    }
}
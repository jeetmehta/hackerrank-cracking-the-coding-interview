#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void swap(vector <int> &a, int a_idx, int b_idx)
{
    int temp = a[a_idx];
    a[a_idx] = a[b_idx];
    a[b_idx] = temp;
}

void bubble_sort(vector <int> &a, int n)
{
    int swap_count = 0;
    for (int i = 0; i < n; i++)
    {
        int numSwaps = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] > a[j+1] && j != (n-1))
            {
                swap(a, j, j+1);
                swap_count++;
                numSwaps++;
            }
        }
        
        if (numSwaps == 0)
            break;
    }
    cout << "Array is sorted in " << swap_count << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n-1] << endl;
}


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    bubble_sort(a, n);
    return 0;
}
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

int num_methods(int n, int storage[37])
{
    if (storage[n] == 0)
    {
        storage[n] = num_methods(n-3, storage) + num_methods(n-2, storage) + num_methods(n-1, storage);
    }
    return storage[n];
}


int main(){
    int s;
    cin >> s;
    
    int storage[37] = {0};
    storage[0] = 0;
    storage[1] = 1;
    storage[2] = 2;
    storage[3] = 4;
    
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        cout << num_methods(n, storage) << endl;
    }
    return 0;
}
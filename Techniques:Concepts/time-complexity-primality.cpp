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

bool checkPrimality(int n)
{
    // 1 or less is not a prime
    if (n <= 1)
        return false;
    
    // 2 and 3 are both primes
    else if (n <= 3)
        return true;
    else
    {
        // Only need to check upto the square root
        for (int i = 2; i <= (sqrt(n) + 1); i++)
        {
            if (n%i == 0)
                return false;
        }
        return true;
    }
    return true;
}

int main(){
    int p;
    cin >> p;
    for(int a0 = 0; a0 < p; a0++){
        int n;
        cin >> n;
        if (checkPrimality(n))
            cout << "Prime" << endl;
        else
            cout << "Not prime" << endl;
    }
    return 0;
}
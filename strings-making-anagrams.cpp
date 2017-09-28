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

int number_needed(string a, string b) {
    auto count = 0;
    vector<int> freq(26, 0);
    for (auto c : a) { ++freq[c - 'a']; }
    for (auto c : b) { --freq[c - 'a']; }
    for (auto val : freq) { count += abs(val); }
    return count;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
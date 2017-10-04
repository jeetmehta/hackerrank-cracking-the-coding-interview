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

// Bounds checking: make sure indices are within the grid
bool checkBounds(vector <vector <int> > grid, int x, int y)
{
    return (x >= 0) && (x < grid.size()) && (y >= 0) && (y < grid[0].size());
}

// Performs graph search until connected region ends
int graph_search(vector <vector <int>> graph, stack <pair <int, int>> &visit, map <pair <int, int>, int> &visited_nodes)
{
    // Base case: no more children to visit
    if (visit.empty())
        return 0;
    
    // Get current node from stack
    pair <int, int> current = visit.top();
    visit.pop();
    
    // Store current node's coordinates and mark it as visited in the hash table
    int x = current.first;
    int y = current.second;
    visited_nodes.insert(make_pair(current, graph[x][y]));
    
    // Base case: value @ current node = 0
    if (!graph[x][y])
        return 0;
    
    // Initialize region size
    int region = 1;
   
    // Run graph search recursively on 8 possible children/adjascent nodes
    if (checkBounds(graph, x, y-1) && graph[x][y-1] && visited_nodes.find(make_pair(x,y-1)) == visited_nodes.end())
    {
        visit.push(make_pair(x,y-1));
        region += graph_search(graph, visit, visited_nodes);
    }
    
    if (checkBounds(graph, x, y+1) && graph[x][y+1] && visited_nodes.find(make_pair(x,y+1)) == visited_nodes.end())
    {
        visit.push(make_pair(x,y+1));
        region += graph_search(graph, visit, visited_nodes);
    }
    
    if (checkBounds(graph, x-1, y-1) && graph[x-1][y-1] && visited_nodes.find(make_pair(x-1,y-1)) == visited_nodes.end())
    {
        visit.push(make_pair(x-1,y-1));
        region += graph_search(graph, visit, visited_nodes);
    }
    
    if (checkBounds(graph, x-1, y) && graph[x-1][y] && visited_nodes.find(make_pair(x-1,y)) == visited_nodes.end())
    {          
        visit.push(make_pair(x-1,y));
        region += graph_search(graph, visit, visited_nodes);
    }
    
    if (checkBounds(graph, x-1, y+1) && graph[x-1][y+1] && visited_nodes.find(make_pair(x-1,y+1)) == visited_nodes.end())
    {
        visit.push(make_pair(x-1,y+1));
        region += graph_search(graph, visit, visited_nodes);
    }
    
    if (checkBounds(graph, x+1, y-1) && graph[x+1][y-1] && visited_nodes.find(make_pair(x+1,y-1)) == visited_nodes.end())
    {
        visit.push(make_pair(x+1,y-1));
        region += graph_search(graph, visit, visited_nodes);
    }
    
    if (checkBounds(graph, x+1, y) && graph[x+1][y] && visited_nodes.find(make_pair(x+1,y)) == visited_nodes.end())
    {
        visit.push(make_pair(x+1,y));
        region += graph_search(graph, visit, visited_nodes);
    }
    
    if (checkBounds(graph, x+1, y+1) && graph[x+1][y+1] && visited_nodes.find(make_pair(x+1,y+1)) == visited_nodes.end())
    {
        visit.push(make_pair(x+1,y+1));
        region += graph_search(graph, visit, visited_nodes);
    }
    return region;
}

int get_biggest_region(vector< vector<int> > grid) {

    int max_region_size = 0;
    
    // Run through each element in the grid
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            // Ignore and move on if element = 0
            if (!grid[i][j])
                break;
            
            // Initialize stack for nodes to visit, and hash map for already visited nodes
            stack <pair <int, int>> visit;
            map <pair <int, int>, int> visited_nodes;
            
            // Add current position onto the stack
            visit.push(make_pair(i,j));
            
            // Call graph search & update maximum region size if necessary
            int region_size = graph_search(grid, visit, visited_nodes);
            if (region_size > max_region_size)
                max_region_size = region_size;
        }
    }
    return max_region_size;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}
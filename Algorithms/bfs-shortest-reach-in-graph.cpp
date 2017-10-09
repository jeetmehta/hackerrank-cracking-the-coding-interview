#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

class Graph
{
    private:
        vector<int> *adj;
        int V;
    public:
        Graph(int V)
        {
            this->V = V;
            adj = new vector<int>[V];
        }

        void add_edge(int u, int v)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> shortest_reach(int start, int n)
        {
            vector<int> distances(n,-1);
            queue<int> que;
            unordered_set<int> seen;

            que.push(start);
            distances[start] = 0;

            seen.insert(start);
            while(!que.empty())
            {
                int cur = que.front();
                que.pop();
                for(int node : adj[cur])
                {
                    if (seen.find(node) == seen.end())
                    {
                        que.push(node);
                        seen.insert(node);
                        distances[node] = distances[cur] + 6;
                    }
                }
            }
            return distances;
        }
};
int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++)
    {
        // Read # of nodes
        int n, m;
        cin >> n;
        
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        
        // Read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // Add each edge to the graph
            graph.add_edge(u, v);
        }
        
        int startId;
        cin >> startId;
        startId--;
        
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId, n);
        
        // Output distances to console
        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
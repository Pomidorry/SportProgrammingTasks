#include <iostream>
#include<vector>
using namespace std;
struct E {
    int src;
    int dest;
};
struct Graph {       
    vector<vector<int>> adjList;
        Graph(vector<E> const& edges, int n)
        {
          
            adjList.resize(n);
            for (auto& edge : edges)
            {
               
                adjList[edge.src].push_back(edge.dest);
                adjList[edge.dest].push_back(edge.src);
            }
        }
        bool DFS(Graph graph, int v, vector<bool>& discovered, int parent);
    };
bool Graph::DFS(Graph graph, int v, vector<bool>& discovered, int parent) {
    discovered[v] = true;
    for (int w : graph.adjList[v])
    {
        if (!discovered[w])
        {
            if (DFS(graph, w, discovered, v)) {
                return true;
            }
        }
        else if (w != parent)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<E> edges =
    {
        {0, 1}, {0, 6}, {0, 7}, {1, 2}, {1, 5}, {2, 3},
        {2, 4}, {7, 8}, {7, 11}, {8, 9}, {8, 10}, {10, 11}
    };
    int n = 12;
    Graph graph(edges, n);
    vector<bool> discovered(n);
    if (graph.DFS(graph, 0, discovered, -1)) {
        cout << "The graph contains a cycle";
    }
    else {
        cout << "The graph doesn't contain any cycle";
    }

    return 0;

}

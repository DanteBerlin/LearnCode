#include <iostream>
#include <limits.h>
#include <vector>
#include <string>
using namespace std;

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[], vector<int> parent, int src, int V) {
    cout << "Vertex \t Distance from Source \t Shortest Path" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t\t\t" << dist[i] << " \t\t\t\t";
        vector<int> path;
        int j = i;
        while (j != src) {
            path.push_back(j);
            j = parent[j];
        }
        cout << src;
        for (int k = path.size() - 1; k >= 0; k--) {
            cout << " -> " << path[k];
        }
        cout << endl;
    }
}

void graphInput(int** graph, int V) {
    int w;
    for(int i = 0; i < V; ++i) {
        for(int j = i + 1; j < V; ++j) {
            cout << "Do you want to add the Edge between " << i << " and " << j << "?. (Y or N) ";
            char s;    
            cin >> s;
            if (s == 'y' || s == 'Y') {
                cout<<"Enter the weight: ";
                cin>>w;
                graph[i][j] = graph[j][i] = w;
            }
        }
    }
}

void dijkstra(int** graph, int src, int V) {
    int dist[V];
    bool sptSet[V];
    vector<int> parent(V, -1);
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    printSolution(dist, parent, src, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    int** graph = new int*[V];
    for (int i = 0; i < V; ++i) {
        graph[i] = new int[V];
        for (int j = 0; j < V; ++j) {
            graph[i][j] = 0;
        }
    }

    graphInput(graph, V);
    dijkstra(graph, 0, V);

    // Free dynamically allocated memory
    for (int i = 0; i < V; ++i) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}

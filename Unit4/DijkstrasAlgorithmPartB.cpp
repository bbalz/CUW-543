#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int minDistance(const std::vector<int>& dist, const std::vector<bool>& sptSet, int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

void printSolution(const std::vector<int>& dist, int V) {
    std::cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        std::cout << i << " \t\t" << dist[i] << "\n";
    }
}

void printPath(const std::vector<int>& parent, int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    std::cout << j << " ";
}

void dijkstra(const std::vector<std::vector<int>>& graph, int src, int V) {
    std::vector<int> dist(V, INF);

    std::vector<bool> sptSet(V, false);

    std::vector<int> parent(V, -1);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);

        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, V);

    std::cout << "Path from source to vertex:\n";
    for (int i = 1; i < V; i++) {
        std::cout << "Path (" << src << " -> " << i << "): ";
        printPath(parent, i);
        std::cout << " Cost: " << dist[i] << "\n";
    }
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 4, 0, 0, 3},
        {4, 0, 2, 0, 1},
        {0, 2, 0, 6, 0},
        {0, 0, 6, 0, 2},
        {3, 1, 0, 2, 0}
    };

    int V = graph.size();
    int src = 0;

    dijkstra(graph, src, V);

    return 0;
}

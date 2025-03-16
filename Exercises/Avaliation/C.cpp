#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Edge {
    int u, v, cost;
    bool operator<(const Edge &other) const {
        return cost < other.cost;
    }
};

int n, m, k;
vector<Edge> edges;
int parent[12], treeRank[12], degree[12];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return false;
    if (treeRank[rootX] > treeRank[rootY]) {
        parent[rootY] = rootX;
    } else if (treeRank[rootX] < treeRank[rootY]) {
        parent[rootX] = rootY;
    } else {
        parent[rootY] = rootX;
        treeRank[rootX]++;
    }
    return true;
}

int kruskal() {
    sort(edges.begin(), edges.end());
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        treeRank[i] = 0;
        degree[i] = 0;
    }

    int cost = 0, edgesUsed = 0;
    for (auto &edge : edges) {
        if (edgesUsed == n - 1) break;
        if (degree[edge.u] < k && degree[edge.v] < k && unionSet(edge.u, edge.v)) {
            cost += edge.cost;
            degree[edge.u]++;
            degree[edge.v]++;
            edgesUsed++;
        }
    }
    return (edgesUsed == n - 1) ? cost : -1;
}

int main() {
    while (cin >> n >> m >> k) {
        edges.clear();
        for (int i = 0; i < m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            edges.push_back({u - 1, v - 1, c});
        }
        
        int result = kruskal();
        if (result == -1)
            cout << "NO WAY!" << endl;
        else
            cout << result << endl;
    }
    return 0;
}

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
 
using namespace std;
 
int main() {
   // ios_base::sync_with_stdio(0);
 
    int u, v;
    cin >> u >> v;
 
    int n, m;
    cin >> n >> m;
 
    map<int, vector<pair<int, int>>> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
 
        edges[a].push_back(make_pair(c, b));
    }
 
    vector<int> dist(n + 1, 1000000000);
    dist[u] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int u = 1; u <= n; u++) {
            for (size_t j = 0; j < edges[u].size(); j++) {
                int v = edges[u][j].second;
                int d = edges[u][j].first;
 
                dist[v] = min(dist[v], dist[u] + d);
            }
        }
    }
 
    for (int u = 1; u <= n; u++) {
        for (size_t j = 0; j < edges[u].size(); j++) {
            int v = edges[u][j].second;
            int d = edges[u][j].first;
 
            if (dist[v] > dist[u] + d) {
                cout << "TIDAK\n";
 
                return 0;
            }
        }
    }
 
    cout << "BISA\n";
}
#include <iostream>
#include <queue>

using namespace std;

const int inf = 1e9;

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    
    vector<vector < pair<int,int> >> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int s;
    cin >> s;

    vector <int> dist(n + 1, inf);
    priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    dist[s] = 0;
    pq.push({dist[s], s});
    vector<int> visited(n + 1);
    while(pq.size()){
        pair<int,int> p = pq.top();
        pq.pop();
        int v = p.second, d = p.first;
        if(visited[v]) continue;
        // cout << v << " ";
        visited[v] = 1;
        for(pair<int,int> edge : adj[v]){
            int u = edge.second, w = edge.first;
            if(dist[u] > d + w){
                dist[u] = d + w;
                pq.push({dist[u], u});
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     cout << dist[i] << " ";
    // }
    // cout << "\n";
}
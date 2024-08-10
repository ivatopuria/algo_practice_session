#include <iostream>
#include <queue>

using namespace std;

int n, m;

int s;

vector<int> adj[10000];

int level[10000];

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v),adj[v].push_back(u);
	}

	cin >> s;

	for(int i = 1; i <= n; i++){
		level[i] = -1;
	}
	level[s] = 0;
	queue<int> que;
	que.push(s);
	while(que.size()){
		int v = que.front();
		que.pop();
		for(auto u : adj[v]){
			if(level[u] == -1){
				level[u] = level[v] + 1;
				que.push(u);
			}
		}
	}

	for(int i = 1; i <= n; i++){
		cout << level[i]<<" ";
	}
	cout << "\n";
}
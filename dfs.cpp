#include <iostream>
#include <queue>

using namespace std;

int n, m;

vector<int> adj[10000];

int visisted[10000];

int dfs(int v){
	visisted[v] = 1;
	int answer = 0;
	for(auto u : adj[v]){
		if(visisted[u]) continue;
		answer = max(answer, dfs(u) + 1);
	}
	return answer;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v),adj[v].push_back(u);
	}
	int answer = dfs(1);
	cout << answer << "\n";
}
#include <iostream>
#include <map>
#include <queue>

using namespace std;

const int inf = 1e9;

int n, k;

vector<int> heights;

vector<bool> visited;

vector<int> minimum_total_cost;

int recurse(int i){
    if(i == n - 1){
        return 0;
    }
    if(visited[i]){
        return minimum_total_cost[i];
    }
    visited[i] = 1;
    minimum_total_cost[i] = inf;
    for(int j = 1; j <= k; j++){
        if(i + j >= n) break;
        minimum_total_cost[i] = min(minimum_total_cost[i], recurse(i + j) + abs(heights[i] - heights[i + j]));
    }
    return minimum_total_cost[i];
}

int main(){
    cin >> n >> k;

    heights.resize(n);
    visited.resize(n);
    minimum_total_cost.resize(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }

    recurse(0);

    cout << minimum_total_cost[0] << "\n";
}
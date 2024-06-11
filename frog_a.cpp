#include <iostream>
#include <map>
#include <queue>

using namespace std;

const int inf = 1e9;

int n;

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
    if(i + 1 < n){
        int total_cost = recurse(i + 1);
        total_cost += abs(heights[i] - heights[i + 1]);
        minimum_total_cost[i] = min(minimum_total_cost[i], total_cost);
    }
    if(i + 2 < n){
        int total_cost = recurse(i + 2);
        total_cost += abs(heights[i] - heights[i + 2]);
        minimum_total_cost[i] = min(minimum_total_cost[i], total_cost);
    }
    return minimum_total_cost[i];
}

int main(){
    cin >> n;

    heights.resize(n);
    visited.resize(n);
    minimum_total_cost.resize(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }

    recurse(0);

    cout << minimum_total_cost[0] << "\n";
}
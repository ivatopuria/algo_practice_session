class Solution {
public:
    const int inf = 1e9;
    vector <bool> visited;
    vector <int> minimum_total_cost;
    vector<int> global_cost;
    int recurse(int n){
        if(n <= 1){
            return 0;
        }
        if(visited[n]){
            return minimum_total_cost[n];
        }
        visited[n] = 1;
        int val = inf;
        if(n - 1 >= 0){
            val = min(val, recurse(n - 1) + global_cost[n - 1]);
        }
        if(n - 2 >= 0){
            val = min(val, recurse(n - 2) + global_cost[n - 2]);
        }
        minimum_total_cost[n] = val;
        return minimum_total_cost[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        global_cost = cost;
        int n = cost.size();
        visited.resize(n + 2);
        minimum_total_cost.resize(n + 2);
        return recurse(n);
    }
};
class Solution {
public:
    vector <bool> visited;
    vector <int> number_of_ways;
    int recurse(int n){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return 0;
        }
        if(visited[n]){
            return number_of_ways[n];
        }
        visited[n] = 1;
        number_of_ways[n] = recurse(n - 1) + recurse(n - 2); 
        return number_of_ways[n];
    }
    int climbStairs(int n) {
        visited.resize(n + 1);
        number_of_ways.resize(n + 1);
        return recurse(n);
    }
};
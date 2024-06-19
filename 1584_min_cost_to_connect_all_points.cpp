struct disjoint_set_union{
    vector <int> label;
    vector <vector<int>> components;
    void initilize(int n){
        label = vector <int>(n);
        components = vector<vector<int>>(n);
        for(int i = 0; i < n; i++){
            label[i] = i;
            components[i].push_back(i);
        }
    }
    bool merge(int x, int y){
        if(label[x] == label[y]){
            return true;
        }
        x = label[x], y = label[y];
        if(components[x].size() < components[y].size()){
            swap(x, y);
        }
        for(auto vertex : components[y]){
            components[x].push_back(vertex);
            label[vertex] = x;
        }
        components[y].clear();
        return false;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector <pair<int,pair<int,int>>> edges;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());

        disjoint_set_union union_find;
        union_find.initilize(n);
        int minimum_total_cost = 0;
        for(int i = 0; i < edges.size(); i++){
            int w = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if(union_find.merge(u, v) == 0){
                minimum_total_cost += w;
            }
        }
        return minimum_total_cost;
    }
};
#include <iostream>
#include <cstring>
using namespace std;

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
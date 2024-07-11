#include <bits/stdc++.h>

using namespace std;


struct trie{
    struct Info{
        int adj[2]{0};
    };
    vector<Info> vertices = {Info{}};
    void insert(string s){
        int current_vertex = 0;
        for(auto ch : s){
            // cout << current_vertex << " " << ch - '0' << "\n";
            int next_vertex = vertices[current_vertex].adj[ch - '0'];
            if(next_vertex != 0){
                current_vertex = next_vertex;
            }else{
                next_vertex = vertices.size();
                vertices.push_back(Info{});
                vertices[current_vertex].adj[ch - '0'] = next_vertex;
                current_vertex = next_vertex;
            }
        }
    }
};

class Solution {
public:
    trie my_trie;
    string x;
    int find_maximum(int i, int current_vertex){
        if(i == x.size()){
            return 0;
        }
        int val = x[i] - '0';
        int need = 0;
        if(val == 0){
            need = 1;
        }else{
            need = 0;
        }
        int next_vertex = my_trie.vertices[current_vertex].adj[need];
        int next_vertex1 = my_trie.vertices[current_vertex].adj[need ^ 1];
        if(next_vertex != 0){
            return find_maximum(i + 1, next_vertex) + (1 << (30 - i));
        }else{
            return find_maximum(i + 1, next_vertex1);
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        for(int i = 0; i < n; i++){
            int v = nums[i];
            x = "";
            while(v > 0){
                x += (char)((v % 2) + '0');
                v /= 2;
            }
            while(x.size() < 31){
                x.push_back('0');
            }
            reverse(x.begin(), x.end());
            my_trie.insert(x);
            answer = max(answer, find_maximum(0, 0));
        }
        return answer;
    }
};

int main(){
    Solution sol;
    vector<int> nums={3,10,5,25,2,8};
    sol.findMaximumXOR(nums);
}
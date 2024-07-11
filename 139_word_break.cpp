#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct trie{
    struct Info{
        int ends_here = 0;
        int counter = 0;
        int adj[26]{0};
    };
    vector<Info> vertices = {Info{}};
    void insert(string s){
        int current_vertex = 0;
        for(auto ch : s){
            int next_vertex = vertices[current_vertex].adj[ch - 'a'];
            // 'a' == 0
            // 'b' == 1
            // 'c' == 2
            // ...
            if(next_vertex != 0){
                current_vertex = next_vertex;
            }else{
                next_vertex = vertices.size();
                vertices.push_back(Info{});
                vertices[current_vertex].adj[ch - 'a'] = next_vertex;
                current_vertex = next_vertex;
            }
            vertices[current_vertex].counter += 1;
        }
        vertices[current_vertex].ends_here = 1;
    }
    void erase(string s){
        int current_vertex = 0;
        for(auto ch : s){
            int next_vertex = vertices[current_vertex].adj[ch - 'a'];
            current_vertex = next_vertex;
            vertices[current_vertex].counter -= 1;
        }
    }
    // there exists string with prefix s
    bool find_prefix(string s){
        int current_vertex = 0;
        for(auto ch : s){
            int next_vertex = vertices[current_vertex].adj[ch - 'a'];
            // there doesn't exists such vertex
            if(next_vertex == 0){
                return false;
            }
            current_vertex = next_vertex;
            if(vertices[current_vertex].counter == 0){
                return false;
            }
        }
        return true;
    }
    // there exists string s
    bool find(string s){
        int current_vertex = 0;
        for(auto ch : s){
            int next_vertex = vertices[current_vertex].adj[ch - 'a'];
            // there doesn't exists such vertex
            if(next_vertex == 0){
                return false;
            }
            current_vertex = next_vertex;
            if(vertices[current_vertex].counter == 0){
                return false;
            }
        }
        int sum_of_children = 0;
        for(int i = 0; i < 26; i++){
            int next_vertex = vertices[current_vertex].adj[i];
            if(next_vertex > 0){
                sum_of_children += vertices[next_vertex].counter;
            }
        }
        if(sum_of_children < vertices[current_vertex].counter){
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int n;
    string global_s;
    trie my_trie;
    vector<int> used;
    vector<bool> dp;
    bool rec(int i){
        if(used[i]) return dp[i];
        used[i] = 1;
        int current_vertex = 0;
        for(int j = i; j < n; j++){
            char ch = global_s[j];
            int next_vertex = my_trie.vertices[current_vertex].adj[ch - 'a'];
            if(next_vertex == 0) break;
            // there is some string x in wordDict, that ends in next_vertex
            if(my_trie.vertices[next_vertex].ends_here == 1) {
                if(j == n - 1 or rec(j + 1) == 1){
                    dp[i] = 1;
                    return 1;
                }
            }
            current_vertex = next_vertex;
        }
        dp[i] = 0;
        return 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        global_s = s;
        for(auto x : wordDict){
            my_trie.insert(x);
        }
        n = s.size();
        dp = vector<bool>(n, 0);
        used = vector<int>(n, 0);
        return rec(0);
    }
};

int main(){

}
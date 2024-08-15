#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int k = words[0].size();
        int m = words.size();

        map<string,int> mp2;
        for(auto s : words){
            mp2[s] += 1;
        }

        vector<int> result;
        for(int group = 0; group < k; group++){
            vector<int> block_indices;
            for(int i = group; i < n; i += k){
                block_indices.push_back(i);
            }
            if(block_indices.size() < m) continue;
            
            map<string,int> mp;
            for(int i = 0; i < m; i++){
                string current_string = s.substr(block_indices[i], k);
                mp[current_string] += 1;
            }

            set<string> bad_keys;
            // bad_keys = {keys for which mp[key] != mp2[key]}
            for(auto [key,cnt] : mp){
                if(mp2[key] != cnt){
                    bad_keys.insert(key);
                }
            }

            if(bad_keys.empty()){
                result.push_back(block_indices[0]);
            }

            for(int i = 1; i < block_indices.size(); i++){
                // remove i - 1
                // add i + m - 1
                if(i + m - 1 == block_indices.size()) break;
                
                string before = s.substr(block_indices[i - 1], k);
                mp[before] -= 1;
                if(mp[before] == mp2[before]){
                    bad_keys.erase(before);
                }else{
                    bad_keys.insert(before);
                }
                
                string after = s.substr(block_indices[i + m - 1], k);
                mp[after] += 1;
                if(mp[after] == mp2[after]){
                    bad_keys.erase(after);
                }else{
                    bad_keys.insert(after);
                }

                if(bad_keys.empty()){
                    result.push_back(block_indices[i]);
                }
            }
        }
        return result;
    }
};
int main(){
    Solution sol;
    string s="barfoothefoobarman";
    vector<string> words={"foo","bar"};
    sol.findSubstring(s,words);
}
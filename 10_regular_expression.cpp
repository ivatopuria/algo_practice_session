#include "bits/stdc++.h"
using namespace std;
int n, m;
vector<int> adj[10000];
vector<int> visited(10000, -1);

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            // need to match s[i] 
            char x = s[i];
            for(int j = 0; j < m; j++){
                // last index was at j 
                if(!dp[i][j]) continue;
                // last one has * and I repeat that character
                if(j){
                    if(p[j] == '*' and ((i and s[i - 1] == x) or p[j - 1] == '.')){
                        // if(i == 1) cout << p[j] << "\n";
                        dp[i + 1][j] = 1;
                    }
                }
                // move to next character and match
                {
                    int j1 = j;
                    if(p[j1] == '*'){
                        j1 += 1;
                    }
                    char y = p[j1];
                    if(y == x or y == '.'){
                        // if(!i) cout << "here\n";
                        dp[i + 1][j1 + 1] = 1;
                    }
                }
                // skip next character until it has * 
                {
                    int j1 = j;
                    if(p[j1] == '*'){
                        j1 += 1;
                    }
                    while(j1 + 1 <= m and p[j1 + 1] == '*'){
                        // if(i == 0) cout << "e" << "\n";
                        if(p[j1] == '.' or p[j1] == x){
                            dp[i + 1][j1 + 1] = 1;
                        }
                        j1 += 2;
                    }
                    // if(i + 1 == n and j1 == m){
                    //     return true;
                    // }
                    if(j1 <= m and p[j1] == '.' or p[j1] == x){
                        // if(i + 1 == n) cout << j << "\n";
                        dp[i + 1][j1 + 1] = 1;
                    }
                }
            }  
        }
        if(dp[n][m]) return true;
        int j = m - 1;
        while(j >= 0 and p[j] == '*'){
            // cout << j << "\n";
            if(dp[n][j]) return true;
            j -= 2;
        }
        if(j >= 0 and dp[n][j + 1]) return true;
        return false;
    }
};

int main(){
    Solution sol;
    bool e=sol.isMatch("a","ab*");
    cout<<e<<"\n";
}
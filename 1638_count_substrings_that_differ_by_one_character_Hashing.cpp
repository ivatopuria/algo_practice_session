#include <iostream>
#include <vector>
#include <map>

using namespace std;

// a^k mod m
int binary_exponentiation(int a, int k, int m){
    if(k == 0){
        return 1 % m;
    }else if(k == 1){
        return a % m;
    }else{
        long long x = binary_exponentiation(a, k / 2, m);
        long long ret = (x * x) % m;;
        if(k % 2){
            ret = (ret * a) % m;
        }
        return ret % m;
    }
}

struct rolling_hash{
    const int p = 50331653;
    const int m = 1610612741;
    const int p1 = 12289;
    const int m1 = 1000000007;
    vector<pair<long long, long long>> hash;
    vector<long long> power, power1;
    void prepare(string s){
        int n = s.size();
        power.push_back(1);
        power1.push_back(1);
        for(int i = 0; i < n; i++){
            power.push_back((power.back() * p) % m);
            power1.push_back((power1.back() * p1) % m1);
        }
        long long prefix_hash_sum = 0;
        long long prefix_hash_sum1 = 0;
        for(int i = 0; i < n; i++){
            long long x = s[i] - 'a' + 1;
            x = (x * power[i]) % m;
            prefix_hash_sum = (prefix_hash_sum + x) % m;
            long long x1 = s[i] - 'a' + 1;
            x1 = (x1 * power1[i]) % m1;
            prefix_hash_sum1 = (prefix_hash_sum1 + x1) % m1;
            hash.push_back({(int)(prefix_hash_sum), (int)(prefix_hash_sum1)});
        }
    }
    pair<int,int> get_hash(int l, int r){
        long long result = hash[r].first;
        if(l > 0){
            result -= hash[l - 1].first;
            result += m;
            result %= m;
        }
        long long inv_p = binary_exponentiation(power[l], m - 2, m);
        result = (result * inv_p) % m;
        long long result1 = hash[r].second;
        if(l > 0){
            result1 -= hash[l - 1].second;
            result1 += m1;
            result1 %= m1;
        }
        long long inv_p1 = binary_exponentiation(power1[l], m1 - 2, m1);
        result1 = (result1 * inv_p1) % m1;
        return {(int)(result), (int)(result1)};
    }
};

class Solution {
public:
    int countSubstrings(string s, string t) {
        rolling_hash HashT;
        HashT.prepare(t);
        map<pair<int,int>, int> mp;
        for(int i = 0; i < t.size(); i++){
            for(int j = i; j < t.size(); j++){
                mp[HashT.get_hash(i, j)] += 1;
            }
        }
        rolling_hash HashS;
        HashS.prepare(s);
        int answer = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                // considering substring [i ... j]
                pair<int,int> p = HashS.get_hash(i, j);
                long long x = p.first;
                long long x1 = p.second;
                for(int k = i; k <= j; k++){
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        if(s[k] == ch){
                            continue;
                        }
                        long long val = (s[k] - 'a' + 1) * HashS.power[k - i];
                        val %= HashS.m;
                        long long new_x = (x - val + HashS.m) % HashS.m;
                        new_x += ((ch - 'a' + 1) * HashS.power[k - i]) % HashS.m;
                        new_x %= HashS.m;
                        long long val1 = (s[k] - 'a' + 1) * HashS.power1[k - i];
                        val1 %= HashS.m1;
                        long long new_x1 = (x1 - val1 + HashS.m1) % HashS.m1;
                        new_x1 += ((ch - 'a' + 1) * HashS.power1[k - i]) % HashS.m1;
                        new_x1 %= HashS.m1;
                        if(mp.find({new_x, new_x1}) != mp.end()){
                            answer += mp[{new_x, new_x1}];
                        }
                    }
                }
            }
        }
        // cout << answer << "\n";
        return answer;
    }
};

int main(){
    Solution sol;
    string s = "bbbbcbbababbcabbccaaaaacccbcccbabaacbbccbabbcaccbcbbbabaabbcabbccaa";
    string t = "bcabbcbcbacaccaababaaacaabaacccccabcacacbbacabbbcccabaabbbbaacaabbc";
    sol.countSubstrings(s, t);
}
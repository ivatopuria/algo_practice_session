class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        pq.push(1);
        // n = n + 1;
        long long answer = -1;
        map<long long,long long> mp;
        while(pq.size() and n > 0){
            long long root = pq.top();
            pq.pop();
            // cout << root << "\n";
            answer = root;
            if(mp.find(root * 2) == mp.end()){
                mp[root * 2] = 1;
                pq.push(root * 2);
            }
            if(mp.find(root * 3) == mp.end()){
                mp[root * 3] = 1;
                pq.push(root * 3);
            }
            if(mp.find(root * 5) == mp.end()){
                mp[root * 5] = 1;
                pq.push(root * 5);
            }
            n -= 1;
        }
        return answer;
    }
};
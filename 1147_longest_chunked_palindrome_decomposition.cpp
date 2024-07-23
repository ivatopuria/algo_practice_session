class Solution {
public:
    string global_text;
    int rec(int n){
    	if(n == 0){
    		return 0;
    	}
        int ctr = (global_text.size() - 1) / 2;
        // a a a a
        // 0 1 2 3
        // a a a a a
        // 0 1 2 3 4
        // * *          * *
        int x = (global_text.size() - n) / 2;
        int i = x;
        int j = global_text.size() - 1 - x;
        // cout << x << " " <<global_text.substr(i, j - i + 1) << "\n";
        for(int k = j; k > ctr; k--){
            int len = j - k + 1;
            if(global_text.substr(i, len) == global_text.substr(k, len)){
                return 2 + rec(n - 2 * len);
            }
        }
        return 1;
    }
    int longestDecomposition(string text) {
        global_text = text;
        return rec(text.size());
    }
};
class Solution {
public:
    vector < vector<int> > answer;
    void recursion(vector <int>& choice, int i, int n, int k){
        if(choice.size() == k){
            answer.push_back(choice);
            return;
        }
        if(i > n){
            return;
        }
        choice.push_back(i);
        recursion(choice, i + 1, n, k);
        choice.pop_back();
        recursion(choice, i + 1, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector <int> choice;
        recursion(choice, 1, n, k);
        return answer;
    }
};
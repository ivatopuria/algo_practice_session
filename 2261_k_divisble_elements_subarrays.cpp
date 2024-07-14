struct trie{
	struct Info{
		int counter = 0;
		map<int,int> adj;
	};
	vector<Info> vertices = {Info{}};
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        trie my_trie;
        for(int i = 0; i < n; i++){
            int current_vertex = 0;
            int cnt = 0;
            for(int j = i; j < n; j++){
                int v = nums[j];
                if(v % p == 0){
                    cnt += 1;
                }
                if(cnt > k){
                    break;
                }
                int next_vertex = 0;
                if(my_trie.vertices[current_vertex].adj.find(v) != my_trie.vertices[current_vertex].adj.end()){
                   next_vertex = my_trie.vertices[current_vertex].adj[v];
                }else{
                    next_vertex = my_trie.vertices.size();
                    my_trie.vertices[current_vertex].adj[v] = next_vertex;
                    my_trie.vertices.push_back({});
                }
                current_vertex = next_vertex;
            }
        }
        return (int)(my_trie.vertices.size()) - 1;
    }
};
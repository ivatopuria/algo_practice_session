#include <iostream>
#include <vector>
using namespace std;

struct trie{
	struct Info{
		int counter = 0;
		unordered_map<int,int> adj;
	};
	vector<Info> vertices = {Info{}};
	void insert(string s){
		int current_vertex = 0;
		for(auto ch : s){
			int next_vertex = vertices[current_vertex].adj[ch - 'a'];
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

int main(){
	trie my_trie;
	while(true){
		string operation, s;
		cin >> operation;
		if(operation == "insert"){
			cin >> s;
			my_trie.insert(s);
		}else if(operation == "erase"){
			cin >> s;
			my_trie.erase(s);
		}else{
			cin >> s;
			cout << my_trie.find(s) << "\n";
		}
	}
}
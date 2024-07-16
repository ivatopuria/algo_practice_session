#include <iostream>
#include <vector>

using namespace std;

struct string_hashing{
	const int p = 196613;
	const int m = 1000000007;
	int hash;
	vector<int> power;
	void prepare(int n){
		power.push_back(1);
		for(int i = 0; i < n; i++){
			power.push_back((power.back() * p) % m);
		}
	}
	int get(string s){
		int n = s.size();
		prepare(n);
		hash = 0;
		for(int i = 0; i < n; i++){
			int x = s[i] - 'a' + 1;
			x = (x * power[i]) % m;
			hash = (hash + x) % m;
		}
		return hash;
	}
};

int main(){
	string_hashing h;
	int hash = h.get("ebaa");
	int hash1 = h.get("ebaq");
	cout << hash << " " << hash1 << "\n";
}
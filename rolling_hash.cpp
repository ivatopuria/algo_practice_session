#include <iostream>
#include <vector>

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
	const int p = 196613;
	const int m = 1000000007;
	vector<int> hash;
	vector<long long> power;
	void prepare(string s){
		int n = s.size();
		power.push_back(1);
		for(int i = 0; i < n; i++){
			power.push_back((power.back() * p) % m);
		}
		long long prefix_hash_sum = 0;
		for(int i = 0; i < n; i++){
			long long x = s[i] - 'a' + 1;
			x = (x * power[i]) % m;
			prefix_hash_sum = (prefix_hash_sum + x) % m;
			hash.push_back((int)(prefix_hash_sum));
		}
	}
	int get_hash(int l, int r){
		long long result = hash[r];
		if(l > 0){
			result -= hash[l - 1];
			result += m;
			result %= m;
		}
		long long inv_p = binary_exponentiation(power[l], m - 2, m);
		result = (result * inv_p) % m;
		return (int)(result);
	}
};

int main(){
	rolling_hash H, H1;
	H.prepare("qebaaqebaa");
	H1.prepare("qqebaaq");
	cout << H.get_hash(1, 2) << " " << H.get_hash(6, 7) << "\n";
}
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
		int x = binary_exponentiation(a, k / 2, m);
		long long ret = (x * x) % m;;
		if(k % 2){
			ret = (ret * a) % m;
		}
		return ret % m;
	}
}

int main(){
	int ret = binary_exponentiation(3, 4, 7);
	cout << ret << "\n";
}
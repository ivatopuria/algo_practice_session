#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	map<int,int> cnt;
	for(int i = 0; i < n; i++){
		cnt[a[i]] += 1;
	}
	
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	
	vector<int> answer(n);
	for(int i = 0; i < a.size(); i++){
		int k = a.size() - i - 1;
		answer[k] += cnt[a[i]];
	}
	
	for(int i = 0; i < n; i++){
		cout << answer[i] << "\n";
	}
	return 0;
}
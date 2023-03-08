#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	map<int,int> used, cnt;
	priority_queue<int> pq;
	for(int i = 0; i < n; i++){
		cnt[a[i]] = cnt[a[i]] + 1;
		if(used.find(a[i]) == used.end()){
			pq.push(a[i]);
			used[a[i]] = 1;
		}
	}
	
	vector<int> answer(n);
	int k = 0;
	while(pq.size()){
		int top = pq.top();
		pq.pop();
		answer[k] += cnt[top];
		k = k + 1;	
	}
	
	for(int i = 0; i < n; i++){
		cout << answer[i] << "\n";
	}
	return 0;
}
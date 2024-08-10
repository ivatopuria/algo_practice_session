#include <bits/stdc++.h>
using namespace std;

int n;

int a[50000];

int segtree[50000];

void build(int node, int l, int r){
	// [l ... l + 1)
	if(l == r - 1){
		segtree[node] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(node * 2, l, m);
	build(node * 2 + 1, m, r);
	segtree[node] = max(segtree[node * 2], segtree[node * 2 + 1]);
}

int sum(int node, int l, int r, int interval_l, int interval_r){
	if(interval_l <= l and r <= interval_r){
		return segtree[node];
	}
	if(l >= interval_r or r <= interval_l){
		return 0;
	}
	int m = (l + r) / 2;
	int answer = 0;
	answer = max(answer, sum(node * 2, l, m, interval_l, interval_r));
	answer = max(answer, sum(node * 2 + 1, m, r, interval_l, interval_r));
	return answer;
}

void update(int node, int l, int r, int pos, int x){
	if(l == r - 1){
		segtree[node] = x;
		return;
	}
	int m = (l + r) / 2;
	if(pos < m){
		update(node * 2, l, m, pos, x);
	}else{
		update(node * 2 + 1, m, r, pos, x);
	}
	cout << " currently at node " << node << " " << " left child with value " << segtree[node * 2] << " right child with value " << segtree[node * 2 +  1] << "\n";
 	segtree[node] = max(segtree[node * 2], segtree[node * 2 + 1]);
}

int main(){
	n = 8;
	a[0] = 1;
	a[1] = 7;
	a[2] = 5;
	a[3] = 9;
	a[4] = 11;
	a[5] = 12;
	a[6] = 6;
	a[7] = 17;
	
	// [l ... r)
	build(1, 0, n);
	// [l ... r)
	int answer = sum(1, 0, n, 2, 5);
	cout << " before update " << answer << "\n";
	update(1, 0, n, 4, 1);
	update(1, 0, n, 3, 2);
	update(1, 0, n, 2, 1);
	answer = sum(1, 0, n, 2, 5);
	cout << " after update " << answer << "\n";
}
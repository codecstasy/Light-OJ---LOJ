#include<bits/stdc++.h>
#define INF 100010
using namespace std;
int tree[400000] , arr[100010];
 
void build(int ind, int lb, int ub) {
	if(lb == ub) {
		tree[ind] = arr[lb];
		return;
	}
 
	int mid = (lb + ub)/2;
	build(2*ind, lb, mid);
	build(2*ind+1, mid+1, ub);
 
	tree[ind] = min(tree[2*ind] , tree[2*ind+1]);
}
 
int query(int ind, int lb, int ub , int ql , int qr) {
	if(qr < lb || ql > ub)
		return INF;
 
	if(lb >= ql && ub <= qr)
		return tree[ind];
 
	int mid = (lb + ub)/2;
	int l = query(2*ind, lb, mid, ql, qr);
	int r = query(2*ind+1, mid+1, ub, ql, qr);
 
	return min(l, r);
}
void solve(int cs) {
	int n , q , l , r;
	cin >> n >> q;
	for(int i=1 ; i<=n ; i++)
		cin >> arr[i];
 
	build(1, 1, n);
	cout << "Case " << cs << ":" << endl;
	while(q--) {
		cin >> l >> r;
		cout << query(1, 1, n , l, r) << endl;
	}
}

int main() {
	int t, i = 1;
	cin >> t;
	while(t--) {
		solve(i++);
	}
}
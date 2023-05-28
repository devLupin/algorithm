#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<pii> v(26);

void preorder(int node) {
	char cur = node + 'A';
	cout << cur;

	if (v[node].first > 0) preorder(v[node].first);
	if (v[node].second > 0) preorder(v[node].second);
}

void inorder(int node) {
	if (v[node].first > 0) inorder(v[node].first);
	char cur = node + 'A';
	cout << cur;
	if (v[node].second > 0) inorder(v[node].second);
}

void postorder(int node) {
	if (v[node].first > 0) postorder(v[node].first);
	if (v[node].second > 0) postorder(v[node].second);
	char cur = node + 'A';
	cout << cur;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char p, l, r; cin >> p >> l >> r;
		int parent = p - 'A';
		int left = l - 'A';
		int right = r - 'A';

		v[parent] = make_pair(left, right);
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);

	return 0;
}
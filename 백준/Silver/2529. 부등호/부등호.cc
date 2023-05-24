#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> cmp, vector<char> v) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == '<' && cmp[i] > cmp[i + 1]) return false;
		if (v[i] == '>' && cmp[i] < cmp[i + 1]) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k; cin >> k;

	vector<char> v(k);
	for (int i = 0; i < k; i++)
		cin >> v[i];

	vector<int> small(k + 1);
	vector<int> big(k + 1);

	for (int i = 0; i <= k; i++) {
		small[i] = i;
		big[i] = 9 - i;
	}

	do {
		if (check(big, v)) break;
	} while (prev_permutation(big.begin(), big.end()));

	do {
		if (check(small, v)) break;
	} while (next_permutation(small.begin(), small.end()));
	
	for (int n : big) cout << n;
	cout << '\n';
	for (int n : small) cout << n;

	return 0;
}
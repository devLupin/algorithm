#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ull m = 0;
	int n;
	cin >> n;

	vector<ull> v(n);
	for(int i=0; i<n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	if(v.size() > 1 && v.size() % 2 != 0) v.pop_back();

	int i=0, j=v.size()-1;
	while(i < j) {
		m = max(v[i] + v[j], m);
		i++, j--;
	}

	cout << m;
}
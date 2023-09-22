#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin >> v[i];

	sort(v.begin(), v.end(), greater<>());
	
	double sum = v[0];
	for(int i=1; i<v.size(); i++)
		sum += (double)v[i]/2;
	
	cout << sum;
	return 0;
}
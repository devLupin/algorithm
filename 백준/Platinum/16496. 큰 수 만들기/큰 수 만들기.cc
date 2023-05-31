#include<bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b) { return a + b > b + a; };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	
	vector<string> v(n);
	for (int i = 0; i < n; i++) 
		cin >> v[i];

	sort(v.begin(), v.end(), cmp);

	if (v[0] == "0") cout << "0";
	else
		for (string s : v)
			cout << s;

	return 0;
}
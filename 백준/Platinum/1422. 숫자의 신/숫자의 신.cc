#include<bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b) { return stoi(a) > stoi(b); }
bool cmp2(const string& a, const string& b) { return a + b > b + a; };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k, n;
	cin >> k >> n;
	
	vector<string> v(n);
	for (int i = 0; i < k; i++) cin >> v[i];
	sort(v.begin(), v.begin() + k, cmp);

	for (int i = k; i < n; i++) v[i] = v[0];
	sort(v.begin(), v.end(), cmp2);

	for (string s : v)
		cout << s;
	return 0;
}
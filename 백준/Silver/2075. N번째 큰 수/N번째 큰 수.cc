#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<int> v(n * n);
	for (int i = 0; i < n * n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	cout << v[v.size() - n];
	return 0;
}
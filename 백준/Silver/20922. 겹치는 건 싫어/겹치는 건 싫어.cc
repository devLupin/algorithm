#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	unordered_map<int, int> m;
	int start = 0, end = 1, ans = 1;
	
	m[v[start]]++;
	while (end < n) {
		m[v[end]]++;
		if (m[v[end]] > k) {
			if (ans < end - start) ans = end - start;
			while (m[v[end]] > k)
				m[v[start++]]--;
		}
		end++;
	}
	if (ans < end - start) ans = end - start;
	cout << ans;
}
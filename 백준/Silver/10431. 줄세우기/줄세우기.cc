#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int TC; cin >> TC;
	while (TC--) {
		int t, arr[20], ans = 0;
		
		cin >> t;
		for (int i = 0; i < 20; i++)
			cin >> arr[i];

		for (int i = 0; i < 20; i++)
			for (int j = i+1; j < 20; j++)
				if (arr[i] > arr[j])
					ans++;

		cout << t << ' ' << ans << '\n';
	}

	return 0;
}
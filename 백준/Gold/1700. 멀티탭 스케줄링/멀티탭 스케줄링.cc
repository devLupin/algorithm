#include <bits/stdc++.h>
using namespace std;

const int SZ = 101;
int n, k, order[SZ], tap[SZ], ans;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> order[i];

	for (int i = 0; i < k; i++)
	{
		bool flag = false;

		for (int j = 0; j < n; j++)
		{
			if (tap[j] == 0)
				break;
			if (tap[j] == order[i])
			{
				flag = true;
				break;
			}
		}

		// 자리가 있으면
		for (int j = 0; j < n && !flag; j++)
		{
			if (tap[j] == 0)
			{
				flag = true;
				tap[j] = order[i];
				break;
			}
		}

		if(flag) continue;

		// 새로운 자리를 만들어야 된다면

		int idx = -1;
		int last_use = -1;
		
		for(int j=0; j<n; j++) {
			int tmp = 0;

			for(int c=i+1; c<k; c++) {
				if(order[c] == tap[j]) break;
				tmp++;
			}

			if(tmp > last_use) {
				idx = j;
				last_use = tmp;
			}
		}

		tap[idx] = order[i];
		ans++;
	}

	cout << ans;
	return 0;
}
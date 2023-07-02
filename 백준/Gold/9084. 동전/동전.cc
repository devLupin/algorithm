#include <bits/stdc++.h>
using namespace std;

const int SZ = 10005;
int TC, n, m;
int arr[SZ], DP[SZ];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> TC;
	while (TC--) {
		fill_n(&DP[0], SZ, 0);

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cin >> m;

		DP[0] = 1;  // 동전을 사용하지 않은 경우, 무조건 1
		for (int i = 0; i < n; i++)
			for (int j = arr[i]; j <= m; j++)
				DP[j] += DP[j - arr[i]];	// 동전의 가치를 뺐을 때의 경우의 수 누적
		
		cout << DP[m] << '\n';
	}
	
	return 0;
}
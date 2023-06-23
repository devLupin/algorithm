#include <bits/stdc++.h>
using namespace std;

const int SZ = 1002;
int n, arr[SZ], DP[SZ];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	for(int i=0; i<n; i++) {
		DP[i] = 1;
		for(int j=0; j<i; j++) {
			if(arr[i] > arr[j])
				DP[i] = max(DP[i], DP[j] + 1);
		}
	}

	cout << *max_element(DP, DP+n);
    return 0;
}
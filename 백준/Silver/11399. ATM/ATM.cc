#include <bits/stdc++.h>
using namespace std;

int n, arr[1000], ans;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	sort(arr, arr+n);

	for(int i=0; i<n; i++)
		for(int j=0; j<=i; j++)
			ans += arr[j];

	cout << ans;
	return 0;
}
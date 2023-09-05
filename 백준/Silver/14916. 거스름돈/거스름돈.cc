#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n, ans = 0;
	cin >> n;

	int len = n / 5;
	for(int i=len; i>=0; i--) {
		int tmp = n - 5 * i;
		if(tmp % 2 == 0) {
			ans = i + tmp / 2;
			break;
		}
	}

	if(!ans && n % 2 == 0) ans = n / 2; 

	if(ans == 0) cout << -1;
	else cout << ans;
    
    return 0;
}
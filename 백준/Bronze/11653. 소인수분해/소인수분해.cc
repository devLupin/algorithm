#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n, div=2;
    cin >> n;
	
    while(div*div <= n) {
        if(n % div == 0) {
            n /= div;
            cout << div << '\n';
        }
        else div++;
    }
    if (n != 1) cout << n;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n, div=2;
    cin >> n;
	
    while(div <= n) {
        if(n % div == 0) {
            n /= div;
            cout << div << '\n';
        }
        else div++;
    }

	return 0;
}
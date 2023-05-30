#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool num[1000001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    ll min, max;
    int cnt = 0;

    cin >> min >> max;

    for (ll i = 2; i * i <= max; i++) {
        ll n = min / (i * i);

        if (min % (i * i)) n++;

        while (n * i * i <= max) {
            num[n * i * i - min] = true;
            n++;
        }
    }

    for (int i = 0; i <= max - min; i++)
        if (!num[i]) cnt++;

	cout << cnt;
	return 0;
}
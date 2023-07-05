#include <bits/stdc++.h>
using namespace std;
using pis = pair<int, string>;

const int SZ = 1000;
int n, m, cnt[26], hamm;
string dna[SZ];
string ans;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> dna[i];

    for(int j=0; j<m; j++) {
        fill_n(&cnt[0], 26, 0);
        int mx=0;
        char mx_ch = 'A';

        for(int i=0; i<n; i++) {
            int a = ++cnt[dna[i][j] - 'A'];
            if((a == mx && dna[i][j] < mx_ch) || a > mx) {
                mx = a;
                mx_ch = dna[i][j];
            }
        }
        hamm += n - mx;
        ans += mx_ch;
    }
    
    cout << ans << '\n' << hamm;
    return 0;
}
#include <iostream>
using namespace std;

int n, A[1'000'002], a, b;
long long ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) cin >> A[i];
    cin >> a >> b;

    for(int i=0; i<n; i++) {
        A[i] -= a;
        if(A[i] > 0) {
            ans += A[i] / b;
            if(A[i] % b != 0) ans++;
        }
    }

    cout << ans + n;
    return 0;
}
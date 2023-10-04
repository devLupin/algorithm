#include<bits/stdc++.h>
using namespace std;

int N, A[100'002], D[100'002], ans;

int main()
{
    int ans = 0;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> A[i];
        D[i] = D[i-1] + A[i];
    }

    for(int i=2; i<N; i++)
        ans = max(ans, (D[i]-D[1]) + (D[N-1]-D[i-1]));

    for(int i=2; i<N; i++)
        ans = max(ans, (D[N]-D[1]-A[i]) + (D[N]-D[i]));
    
    for(int i=2; i<N; i++)
        ans = max(ans, (D[N-1]-A[i])+D[i-1]);

    cout << ans;

	return 0;
}
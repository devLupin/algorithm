#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f, SZ = 20;
int n, D[SZ][SZ], ans;
bool tmp[SZ][SZ];

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> D[i][j];

	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {
				if(i==j || j==k || i==k) continue;

				if(D[i][j] > D[i][k]+D[k][j]) { 	// 말이 안되는 경우
					cout << -1;
					return 0;
				}

				// 한번에 3개의 노드를 처리할 수 있으니, 기존 2개는 처리
				if(D[i][j] == D[i][k]+D[k][j]) tmp[i][j] = true;
			}

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			ans += (!tmp[i][j] ? D[i][j] : 0);

	// 경로가 양방향인데 양방향 모두 계산했음.
	cout << ans / 2;

	return 0;
}

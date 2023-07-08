#include <bits/stdc++.h>
using namespace std;

int n, m, k, r, c;
int note[40][40], paper[10][10];

void rotate() {
	int tmp[10][10];

	for(int i = 0; i < r; i++)
    	for(int j = 0; j < c; j++)
    		tmp[i][j] = paper[i][j];

  	for(int i = 0; i < c; i++)
    	for(int j = 0; j < r; j++)
    		paper[i][j] = tmp[r-1-j][i];

	swap(r, c);
}

bool check(int y, int x) {
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			if(note[y+i][x+j] == 1 && paper[i][j] == 1)
				return false;
	
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			if(paper[i][j] == 1)
				note[y+i][x+j] = 1;

	return true;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	while(k--) {
		cin >> r >> c;

		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				cin >> paper[i][j];

		for(int rot=0; rot<4; rot++) {
			bool is_paste = false;
			for(int y=0; y<=n-r; y++) {
				if(is_paste) break;
				for(int x=0; x<=m-c; x++) {
					if(check(y, x)) {
						is_paste = true;
						break;
					}
				}
			}
			if(is_paste) break;
			rotate();
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++)
    	for(int j = 0; j < m; j++)
			ans += note[i][j];
	
	cout << ans;
	return 0;
}
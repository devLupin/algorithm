#include <bits/stdc++.h>
using namespace std;

const int SZ = 101;
int A[SZ][SZ], B[SZ][SZ];
int N, L, ans;

bool is_road(int arr[][SZ], int x, int y) {
	int cmp = arr[x][y + 1];
	for (int j = y + 1; j < y + 1 + L; j++)
		if (arr[x][j] != cmp) return false;
	return true;
}

int solution(int arr[][SZ]) {
	int ret = 0;

	for (int x = 0; x < N; x++) {
		bool chk = true;
		int prev = 1;

        /***
        ## case 1. 값이 같은 경우
        ## case 2. 왼쪽 칸이 큰 경우
        ## case 3. 오른쪽 칸이 큰 경우
        ## case 4. 칸의 차이가 2 이상인 경우
        ***/
		for (int y = 0; y < N - 1; y++) {
			if (arr[x][y] == arr[x][y + 1]) prev++;
			else if (arr[x][y] == arr[x][y + 1] + 1) {
				if (is_road(arr, x, y)) {
					y += L - 1;
					prev = 0;
				}
				else {
					chk = false;
					break;
				}
			}
			else if (arr[x][y] + 1 == arr[x][y + 1]) {
				if (prev >= L) prev = 1;
				else {
					chk = false;
					break;
				}
			}
			else if (abs(arr[x][y] - arr[x][y + 1]) >= 2) {
				chk = false;
				break;
			}
		}

		if (chk) ret++;
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++) {
			cin >> A[x][y];
			B[y][x] = A[x][y];
		}

	ans += solution(A);
	ans += solution(B);

	cout << ans;

	return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int H, W, N, M;
	cin >> H >> W >> N >> M;

	// 풀이 1
	int t1 = (H - 1) / (N + 1) + 1;
	int t2 = (W - 1) / (M + 1) + 1;


	// 풀이 2
	t1 = ceil((double)H / (N + 1));
	t2 = ceil((double)W / (M + 1));
	
	cout << t1 * t2;
}
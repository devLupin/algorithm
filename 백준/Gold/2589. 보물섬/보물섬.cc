#include <bits/stdc++.h>
using namespace std;
typedef struct {
	int y, x, distance;
}Treasure;
int main(void) {
	int maxDistance = -1;
	char map[50][50] = { 0, };

	int dy[] = {1, -1, 0, 0};
	int dx[] = {0, 0, -1, 1};
	
	int height, width;
	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> map[i][j];
		}
	}

	queue<Treasure> q;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			bool visited[50][50] = { false, };
			
			if (map[i][j] == 'W')
				continue;

			visited[i][j] = true;
			Treasure temp = { i, j, 0 };
			q.push(temp);

			while (!q.empty()) {
				Treasure current = q.front();
				q.pop();

				if (maxDistance < current.distance)
					maxDistance = current.distance;

				for (int k = 0; k < 4; k++) {
					int x = current.x + dx[k];
					int y = current.y + dy[k];

					if (map[y][x] == 'W' || visited[y][x] == true)
						continue;
					if (x < 0 || y < 0 || x >= width || y >= height)
						continue;

					visited[y][x] = true;
					Treasure traveler = { y, x, current.distance + 1 };
					q.push(traveler);
				}
			}
		}
	}

	cout << maxDistance;
	
	return 0;
}
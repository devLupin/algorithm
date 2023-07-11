#include <bits/stdc++.h>
using namespace std;

int solve(int bridge_length, int weight, vector<int> truck_weights) {
	int ans = 0, idx=0, w=0;
	queue<int> q;

	for(int i=0; i<bridge_length; i++)
		q.push(0);

	while(!q.empty()) {
		ans++;
		w -= q.front();
		q.pop();

		if(idx < truck_weights.size()) {
			if(w + truck_weights[idx] <= weight) {
				w += truck_weights[idx];
				q.push(truck_weights[idx++]);
			}
			else q.push(0);
		}
	}

	return ans;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, w, L;
	cin >> n >> w >> L;

	vector<int> truck_weight(n);
	for(int i=0; i<n; i++)
		cin >> truck_weight[i];

	cout << solve(w, L, truck_weight);
	return 0;
}
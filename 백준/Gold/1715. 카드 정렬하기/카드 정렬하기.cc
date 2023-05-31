#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, res = 0; 
	cin >> n;
	
	priority_queue<int> pq;
	for (int tmp, i = 0; i < n; i++) {
		cin >> tmp;
		pq.push(~tmp);
	}

	while (pq.size() > 1) {
		int a, b;
		a = ~pq.top(); pq.pop();
		b = ~pq.top(); pq.pop();

		res += a + b;
		pq.push(~(a + b));
	}
	
	cout << res;
	
	return 0;
}
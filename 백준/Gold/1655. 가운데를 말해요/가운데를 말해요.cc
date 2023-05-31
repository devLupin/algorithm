#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; 
	cin >> n;
	
	priority_queue<int> max_pq;
	priority_queue<int> min_pq;
	while (n--) {
		int tmp; cin >> tmp;
		
		if (max_pq.size() > min_pq.size()) min_pq.push(~tmp);
		else max_pq.push(tmp);

		if (!max_pq.empty() && !min_pq.empty()) {
			int a = max_pq.top(); 
			int b = ~min_pq.top();

			if (a > b) {
				max_pq.pop();
				min_pq.pop();

				max_pq.push(b);
				min_pq.push(~a);
			}
		}
		cout << max_pq.top() << '\n';
	}
	
	return 0;
}
#include <stack>
#include <iostream>
using namespace std;
typedef struct { int n, idx; }pos;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	stack<pos> st;
	
	int N; cin >> N;
	for (int k, i = 1; i <= N; i++) {
		cin >> k;

		while (!st.empty()) {
			pos cur = st.top();
			if (cur.n > k) {
				cout << cur.idx << " ";
				break;
			}
			st.pop();
		}

		if (st.empty()) cout << "0 ";
		st.push({ k, i });
	}

	return 0;
}
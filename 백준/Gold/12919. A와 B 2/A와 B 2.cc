#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void DFS(const string S, const string T) 
{
	if (S == T) {
		cout << 1;
		exit(0);
	}
	if (S.size() > T.size())
		return;
	
	if (T[T.size() - 1] == 'A') {
		string temp = T;
		temp.erase(temp.size() - 1);
		DFS(S, temp);
	}
	if (T[0] == 'B') {
		string temp = T;
		reverse(temp.begin(), temp.end());
		temp.erase(temp.size() - 1);
		DFS(S, temp);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string S, T;
	cin >> S >> T;

	DFS(S, T);

	cout << 0;
	return 0;
}
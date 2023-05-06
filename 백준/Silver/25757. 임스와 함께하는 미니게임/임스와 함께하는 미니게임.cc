#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; char type;
	cin >> n >> type;

	set<string> s;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}
	
	int sz = s.size();
	if (type == 'Y') cout << sz;
	else if (type == 'F') cout << sz / 2;
	else cout << sz / 3;
}
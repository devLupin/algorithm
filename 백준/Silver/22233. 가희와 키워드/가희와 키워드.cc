#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str) {
    istringstream iss(str);
    string buffer;
    vector<string> result;
    while (getline(iss, buffer, ',')) result.push_back(buffer);
    return result;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set<string> S;

    int n, m;
    cin >> n >> m;

    for(string s; n--;) {
        cin >> s;
        S.insert(s);
    }

    for(string s; m--;) {
        cin >> s;
        auto li = split(s);

        for(auto a : li)
            if(S.find(a) != S.end()) {
                auto it = S.find(a);
                S.erase(it);
            }
        cout << S.size() << '\n';
    }

	return 0;
}
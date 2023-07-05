#include <bits/stdc++.h>
using namespace std;

bool cmp(string &a, string &b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    vector<string> v;

    int n;
    cin >> n;
    
    while(n--) {
        string s;
        cin >> s;

        string tmp = "";
        for(char c : s) {
            if(c >= '0' && c <= '9') {
                if(tmp.size() > 1 && tmp[0] == '0') tmp = tmp.substr(1, tmp.size());
                tmp += c;
            }
            else {
                if(tmp != "") {
                    if(tmp.size() > 1 && tmp[0] == '0') tmp = tmp.substr(1, tmp.size());
                    v.push_back(tmp);
                }
                tmp = "";
            }
        }

        if(tmp != "") {
            if(tmp.size() > 1 && tmp[0] == '0') tmp = tmp.substr(1, tmp.size());
            v.push_back(tmp);
        }
    }

    sort(v.begin(), v.end(), cmp);

    for(auto a : v) cout << a << '\n';
    return 0;
}
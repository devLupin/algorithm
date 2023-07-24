#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int SZ = 2001;
int num, arr[SZ];

bool is_zero(const string s) {
    string tmp = s;
    tmp.erase(remove(tmp.begin(), tmp.end(), ' '), tmp.end());

    vector<int> v;
    vector<char> op;

    string x = "";
    for(char c : tmp) {
        if(c != '+' && c != '-') x += c;
        else {
            v.push_back(stoi(x));
            x = "";
            op.push_back(c);
        }
    }
    if(x != "") v.push_back(stoi(x));

    if(op.size() == 0) return stoi(tmp) == 0 ? true : false;

    int a = (op[0] == '+' ? v[0] + v[1] : v[0] - v[1]);
    for(int i=1, idx=2; i<op.size(); i++, idx++)
        a = (op[i] == '+' ? a + v[idx] : a - v[idx]);

    return a == 0;
}

void dfs(string s, int n) {
    if(n > num) {
        if(is_zero(s)) cout << s << '\n';
        return;
    }

    dfs(s + " " + to_string(n), n+1);
    dfs(s + "+" + to_string(n), n+1);
    dfs(s + "-" + to_string(n), n+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while(TC--) {
        cin >> num;
        dfs("1", 2);
        cout << '\n';
    }

    return 0;
}
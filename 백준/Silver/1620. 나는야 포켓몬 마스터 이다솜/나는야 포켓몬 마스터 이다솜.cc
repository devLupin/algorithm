#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> s2i;
string i2s[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        cin >> s;
        i2s[i] = s; 
        s2i[i2s[i]] = i;
    }

    while(m--) {
        cin >> s;
        if(isdigit(s[0])) cout << i2s[stoi(s)] << '\n';
        else cout << s2i[s] << '\n';
    }

    return 0;
}
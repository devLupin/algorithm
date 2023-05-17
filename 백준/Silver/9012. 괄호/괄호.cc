#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while (tc--) {
        string str; cin >> str;
        stack<char> st;

        bool chk = true;
        for (char c : str) {
            if (c == '(') st.push('(');
            else {
                if (st.empty()) {
                    chk = false;
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty()) chk = false;

        cout << (chk ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
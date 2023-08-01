#include <bits/stdc++.h>
using namespace std;

int n, q, opt, x, cur = 1;
set<int> st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i=1; i<=n; i++) {
        cin >> x;
        if(x == 1) st.insert(i);
    }

    while(q--) {
        cin >> opt;

        if(opt == 1) {
            cin >> x;
            if(st.find(x) == st.end()) st.insert(x);
            else st.erase(x);
        }
        else if(opt == 2) {
            cin >> x;
            cur = (cur + x -1) % n + 1;
        }
        else {
            if(st.empty()) cout << "-1\n";
            else {
                auto it = st.lower_bound(cur);
                if(it == st.end()) cout << n - cur + *st.begin() << '\n';
                else cout << *it - cur << '\n';
            }
        }
    }

    return 0;
}
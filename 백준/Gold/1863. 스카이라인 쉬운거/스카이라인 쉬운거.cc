#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans = 0;
    cin >> n;

    stack<int> st;
    for(int i=0; i<=n; i++) {
        int x, y;

        if(i == n) y = 0;
        else cin >> x >> y;

        while(!st.empty() && st.top() >= y) {
            if(st.top() != y) ans++;
            st.pop();
        }

        st.push(y);
    }

    cout << ans;

    return 0;
}
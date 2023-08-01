#include <bits/stdc++.h>
using namespace std;

int main(){
    int TC, t, k;
    cin >> TC;
    while(TC--) {
        multiset<int> ms;

        cin >> t;
        while(t--) {
            char op;
            int n;
            cin >> op >> n;

            if(op == 'I') ms.insert(n);
            else {
                if(ms.empty()) continue;
                if(n == 1) ms.erase(prev(ms.end()));
                else ms.erase(ms.begin());
            }
        }

        if(ms.empty()) cout << "EMPTY" << '\n';
        else cout << *(prev(ms.end())) << ' ' << *(ms.begin()) << '\n';
    }

    return 0;
}
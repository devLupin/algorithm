#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n, p, l, m;
string opt;

int P[100005];
set<int> L[105];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> p >> l;
        P[p] = l;
        L[l].insert(p);
    }

    cin >> m;
    while(m--) {
        cin >> opt;

        if(opt == "recommend") {
            cin >> p;

            if(p == 1) {
                for(int i=100; i>=0; i--)
                    if(!L[i].empty()) {
                        cout << *prev(L[i].end()) << '\n';
                        break;
                    }
            }
            else {
                for(int i=0; i<=100; i++)
                    if(!L[i].empty()) {
                        cout << *L[i].begin() << '\n';
                        break;
                    }
            }
        }
        else if(opt == "add") {
            cin >> p >> l;
            P[p] = l;
            L[l].insert(p);
        }
        else {
            cin >> p;
            L[P[p]].erase(p);
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int N, P, M, L, G, x;
pii problem[100'005];
set<int> lv[105];
set<int> cls_lv[105][105];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while(N--) {
        cin >> P >> L >> G;
        problem[P] = {G, L};
        lv[L].insert(P);
        cls_lv[G][L].insert(P);
    }

    cin >> M;
    while(M--) {
        string opt;
        cin >> opt;

        if(opt == "recommend") {
            int num, cmp;
            cin >> G >> x;

            if(x == 1) {
                for(int i=100; i>0; i--) {
                    if(cls_lv[G][i].empty()) continue;
                    cout << *prev(cls_lv[G][i].end()) << '\n';
                    break;
                }
            }
            else {
                for(int i=1; i<=100; i++) {
                    if(cls_lv[G][i].empty()) continue;
                    cout << *cls_lv[G][i].begin() << '\n';
                    break;
                }
            }
        }
        else if(opt == "recommend2") {
            cin >> x;

            if(x == 1) {
                for(int i=100; i>0; i--) {
                    if(lv[i].empty()) continue;
                    cout << *prev(lv[i].end()) << '\n';
                    break;
                }
            }
            else {
                for(int i=1; i<=100; i++) {
                    if(lv[i].empty()) continue;
                    cout << *lv[i].begin() << '\n';
                    break;
                }
            }
        }
        else if(opt == "recommend3") {
            int flag = false;
            cin >> x >> L;

            if(x == 1) {
                for(int i=L; i<=100; i++) {
                    if(lv[i].empty()) continue;
                    cout << *lv[i].begin() << '\n';
                    flag = true;
                    break;
                }
                if(!flag) cout << "-1\n";
            }
            else {
                for(int i=L-1; i>0; i--) {
                    if(lv[i].empty()) continue;
                    cout << *prev(lv[i].end()) << '\n';
                    flag = true;
                    break;
                }
                if(!flag) cout << "-1\n";
            }
        }
        else if(opt == "add") {
            cin >> P >> L >> G;
            problem[P] = {G, L};
            lv[L].insert(P);
            cls_lv[G][L].insert(P);
        }
        else {
            cin >> P;
            pii cur = problem[P];
            cls_lv[cur.first][cur.second].erase(P);
            lv[cur.second].erase(P);
        }
    }

    return 0;
}
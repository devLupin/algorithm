#include <string>
#include <vector>
#define FOR(i, n) for(int i=1; i<=(n); i++)
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int chk1[12] = { false, };
    int chk2[12] = { false, };
    chk1[0] = chk2[0] = true;
    
    for(int i=0; i<goal.size(); i++) {
        bool flag = false;

        FOR(c1, cards1.size()) {
            if (cards1[c1-1] == goal[i])
                if (chk1[c1 - 1] && !chk1[c1 + 1]) {
                    flag = true;
                    chk1[c1] = true;
                    break;
                }
        }
        
        if (flag)
            continue;

        FOR(c2, cards2.size()) {
            if (cards2[c2-1] == goal[i])
                if (chk2[c2 - 1] && !chk2[c2 + 1]) {
                    flag = true;
                    chk2[c2] = true;
                    break;
                }
        }

        if (!flag)
            return "No";
    }
    return "Yes";
}
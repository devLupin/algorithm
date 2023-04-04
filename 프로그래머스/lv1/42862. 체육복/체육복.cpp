#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool chk[32] = { false, };

int solution(int n, vector<int> lost, vector<int> reserve) {
    int ret = n;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for(int i=0; i<lost.size(); i++)
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                reserve.erase(reserve.begin() + j);
                lost.erase(lost.begin() + i);
                i--;
                break;
            }
        }

    for (int i = 0; i < reserve.size(); i++)
        chk[reserve[i]] = true;

    for (int i = 0; i < lost.size(); i++) {
        int cur = lost[i];
        
        if (chk[cur - 1])
            chk[cur] = false;
        else if (chk[cur + 1])
            chk[cur + 1] = false;
        else
            ret--;
    }
    return ret;
}
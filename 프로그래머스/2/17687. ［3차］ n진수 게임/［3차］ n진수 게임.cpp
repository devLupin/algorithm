#include <bits/stdc++.h>

using namespace std;

string solution(int n, int t, int m, int p) {
    int num = 1, cnt = 2;
    string answer = "";

    if (p == 1) answer += '0';

    while (true) {
        if (answer.size() >= t) break;

        int x = num;
        string tmp = "";

        while (x > 0) {
            int bit = x % n;
            x /= n;
            
            if (bit > 9) tmp += char('A' + (bit - 10));
            else tmp += char(bit + '0');
        }
        reverse(tmp.begin(), tmp.end());

        for (char c : tmp) {
            if (answer.size() >= t) break;
            if (cnt == p) answer += c;
            
            cnt++;
            if (cnt > m) cnt = 1;
        }

        num++;
    }

    return answer;
}

int main(void) {
    cout << solution(16, 16, 2, 1);
}
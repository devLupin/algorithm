#include <bits/stdc++.h>
using namespace std;

int solution(int storey) {
    int answer = 0;

    while(storey) {
        // 일의 자리, 십의 자리
        int cur = storey % 10;
        int nxt = storey / 10 % 10;
        
        if(cur > 5) {  // 올림
            answer += 10 - cur;
            storey += 10;
        }
        else if(cur == 5) { // 반올림
            answer += 5;
            storey += nxt >= 5 ? 10 : 0;
        }
        else  // 내림
            answer += cur;
        
        storey /= 10;
    }

    return answer;
}
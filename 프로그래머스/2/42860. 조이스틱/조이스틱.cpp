#include <bits/stdc++.h>
using namespace std;

int A[26];

int solution(string name) {
    int ans = 0;
    int len = name.size();
    int cmp = len - 1;
    
    // 거리 초기화
    for(int i=0; i<=13; i++) A[i] = i;
    for(int j=12, i=14; i<26; i++, j--) A[i] = j;
    
    for(int i=0; i<len; i++) {
        ans += A[name[i] - 'A'];
        
        int tmp = i + 1;
        while(tmp < len && name[tmp] == 'A') tmp++;
        cmp = min(cmp, i + len - tmp + min(i, len - tmp));
    }
    
    return ans + cmp;
}
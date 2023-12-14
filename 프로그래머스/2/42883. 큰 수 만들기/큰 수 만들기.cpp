#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    string ans = "";
    int len = number.size() - k;
    int idx = 0;
    
    for(int i=0; i<len; i++) {
        char num = number[idx];
        int c_idx = idx;
        
        for(int j=idx; j<=k+i; j++) {
            if(num < number[j]) {
                num = number[j];
                c_idx = j;
            }
        }
        
        idx = c_idx + 1;
        ans += num;
    }
    
    return ans;
}
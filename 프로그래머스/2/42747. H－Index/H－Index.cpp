#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int ans = 0;
    sort(citations.begin(), citations.end(), greater<>());
    
    for(int i=0; i<citations.size(); i++) {
        if(citations[i] > i) ans++;
        else break;
    }
    
    return ans;
}
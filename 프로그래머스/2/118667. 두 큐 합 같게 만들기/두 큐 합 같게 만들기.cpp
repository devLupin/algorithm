#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int ans = 0;
    queue<int> q1, q2;
    long long sum1, sum2;
    sum1 = sum2 = 0;
    
    for(int x : queue1) {
        sum1 += x;
        q1.push(x);
    }
    for(int x : queue2){
        sum2 += x;
        q2.push(x);
    }
    
    if((sum1 + sum2) % 2 != 0) return -1;
    
    int sz = q1.size() + q2.size() + 1;
    while(sum1 != sum2) {
        int x;
        
        if(sz < ans) return -1;
        
        if(sum1 < sum2) {
            x = q2.front();
            q2.pop();
            q1.push(x);
            sum1 += x;
            sum2 -= x;
        }
        else {
            x = q1.front();
            q1.pop();
            q2.push(x);
            sum1 -= x;
            sum2 += x;
        }
        
        ans++;
    }
    
    return ans;
}
#include <bits/stdc++.h>
using namespace std;

int solution(int N, int number) {
    unordered_set<int> S[9];
    int sum = 0;
    
    for(int i=1; i<=8; i++) {
        sum = sum * 10 + N;
        S[i].insert(sum);
    }
    
    for(int i=1; i<=8; i++) {
        for(int j=1; j<i; j++) {
            for(int a : S[j]) {
                for(int b : S[i - j]) {
                    S[i].insert(a + b);
                    S[i].insert(a - b);
                    S[i].insert(a * b);
                    if(b != 0) S[i].insert(a / b);
                }
            }
        }
    }
    
    for(int i=1; i<=8; i++)
        if(S[i].find(number) != S[i].end())
            return i;
    
    return -1;
}
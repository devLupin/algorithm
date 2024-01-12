#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int from, int to, int by) {
    if(n == 1) {
        answer.push_back({from, to});
        return;
    }
    
    hanoi(n-1, from, by, to);
    answer.push_back({from, to});
    hanoi(n-1, by, to, from);
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3, 2);
    return answer;
}
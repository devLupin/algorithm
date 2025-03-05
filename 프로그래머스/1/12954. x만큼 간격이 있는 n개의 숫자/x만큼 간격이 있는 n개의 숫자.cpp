#include <bits/stdc++.h>
using namespace std;

vector<long long> solution(int x, int n) 
{
    vector<long long> answer;
    for(int i = x; n--; i += x) answer.push_back(i);
    return answer;
}
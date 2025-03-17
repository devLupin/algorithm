#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int m) 
{
    vector<int> answer;
    int gcd;
    
    for(int i = 1; i <= max(n, m); i++)
        gcd = !(n % i) && !(m % i) ? i : gcd;
    
    return {gcd, n * m / gcd};
}
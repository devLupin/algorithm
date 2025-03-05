#include <bits/stdc++.h>
using namespace std;

double solution(vector<int> arr) 
{
    int sum = 0;
    for(int x : arr) sum += x; 
    return sum / double(arr.size());
}
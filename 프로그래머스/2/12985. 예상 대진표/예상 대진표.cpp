#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int ans=0;
    while(a != b) {
        a = (a+1)/2;
        b = (b+1)/2;
        ans++;
    }

    return ans;
}
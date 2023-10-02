#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int lcm(int a, int b) { return (a * b) / gcd(a, b);}

int solution(vector<int> arr) {
    sort(arr.begin(), arr.end());

    int x = lcm(arr[0], arr[arr.size()-1]);
    int p = x;
    
    while(true) {
        bool flag = true;
        for(int i=0; i<arr.size()-1; i++)
            if(x % arr[i] != 0) {
                flag = false;
                break;
            }

        if(flag) break;
        x += p;
    }
    return x;
}
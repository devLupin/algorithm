#include <bits/stdc++.h>
using namespace std;

string arr[] = {"4", "1", "2"};

string solution(int n) {
    string ans = "";
    
    while(n != 0) {
        int remain = n % 3;
        n /= 3;
        
        if(remain == 0) n--;
        ans = arr[remain] + ans;
    }

    return ans;
}
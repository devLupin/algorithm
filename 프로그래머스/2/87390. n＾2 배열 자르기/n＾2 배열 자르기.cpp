#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> ans;
    for(long long idx = left; idx <= right; idx++) {
        int mod = idx % n;
        int div = idx / n;
        
        if(div >= mod + 1) mod += (div - mod);
        ans.push_back(mod + 1);
    }
    return ans;
}
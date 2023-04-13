#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

bool arr[2998];

void eratos(int n) {
    fill_n(arr, 1001, false);
    
    for(int i=2; i<=n; i++)
        arr[i] = true;
    
    for(int i=2; i<=sqrt(n); i++) {
        if(!arr[i]) continue;
        
        for(int j=i*i; j<=n; j += i) {
            arr[j] = false;
        }
    }
}

int solution(vector<int> nums) {
    sort(nums.begin(), nums.end());
    
    int sz = nums.size();
    eratos(nums[sz-1] + nums[sz-2] + nums[sz-3]);
    
    int answer = 0;
    for(int i=0; i<sz; i++)
        for(int j=i+1; j<sz; j++)
            for(int k=j+1; k<sz; k++)
                if(arr[nums[i]+nums[j]+nums[k]]) 
                    answer++;
    
    return answer;
}
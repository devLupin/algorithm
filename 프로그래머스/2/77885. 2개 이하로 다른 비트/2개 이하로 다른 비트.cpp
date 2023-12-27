#include <bits/stdc++.h>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(auto num : numbers) {
        if(num % 2 == 0) answer.push_back(num + 1);
        else {
            long long tmp = 1;
            while((num & tmp) != 0) tmp *= 2;
            answer.push_back(num + tmp / 2);
        }
    }
    
    return answer;
}
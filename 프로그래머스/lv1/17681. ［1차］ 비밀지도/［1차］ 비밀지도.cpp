#include <string>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<arr1.size(); i++) {
        bitset<16> bit1(arr1[i]);
        bitset<16> bit2(arr2[i]);
        
        bitset<16> or_val = bit1 | bit2;
        string part = or_val.to_string();
        part = part.substr(16-n, part.size());
        
        for(int j=0; j<part.size(); j++)
            part[j] = (part[j] == '1') ? '#' : ' ';
        
        answer.push_back(part);
    }
    
    
    return answer;
}
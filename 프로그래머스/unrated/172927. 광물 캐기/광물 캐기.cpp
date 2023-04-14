#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct Weight
{
    int sum;
    int arr[3];
    
    Weight(int dia, int iron, int stone) {
        sum = dia + iron + stone;
        arr[0] = dia, arr[1] = iron, arr[2] = stone;
    }
    
    bool operator< (const Weight &other) const {
        return sum < other.sum;
    }
};

int solution(vector<int> picks, vector<string> minerals) {
    priority_queue<Weight> pq;
    
    int len = (picks[0]+picks[1]+picks[2])*5;
    len = (len <= minerals.size()) ? len : minerals.size();
    
    for(int i=0; i<len; i+=5) {
        int dia = 0, iron = 0, stone = 0;
        
        for(int j=i; j<min(len, i+5); j++) {
            string cur = minerals[j];
            
            if(cur == "diamond") {
                dia += 1;
                iron += 5;
                stone += 25;
            }
            else if(cur == "iron") {
                dia += 1;
                iron += 1;
                stone += 5;
            }
            else {
                dia += 1;
                iron += 1;
                stone += 1;
            }
        }
        
        pq.push(Weight(dia, iron, stone));
    }
    
    int ans = 0;
    while(!pq.empty()) {
        Weight cur = pq.top();
        pq.pop();
        
        for(int i=0; i<3; i++) {
            if(picks[i] != 0){
                picks[i]--;
                ans += cur.arr[i];
                break;
            }
        }
    }
    
    return ans;
}
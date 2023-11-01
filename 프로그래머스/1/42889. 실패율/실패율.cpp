#include <bits/stdc++.h>
using namespace std;
using pdi = pair<double,int>;

bool cmp(pair<double,int> a, pair<double,int> b){
    if(a.first==b.first)return a.second<b.second;
    else return a.first>b.first;

}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pdi> per;
    map<int, double> ma;
    int size = stages.size();

    for(int i=0;i <stages.size();i++){
        ma[stages[i]]++;
    }
    double minus_mem=0;
    for(int i=1; i<=N;i++){
        if(ma[i]==0){
            per.push_back({0,i});
            continue;
        }
        per.push_back({ma[i]/(size-minus_mem),i});
        minus_mem+=ma[i];
    }
    sort(per.begin(),per.end(),cmp);
    for(auto o: per){
       answer.push_back(o.second);
    }

    return answer;
}
#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, j = 0, time = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    sort(jobs.begin(), jobs.end());

    while (j < jobs.size() || !pq.empty()) {
        if (j < jobs.size() && jobs[j][0] <= time) {
            pq.push(jobs[j++]);
            continue;
        }

        if (!pq.empty()) {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else time = jobs[j][0];
    }

    return answer / jobs.size();
}
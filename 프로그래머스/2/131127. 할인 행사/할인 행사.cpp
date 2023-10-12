#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> want_map;

bool check(unordered_map<string, int> discount_map) {
    for (auto nxt : want_map) {
        if (discount_map[nxt.first] == 0) return false;
        else if (discount_map[nxt.first] != nxt.second) return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int ans = 0;

    for (int i = 0; i < want.size(); i++)
        want_map[want[i]] = number[i];

    for (int i = 0; i <= discount.size() - 10; i++) {
        unordered_map<string, int> discount_map;
        for (int j = i; j < i + 10; j++)
            discount_map[discount[j]]++;

        ans += check(discount_map);
    }

    return ans;
}
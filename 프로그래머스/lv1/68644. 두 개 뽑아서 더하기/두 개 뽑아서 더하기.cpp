#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int, less<int>> s;
    vector<int> v;

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers.size(); j++) {
            if (i == j) continue;
            s.insert(numbers[i] + numbers[j]);
        }
    }

    for (auto i : s)
        v.push_back(i);

    return v;
}
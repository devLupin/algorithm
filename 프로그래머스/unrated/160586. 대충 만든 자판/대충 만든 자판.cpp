#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[26] = { 0 };

void allocate(vector<string> keymap) {
    fill_n(arr, 26, 101);

    for (int i = 0; i < keymap.size(); i++)
        for (int j = 0; j < keymap[i].size(); j++) {
            int idx = keymap[i][j] - 'A';
            arr[idx] = (arr[idx] <= j) ? arr[idx] : j + 1;
        }
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size());

    allocate(keymap);

    for (int i = 0; i < targets.size(); i++) {
        answer[i] = 0;
        for (int j = 0; j < targets[i].size(); j++) {
            int idx = targets[i][j] - 'A';
            if (arr[idx] == 101) {
                answer[i] = -1;
                break;
            }
            else
                answer[i] += arr[idx];
        }
    }
    return answer;
}
#include <string>

using namespace std;

bool jump[26] = { false, };

string solution(string s, string skip, int index) {
    string answer = "";

    for (int i = 0; i < skip.size(); i++)
        jump[skip[i] - 'a'] = true;

    for (int i = 0; i < s.size(); i++) {
        int cur = s[i] - 'a';

        for (int j = 0; j < index; j++) {
            cur++;

            if (cur >= 26)
                cur -= 26;
            if (jump[cur]) {
                j--;
                continue;
            }
        }
        answer += (char)(cur + 'a');
    }

    return answer;
}
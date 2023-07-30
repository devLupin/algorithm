#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;
typedef struct
{
    pii left, right;
} pos;

pii key_value[] = {
    {4, 2}, {1, 1}, {1, 2}, {1, 3}, {2, 1}, {2, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3}};

string solution(vector<int> numbers, string hand)
{
    string answer = "";

    queue<pos> q;
    q.push({{4, 1}, {4, 3}});

    for (int i = 0; i < numbers.size(); i++)
    {
        pos cur = q.front();
        q.pop();

        int num = numbers[i];
        if (num % 3 == 1)
        {
            q.push({key_value[num], cur.right});
            answer += "L";
        }
        else if (num != 0 && num % 3 == 0)
        {
            q.push({cur.left, key_value[num]});
            answer += "R";
        }
        else
        {
            pii left = cur.left;
            pii right = cur.right;

            int left_distance = abs(left.first - key_value[num].first) + abs(left.second - key_value[num].second);
            int right_distance = abs(right.first - key_value[num].first) + abs(right.second - key_value[num].second);

            if (left_distance < right_distance)
            {
                q.push({key_value[num], right});
                answer += "L";
            }
            else if (left_distance > right_distance)
            {
                q.push({left, key_value[num]});
                answer += "R";
            }
            else
            {
                if (hand == "left")
                {
                    q.push({key_value[num], right});
                    answer += "L";
                }
                else
                {
                    q.push({left, key_value[num]});
                    answer += "R";
                }
            }
        }
    }

    return answer;
}
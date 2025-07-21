#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <iostream>

using namespace std;

int solution(string s)
{
    unordered_map<string, char> mm;
    mm["zero"] = '0';
    mm["one"] = '1';
    mm["two"] = '2';
    mm["three"] = '3';
    mm["four"] = '4';
    mm["five"] = '5';
    mm["six"] = '6';
    mm["seven"] = '7';
    mm["eight"] = '8';
    mm["nine"] = '9';

    string ans = "";
    string tmp = "";
    for (const auto& c : s)
    {
        if (c >= '0' && c <= '9')
        {
            ans += c;
            continue;
        }

        tmp += c;
        if (mm.find(tmp) != mm.end())
        {
            ans += mm[tmp];
            tmp = "";
        }
    }
    return stoi(ans);
}
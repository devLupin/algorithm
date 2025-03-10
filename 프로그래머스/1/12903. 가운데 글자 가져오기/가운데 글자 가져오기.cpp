#include <string>
using namespace std;

string solution(string s) 
{
    int sz = s.size();
    return (sz % 2 == 0) ? s.substr(sz / 2 - 1, 2) : s.substr(sz / 2, 1); 
}
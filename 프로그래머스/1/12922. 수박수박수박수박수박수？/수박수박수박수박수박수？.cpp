#include <string>
using namespace std;

string solution(int n) 
{
    string a = "수", b = "박", ans;
    for(int i=1; i<=n; i++)
        ans += (i % 2 == 0) ? b : a;
    return ans;
}
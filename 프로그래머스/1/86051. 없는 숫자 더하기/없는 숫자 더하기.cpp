#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers)
{
    vector<bool> v(10, false);
    for(int x : numbers) v[x] = true;
    int ans = 0;
    for(int i=1; i<10; i++)
        if(!v[i]) ans += i;
    return ans;
}
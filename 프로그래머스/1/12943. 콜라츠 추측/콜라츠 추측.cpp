#include <string>
#include <vector>

using namespace std;

int solution(int num) 
{
    long long n = num;
    int cnt = 0;
    while(n != 1 && cnt < 501)
    {
        if(n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
        cnt++;
    }
    return (cnt > 500 ? -1 : cnt);
}
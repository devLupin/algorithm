#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) 
{
    for(int i = 0; i < phone_number.size() - 4; i++)
    {
        char& c = phone_number[i];
        c = '*';
    }
    return phone_number;
}
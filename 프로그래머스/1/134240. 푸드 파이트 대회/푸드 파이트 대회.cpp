#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) 
{
    string fr, rr;
    
    for(int i=1; i<food.size(); i++)
    {
        int& nxt = food[i];
        nxt = (nxt % 2 == 0) ? nxt : nxt - 1;
    }
    
    for(int i=1; i<food.size(); i++)
    {
        for(int j=food[i]; j>0; j -= 2)
        {
            fr += to_string(i);
            rr += to_string(i);
        }
    }
    reverse(rr.begin(), rr.end());
    return fr + "0" + rr;
}
#include <set>
#include <vector>

using namespace std;

vector<int> elements;
set<int> s;

void sum(int len) 
{
    int sz = elements.size();
    
    for(int i=0; i<sz; i++) {
        int sum = 0;
        
        for(int j=i; j<i+len; j++)
            sum += (j < sz) ? elements[j] : elements[j - sz];
        
        s.insert(sum);
    }
}

int solution(vector<int> elements) {
    ::elements = elements;
    
    int len = 1;
    while(len <= elements.size())
        sum(len++);
    
    return s.size();
}
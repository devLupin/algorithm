#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool arr[1000001];

int solution(int n) {
    fill_n(arr, 1000001, false);
    
    for(int i=2; i<=n; i++)
        arr[i] = true;
    
    for(int i=2; i<=sqrt(n); i++) {
        if(!arr[i]) continue;
        
        for(int j=i*i; j<=n; j += i) {
            arr[j] = false;
        }
    }
    
    int ans = 0;
    for(int i=2; i<=n; i++)
        if(arr[i]) ans++;
    
    return ans;
}
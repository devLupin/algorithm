#include <string>
#include <vector>

using ULL = unsigned long long;
using namespace std;

int solution(string t, string p) {
    int ans = 0;

    int n = p.size();
    int s = 0, e = n;

    ULL num = stoull(p);

    while (s < t.size() && e < t.size() + 1) {
        ULL cur = stoull(t.substr(s, n));
        if (num >= cur)
            ans++;
        s++; e++;
    }

    return ans;
}
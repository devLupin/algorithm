#include <vector>
#include <stack>

using namespace std;
using pii = pair<int, int>;

vector<int> solution(vector<int> numbers) {
    int sz = numbers.size();
    vector<int> ans(sz, -1);

    stack<pii> st;
    for (int i = 0; i < sz; i++) {
        while (!st.empty()) {
            pii cur = st.top();

            if (cur.first >= numbers[i])
                break;
            
            ans[cur.second] = numbers[i];
            st.pop();
        }
        st.push({ numbers[i], i });
    }
    return ans;
}
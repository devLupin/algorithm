from collections import deque

def solution(arr):
    q = deque()
    
    for cur in arr:
        if not q or q[0] != cur:
            q.appendleft(cur)

    ans = []
    while q:
        ans.append(q.pop())
    
    return ans
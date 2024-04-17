from collections import deque

def solution(priorities, location):
    q = deque([(p, i) for i, p in enumerate(priorities)])
    priorities.sort(reverse=True)

    idx = 0
    while q:
        cur = q.popleft()

        if cur[0] == priorities[idx]:
            if cur[1] == location:
                break
            idx += 1
        else:
            q.append(cur)

    return idx + 1
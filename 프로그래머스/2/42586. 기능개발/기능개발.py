from collections import deque, defaultdict

def solution(progresses, speeds):
    answer = []
    dict = defaultdict(int)
    q = deque()

    for i in range(len(speeds)):
        p = progresses[i]
        s = speeds[i]

        remain = (100 - p)
        t = (remain // s) if (remain % s == 0) else (remain // s + 1)
        q.append(t)

    cmp = q[0]
    while q:
        cur = q.popleft()

        if cur <= cmp:
            dict[cmp] += 1
        else:
            dict[cur] += 1
            cmp = cur

    for k, v in dict.items():
        answer.append(v)

    return answer
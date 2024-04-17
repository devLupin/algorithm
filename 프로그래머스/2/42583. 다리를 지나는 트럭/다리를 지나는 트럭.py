from collections import deque

def solution(bridge_length, weight, truck_weights):
    ans, cw, i = 0, 0, 0
    q = deque(0 for _ in range(bridge_length))

    while q:
        ans += 1
        cw -= q.popleft()

        if i < len(truck_weights):
            if cw + truck_weights[i] <= weight:
                cw += truck_weights[i]
                q.append(truck_weights[i])
                i += 1
            else:
                q.append(0)

    return ans
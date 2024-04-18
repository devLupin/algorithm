import heapq

def solution(operations):
    cnt = 0

    mx, mn = [], []
    heapq.heapify(mx)
    heapq.heapify(mn)

    for operation in operations:
        tmp = operation.split(' ')
        cmd, num = tmp[0], int(tmp[1])
        
        if cnt == 0:
            while mn:
                heapq.heappop(mn)
            while mx:
                heapq.heappop(mx)

        if cmd == 'I':
            heapq.heappush(mn, num)
            heapq.heappush(mx, ~num)
            cnt += 1

        elif cmd == 'D':
            if cnt > 0:
                if num == -1:
                    heapq.heappop(mn)
                else:
                    heapq.heappop(mx)
                cnt -= 1

    if cnt == 0:
        return [0, 0]
    else:
        return [~heapq.heappop(mx), heapq.heappop(mn)]
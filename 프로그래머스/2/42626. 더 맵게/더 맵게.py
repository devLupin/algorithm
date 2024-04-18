import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)

    while len(scoville) >= 2 and scoville[0] < K:
        f = heapq.heappop(scoville)
        s = heapq.heappop(scoville)
        heapq.heappush(scoville, f + s * 2)
        answer += 1

    if scoville[0] < K:
        return -1
    
    return answer
from collections import defaultdict

def solution(clothes):
    dict = defaultdict(int)
    
    for cloth in clothes:
        dict[cloth[1]] += 1

    answer = 1
    for k, v in dict.items():
        answer *= (v + 1)

    return answer - 1
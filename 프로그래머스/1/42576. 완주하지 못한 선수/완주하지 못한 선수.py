from collections import defaultdict

def solution(participant, completion):
    dict = defaultdict(int)
    answer = 0

    for p in participant:
        dict[p] += 1
    for c in completion:
        dict[c] += 1

    for k, v in dict.items():
        if v % 2 != 0:
            return k
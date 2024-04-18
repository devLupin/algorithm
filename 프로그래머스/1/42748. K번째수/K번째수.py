def solution(array, commands):
    answer = []

    for cmd in commands:
        st, en, tgt = cmd
        tmp = []
        
        for i in range(st-1, en):
            tmp.append(array[i])
        tmp.sort()
        
        answer.append(tmp[tgt - 1])

    return answer
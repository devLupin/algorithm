a1 = [1, 2, 3, 4, 5]
a2 = [2, 1, 2, 3, 2, 4, 2, 5]
a3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

def solution(answers):
    answer = [0, 0, 0]
    i, j, k = 0, 0, 0

    for ans in answers:
        answer[0] += int(a1[i] == ans)
        answer[1] += int(a2[j] == ans)
        answer[2] += int(a3[k] == ans)

        i = (i + 1) % len(a1)
        j = (j + 1) % len(a2)
        k = (k + 1) % len(a3)

    tmp = [[answer[i], i + 1] for i in range(len(answer))]
    tmp.sort(key=lambda x: ~x[0])

    ret = []
    for v, k in tmp:
        if tmp[0][0] == v:
            ret.append(k)
    return ret
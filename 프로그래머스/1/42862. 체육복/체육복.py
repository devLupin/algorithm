def solution(n, lost, reserve):
    answer = 0
    check = [1 for _ in range(n + 2)]
    check[n + 1] = 0
    check[0] = 0

    for x in reserve:
        check[x] = 2
    
    for x in lost:
        check[x] = check[x] - 1

    for i in range(1, n + 1):
        if(check[i] == 0):
            if check[i - 1] > 1:
                check[i - 1] -= 1
                check[i] = 1
            elif check[i + 1] > 1:
                check[i + 1] -= 1
                check[i] = 1

    for i in range(1, n + 1):
        answer += check[i] > 0
    
    return answer
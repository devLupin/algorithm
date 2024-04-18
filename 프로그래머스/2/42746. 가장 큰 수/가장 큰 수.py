from functools import cmp_to_key

def cmp(a, b):
    s1 = str(a)
    s2 = str(b)

    if s1 + s2 > s2 + s1:
        return -1
    else:
        return 1

def solution(numbers):
    numbers = sorted(numbers, key=cmp_to_key(cmp))
    answer = ''
    for num in numbers:
        answer += str(num)

    if numbers[0] == 0:
        return "0"
    return answer
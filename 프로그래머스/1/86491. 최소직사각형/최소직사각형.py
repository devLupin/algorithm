def solution(sizes : list):
    mx = max(sizes, key=max)
    
    for x, y in sizes:
        if (x <= mx[0] and y <= mx[1]) or (x <= mx[1] and y <= mx[0]):
            continue
        else:
            tmp = [mx[0], mx[1], x, y]
            tmp.sort()
            mx[0] = tmp[3]
            mx[1] = tmp[1]

    return mx[0] * mx[1]
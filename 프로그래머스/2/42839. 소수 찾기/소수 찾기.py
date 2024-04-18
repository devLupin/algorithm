vis = [False for _ in range(7)]
uniq = []

def check(s):
    conv = int(s)

    if conv <= 1:
        return

    for i in range(2, conv):
        if conv % i == 0:
            return

    uniq.append(conv)
    return

def DFS(s):
    if len(s) > len(num):
        return
    
    for i, n in enumerate(num):
        if vis[i] == False:
            vis[i] = True
            check(s + n)
            DFS(s + n)
            vis[i] = False


def solution(numbers : str):
    global num
    num = numbers
    answer = 0

    DFS("")

    return len(list(set(uniq)))
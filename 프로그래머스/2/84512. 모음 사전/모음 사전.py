char_list = ['A', 'E', 'I', 'O', 'U']

answer = 0
cnt = -1

def DFS(cur, target):
    global answer, cnt

    if len(cur) > 5:
        return
    
    cnt += 1

    if (cur == target):
        answer = cnt
        return
    
    for c in char_list:
        DFS(cur + c, target)
    
def solution(word):
    DFS("", word)
    return answer
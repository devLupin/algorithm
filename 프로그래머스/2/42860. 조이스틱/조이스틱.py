def solution(name):
    ans = 0
    cmp = len(name) - 1

    for i, ch in enumerate(name):
        ans += min(ord(ch) - ord('A'), ord('Z') - ord(ch) + 1)

        nxt = i + 1
        while nxt < len(name) and name[nxt] == 'A':
            nxt += 1
        
        cmp = min([cmp, 2 * i + len(name) - nxt, i + 2 * (len(name) - nxt)])
    
    return ans + cmp
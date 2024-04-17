from collections import deque

def solution(s):
    answer = True
    st = deque()

    for c in s:
        if(c == '('):
            st.append(c)
        else:
            if not st:
                return False
            else:
                st.pop()
    
    if st:
        return False
    else:
        return True
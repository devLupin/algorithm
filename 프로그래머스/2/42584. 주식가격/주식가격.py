def solution(prices):
    sz = len(prices)
    answer = [0 for _ in range(sz)]
    st = []

    for i, p in enumerate(prices):
        while st and prices[st[-1]] > p:
            top = st.pop()
            answer[top] = i - top
        st.append(i)

    while st:
        top = st.pop()
        answer[top] = sz - 1 - top
    
    return answer
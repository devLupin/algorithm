def solution(number, k):
    st = []

    for num in number:
        while k > 0 and st and st[-1] < num:
            st.pop()
            k -= 1
        st.append(num)

    if k > 0:
        st = st[:-k]
    
    return ''.join(st)
def time_c(t):
    return int(t.split(':')[0])*60 + int(t.split(':')[1])

def change(x):
    exc = {'C#':'1','D#':'2', 'F#':'3', 'G#':'4', 'A#':'5'}
    for k, v in exc.items():
        x = x.replace(k, v)
    return x

def solution(m, musicinfos):
    answer = []
    for info in musicinfos:
        info = info.split(',')
        info[3] = change(info[3])
        T = time_c(info[1]) - time_c(info[0])
        
        if T >= len(info[3]):
            M = info[3] * (T//len(info[3])) + info[3][:T%len(info[3])]
        else:
            M = info[3][:T]
        
        if change(m) in M:
            answer.append([T, info[2]])
        
    if len(answer) == 0:
        return '(None)'
    else:
        # -x는 reverse(내림차순)의 효과
        # 여러 개의 [재생시간, 제목] 중 재생 시간이 가장 긴 것 
        return sorted(answer, key=lambda x: -x[0])[0][1]
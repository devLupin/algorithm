answer = 0

def dfs(numbers, target, idx, total):
    if idx == len(numbers):
        if total == target:
            global answer
            answer += 1
        return
    
    dfs(numbers, target, idx + 1, total + numbers[idx])
    dfs(numbers, target, idx + 1, total - numbers[idx])
        
    
def solution(numbers, target):
    dfs(numbers, target, 0, 0)
    return answer
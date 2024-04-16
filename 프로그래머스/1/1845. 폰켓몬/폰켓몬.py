from collections import defaultdict

def solution(nums):
    dict = defaultdict(int)
    
    for num in nums:
        dict[num] += 1

    return min(len(dict), len(nums) / 2)
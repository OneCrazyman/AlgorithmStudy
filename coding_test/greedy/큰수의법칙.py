#2019
from sys import stdin as s

s = open("input.txt", "rt")

N, M, K = map(int,s.readline().split())
arr = list(map(int,s.readline().split()))

n_maxone = max(arr) #O(n) // sort 후 arr[n-1] : O(nlogn)
arr.remove(n_maxone) #첫번째 최댓값 삭제
n_maxtwo = max(arr)
val = (n_maxone * K + n_maxtwo) * int((M/(K+1)))
print("val : {0}".format(val))

rem = M%(K+1)
print("rem : {0}".format(rem))
result = val + (rem * n_maxone)

print(result)

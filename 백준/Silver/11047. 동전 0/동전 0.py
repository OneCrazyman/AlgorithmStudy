#https://www.acmicpc.net/problem/11047
from sys import stdin as s
# s = open("input.txt")
N, K = map(int, s.readline().split())
list = []
result = 0
for _ in range(N):
    list.append(int(s.readline()))
#
max = 0
for n in list:
    if n <= K:
        if n > max:
            max = n
r = K
for i in range(list.index(max),-1,-1):
    result += r // list[i]
    r = K % list[i]
#
print(result)
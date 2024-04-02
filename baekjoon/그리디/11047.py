#https://www.acmicpc.net/problem/11047
from sys import stdin as s
s = open("input.txt")
N, K = map(int, s.readline().split())
list = []
result = 0
for _ in range(N):
    list.append(int(s.readline()))
#
for i in range(N-1,-1,-1):

    if K//list[i] > 0:
        result+=K//list[i]
        K = K%list[i]
    else:
        continue
#
print(result)
#https://www.acmicpc.net/problem/14720
from sys import stdin as s
#딸기-> 초코 -> 바나나-> 딸기
#s = open("input.txt")
N = int(s.readline())
mylist = list(map(int,s.readline().split()))
#
choice = 0
count = 0
for i in mylist:
    if i == choice:
        count += 1
        choice += 1
        choice %= 3
    else: continue
print(count)
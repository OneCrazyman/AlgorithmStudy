from sys import stdin as s
# import os
# print(os.getcwd())
# s = open("input.txt") #제출시에는 해당라인 주석처리
N, M = map(int, s.readline().split())
V = int(s.readline())

result = 0
min = 1
max = M

for _ in range(V):
    apple_pos = int(s.readline())
    if min<=apple_pos<=max:
        result+=0 #반응없음
    elif apple_pos<min:
        move=min-apple_pos
        min-=move
        max-=move
        result+=move
    elif max<apple_pos:
        move=apple_pos-max
        min+=move
        max+=move
        result+=move

print(result)
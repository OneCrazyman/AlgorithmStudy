from sys import stdin as s

s = open("input.txt","rt")

N = int(s.readline()) #회의수
print(N)
for _ in range(N):
    t1, t2 = map(int, s.readline().split())
    print(t1, t2)
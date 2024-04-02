from sys import stdin as s
#s = open("input.txt")
N,M = map(int,s.readline().split())
nset = set(s.readline().strip() for _ in range(N))
count = 0
for i in range(M):
    if (s.readline().strip()) in nset:
        count += 1
print(count)
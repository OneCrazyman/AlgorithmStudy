from sys import stdin as s
s = open("input.txt")
N = int(s.readline())
nset = set(s.readline().split())
# print(nset)
M = int(s.readline())
mlist = s.readline().split()
# print(mlist)
for i in range(M):
    if mlist[i] in nset:
        print(1,end=' ')
    else:
        print(0,end=' ')
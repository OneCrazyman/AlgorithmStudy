from sys import stdin as s
s = open("../실버/input.txt")
N = int(s.readline())
li = [s.readline().split() for i in range(N)]
li.sort(key= lambda x: int(x[0]))
for item in li:
    print(*item)

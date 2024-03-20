from sys import stdin as s
#s = open("input.txt")
N = int(s.readline())
print(*sorted([int(s.readline()) for i in range(N)]), sep="\n")
from sys import stdin as s
s = open("../실버/input.txt")
N = int(s.readline())
print(*sorted([int(s.readline()) for i in range(N)]), sep="\n")
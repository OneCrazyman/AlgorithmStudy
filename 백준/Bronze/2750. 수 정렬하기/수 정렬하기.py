from sys import stdin as s
#s = open("input.txt")
N = int(s.readline())
arr = [int(s.readline()) for i in range(N)]
arr.sort()
print(*arr, sep="\n")
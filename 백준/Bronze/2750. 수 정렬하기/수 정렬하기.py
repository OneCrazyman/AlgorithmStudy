from sys import stdin as s
#s = open("input.txt")
N = int(s.readline())
min_num = 1000
arr = [int(s.readline()) for i in range(N)]
for i in range(N):
    for j in range(i,N):
        if min_num > arr[j]:
            min_num = arr[j]
    arr[arr.index(min_num)] = arr[i]
    arr[i] = min_num
    min_num = 1000
answer = ""
for i in arr:
    print(i)

from sys import stdin as s
s = open('input.txt')
N, M = map(int,s.readline().split())
double_array = [[0] * 100 for _ in range(100)]
for _ in range(N):
    x1,y1,x2,y2 = map(int,s.readline().split())
    for i in range(x1-1,x2):
        for j in range(y1-1,y2):
            double_array[i][j] += 1
count = 0
for r in double_array:
    for element in r:
        if element > M:
            count += 1
print(count)

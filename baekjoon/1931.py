from sys import stdin as s

s = open("input.txt", "rt")

N = int(s.readline()) #회의수

arr = []
for _ in range(N):
    t1, t2 = map(int, s.readline().split())
    arr.append((t1, t2))
arr.sort(key=lambda x: x[0])
print(arr)

mo = 0
count = 0
to = arr[0][0]
for t1, t2 in arr:
    mo -= t1-to
    to = t1
    m = t2 - t1
    if m < mo:
        mo = m; continue
    if mo <= 0:
        count += 1
        print(t1, t2)
        mo = m
# print(f'답은 {count}')
print(count)
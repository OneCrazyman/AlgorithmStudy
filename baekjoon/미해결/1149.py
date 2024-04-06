from sys import stdin as s
s = open('../DP/input.txt')
N = int(s.readline())
street = []
ans = 0
rgb = list(map(int,s.readline().split()))
minVal = min(rgb)
tmp = rgb.index(minVal)
ans += minVal

for i in range(1,N):
    rgb = list(map(int, s.readline().split()))
    minVal = min(rgb)
    rgbIndex = rgb.index(minVal)
    if rgbIndex == tmp:
        rgb[rgbIndex] = 1000
        minVal = min(rgb)
        rgbIndex = rgb.index(minVal)
    print(minVal)
    tmp = rgbIndex
    ans += minVal
print(ans)

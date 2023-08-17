#달팽이는 올라가고 싶다
A,B,V = list(map(int,input().split()))
now, count = 0, 0

oneday = A-B
lev = int(V / oneday)
rem = (V % oneday)

for i in range(lev-1,-1,-1):
    # print(i)
    if i * oneday + A >= V:
        continue
    else:
        result = i+2
        break


print(result)
dd
# 2 4 11
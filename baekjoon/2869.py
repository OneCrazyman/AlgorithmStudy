#달팽이는 올라가고 싶다
A,B,V = list(map(int,input().split()))
now, count = 0, 0

oneday = A-B
lev = int(V / oneday)
rem = (V % oneday)

if (lev-1) * oneday + A > V:
    result = lev - int((B-rem)/oneday)
else : result = lev + 1 - int((A-rem)/oneday)

print(result)

# 2 4 11
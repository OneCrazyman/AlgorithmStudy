#달팽이는 올라가고 싶다
A,B,V = list(map(int,input().split()))
now, count = 0, 0

oneday = A-B

lev = int(V / oneday)
rem = (V % oneday)

if A >= rem

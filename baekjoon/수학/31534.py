from sys import stdin as s
s = open("input.txt")
a,b,h = map(int,s.readline().split())
if a == b:
    print(-1)
    exit(1)
if a > b:
    a,b = b,a
import math
result=0
if a != 0:
    hs = (a*h) / (b-a)
    rs = math.sqrt(hs**2 + a**2)
    r = math.sqrt((h+hs)**2 + b**2)
    result=(r**2-rs**2)
elif a==0:
    r = math.sqrt((h) ** 2 + b ** 2)
    result = (r ** 2)
print(result*math.pi)
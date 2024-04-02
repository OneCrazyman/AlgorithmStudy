from sys import stdin as s
#s = open("input.txt")
a,b,h = map(int,s.readline().split())
import math

hs = (a*h) / (b-a)
rs = math.sqrt(hs**2 + (a)**2)
r = math.sqrt((h+hs)**2 + b**2)
# print(r)
# print(rs)
print((r**2-rs**2)*math.pi)
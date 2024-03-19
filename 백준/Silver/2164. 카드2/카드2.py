from sys import stdin as s
from collections import deque
#s = open("input.txt")
N = int(s.readline())
Q = deque([_ for _ in range(1,N+1)])
while len(Q)!=1:
    # print(Q)
    Q.popleft()
    Q.append(Q.popleft())
print(Q[0])
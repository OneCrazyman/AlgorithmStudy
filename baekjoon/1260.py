import sys
from sys import stdin as s
from queue import Queue
sys.setrecursionlimit(10**6) #재귀 한계 해제
#s = open("input.txt") #제출시에는 해당라인 주석처리
N, V, M = map(int, s.readline().split())

#간선 딕셔너리에 생성
edge = {}
for i in range(1,N+1):
    edge[i] = []
for i in range(V):
    v1, v2 = map(int, s.readline().split())
    edge[v1].append(v2)
    edge[v2].append(v1)

#간선 정렬
for i in edge:
    edge[i].sort()

def dfs(now):
    visited.append(now)
    for v in edge[now]:
        if v not in visited:
            dfs(v)

def bfs(que):
    now = que.get()
    visited.append(now)
    for v in edge[now]:
        if v not in list(que.queue) and v not in visited:
            que.put(v)
    if que.empty():
        return
    bfs(que)

visited = []
dfs(M)
print(" ".join(str(i) for i in visited))
que = Queue()
que.put(M)
visited = []
bfs(que)
print(" ".join(str(i) for i in visited))

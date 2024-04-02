domino = []
for i in range(7):
    for j in range(i,7):
        domino.append([i,j])

from sys import stdin as s
s = open('../골드/input.txt')
board = []
for _ in range(8):
    board.append(s.readline().strip())
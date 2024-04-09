##보류 완전탐색
from sys import stdin as s
s = open('../실버/input.txt')
N, M = map(int,s.readline().split())
board = []
answer = []

for _ in range(N):
    board.append(list(s.readline().strip()))

for i in range(N-7):
    for j in range(M-7):
        drawB = 0
        drawW = 0
        for a in range(i,i+8):
            for b in range(j,j+8):
                if (a+b) % 2 == 0:
                    if board[a][b] == 'W':
                        drawB += 1
                    else:
                        drawW += 1
                else:
                    if board[a][b] == 'B':
                        drawB += 1
                    else:
                        drawW += 1
        answer.append(drawW)
        answer.append(drawB)

print(min(answer))
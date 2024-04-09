from sys import stdin as s
s = open('input.txt')
N, M = map(int,s.readline().split())
board = []
for n in range(N):
    board.append(s.readline().strip())
used = [[False]*M for _ in range(N)]
count = 0
for n in range(N):
    for m in range(M):
        if used[n][m] == True:
            continue
        count += 1
        used[n][m] = True
        if board[n][m] == '-':
            for i in range(m+1,M):
                if board[n][i] == '|':
                    break
                used[n][i] = True
        elif board[n][m] == '|':
            for j in range(n+1,N):
                if board[j][m] == '-':
                    break
                used[j][m] = True
print(count)
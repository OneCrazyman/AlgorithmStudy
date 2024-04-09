from sys import stdin as s
s = open("input.txt")
K = int(s.readline())
stack = []
for _ in range(K):
    n = int(s.readline().strip())
    if n != 0:
        stack.append(n)
    else: #0
        stack.pop()
        # del stack[-1]
print(sum(stack))
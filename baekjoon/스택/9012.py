from sys import stdin as s
s = open("input.txt")
N = int(s.readline())

for _ in range(N):
    stack = []
    VPN = 'YES'
    str = s.readline().strip()
    for w in str:
        if w == '(':
            stack.append(w)
        else:
            try:
                stack.pop()
            except IndexError:
                VPN = 'NO'
    #
    if stack: VPN = 'NO'
    print(VPN)
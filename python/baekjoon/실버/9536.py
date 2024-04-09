from sys import stdin as s
s = open('input.txt')
N = int(s.readline())
for _ in range(N):
    list = s.readline().split()
    wlist = []
    answer = ""
    while True:
        line = s.readline()
        if line == "what does the fox say?\n":
            break
        wlist.append(line.split()[2])
    for l in list:
        if l not in wlist:
            answer += l+' '
    print(answer)
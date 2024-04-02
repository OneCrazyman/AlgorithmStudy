from sys import stdin as s
s = open("input.txt")
N = int(s.readline())
count=0
for _ in range(N):
    word = s.readline().strip()
    length = len(word)
    if length == 1:
        continue
    blackList = []
    if word[0] == word[1]:
        count+=0
    elif word[1] in blackList:
        continue
    else:
        blackList.append(word[0])
    for i in range(2,length):
        if word[i-1] == word[i]:
            count+=0
        elif word[i] in blackList:
            count+=1
            break
        else:
            blackList.append(word[i-1])
print(N-count)
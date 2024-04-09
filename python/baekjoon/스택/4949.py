from sys import stdin as s
import re
s = open("input.txt")
answer = ""
while True:
    line = s.readline()
    if line == '.': #end
        break
    line = re.sub(r'[^(\)\[\]]', '', line)
    while True:
        if '()' in line:
            line = line.replace('()','')
        elif '[]' in line:
            line = line.replace('[]','')
        else: break
    answer+="no\n" if line else "yes\n"
print(answer,end="")
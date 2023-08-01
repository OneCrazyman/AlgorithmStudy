#백준5598_카이사르 암호 문제
word = input()
# A to ord 65 , Z to 90
result=''
for w in word:
    n = (ord(w)-3)
    if n < ord('A'):
        n = ord('Z') - (ord('A') - n - 1)
    result = result + chr(n)
print(result)
#백준2562_최댓값

max = 0
n = -1
for i in range(9): #9숫자 삽입
   num = int(input())
   if num > max:
      max = num
      n = i+1
   
print(max)
print(n)
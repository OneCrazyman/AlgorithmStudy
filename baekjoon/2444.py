#백준2444_별찍기7

n = int(input())
print(n)

#upper
for i in range(n):
    print(" "*(n-1-i)+"*"*(i*2)+"*")
#lower
for i in range(n-1):
    print(" "+" "*i+"*"*(n-2-i)*2+"*")
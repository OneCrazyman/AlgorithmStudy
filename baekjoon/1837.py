#암호제작

num=list(map(int,input().split()))

result = None
for i in range(2,num[1]):
    if num[0]%i==0:
        result = "BAD %i" % i
        break
if result: print(result)
else: print("GOOD")
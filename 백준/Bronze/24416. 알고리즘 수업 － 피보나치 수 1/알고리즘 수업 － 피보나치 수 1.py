n = int(input())

# def fib(n):
#     if (n==1 or n==2):
#         return 1
#     else:
#         return (fib(n-1)+fib(n-2))

def fibonacci(n):
    count = 0
    f = [0 for _ in range(40)]
    f[0] = f[1] = 1
    for i in range(2,n):
        count += 1
        f[i] = f[i-1] + f[i-2]
    return f[n-1], count

answer, count = map(str,fibonacci(n))
print(answer+' '+count)
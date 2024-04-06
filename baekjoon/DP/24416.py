import sys

n = int(input())

# def fib(n):
#     if (n==1 or n==2):
#         return 1
#     else:
#         return (fib(n-1)+fib(n-2))

def fibonacci(n):
    count = 0
    f = [0 for _ in range(41)]
    f[1] = f[2] = 1
    for i in range(3,n+1):
        count += 1
        f[i] = f[i-1] + f[i-2]
    return f[n], count

answer = fibonacci(n)
print(f"{answer[0]} {answer[1]}")
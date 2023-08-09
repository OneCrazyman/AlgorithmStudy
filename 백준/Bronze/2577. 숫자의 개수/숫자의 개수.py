#숫자의 개수

_list = [0]*10
_input = []
for i in range(3):
    _input.append(input())
n = list(map(int,_input))
mul = 1
for i, val in enumerate(n):
    mul *= val 
for i, val in enumerate(str(mul)):
    _list[int(val)] += 1
for i, val in enumerate(_list):
    print(val) 
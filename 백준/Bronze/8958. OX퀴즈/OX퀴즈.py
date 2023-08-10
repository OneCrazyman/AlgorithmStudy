#OX퀴즈
a = []
temp = []
result=0
n = int(input())
for i in range(n):
    a.append(input())
for _case in a:
    for i,value in enumerate(_case):
        if value == "O":
            temp.append(value)
        else: #value == "X"
            for _i, val in enumerate(temp):
                _i+=1
                result+=_i
            temp  = []
    for _i, val in enumerate(temp):
        _i += 1
        result += _i
    temp = []
    print(result)
    result = 0
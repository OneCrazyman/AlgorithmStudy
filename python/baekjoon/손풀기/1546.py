#평균
def solution():
    n=[]
    for i in range(2):
        n.append(input())
    n[0] = int(n[0]) #개수
    n[1] = list(map(int,n[1].split()))

    #최고점
    _max = n[1][0]
    for i in n[1]:
        if i > _max:
            _max = i
    _sum=0
    for i in n[1]:
        _sum+=i/_max*100
    return _sum/n[0]

print(solution())

#enumerate 함수를 이용해보자
#평균은넘겠지
case_l =[]
case_n = int(input())
for i in range(case_n):
    case_l.append(list(map(int,input().split())))

for case in case_l:
    sum=0
    for i in range(1,case[0]+1):
        sum+=case[i]
    avr = sum/case[0] #평균
    count=0
    for i in range(1,case[0]+1):
        if case[i] > avr:
            count +=1 
    result = count/case[0]*100

    print("%0.3f%%"% result)
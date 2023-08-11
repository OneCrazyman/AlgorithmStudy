P,K=map(int,input().split()) #입력을 공백으로 스플릿, int형변환화여 map화 P,K에 저장
print('GBOAODD'[any(l:=[
    i for i in range(2,K)
        if P%i<1
    ])::2],*l[:1])
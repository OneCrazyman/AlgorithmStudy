#백준1110_
count = 0
n = input()
intialNum = n
#일단 두자리수

while 1:
    # if int(n) < 10: n = '0' + n
    if len(n)==1: n='0'+n
    count += 1
    # one = n[0]
    # two = n[1]
    three = str(int(n[0]) + int(n[1]))
    if int(three) < 10: three = '0' + three
    #다시 두자리수
    n = str(int(n[1] + three[1])) #new number
    if n == intialNum: break
     
print(count)

#평균 40ms
#한자리수는 감별은 len()==1 을 사용하자 # --- 차이없음
#첫번째 시간 60ms 소요 
#두번째 시간 44ms 소요 #형변환과 변수사용을 줄임
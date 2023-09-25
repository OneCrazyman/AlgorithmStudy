from sys import stdin as s

# s = open("input.txt", "rt")

N = int(s.readline()) #회의수

arr = []
for _ in range(N): #배열 생성
    t1, t2 = map(int, s.readline().split())
    arr.append((t1, t2))
arr.sort(key=lambda x: x[0]) #시작시간으로 오름차순 정렬
# print(arr)
mo = arr[0][1]-arr[0][0] # mo : 맞다은 원소의 시작시간 차이
count = 1 #count 변수 : 회의실이 배정된 횟수, 1인 이유 = 아래 로직상 마지막 회의실 배정 카운트가 안되기에 미리 해줌
to = arr[0][0] #바로 전원소의 시작시간

t1,t2 = arr[-1]

# if t1==t2:
#     count-=1

#배정 알고리즘
for t1, t2 in arr: #정렬된 배열 순환
    mo -= t1-to #시작시간 차이만큼 제해줌
    to = t1
    m = t2 - t1 #현재 선택된 원소의 회의시간
    if mo <= 0: #mo가 0이하가 된다는것 = 현재 배정된 회의가 최선의 수, 그러므로 본 회의를 확정, 카운트
        mo = m #현재 원소로 회의를 새로 올린다 -> 이후 앞선과정 반복
        count += 1
        # print("count up.")
    if m < mo: #이전 회의시간보다 작으면 회의를 교체함 (짧게 걸리는 회의로 교체, 하지만 확정은 아직 아님)
        mo = m; continue
    # if t1 == t2:
    #     pass



print(count)
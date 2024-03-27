N = int(input())
lenth = 1+(N-1)*4
list = [[" "]*lenth for _ in range(lenth)]
def printList():
    for i in range(len(list)):
        for j in range(len(list)):
            print(list[i][j],end='')
        print('')
def roopStar(N,k):
    if N==1:
        list[k][k] = '*'
        return
    lenth = 1+(N-1)*4
    for i in range(lenth):
        list[k][k+i] = '*'
    for i in range(lenth-2):
        list[k+i+1][k] = '*'
        list[k+i+1][k+lenth-1] = '*'
    for i in range(lenth):
        list[k+lenth-1][k+i] = '*'
    roopStar(N-1,k+2)

roopStar(N,0)
printList()
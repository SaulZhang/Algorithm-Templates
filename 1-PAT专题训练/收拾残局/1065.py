n = eval(input())
for i in range(n):
    a,b,c = tuple(map(int,input().split()))
    if(a+b>c): print("Case #"+str(i+1)+": true")
    else: print("Case #"+str(i+1)+": false")

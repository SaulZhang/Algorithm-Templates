n = eval(input())
for i in range(n):
    a,b,c = tuple(input().split())
    a = eval(a)
    b = eval(b)
    c = eval(c)
    if(a+b>c):
        print("Case #"+str(i+1)+": true")
    else:
        print("Case #"+str(i+1)+": false")

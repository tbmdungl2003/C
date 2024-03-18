def UCLN(a,b):
    min=a if a<b else b
    for i in range(min,0,-1):
        if a % i ==0 and b%i==0:
             return i
        return 1
uoc =UCLN(10,20)
print(uoc)
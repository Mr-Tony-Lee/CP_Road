factor = [1]
mod = 1000000007
for i in range(1,1000001):
    factor.append(factor[i-1]*i % mod)
while True:
    try:
        num=int(input())
        if num % 2 == 1 :
            ans = factor[int(num/2)]**2 * num 
            print(ans % mod)
        else:
            ans = factor[int(num/2)]**2 
            print(ans % mod)
    except EOFError:
        break

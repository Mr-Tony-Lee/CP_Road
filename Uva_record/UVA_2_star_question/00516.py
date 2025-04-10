p = [False for i in range(32768)]
prime = []
for i in range(2,32768):
    if(p[i] == False):
        prime.append(i)
        for j in range(2*i , 32768 , i ):
            p[j] = True

while True:
    string = input()
    
    if string == "0": break

    factor = list(map(int,string.split(" ")))   # 把 split 出來的結果透過Map變成int，然後再變成 List 

    fact = []
    power = []
    
    num = 1
    for i in range(0,len(factor)-1,2):
        num *= factor[i]**factor[i+1]
    
    num -= 1 
    for i in range(len(prime)):
        if( num == 1 ): break
        if( num % prime[i] == 0 ):
            fact.append(prime[i])
            count = 0 
            while(num % prime[i] == 0):
                num /= prime[i]
                count += 1 
            power.append(count)
    if( num != 1 ):
        fact.append(num)
        power.append(1)

    for i in range(len(fact)):
        if (i != len(fact)-1):
            print(fact[len(fact)-1-i], power[len(fact)-1-i], end = " ")
        else :
            print(fact[len(fact)-1-i], power[len(fact)-1-i])
# prime = {2}
# table = [False for i in range(65000)]
# for i in range(3,65000,2):
#     if table[i] == False:
#         prime.add(i)
#         for j in range(2*i,65000,i):
#             table[j] = True

# C_num = set()

# for num in range(2,65000):
#     test = True 
#     if num in prime :
#         continue
#     for a in range(2,num):
#         if pow(a, num, num) != a :  # 這行快超多 !! 
#             test = False
#             break
#     if test and (num not in prime):
#         C_num.add(num)

# cheating code ... 
C_num = {2465, 1729, 15841, 46657, 2821, 62745, 63973, 6601, 52633, 8911, 1105, 561, 41041, 10585, 29341}
    
while True:
    num = int(input(""))
    if num == 0 :
        break
    # test = True 
    # if num in prime :
    #     print(f"{num} is normal.")
    #     continue

    # for a in range(2,num):
    #     if pow(a, num, num) != a :  # 這行快超多 !! 
    #         test = False
    #         break
    # if test and (num not in prime):
    if num in C_num:
        print(f"The number {num} is a Carmichael number.")
    else:
        print(f"{num} is normal.")
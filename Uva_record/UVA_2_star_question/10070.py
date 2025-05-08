kase = 0
while True:
    try:
        n = int(input())
        if kase > 0:
            print()
        kase += 1
        leap = False
        ordinary = False
        if (n % 4 == 0 and n % 100 != 0) or n % 400 == 0:
            print("This is leap year.")
            leap = True
            ordinary = True
        if n % 15 == 0:
            print("This is huluculu festival year.")
            ordinary = True
        if n % 55 == 0 and leap:
            print("This is bulukulu festival year.")
            ordinary = True
        if not ordinary:
            print("This is an ordinary year.")
    except EOFError:
        break
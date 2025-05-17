while True:
    try:
        a = int(input())
        b = int(input())
        result = a * b
        print(result)
    except EOFError:
        break
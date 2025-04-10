while True:
    try:
        print(eval(input()))
    except EOFError:
        break
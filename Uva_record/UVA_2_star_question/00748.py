while True:
    try:
        In = input("")
        a = In[:In.find(" ")]
        b = In[In.find(" "):]
        point_a = len(a) - a.find(".") - 1    # a 在小數點後有幾位
        a = a.replace(".","")
        num = int(a) ** int(b)

        ans = str(num)

        num_point_num = point_a * int(b)

        if(len(ans) <= num_point_num):
            ans = "."+ (num_point_num-len(ans))*'0' + ans
            ans.lstrip('0')
            ans.rstrip('0')
        else:
            ans = ans[:len(ans)-num_point_num]+ "." + ans[len(ans)-num_point_num:].rstrip("0")
            
        print(ans)
    except EOFError:
        break

'''
95.123 12
0.4321 20
5.1234 15
6.7592  9
98.999 10
1.0100 12

'''
try:
    s = input()
    tmp = s.replace("+", "^")
    tmp = tmp.replace("-", "^")
    tmp = tmp.replace("/", "^")
    tmp = tmp.replace("*", "^")
    eval(tmp)
    s = s.replace("/", "//")
    print(int(eval(s)))
except:
    print("ROCK")

def cube_count(a):
    if is_number(a):
        return a **3
    else:
        print("非数字不饿能计算立方值")
def is_number(a):
    if not isinstance(a,(int,float)):
        print("请重新输入")
        return False
    else:
        return True
c=cube_count(eval(input()))
print(c)

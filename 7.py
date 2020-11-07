f=open('sha.txt','r')
data=f.read()

def wordCount(data):
    re = {}
    for i in data:
        re[i] = re.get(i,0) + 1
    return re
if __name__ == "__main__":
    data=data.split()
print ("The result is %s" % wordCount(data))

#!/usr/bin/python3
import base64 as b64
import string
s = string.ascii_lowercase[:10] + "012345"
file = open("./flag.txt",'r')
data = file.read().encode("utf-8")
flag = b64.b64encode(data)
fleg = str(flag)[2:-1]
enc = ""
for i in fleg:
    binary = "{0:08b}".format(ord(i))
    char1 = s[int(binary[:4],2)]
    char2 = s[int(binary[4:],2)]
    enc += (char1 + char2)
print(enc)

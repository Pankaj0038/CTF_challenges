#!/usr/bin/python3
import hashlib

enc = open("output.txt","r").read()

def decrypt(enc):
	str_int_val = ''
	for i in enc:
		if i.isalpha():
			str_int_val+=str(ord(i))
		else:
			str_int_val+=i
	hashed_flag = hex(int(str_int_val))
	return hashed_flag[2:]
#print(decrypt(enc))

rockyou = (open("/home/gumn4m1/Downloads/rockyou.txt","rb").readlines())
for i in rockyou:
	hashed = (hashlib.sha256((str(i)[2:-3]).encode())).hexdigest()
	if str(hashed)==str(decrypt(enc)):
		print(str(i)[2:-3])
		break
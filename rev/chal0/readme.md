# Chal0
---

### Challenge
Here is the challenge code

```bash
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

# output : fdg1e4fffcg4hefde3ddf0gge3fie4gge3h0fbdbgffidae
```

1. In this code I firsty encoded the message in base64 
2. Then convert each character in 8 bit binary number 
3. Then split the binary number in length on 4
4. Lastly I print the character from the 's' string corresponding to the index value that we got by converting the binary number

### Solution

To reverse the code participants need to follow the steps:
1. Find the index of the output characters in the 's' string
2. convert the number in 4 bit numbers
3. Then run a loop jumping 2 step at a time and add 2 binary into one 8 bit binary number
4. COnvert the binary to character and append them in a string
5. lastly decode the message from base64

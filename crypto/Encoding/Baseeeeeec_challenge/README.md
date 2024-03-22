# Basic challenge
---
Encoded text : U0xBWXtRMzRWRV8wR19JUkhSREJ9
Hint: Baseeec challenge

---
Solution:
To solve this challenge user need to decode the encoded message using base64 decoding algorithm.

### code to decode the message
Note: <i>As there is no "=" at the end of the message so I didn't consider the extra padding bits</i>
```bash
#!/usr/bin/env python3
message= 'U0xBWXtRMzRWRV8wR19JUkhSREJ9'
char = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
li = []
for i in range(0,len(message)):
    for j in range(0,len(char)):
        if enc[i] == char[j]:
            li.append(str(j))
binary = ''
flag =''
for num in li:
    binary += "{0:06b}".format(int(num))
chunks = [binary[i:i+8] for i in range(0,len(binary),8)]        
for i in chunks:
    flag += chr(int(i,2))
print(flag)
```

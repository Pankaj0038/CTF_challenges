# Rottor
---
Encoded text: ${p*L\`d44dc4g64e\`fc2f4ccc\`4a\`73_\`g255N  <br>
Hint: rotate it , break it , decipher it !!

---
### code
To decipher the message user need to use rot47 algorithm
```bash
#!/usr/bin/env python3
li = []
for i in range(33,127):
    li.append(chr(i))
enc = ''
for char in flag:
    enc += li[((ord(char)-33)+47)%94]
print(enc)
```

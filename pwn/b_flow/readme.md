# b_flow
---
### Category : <i>Binary Exploitation</i>
---

#### Requirements
- Python
- SocketServer module
- pwntools library
- Ngrok

Download all the requirements
   ```bash
   python -m pip install requirements.txt
   ```

#### Description
In this challenge a binary file "fl0w" will be provided to the user with a netcat command,
```bash
  nc <IP router provided> 6667 # ncat for windows
   ```
The binary file is created from the C program "chal2.c" which contains a vulnerability related to "buffer overflow"<p>
```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void ret2win(){
        int key = 0;
        char buffer[32];
        printf("  _____   _                 _     _ \n");
        printf(" / ____| | |         /\\    | |   | |\n");
        printf("| (___   | |        /  \\    \\ \\_/ / \n");
        printf(" \\___ \\  | |       / __ \\    \\   / \n");
        printf(" ____) | | |____  / ____ \\    | |  \n");
        printf("|_____/  |______|/_/    \\_\\   |_|  \n");
        printf("You need to bypass me to get the flag: \n");
        printf(">");
        fflush(stdout);
        gets(buffer);
        if(key==0xf007ba11){
                printf("Redacted\n");
                printf("%04x\n",key);
                fflush(stdout);
        }
        else{
                printf("F4k3_k3y\n");
                printf("%04x\n",key);
                fflush(stdout);
        }
}

int main(int argc , char* argv[]){
        ret2win();
        return 0;
}  
```
</p>

#### Create the binary file from the C code
---

```bash
gcc filename.c -o output -fno-stack-protector -z execstack -no-pie -m32
```

It uses "gets" function which can be exploited to get sensitive information

```bash
chal2.c: In function ‘ret2win’:
chal2.c:17:9: warning: implicit declaration of function ‘gets’; did you mean ‘fgets’? [-Wimplicit-function-declaration]
   17 |         gets(buffer);
      |         ^~~~
      |         fgets
/usr/bin/ld: /tmp/ccWKPnr3.o: in function `ret2win':
chal2.c:(.text+0xc0): warning: the `gets' function is dangerous and should not be used.
```


#### Run the challenge in your local area network
---

To run the code we need to create a socket server in our localhost on any free port (here I used 6667)

```python
#!/usr/bin/python

import socketserver # to create a socket server
import time
import threading
import pwn # to run sub process

class Service(socketserver.BaseRequestHandler):
        def handle(self):
                # this is where we will handle the connection , do what we want to do once someone connects 
                print("Someone Connected")
                io = pwn.process("./b0flow")
                self.send(io.recvline().decode())
                self.send(io.recvline().decode())
                self.send(io.recvline().decode())
                self.send(io.recvline().decode())
                self.send(io.recvline().decode())
                self.send(io.recvline().decode())
                self.send(io.recvline().decode())
                entered = self.recieve()
                io.sendline(entered)
                self.send(io.recvline().decode())
                self.send(io.recvline().decode())

        def send(self, string , newline = True):
                if newline: string = string 
                self.request.sendall(bytes(string,'utf-8'))     # this request object is internal to the base request handler and used to send data to the client 

        def recieve(self, prompt = ">"):
                self.send(prompt, newline= False)
                return self.request.recv(4096).strip()         # to recieve data from the client 

class TheadedService(socketserver.ThreadingMixIn , socketserver.TCPServer , socketserver.DatagramRequestHandler):
        #this class doesn't need to anything but we need it to exist to make the threaded service and serve it up
        pass


def main():
        port = 6667                     # port to run the challenge
        host = "127.0.0.1"              # visible to LAN

        service = Service

        # server object , using host and port , hosting our service
        server = TheadedService((host,port),service)

        # make the port reusable
        server.allow_reuse_address = True

        # thread the service ! 
        server_thread = threading.Thread(target = server.serve_forever)
        server_thread.start()

        print("Server started on port", port)

        # wait and do nothing
        while True : time.sleep(60)

if __name__ == "__main__":
        main() 
```

Check your IP address : {IP}
   ```bash
   ipconfig # for Windows
   ```
   ```bash
   ifconfig # for Linux
   ```
Run the python program mentioned above ("netc_file_1.py")

Connect it on the client machine
   ```bash
   nc {TCP channel} 6667
   ```

#### Forward the port using Ngrok to run on a public network
---
- Go to https://Ngrok.com and [download](https://ngrok.com/download) ngrok , also [sign up](https://dashboard.ngrok.com/signup) on the website
- go to your dashboard and get your [auth-token](https://dashboard.ngrok.com/get-started/your-authtoken)
- set your environment
  ```bash
  ngrok config add-authtoken <your auth-token> 
  ```
- to forward this code on local tcp port
  ```bash
  ngrok tcp 6667 # 6667 is the port in which I host my service (basically it runs my localhost service in a public channel)

  ```
- there you will get  a tcp channel link like in my case <b><i>tcp://0.tcp.ap.ngrok.io:17426</b></i>
```bash
ngrok                                                                                              (Ctrl+C to quit)
                                                                                                                   
Build better APIs with ngrok. Early access: ngrok.com/early-access                                                 
                                                                                                                   
Session Status                online                                                                               
Account                       PANKAJ BARMAN (Plan: Free)                                                          
Version                       3.5.0                                                                                
Region                        Asia Pacific (ap)                                                                    
Latency                       -                                                                                    
Web Interface                 http://127.0.0.1:4040                                                                
Forwarding                    tcp://0.tcp.ap.ngrok.io:17426 -> localhost:6667                                      
                                                                                                                   
Connections                   ttl     opn     rt1     rt5     p50     p90                                          
                              0       0       0.00    0.00    0.00    0.00 
```
- run this on client side
  ```bash
  nc 0.tcp.ap.ngrok.io 17426
  ```
  That's it
  
```bash
    _____   _                 _     _ 
   / ____| | |         /\    | |   | |
  | (___   | |        /  \    \ \_/ / 
   \___ \  | |       / __ \    \   / 
   ____) | | |____  / ____ \    | |  
  |_____/  |______|/_/    \_\   |_|  
  You need to bypass me to get the flag: 
  >
```

import socket

try:
    socket_op = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    portList = [22,80,443]

    ip = socket.gethostbyname("www.google.com")
    print(ip)
    socket_op.settimeout(1)

    for i in portList:
        scan = socket_op.connect_ex((ip,i))
        if scan == 0:
            print(f"{i} is openned : service {socket.getservbyport(i)}")
        else:
            print(f"{i} is closed : service {socket.getservbyport(i)}")

except socket.error as e:
    print(e)
finally:
    socket_op.close()
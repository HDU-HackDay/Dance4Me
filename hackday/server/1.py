from socket import *
from time import ctime
import struct


def reverse(original):
    t = original
    t.reverse()
    return t


def decode(data):
    print(data)
    type1 = data[1]
    type2 = data[2]
    module_id = int.from_bytes(data[3:7], byteorder='big')
    distance = struct.unpack('f', reverse(data[7:11]))[0]
    breath = struct.unpack('f', reverse(data[11:15]))[0]
    heartbeat = struct.unpack('f', reverse(data[15:19]))[0]
    visibility = struct.unpack('f', reverse(data[19:23]))[0]
    result = int.from_bytes(data[23:27], byteorder='big')
    return type1, type2, module_id, distance, breath, heartbeat, visibility, result


# a = bytearray(b'\x7D\x50\x01\x00\x00\xEA\x61\x40\x1C\xCC\xCD\x41\x20\x00\x00\x42\x94\x00\x00\x41\x9C\xB6\x49\x00\x00\x00\x02\x6D\x7E')
# print(decode(a))

bufsize = 28
addr = ('192.168.1.255', 9000)
udpServer = socket(AF_INET, SOCK_DGRAM)
udpServer.bind(addr)

sock = socket(AF_INET, SOCK_DGRAM)
while True:
    print('Waiting for connection...')
    data, addr = udpServer.recvfrom(bufsize)  #接收数据和返回地址
    print(decode(bytearray(data)))
    # print("at %s: %s" % ctime(), decode(data))

    sock.sendto(str.encode(str(data[5]) + '\0\0'), ("115.159.152.245", 12346))

udpServer.close()
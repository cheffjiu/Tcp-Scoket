#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>
#include<string>
#include<thread>
#include<vector>

constexpr int PORT = 8080;
constexpr int BUFSIZE = 1024;
constexpr char SERVER_IP[] = "127.0.0.1";
#endif

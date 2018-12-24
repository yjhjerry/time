#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>

#define LISTENQ     1024
#define MAXLINE 	4096
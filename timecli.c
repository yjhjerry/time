#include "time.h"

void err_quit(char *);

int main(int argc, char const *argv[])
{
	int sockfd, n;
	char recvline[MAXLINE + 1];
	struct sockaddr_in servaddr;

	if(argc != 2)
		err_quit("Usage: ./a.out <IPaddres>");
	
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) <0 )
		err_quit("Socket error");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);

	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
		err_quit("Error converting ASCII IP address to binary format");

	if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) <0 )
		err_quit("connect error");

	while((n = read(sockfd, recvline, MAXLINE)) > 0 ) {
		recvline[n] = 0;
		if(fputs(recvline, stdout) == EOF )
			err_quit("fputs error");
	}

	if ( n < 0 )
		err_quit("read error");

	return 0;
}

void err_quit(char *msg)
{
	printf("%s\n", msg);
	exit(-1);
}
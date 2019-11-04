#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	int fd = open("list1.txt", O_WRONLY|O_CREAT|O_TRUNC, 0700);
	char buf[] = "101   GM\tBuick\t2010\n102   Ford\tLincoln\t2005";
	write(fd, buf, 50);
	close(fd);
	return 0;
}

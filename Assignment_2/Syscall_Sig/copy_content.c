#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2, nbytes;

    //Opening file1 to read the data from the file
	fd1 = open("alpha.txt",O_RDONLY);

    //Opening file2 to write the data which is in file1 to file2
	fd2 = open("beta.txt",O_WRONLY|O_CREAT, 0666);

    //Checking the condition of the file
	if(fd1<0 || fd2<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen = 128;
	char buf[maxlen];

    //Reading nbytes from the file1
	nbytes=read(fd1,buf,maxlen);

    //Checking whether the data was added into file2 from file1 are not
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
    
    //Writing read into file2
	write(fd2,buf,nbytes);

    //Closing the files which are opened
	close(fd1);
    close(fd2);
	return 0;
}

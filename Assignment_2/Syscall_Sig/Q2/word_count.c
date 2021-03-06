#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd, nbytes;
	char ch[16384];
    int char, word, lin;
	fd=open("sample.txt",O_RDONLY);

	if(fd<0)
	{
		perror("open");
		exit(1);
	}

   
    word = 0,lin = 0;
    while(nbytes = read(fd,ch,sizeof(ch)))
    {
        for(int i=0;i<nbytes;i++)
        {
            //Check new line
            if (ch[i] == '\n')
               lin++;

            //Check words */
            if (ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\n')
               word++;
        }
        char = nbytes;
    }

    printf("Total characters : %d\n", char);
    printf("Total words      : %d\n", word);
    printf("Total lines      : %d\n", lin);


    //Close files to release resources
    close(fd);

    return 0;
}

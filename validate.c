#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

//if user need help, then this will be displayed
void usage_help()                                   
{
	line();
    	printf("                            ::: Help Menu :::\n");
    	line();
	printf("USAGE :\nTo view please pass like     : ./a.out -v mp3filename\n");
    	printf("To edit please pass like     : ./a.out -e -t/-a/-A/-y/-C/-c mp3filename\n");
    	printf("    -t      Modifies Title tag\n");
    	printf("    -a      Modifies Artist tag\n");
    	printf("    -A      Modifies Album tag\n");
    	printf("    -y      Modifies Year tag\n");
    	printf("    -c      Modifies Content tag\n");
    	printf("    -C      Modifies Comment tag\n");
	line();
}

//if the input is not proper it enters 

void input_check(int argc,char* argv[])
{
	line();
	printf("ERROR:");
	for(int i = 0; i < argc; i++)
    	{
        	printf("%s ",argv[i]);
    	}
    	printf(":INVALID ARGUMENTS\n");
    	printf("USAGE :\nTo view please pass like     : ./a.out -v mp3filename\n");
    	printf("To edit please pass like     : ./a.out -e -t/-a/-A/-y/-C/-c mp3filename\n");
    	printf("For help please pass like    : ./a.out --help\n");
	line();
}

int header_check(char* str) //function for checking whether it is ID3 or not
{
	if(strcmp("ID3",str) != 0)
    	{
		line();
        	printf("FILE IS NOT AN MP3 FILE\n");
		line();
        	exit(0);
    	}
    	else
        	return 1; 
}


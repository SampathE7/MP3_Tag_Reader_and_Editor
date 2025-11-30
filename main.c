#include <stdio.h>
#include <string.h>
#include "header.h"

int main(int argc,char* argv[])
{
	
    	if(argc == 3 && strcmp(argv[1], "-v") == 0)
        	mp3_view(argc,argv); //handles the view option

    	else if (argc == 5 && strcmp(argv[1], "-e") == 0 && ((strcmp(argv[2], "-t") == 0)||(strcmp(argv[2], "-a") == 0) ||
                        				(strcmp(argv[2], "-A") == 0) ||(strcmp(argv[2], "-y") == 0) ||
                        				(strcmp(argv[2], "-C") == 0) ||(strcmp(argv[2], "-c") == 0)))
        	mp3_edit(argc,argv); //handle edit option

    	else if(argc == 2 && strcmp(argv[1], "--help") == 0)
        	usage_help(); //handles help options

    	else
        	input_check(argc,argv); //handle invalid input

    	return 0;
}

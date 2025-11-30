/*
NAME : T.Sampath
DATE : 28-10-25
PROJECT : MP3 Tag Reader/Editor

This project is a simple program that lets you read and edit MP3 song details like title, artist, album, year, contents
and comments. It works from the command line and helps understand how media players store song information such as Title, 
Artist, Album, Year, Contents and Comment within the MP3 file header. Various Functions such as String functions, 
File handling functions, Built in functions, Pointers, Loops concepts, 2D arrays 
and Operators are used to create this project.

Features:
1. View existing MP3 tag information (-v option)
2. Edit specific tags such as title, artist, or album (-e option)
3. File validation and error handling for missing or invalid MP3 files
4. Uses file I/O and byte-level data manipulation to access tag data
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void line()
{
	printf("+---------------------------------------------------------------------------------+\n");
}

void mp3_view(int argc,char* argv[])
{ 
	FILE* fp = fopen(argv[2], "r"); //opening mp3 file
    	if(fp == NULL)  //for file checking
    	{
        	printf("THERE IS NO SUCH FILE!\n");
		input_check(argc,argv);
        	exit(0);
    	}

	char header[4]; //creating header varible
    	fread(header, 3, 1, fp); //To read first 3 bytes which is ID3 header
    	header[3] = '\0';
    
	//checking whether file is mp3 file
	if(header_check(header)) 
    	{
        	line();
		printf("\t\tThe File is mp3\n");
    	}

	line();
    	printf("\t\tMP3 Tag Reader and Editor for ID3v2\n");
	line();
    	fseek(fp,7,SEEK_CUR); //To skip next 7 bytes

	//iterates 6 times for reading 6 mp3 tags
    	for(int i = 0; i <6; i++)                      
    	{
        	char tag[5]; //create a tag variable to store the tag
        	fread(tag, 4, 1, fp);  //read tag
        	tag[4] = '\0';

        	char mp3tag[6][5] = {"TIT2", "TPE1", "TALB", "TYER", "TCON", "COMM"};//array which stores the tags
        	char mp3tit[6][15] = {"Title", "Artist", "Album", "Year", "Contents", "Comments"}; //array which stores titles
        	
		//if tag matches, we will print the title...
		for(int j=0; j<6; j++)
        	{
            		if(strcmp(tag,mp3tag[j]) == 0)
            		{
                		printf("%-20s     : ",mp3tit[j]);
            		}
        	}

        	int size;
        	fread(&size, 4, 1 ,fp);   //for reading tag size content

        	endianness_conversion(&size);  //function for converting big endian to little endian

        	fseek(fp,3,SEEK_CUR); //for skipping flag and null
        
        	char content[size]; //creating array of content size
		for(int i=0; i< size-1; i++)
        	{
            		fread(&content[i], 1, 1,fp); //reading characters to array byte by byte
        	}
        	content[size - 1] = '\0';

        	printf("%s\n",content); //printing the characters

    	}
    	line();
	fclose(fp);
}

//function that converts size from Big endian to Little endian
void endianness_conversion(int *size)                     
{
	char* ptr = (char*) size;
    	for (int i = 0; i < 2; i++)
    	{
        	char temp = ptr[i];
       		ptr[i] = ptr[3 - i];
        	ptr[3 - i] = temp;
    	}
}

#ifndef HEADER_H
#define HEADER_H

void mp3_view(int argc, char* argv[]);
void endianness_conversion(int *size);
void input_check(int argc, char* argv[]);
void mp3_edit(int argc, char* argv[]);
void usage_help();
int header_check(char* str);
void line();

#endif

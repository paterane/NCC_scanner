// Program    : scan.c
// Created by : Peter Oo
// Created on : 1/20/2023 (1:04 PM).
// About      : implemented user input function

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char *scanner();

int main(){
    char *userIn = scanner();
    printf("%s\n", userIn);
    free(userIn);
    return 0;
}

char *scanner(){
    char *buff =(char*)(malloc(sizeof(char)));
    int ch = 0;
    int idx = 0;
    while((ch=getch()) != '\r'){
        if(ch >= 32 && ch <= 126){
            buff[idx++] = (char)ch;
            printf("%c", ch);
            buff = (char*)(realloc(buff, (idx+1)*sizeof(char)));
        }
        else if(ch == '\b'){
            if(idx>0){
                buff[--idx] = '\0';
                printf("\b%c\b", 32);
                buff = (char*)(realloc(buff, (idx+1)*sizeof(char)));
            }
        }
        else if(ch == '\t'){
            for(int i=0; i<4; i++){
                buff[idx++] = 32;
                printf("%c", 32);
                buff = (char*)(realloc(buff, (idx+1)*sizeof(char)));
            }
        }
        else if(ch == 127){
            if(buff[idx-1] == 32){
                while(buff[idx-1] == 32 && idx > 0){
                    buff[--idx] = '\0';
                    printf("\b%c\b", 32);
                    buff = (char*)(realloc(buff, (idx+1)*sizeof(char)));
                }
            }
            else{
                while(buff[idx-1] != 32 && idx > 0){
                    buff[--idx] = '\0';
                    printf("\b%c\b", 32);
                    buff = (char*)(realloc(buff, (idx+1)*sizeof(char)));
                }
            }
        }
        buff[idx] = '\0';
    }
    printf("\n");
    return buff;
}

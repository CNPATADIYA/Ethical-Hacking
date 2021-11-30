#include<stdio.h>
#include<string.h>
void greeting(char *temp1,char *temp2){
    char name[10];
    strcpy(name,temp2);
    printf("Hello %s %s\n",temp1,name);
}
void main(int argc,char* argv[]){
	
    //char a[10];
    //strcpy(a,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    greeting(argv[1],argv[2]);
    printf("Bye %s %s\n",argv[1],argv[2]);
}

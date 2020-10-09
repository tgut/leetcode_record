#include<stdio.h>
// #include<stdbool.h>

int strStr(char* haystack,char* needle){
    char* ch1, *ch2;
    ch1=haystack;
    ch2=needle;
    printf("ch1:%s;\nch2:%s\n",ch1,ch2);
    while((ch1 != NULL) && (ch2 != NULL)){
       
        if((*ch1) == (*ch2)){
            ch2++;
        }
        else{
            ch2=&needle;
        }
        ch1++;    
    
    }
    if(ch2==NULL){
        return 0;
    }

    return -1;
        
}
 void main(){
     char* haystack;
     char* needle;
     while(1){
         printf("input data haystack,eedle:\n");

        scanf("%s,%s",*haystack,*needle);
        printf("ch1:%s;\nch2:%s\n",haystack,needle);   
        if(strStr(haystack,needle) == 0){
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
     }
    
 }
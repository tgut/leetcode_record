#include<stdio.h>
#define false 0
#define true 1
typedef int bool;
int lengthOfLongestSubstring(char * s){
    /*save data state isExist*/
    bool exist_array[256]; 
    /*save data exist position*/
    int postion_array[256]; 
    /*
        i to iterate the string;
        start to record unrepeat position;
        max_length record the Longest substring Length;
    */
    int i = 0,start = 0,max_length = 0;
    /*init exist and positon array*/
    for(i = 0; i < 256;i++)
    {
        exist_array[i] = false;
        postion_array[i] = 0; 
    }
    /*iterator the string*/
    i=0;
    while(*(s+i) != NULL)
    {
        if(exist_array[*(s+i)])
        {
            for(int j = start;j <  postion_array[*(s+i)];j++ )
            {
                exist_array[*(s+j)] = false;//the merchanic for what purpose.
            }
            /*update the unrepeat position*/
            start = postion_array[*(s+i)] + 1;
            postion_array[*(s+i)] = i ;
        }
        else
        {
            exist_array[*(s+i)] = true;
            postion_array[*(s+i)] = i ;
            max_length = max_length > (i - start + 1)? max_length:(i - start + 1);
        }
        i++;
    }
    return max_length;
 }

 int main()
{   
    int length = 0;
    char a[]="pwwkew";
    length = lengthOfLongestSubstring(a);
    printf("length = %d\n",length);
    return 0;
}
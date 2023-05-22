#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#include <libtranslate/libtranslate.h>

char* all_upper(char *from,int size)
{
    for(int i = 1;i < size;i += 2){
        if(((from[i] >= -80 && from[i] <= -65) && from[i - 1] == -48) ||
        ((from[i] >= -128 && from[i] <= 113) && from[i - 1] == -47) ||
        (from[i] == -111 && from[i - 1] == -47)){
            if(((from[i] >= -80 && from[i] <= -65) && from[i - 1] == -48)){
                from[i] -= 32;
            }else if(((from[i] >= -128 && from[i] <= -113) && from[i - 1] == -47)){
                from[i] += 32;
                from[i - 1]--;
            }else{
                from[i] -= 16;
                from[i - 1]--;
            }
        }
    }
    return from;
}

void write_in_arr(char *in,char *from,int index)
{
    int ind = 0;

    while(ind != index){
        in[ind] = from[ind];
        ind++;
    }
}

char punctuation_in_word(char *arr)
{
    if(arr[strlen(arr) - 1] == '.' || arr[strlen(arr) - 1] == ',' ||
    arr[strlen(arr) - 1] == ':' || arr[strlen(arr) - 1] == ';' ||
    arr[strlen(arr) - 1] == '?' || arr[strlen(arr) - 1] == '!')
        return arr[strlen(arr) - 1];

    return '\0';
}
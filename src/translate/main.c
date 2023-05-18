#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>

#include <libtranslate/libtranslate.h>

int main(int argc,char *argv[])
{
    FILE *rus = fopen(argv[1],"r");
    FILE *dict = fopen(argv[2],"r");
    FILE *eng = fopen(argv[3],"w");

    if(rus == NULL || dict == NULL || eng == NULL){
        printf("Can't open file\n");
        return 0;
    }else if(argc != 4){
        printf("Error argument\n");
        return 0;
    }
    
    while(feof(rus) == 0){
        char *word_rus = (char *)malloc(sizeof(char) * SIZE_WORD);
        int flag = 0;

        fscanf(rus,"%s\n",word_rus);

        while(feof(dict) == 0){
            char *dict_rus_copy = (char *)malloc(sizeof(char) * SIZE_WORD);
            char *word_rus_copy = (char *)malloc(sizeof(char) * SIZE_WORD);
            char *word_dict = (char *)malloc(sizeof(char) * SIZE_STRING);
            char symbol;
            int index_word_dict = 0;

            fgets(word_dict,SIZE_STRING,dict);

            while(word_dict[index_word_dict] != ' ')
                index_word_dict++;

            char *dict_rus = (char *)malloc(sizeof(char) * index_word_dict);

            write_in_arr(dict_rus,word_dict,index_word_dict);
            strcpy(dict_rus_copy,dict_rus);
            all_upper(dict_rus_copy,strlen(dict_rus_copy));
            strcpy(word_rus_copy,word_rus);

            if(punctuation_in_word(word_rus_copy) != '\0'){
                symbol = punctuation_in_word(word_rus_copy);
                word_rus_copy[strlen(word_rus_copy) - 1] = '\0';
            }

            all_upper(word_rus_copy,strlen(word_rus_copy));

            if(strcmp(dict_rus_copy,word_rus_copy) == 0){
                char *word_eng = (char *)malloc(sizeof(char) * 20);
                int index_dict_eng = 0;

                for(size_t n = 0;n < strlen(word_dict);n++){
                    if(isalpha(word_dict[n]) != 0){
                        word_eng[index_dict_eng] = word_dict[n];
                        index_dict_eng++;
                    }
                }

                if(punctuation_in_word(word_rus) != '\0')
                    fprintf(eng,"%s%c ",word_eng,symbol);
                else
                    fprintf(eng,"%s ",word_eng);

                free(word_eng);
                flag = 1;
            }

            free(word_dict);
            free(dict_rus_copy);
            free(word_rus_copy);
        }
        fseek(dict,0,SEEK_SET);

        if(flag == 0)
            fprintf(eng,"%s ",word_rus);

        if(punctuation_in_word(word_rus) != '\0')
            fprintf(eng,"%c",'\n');

        free(word_rus);
    }

    fclose(rus);
    fclose(eng);
    fclose(dict);

    return 0;
}
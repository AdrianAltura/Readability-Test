#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float computeIndexL(char sen[]);
float computeIndexS(char sen[]);

int main(void){

    char text[900000];
    char text1[900000];
    float result;
    float l,s;

    printf("Text: ");
    fgets(text, 2000, stdin);

    printf("Your text input: %s\n", text1);

    strcpy(text1, text);

    l = computeIndexL(text);
    s = computeIndexS(text1);

    result = (0.0588*l) - (0.296*s) - 15.8;
    result = round(result);

    if (result < 1){
        printf("Before Grade 1\n");
    }
    else if (result > 1 && result < 16){
        printf("Grade %d\n", (int) result);
    }
    else{
        printf("Grade 16+\n");
    }
}

float computeIndexL(char sen[]){

    char * token = strtok(sen, " ");
    float letters = 0;
    float words_L = 0;

    while (token != NULL){
        for (int i = 0; i < strlen(token); i++){
           if (('A' <= token[i] && token[i] <= 'Z') || ('a' <= token[i] && token[i] <= 'z')){
                letters += 1;
           }
        }
        words_L += 1;
        token = strtok(NULL, " ");
    }

    float l = (letters / words_L) * 100;

    //code below used to see variables if correct
    // printf("Letters: %f\n", letters);
    // printf("words_L: %f\n", words_L);
    // printf("L: %f\n", l);

    return l;
}

float computeIndexS(char sen[]){

    char copy[2000];
    strcpy(copy, sen);
    char * token = strtok(sen, " ");
    float words_S = 0;
    float sentences = 0;

    while (token != NULL){
        for (int i = 0; i < strlen(token); i++){
            if (token[i] == '.' || token[i] == '!' || token[i] == '?'){
                sentences += 1;
            }
        }
        words_S += 1;
        token = strtok(NULL," ");
    }

    float s = (sentences/words_S) * 100;

    //code below used to see variables if correct
    // printf("Sentences: %f\n", sentences);
    // printf("words_S: %f\n", words_S);
    // printf("S: %f\n", s);

    return s;
}

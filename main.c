#include <stdio.h>
#include <stdbool.h>

void printOutContact(char *name, char *number){
    printf("%s\n", name);
    printf("%s\n", number);
}

int main(int argc, char *argv[]) {
    char fileLine[101];
    int matches = 0;
    char phone[50];
    char name[50];
    bool isNumberLine = false;
    char *argument = NULL;
    if(argc == 2){
        argument = argv[1];
        printf("%s\n", argument);
    }else {
        while (fgets(fileLine, sizeof(fileLine), stdin)){
            printf("%s", fileLine);
        }
    }
    while (fgets(fileLine, sizeof(fileLine), stdin)){
        if(sizeof(fileLine) <= 101){
            if(!isNumberLine){
                int index = 0;
                while(fileLine[index] != '\n' && fileLine[index] != '\0'){
                    name[index] = fileLine[index];
                    index++;
                }
                name[index + 1] = '\0';
                isNumberLine = true;
            }else{
                int index = 0;
                while(fileLine[index] != '\n' && fileLine[index] != '\0'){
                    phone[index] = fileLine[index];
                    index++;
                }
                isNumberLine = false;
                phone[index + 1] = '\0';

            }
        }else{
            //error filed input
        }
    }
    if(matches == 0){
        printf("No matches found!");
    }
    return 0;
}
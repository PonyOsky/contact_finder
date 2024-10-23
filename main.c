#include <stdio.h>
#include <stdbool.h>

void printOutContact(char *name, char *number){
    printf("%s\n", name);
    printf("%s\n", number);
}

int main(void) {
    char buffer[101];
    int matches = 0;
    char phone[50];
    char name[50];
    bool isNumberLine = false;
    while (fgets(buffer, sizeof(buffer), stdin)){
        if(sizeof(buffer) <= 101){
            if(!isNumberLine){
                int index = 0;
                while(buffer[index] != '\n' && buffer[index] != '\0'){
                    name[index] = buffer[index];
                    index++;
                }
                name[index + 1] = '\0';
                isNumberLine = true;
            }else{
                int index = 0;
                while(buffer[index] != '\n' && buffer[index] != '\0'){
                    phone[index] = buffer[index];
                    index++;
                }
                isNumberLine = false;
                phone[index + 1] = '\0';

            }
        }
    }
    if(matches == 0){
        printf("No matches found!");
    }
    return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_ACCEPTED_ROW_SIZE 101
#define ZERO {'+'}
#define TWO {'a', 'A', 'b', 'B', 'c', 'C'}
#define THREE {'d', 'D', 'e', 'E', 'f', 'F'}
#define FOUR {'g', 'G', 'h', 'H', 'i', 'I'}
#define FIVE {'j', 'J', 'k', 'K', 'l', 'L'}
#define SIX {'m', 'M', 'n', 'N', 'o', 'O'}
#define SEVEN {'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S'}
#define EIGHT {'t', 'T', 'u', 'U', 'v', 'V'}
#define NINE {'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z'}
#define SHORT_ALT 6
#define LONG_ALT 8

int callError(int errNum){
    switch (errNum){
        case 0:
            fprintf(stderr, "Input file not found.\n");
            return 1;
        case 1:
            fprintf(stderr, "Input file format is invalid.\n");
            return 1;
    }
}

bool isFileInvalid(FILE *file){
    if(file == NULL){
        callError(0);
    }
    char checkLine[MAX_ACCEPTED_ROW_SIZE];
    int checkSum;
    while(fgets(checkLine, sizeof(checkLine), stdin)){
        if(sizeof(checkLine) > MAX_ACCEPTED_ROW_SIZE){
            return true;
        }
        checkSum++;
    }
    if(checkSum % 2 == 0){
        return false;
    }else{
        return true;
    }
}

bool isPhoneNumMatched(char *argument, char *phone, int sizeOfArgument){
    for(int index = 0; index < sizeOfArgument; index++){
        for(int phoneIndex = 0; phoneIndex < sizeof(phone); index++){
            if(phone[index] == argument[index]){
                return true;
            }
        }
    }
    return false;
}

bool foundedMatchByName(char *alternatives, char *name){
    for(int index = 0; index < sizeof(alternatives); index++){
        for(int nameIndex = 0; nameIndex < sizeof(name); nameIndex++){
            if(alternatives[index] == name[nameIndex]){
                return true;
            }
        }
    }
    return false;
}

bool isNameMatched(char *argument, char *name, int sizeOfArgument){
    bool foundMatch = false;
    for(int index = 0; index <= sizeOfArgument; index++){
        switch(argument[index]){
            case 0:
                char zero[1] = ZERO;
                foundMatch = foundedMatchByName(zero, name);
                break;
            case 2:
                char two[SHORT_ALT] = TWO;
                foundMatch = foundedMatchByName(two, name);
                break;
            case 3:
                char three[SHORT_ALT] = THREE;
                foundMatch = foundedMatchByName(three, name);
                break;
            case 4:
                char four[SHORT_ALT] = FOUR;
                foundMatch = foundedMatchByName(four, name);
                break;
            case 5:
                char five[SHORT_ALT] = FIVE;
                foundMatch = foundedMatchByName(five, name);
                break;
            case 6:
                char six[SHORT_ALT] = SIX;
                foundMatch = foundedMatchByName(six, name);
                break;
            case 7:
                char seven[LONG_ALT] = SEVEN;
                foundMatch = foundedMatchByName(seven, name);
                break;
            case 8:
                char eight[SHORT_ALT] = EIGHT;
                foundMatch = foundedMatchByName(eight, name);
                break;
            case 9:
                char nine[LONG_ALT] = NINE;
                foundMatch = foundedMatchByName(nine, name);
                break;
            default:
                break;
        }
    }
    return foundMatch;
}

void printOutContact(char *name, char *number){
    printf("%s, %s\n", name, number);
}

int main(int argc, char *argv[]) {
    if(!isFileInvalid(stdin)){
        bool foundMatch = false;
        char fileLine[MAX_ACCEPTED_ROW_SIZE];
        char phone[MAX_ACCEPTED_ROW_SIZE];
        char name[MAX_ACCEPTED_ROW_SIZE];
        rewind(stdin);
        while (fgets(fileLine, sizeof(fileLine), stdin)){
            int index = 0;
            while(fileLine[index] != '\n' && fileLine[index] != '\0'
                && index < MAX_ACCEPTED_ROW_SIZE - 1){
                    name[index] = fileLine[index];
                    index++;
            }
            name[index] = '\0';
            if(fgets(fileLine, sizeof(fileLine), stdin)){
                int index = 0;
                while(fileLine[index] != '\n'
                    && fileLine[index] != '\0'
                    && index < MAX_ACCEPTED_ROW_SIZE - 1){
                        phone[index] = fileLine[index];
                        index++;
                }
                phone[index] = '\0';
            }
            if(argc == 2){
                char *argument = argv[1];
                int sizeOfArgument = 0;
                while(argument[sizeOfArgument] != '\0' && argument[sizeOfArgument] != '\n'){
                    sizeOfArgument++;
                }
                if(isPhoneNumMatched(argument, phone, sizeOfArgument)){
                    printOutContact(name, phone);
                    foundMatch = true;
                }
                if(isNameMatched(argument, name, sizeOfArgument)){
                    printOutContact(name, phone);
                    foundMatch = true;
                }
            }else{
                printOutContact(name, phone);
                foundMatch = true;
            }
        }
        if(!foundMatch){
            printf("Not found");
        }
    }else{
        callError(1);
    }
    return 0;
}
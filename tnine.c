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

void callError(int errNum){
    switch (errNum){
        case 0:
            fprintf(stderr, "Input has an odd lines, fix it\n");
            break;
        case 1:
            fprintf(stderr, "Too much characters on line\n");
            break;
        case 2:
            fprintf(stderr, "Invalid input argument\n");
            break;
        }
}

bool isValidInput(char *argument) {
    bool isValid = true;
    for (int index = 0; argument[index] != '\0'; index++) {
        if (argument[index] > 57 || argument[index] < 48) {
            isValid = false;
            break;
        }
    }
    return isValid;
}

bool isValidLineLenght(char *checkLine){;
    int checkSum;
    bool isValid = true;
    for(checkSum; checkLine[checkSum] != '\0'; checkSum++){
        if(sizeof(checkLine) > MAX_ACCEPTED_ROW_SIZE){
            isValid = false;
            break;
        }
    }
    return isValid;
}
/*
bool findByParameters(char arguments[], char destination[]){
    printf("spoustim hledani s argumenty: %s destinaci: %s delku argumentu: %d\n", arguments, destination, argLenght);
    int argLenght = 0;
    while(argument[argLenght] != '\0' && argument[argLenght] != '\n'){
        argLenght++;
    }
    int index = 0;
    int lenght = argLenght;
    char destPiece[lenght];
    while(destination[index] != '\0' && destination[index] != '\n'){
        for(int destIndex = 0; destIndex < argLenght; destIndex++){
            destPiece[destIndex] = destination[destIndex];
        }
        printf("substring: %s\n", destPiece);
        destPiece[argLenght] = '\0';
        if(destPiece == arguments){
            return true;
        }
        index++;
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
}*/

void printOutContact(char *name, char *number){
    printf("%s, %s\n", name, number);
}

void editNewLine(char subject[]){
    int enterIndex = 0;
    while (subject[enterIndex] != '\0') {
        if (subject[enterIndex] == '\r' || subject[enterIndex] == '\n') {
            break;
        }
        enterIndex++;
    }
    subject[enterIndex] = '\0';
}

int main(int argc, char *argv[]) {
    char phone[MAX_ACCEPTED_ROW_SIZE];
    char name[MAX_ACCEPTED_ROW_SIZE];
    if(argv[1] == NULL || argc == 1){
        while(fgets(name, sizeof name, stdin) != NULL){
            if(fgets(phone, sizeof phone, stdin) == NULL){
                callError(0);
                return 1;
            }
            if(!isValidLineLenght(phone) && !isValidLineLenght(name)){
                callError(1);
                return 1;
            }
            editNewLine(name);
            editNewLine(phone);
            printOutContact(name, phone);
        }
    }
    char *arguments = argv[1];
    if(!isValidInput(arguments)){
        callError(2);            
        return 1;
    }
    while(fgets(name, sizeof name, stdin) != NULL){
        if(fgets(phone, sizeof phone, stdin) == NULL){
            callError(0);
            return 1;
        }
        if(!isValidLineLenght(phone) && !isValidLineLenght(name)){
            callError(1);
            return 1;
        }/*
        if(findByParameters(argument, phone)){
            printOutContact(name, phone);
            foundMatch = true;
        }
        if(isNameMatched(argument, name, sizeOfArgument)){
            printOutContact(name, phone);
            foundMatch = true;
        }*/
        editNewLine(name);
        editNewLine(phone);
        printOutContact(name, phone);
    }
    for(int index = 0; arguments[index] != '\0'; index++){
        if(arguments[index] < 58 && arguments[index] > 47){
            callError(2);
            return 1;
        }
    }
    /*
    
    /*if(!foundMatch){
        printf("Not found");
    }*/
    return 0;
}
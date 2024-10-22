#include <stdio.h>
#include <stdbool.h>

char* getName(char *line){
    static char name[100];
    int index = 0;
    while(line[index] != ',' && line[index] != '\0'){
        name[index] = line[index];
        index++;
    }
    name[index] = '\0';
    return name;
}

void getNumber(char *line, char *number){
    int numberIndex = 0;
    bool numberStart = false;
    for(int index = 0; line[index] != '\0'; index++){
        if(line[index] == ',')
            numberStart = true;
        if(numberStart){
            number[numberIndex] = line[index + 1];
            numberIndex++;
        }
    }
    number[numberIndex] = '\0';
}

void printOutContact(char *name, char *number){
    printf("%s\n", name);
    printf("%s\n", number);
}

int getLineSize(char *line){
    int count = 0;
    while(line[count] != '\n' && line[count] != '\0'){
        count++;
    }
    return count + 1;
}

int main(void) {
    char buffer[101];
    int matches = 0;
    while (fgets(buffer, sizeof(buffer), stdin)) {
        int lineSize = getLineSize(buffer);
        char *name = getName(buffer);
        char number[100];
        getNumber(buffer, number);
        printOutContact(name, number);
        /*if(isNumberMatch(number)){
            printOutContact(name, number);
            matches++;
        }else if(isNameMatch(name)){
            printOutContact(name, number);
            matches++;
        }*/
    }
    if(matches == 0){
        printf("No matches found!");
    }
    return 0;
}
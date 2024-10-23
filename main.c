#include <stdio.h>
#include <stdbool.h>

int callError(int errNum){
    switch (errNum){
        case 0:
            //file not found
            return 1;
        case 1:
            //invalid file format
            return 1;
        /*case(errNum == ):
            //
            return 1;
        case(errNum == ):
            //
            return 1;*/
    }
}

bool isFileInvalid(FILE *file){
    if(file == NULL){
        callError(0);
    }
    char checkLine[101];
    int checkSum;
    while(fgets(checkLine, sizeof(checkLine), stdin)){
        if(sizeof(checkLine) > 101){
            printf("isFileInvalid: true 1\n");
            return true;
        }
        checkSum++;
    }
    if(checkSum % 2 == 0){
        printf("isFileInvalid: false\n");
        return false;
    }else{
        printf("isFileInvalid: true 2\n");
        return true;
    }
}

void printOutContact(char *name, char *number){
    printf("%s, %s\n", name, number);
}

int main(int argc, char *argv[]) {
    if(!isFileInvalid(stdin)){
        int matches = 0;
        char fileLine[101];
        char phone[51];
        char name[51];
        rewind(stdin);
        while (fgets(fileLine, sizeof(fileLine), stdin)){
            int index = 0;
            while(fileLine[index] != '\n' && fileLine[index] != '\0' && index < sizeof(name) - 1){
                name[index] = fileLine[index];
                index++;
            }
            name[index] = '\0';
            if(fgets(fileLine, sizeof(fileLine), stdin)){
                int index = 0;
                while(fileLine[index] != '\n' && fileLine[index] != '\0' && index < sizeof(name) - 1){
                    phone[index] = fileLine[index];
                    index++;
                }
                phone[index] = '\0';
            }
            if(argc == 2){
                char *argument = argv[1];
                printOutContact(name, phone);
                
            }else{
                printOutContact(name, phone);
            }
        }
        if(matches == 0){
            printf("No matches found!");
        }
    }else{
        callError(1);
    }
    return 0;
}
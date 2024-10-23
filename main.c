#include <stdio.h>
#include <stdbool.h>

void printOutContact(char *name, char *number){
    printf("%s, %s\n", name, number);
}

bool isFileInvalid(FILE *file){
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

int main(int argc, char *argv[]) {
    char fileLine[101];
    char phone[51];
    char name[51];
    int matches = 0;
    switch (argc){
        case 2:
            if(!isFileInvalid(stdin)){
                char *argument = argv[1];
                printf("%s\n", argument);
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
                            //findContactsByArgument(argv[1]);
                        }
                        phone[index] = '\0';
                        printOutContact(name, phone);
                    }
                }
            }else{
                callError(1);
            }
            break;
        case 1:
            if(!isFileInvalid(stdin)){
                rewind(stdin);
                printf("konám case 1\n");
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
                            //findContactsByArgument(argv[1]);
                        }
                        phone[index] = '\0';
                        printOutContact(name, phone);
                    }
                }
            }else{
                callError(1);
            }
            break;
        default:
            callError(0);
    }
    if(matches == 0){
        printf("No matches found!");
    }    
    return 0;
}
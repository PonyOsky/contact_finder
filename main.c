#include <stdio.h>

//object in c;      *StudentPtr is alias and now I can onl call StuendtPtr name
typedef struct{
    char *name;
    int number[9];
    int priority;
} contact, *Contact;

int main(void) {
    char buffer[101];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        printf("%s", buffer);
    }

    return 0;
}
#include <stdio.h>

/* function prototype needed for use before definition */
void hello(char* name);

int main(int argc, char* argv[]) {
    int i = 0;
    /* no need to use printf to output a string with no variables */
    fputs("Hello C!\n", stdout);
    /* argc is the number of tokens in the whole command line */
    for(i = 0; i < argc; ++i)
        hello(argv[i]);
    return 0;
}

void hello(char* name) {
    printf("Hello %s\n", name);
}

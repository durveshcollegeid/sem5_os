//Q2 identify parent and child 
#include <stdio.h>
#include <unistd.h>

int main() {
    
    int pid = fork();

    if( pid==0 ) {
        printf("Hello from parent !");
    }
    else {
        printf("Hello from child !");

    }

    return 0;
}

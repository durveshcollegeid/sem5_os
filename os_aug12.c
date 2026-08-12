//Q3 show process id 

#include <stdio.h>
#include <unistd.h>

int main() {
    
    int pid = fork();

    printf("process id = %d\n", getppid());
    return 0;
}

//Q4 show before fork vs after fork

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("before fork\n");
    int pid = fork();

    printf("after fork\n");
    return 0;
}

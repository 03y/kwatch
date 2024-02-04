#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INTERVAL 2 

int system(const char *command);

void run(char* command) {
    system("clear");
    printf("Running %s, every %d seconds\n\n", command, INTERVAL);
    system(command);
    sleep(INTERVAL);
    run(command);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: ./kwatch <command>\n");
        return 1;
    }

    char* command = argv[1];

    run(command);

    return 0;
}

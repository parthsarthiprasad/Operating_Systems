#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <climits>
void ctrlC_handler(int s)
{
    printf("\nCtrl+C Detected Signal ID %d\n", s);
    printf("Ending Program\n");
    exit(1);
}
int main(int argc, char **argv)
{
    printf("--beginning of program");
    signal(SIGINT, ctrlC_handler);
    pid_t pid = fork();

    if (pid == 0)
    {
        // child process
        int counter = 0, slpt;
        pid_t mypid = getpid();
        pid_t ppid = getppid();
        while (true)
        {

            //system("Clear");
            printf("Process: Child\n\tProcess ID: %d\n\tParent Process ID: %d\n\t Child Counter: %d \n", mypid, ppid, counter++);
            srand(time(0));
            slpt = 1 + rand() % 5;
            printf("\tSleeping For %d s", slpt);
            printf(" ");
            usleep(1000000);

            sleep(slpt);
        }
    }
    else if (pid > 0)
    {

        // parent process
        int counter = 0;
        pid_t mypid = getpid();
        while (true)
        {

            // system("clear");
            printf("\nProcess: Parent \n");
            printf("Process ID: %d", mypid);
            printf("\n Parent Counter: %d  ", counter++);
            printf(" ");
            usleep(1000000);
        }
    }
    else
    {
        // fork failed
        printf("fork() failed!\n");
        return 1;
    }

    printf("--end of program--\n");

    return 0;
}

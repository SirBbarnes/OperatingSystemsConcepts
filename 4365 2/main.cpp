#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{

    //int numChild = atoi(argv[1]);

   //int num = atoi(argv[2]);

     int numChild, num;
   printf("Number of Children: ");
   scanf("%d", &numChild);

   printf("Input number: ");
   scanf("%d", &num);

    int count = 0;

    for (int i = 1; i <= num; ++i) {
        if (num % i == 0) {
            count += 1;
        }
    }

    int arr[count];


    int h, q = 0;
    for (h = 1; h <= num; ++h) {
        if (num % h == 0) {
            arr[q] = h;
            q++;
        }
    }
    int sum = 0;
    //int array[6] = {2, 3, 7, -1, 10, 6};

    printf("\nI am the parent with pid: %d sending the array: ", (int) getpid());
    for (int i : arr) {
        printf("%d, ", i);
    }
    printf("\n");




    if (numChild == 1) {
        int fd[2];
        pipe(fd);
        int rc = fork();
        if (rc < 0) {
            //fork failed; exit
            printf("fork failed\n");
            exit(1);
        }
        else if (rc == 0) {
            close(fd[0]);
            int i;
            for (i = 0; i < count; i++) {  //first correction here from 0-3
                sum = sum + arr[i];
            }

            write(fd[1], &sum, sizeof(sum));
            printf("I am the first child with pid: %d sending the value: %d to my parent\n", (int) getpid(), sum);
            close(fd[1]);
            //sleep(1);
            close(0);
            exit(0);   //I am including exit(0) to kill the process after is done !!!!@
        }
        else {
            int sum1;
            int final = 0;

            close(fd[1]);
            read(fd[0], &sum1, sizeof(sum));
            final = final + sum1;


            printf("I am the parent at the end with ID %d with a final sum of: %d \n", (int) getpid(), final);
            close(fd[0]);
        }
    }





    else if (numChild == 2) {
        int fd[2];
        pipe(fd);

        int fd2[2];
        pipe(fd2);

        int rc = fork();
        int rc1 = fork();
        if (rc < 0 || rc1 < 0) {
            //fork failed; exit
            printf("fork failed\n");
            exit(1);
        }
        else if (rc == 0) {
            close(fd[0]);
            int i;
            for (i = 0; i < (count / 2); i++) {  //first correction here from 0-3
                sum = sum + arr[i];
            }

            write(fd[1], &sum, sizeof(sum));
            printf("I am the first child with pid: %d sending the value: %d to my parent\n", (int) getpid(), sum);
            close(fd[1]);
            //sleep(1);
            close(0);
            exit(0);   //I am including exit(0) to kill the process after is done !!!!@
        }
        else if (rc1 == 0) {
            close(fd2[0]);
            int i;
            for (i = (count / 2); i < count; i++) {  //first correction here from 0-3
                sum = sum + arr[i];
            }

            write(fd2[1], &sum, sizeof(sum));
            printf("I am the second child with pid: %d sending the value: %d to my parent\n", (int) getpid(), sum);
            close(fd2[1]);
            //sleep(1);
            close(0);
            exit(0);   //I am including exit(0) to kill the process after is done !!!!@
        }
        else {
            int sum1, sum2;
            int final = 0;

            close(fd[1]);
            read(fd[0], &sum1, sizeof(sum));
            final = final + sum1;

            close(fd2[1]);
            read(fd2[0], &sum2, sizeof(sum2));
            final = final + sum2;


            printf("I am the parent at the end with ID %d with a final sum of: %d \n", (int) getpid(), final);
            close(fd[0]);
            close(fd2[0]);
        }
    }





    else if (numChild == 3) {
        int fd[2];
        pipe(fd);

        int fd2[2];
        pipe(fd2);

        int fd3[2];
        pipe(fd3);

        int rc = fork();
        int rc1 = fork();
        int rc2 = fork();
        if (rc < 0 || rc1 < 0 || rc2 < 0) {
            // fork failed; exit
            printf("fork failed\n");
            exit(1);
        }
        else if (rc == 0) {
            close(fd[0]);
            int i;
            for (i = 0; i < (count / 3); i++) {  //first correction here from 0-3
                sum = sum + arr[i];
            }

            write(fd[1], &sum, sizeof(sum));
            printf("I am the first child with pid: %d sending the value: %d to my parent\n", (int) getpid(), sum);
            close(fd[1]);
            //sleep(1);
            close(0);
            exit(0);   //I am includeing exit(0) to kill the process after is done !!!!@
        }
        else if (rc1 == 0) {
            // printf("Hello, I am child 2, my pid is: (pid:%d)\n", (int) getpid());
            close(fd2[0]);
            // int sum =0;
            int k;
            for (k = (count / 3); k < (count - (count / 3)); k++) {
                sum = sum + arr[k];
            }
            write(fd2[1], &sum, sizeof(sum));
            printf("I am the second child with pid: %d sending the value: %d to my parent\n", (int) getpid(), sum);
            close(fd2[1]);
            //sleep(1);
            close(0);
            exit(0);
        }
        else if (rc2 == 0) {
            close(fd3[0]);
            int m;
            for (m = (count - (count / 3)); m < count; m++) {
                sum = sum + arr[m];
            }
            write(fd3[1], &sum, sizeof(sum));
            printf("I am the third child with pid: %d sending the value: %d to my parent\n", (int) getpid(), sum);
            close(fd3[1]);
            //sleep(1);
            close(0);
            exit(0);
        }
        else {
            int sum1, sum2, sum3;
            int final = 0;

            close(fd[1]);
            read(fd[0], &sum1, sizeof(sum));
            final = final + sum1;

            close(fd2[1]);
            read(fd2[0], &sum2, sizeof(sum2));
            final = final + sum2;

            close(fd3[1]);
            read(fd3[0], &sum3, sizeof(sum3));
            final = final + sum3;

            printf("I am the parent at the end with ID %d with a final sum of: %d \n", (int) getpid(), final);
            close(fd[0]);
            close(fd2[0]);
            close(fd3[0]);
        }
    }

    else {
        printf("Invalid number of children");
        exit(0);
    }


    return 0;
}
//Note: pipes are not bi-directional, so you will need two pipes per process, one for receiving (reading) and one for sending (writing).  if you the to send (write) something using pipe1 you need to close the reading end of that pipe, namely close(pipe1[0]).  In the same way, if you need to receive something from the someone, you have to use another pipe, let say pipe2, so you use the reading end part and close the writing end, namely close(pipe2[1]) */

//Sorry for any typo, I hope that this code will help you to beeter understand, how to use the API for process. Feel free to extend this code for two and three childrens.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argv, char** argc) {
    // initialize pipes
    int p1[2];
    int p2[2];
    pipe(p1);
    pipe(p2);
    int a, b, c;
    int numChildren, num;

    printf("How many Children: ");
    scanf("%d", &numChildren);
    printf("Input Number: ");
    scanf("%d", &num);
    int numElements = 6;
    if (numChildren == 1) {

         //num of elements in the array
        a = fork();  //creating a child
        //b = fork();
        //c = fork();
        if (a == 0) { // If I am the child read the elements of the array that my parent sent me

            close(p1[1]); //closing the writing end of pipe1 (p1), I am using p1 for reading so p1[0] is open for reading from my parent
            close(p2[0]); //closing the  reading end of pipe2 (p2), I am using p2 for sending (writing) the sumation to my parent
            int vals[num];
            read(p1[0], &vals, sizeof(vals));

            // compute the sum
            int sum = 0;
            printf("I am the child with pid: %d adding the array ",
                   getpid()); //printing my pid and the array that I just received from my parent

            int i;
            for (i = 0; i < numElements; i++) {
                printf("%d, ", vals[i]);
                sum += vals[i];    //Adding the elements of the array
            }
            printf("\n");
            printf("and sending partial sum %d\n", sum);
            // send result to parent
            write(p2[1], &sum, sizeof(sum)); //sending to the parent the sum of the array
            exit(0);     //key line of code.



        } else {
            // parent
            close(p1[0]);  //closing reading, because I will use pipe1 for sending info to my child
            close(p2[1]);  //closing writing, because I will use this pipe2 for receiving the summation from my child
            // send values to child
            int val[] = {};
            int valsToSend[6] = {2, 3, 7, -1, 10, 6};


            printf("\nI am the parent with pid: %d sending the array: ", getpid());
            for (int i = 0; i < numElements; i++) {
                printf("%d, ", valsToSend[i]);
            }
            /*for (int j = 1; j <= num; j++) {
                if (num % j == 0) {
                    printf("%d, ", val[j] = j);
                }
            }
             */
            printf("\n");

            write(p1[1], &valsToSend, sizeof(valsToSend));

            // receive and print the final value
            int recval;
            read(p2[0], &recval, sizeof(recval));
            printf("I am the parent with pid: %d receiving from child with pid %d"
                   " \nthe partial sum %d\n", getpid(), getpid() + 1, recval);
            printf("\nTotal Sum: %d", recval);
            exit(0);
        }
    }



    else if (numChildren == 2) {
        if (a && b == 0) {
        }
        else {
            // parent
            close(p1[0]);  //closing reading, because I will use pipe1 for sending info to my child
            close(p2[1]);  //closing writing, because I will use this pipe2 for receiving the summation from my child
            // send values to child
            int val[] = {};
            int valsToSend[6] = {2, 3, 7, -1, 10, 6};


            printf("\nI am the parent with pid: %d sending the array: ", getpid());
            for (int i = 0; i < numElements; i++) {
                printf("%d, ", valsToSend[i]);
            }
            /*for (int j = 1; j <= num; j++) {
                if (num % j == 0) {
                    printf("%d, ", val[j] = j);
                }
            }
             */
            printf("\n");

            write(p1[1], &valsToSend, sizeof(valsToSend));

            // receive and print the final value
            int recval;
            read(p2[0], &recval, sizeof(recval));
            printf("I am the parent with pid: %d receiving from child with pid %d"
                   " \nthe partial sum %d\n", getpid(), getpid() + 1, recval);
            printf("\nTotal Sum: %d", recval);
            exit(0);
        }
    }




    else if (numChildren == 3) {

        if (a == 0 && b == 0 && c == 0) {

        }
        else {
            // parent
            close(p1[0]);  //closing reading, because I will use pipe1 for sending info to my child
            close(p2[1]);  //closing writing, because I will use this pipe2 for receiving the summation from my child
            // send values to child
            int val[] = {};
            int valsToSend[6] = {2, 3, 7, -1, 10, 6};


            printf("\nI am the parent with pid: %d sending the array: ", getpid());
            for (int i = 0; i < numElements; i++) {
                printf("%d, ", valsToSend[i]);
            }
            /*for (int j = 1; j <= num; j++) {
                if (num % j == 0) {
                    printf("%d, ", val[j] = j);
                }
            }
             */
            printf("\n");

            write(p1[1], &valsToSend, sizeof(valsToSend));

            // receive and print the final value
            int recval;
            read(p2[0], &recval, sizeof(recval));
            printf("I am the parent with pid: %d receiving from child with pid %d"
                   " \nthe partial sum %d\n", getpid(), getpid() + 1, recval);
            printf("\nTotal Sum: %d", recval);
            exit(0);
        }
    }
    return 0;

}

void fillArray() {

}

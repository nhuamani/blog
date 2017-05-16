#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define FIFO_NAME "myfifo"

int main(void){

    char buf[256];
    int num, fd;
    pid_t pid;
    float x, esp;
    float bufer;

    float suma;

    if (mkfifo(FIFO_NAME, 0666) < 0)
        perror("mkfifo");


    pid_t child_a, child_b;
    child_a = fork();

    if(child_a == 0){


        if ((fd = open(FIFO_NAME, O_RDONLY)) < 0)
            perror("parent - open");


     read(fd,&x, sizeof(x));
    read(fd,&esp, sizeof(esp));

    printf("read %f\n",x);
        printf("read %f\n", esp);
    suma = x+esp;


    write(fd,&suma,sizeof(suma));

    close(fd);
    }
    else{
        child_b = fork();

        if(child_b == 0){

        fd = open(FIFO_NAME,O_WRONLY);
        read(fd,&suma,sizeof(suma));
        printf("suma %f \n", suma);
        }
        else{

        if ((fd = open(FIFO_NAME, O_WRONLY)) < 0)


        scanf("%f", &x);
              scanf("%f", &esp);

        if((num = write(fd,&x,sizeof(x)))<0){
            perror("child - write ");
        }
        write(fd,&esp,sizeof(esp));
        close(fd);
        }
    }
}
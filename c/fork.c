#include <stdio.h>
#include <unistd.h>
//   i		Edit
// esc :wq	Save
// gcc -o (name) name.c	    Ejecutar Languaje C

int main(){
	int pid;
	printf("PADRE: Yo soy el padre y mi PID es: %d \n", getpid());
	pid = fork();
	//cuando llamamos a fork se crea un nuevo proceso, en el proceso
	//hijo recien creado su pid = 0
	
	if (pid){
		printf("Padre: He creado un hijo con el pid: %d \n", pid);
	}
}

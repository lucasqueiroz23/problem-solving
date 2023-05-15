#include <wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int sigcount = 0;

pid_t child_id = -1;

void handler(int signum){
	if(sigcount == 0)
	{
		sigcount++;
		return;
	}
	if(sigcount == 1){
		if(child_id > 0) wait(NULL);
		sigcount++;
		return;
	}
	if(sigcount == 2) exit(0);
}

int main(){
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);

	pause();
	if(sigcount == 1) child_id = fork();
	if(child_id > 0) {
		pause();
		pause();
	}
	exit(0);
}

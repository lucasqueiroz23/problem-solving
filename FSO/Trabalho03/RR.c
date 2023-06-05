#include <stdlib.h>
#include <stdio.h>

// linked list with a header node
typedef struct queue
{
	int PID;
	int EXEC_TIME;
    struct queue *next_node;

} queue;

queue *create_queue()
{
    queue *q = malloc(sizeof(queue));
    q->next_node = q;
    q->PID = -1;
	q->EXEC_TIME = -1;
    return q;

}

void enqueue(queue **q, int pid, int exec_time)
{
    queue *new_node = malloc(sizeof(queue));
    new_node->next_node = (*q)->next_node;

    (*q)->next_node = new_node;
    (*q)->PID = pid;
    (*q)->EXEC_TIME = exec_time;

    *q = new_node;
    (*q)->PID = -1;
}

void dequeue(queue **q)
{
	queue *trash = malloc(sizeof(queue));
	trash = (*q)->next_node;
	// empty queue
	if(trash->PID == -1) return;


	(*q)->next_node = trash->next_node;
	free(trash);
}

int main(){
	int N = 0;
	scanf("%d", &N);

	queue *ready_queue = create_queue();	
	queue *finished_processes = malloc(N * sizeof(queue));
	
	int time_slice = 0;
	scanf("%d", &time_slice);

	for(int i = 0; i < N; i++){
		int pid = 0, exec_time = 0;
		scanf("%d %d", &pid, &exec_time);
		enqueue(&ready_queue, pid, exec_time*1000);
	}
	
	int ptr_finished = 0;
	int passed_time = 0;

	// queue is not empty
	while(ready_queue->next_node->PID != -1){
		const int time_difference = ready_queue->next_node->EXEC_TIME - time_slice;
		int new_exec_time = 0;
		if(time_difference > 0){
			passed_time += time_slice;
			int pid = ready_queue->next_node->PID;
			dequeue(&ready_queue);
			enqueue(&ready_queue, pid, time_difference);
			continue;
		}
		if(time_difference == 0){
			passed_time+= time_slice;
			int pid = ready_queue->next_node->PID;
			finished_processes[ptr_finished].PID = pid;
			finished_processes[ptr_finished].EXEC_TIME = passed_time;
			ptr_finished++;
			dequeue(&ready_queue);
			continue;
		}
		if(time_difference < 0) {
			int pid = ready_queue->next_node->PID;
			passed_time += time_slice + time_difference;
			finished_processes[ptr_finished].PID = pid;
			finished_processes[ptr_finished].EXEC_TIME = passed_time;
			ptr_finished++;
			dequeue(&ready_queue);
			continue;
		}
	}
	
	for(int i = 0; i < N; i++)
		printf("%d (%d)\n", finished_processes[i].PID, finished_processes[i].EXEC_TIME);
	
	free(finished_processes);
	exit(0);
}


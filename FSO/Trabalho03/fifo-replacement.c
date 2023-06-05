#include <stdlib.h>
#include <stdio.h>
#define TABLE_SIZE 1000000

typedef int DATA_TYPE;

int table[TABLE_SIZE];

// linked list with a header node
typedef struct queue {
    DATA_TYPE element;
	int size;
	int maxlength;
    struct queue *next_node;

} queue;

queue *create_queue(int max) {
    queue *q = malloc(sizeof(queue));
    q->next_node = q;
    q->element = -1;
    return q;
}

DATA_TYPE dequeue(queue **q) {

    queue *trash = malloc(sizeof(queue));
	trash = (*q)->next_node;

	// queue is empty
	if(trash->element == -1) return -1;

	DATA_TYPE front_element = trash->element;
	(*q)->next_node = trash->next_node;
	free(trash);

	(*q)->size--;
	table[front_element] = 0;
	return front_element;
}

void enqueue(queue **q, DATA_TYPE new_item) {
    queue *new_node = malloc(sizeof(queue));
    new_node->next_node = (*q)->next_node;
	
    (*q)->next_node = new_node;
    (*q)->element = new_item;
    (*q)->size++;

    *q = new_node;
    (*q)->element = -1;
	table[new_item] = 1;
}

int main() {

	int q = 0;
	scanf("%d", &q);
	
	queue *queue = create_queue(q);

	int n = 0;
	scanf("%d", &n);
	
	int count = 0;
	int size = 0;

	while(n--) {
		int p = 0;
		scanf("%d", &p);
		if(table[p] == 0){
			if(size >= q) dequeue(&queue);
			enqueue(&queue, p);
			count++;
			size++;
		}
	}

	printf("%d\n", count);

	exit(0);
}

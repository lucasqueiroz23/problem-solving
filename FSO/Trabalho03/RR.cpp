#include <iostream>
#include <queue>

typedef struct process {
	int pid;
	int exec_time;
} process;

int main(){
	int N = 0;
	std::cin >> N;

	std::queue<process> ready_queue;	
	
	int time_slice = 0;
	std::cin >> time_slice;

	while(N--) {
		int pid = 0, exec_time = 0;
		std::cin >> pid >> exec_time;
		process new_process = {pid, exec_time * 1000};
		ready_queue.push(new_process);
	}
	
	int passed_time = 0;

	while(!ready_queue.empty()){
		process p = ready_queue.front();
		const int time_difference = p.exec_time - time_slice;

		if(time_difference > 0){
			passed_time += time_slice;
			ready_queue.pop();
			ready_queue.push({p.pid, time_difference});
			continue;
		}
		if(time_difference <= 0){
			passed_time += time_slice;
			if(time_difference < 0)
				passed_time += time_difference;
			std::cout << p.pid << " (" << passed_time << ")\n";
			ready_queue.pop();
			continue;
		}
	}
	
	return 0;
}


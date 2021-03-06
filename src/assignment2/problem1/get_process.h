typedef struct Process {
    int pid;
    enum { New, Ready, Running, Terminated } state;
    int arrival_time;
    int cpu_burst;
    int wait_time;
    int time_left;
    int termination_time;
} Process;

int create_pcb(Process process_table[]){

    int n = 0;
    char* filename = "test_2.csv";
    char* delimiter = ",";
    char log_msg[30];

    FILE* fptr = fopen(filename, "r");

    if(fptr == NULL){
        perror("Error");
        // logger("TAG", "no such file log message");
    } else {

        // logger("PRE", "File read successfully");
        const size_t line_size = 10;
        char* line = malloc(line_size);
        while (fgets(line, line_size, fptr) != NULL)  {

            Process proc;
            proc.pid = n + 1;
            proc.state = New;
            proc.wait_time = 0;

            char* token;

            token = strtok(line,",");
            // printf("%s\n",token);
            proc.arrival_time = atoi(token);

            token = strtok(NULL, ",");
            // printf(",%s \n",token);
            proc.cpu_burst = atoi(token);

            proc.time_left = proc.cpu_burst;
            process_table[n++] = proc;

            sprintf(log_msg, "New process. PID = %d", proc.pid);
            // logger("PRE", log_msg);

        }
        free(line);  

       
        sprintf(log_msg, "Read %d processes", n);
        // logger("PRE", log_msg);

        fclose(fptr);
    }
    return n;
}

void print_waiting_times(Process process_table[], int number_of_processes){

    int i=0;
    for(i=0;i<number_of_processes;i++){
        printf("PID: %d\n", process_table[i].pid);
        printf("Arrival Time: %d\n", process_table[i].arrival_time);
        printf("CPU Burst: %d\n", process_table[i].cpu_burst);
        printf("Termination Time: %d\n", process_table[i].termination_time);
        printf("Wait Time: %d\n", process_table[i].wait_time);
        printf("\n");
    }
}

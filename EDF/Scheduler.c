#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Linklist.h"

int main(int argc, char *argv[])
{
    linked_list_t task_queue;
    linked_list_init (& task_queue);
    linked_list_t job_queue;
    linked_list_init (& job_queue);

    task_queue=Scan_File_To_Task_Queue(& task_queue);              
    //task_traverse(& task_queue, 0, print_task); 
    //printf ("\n");    
       
    processor_execution(& task_queue ,& job_queue);              
    printf ("\n");  
    
    print_job_queue_empety_or_not(& job_queue);
    printf ("\n");
           
    system("PAUSE");
    return EXIT_SUCCESS;
}

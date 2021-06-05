void task_traverse (linked_list_t * list, void * data,void (*callback) (task_t *,task_t *)){
    link_t * link;
    
    for (link = list->first; link; link = link->next) {
        callback ((task_t*)data, (task_t*)link->data);
    }
}

void print_task (task_t * user_task, task_t * task){   
    printf ("t%d: phase time= %d  ,period= %d ,execution time= %d  ,relative deadline= %d\n",task->task_id,task->phase_time,task->period,task->execution_time,task->relative_deadline);      
}

void job_traverse (linked_list_t * list, void * data,void (*callback) (job_t *,job_t *)){
    link_t * link;
    
    for (link = list->first; link; link = link->next) {
        callback ((job_t*)data, (job_t*)link->data);
    }
}

void print_job (job_t * user_job, job_t * job){   
    printf ("  Job(%d,%d):ready time= %d  ,remain execution time= %d  ,absolute deadline= %d\n",job->task_id,job->job_id,job->ready_time,job->remain_execution_time,job->absolute_deadline);      
}

void print_first_task (task_t * task){ 
    printf ("\nTask : \n");   
    printf ("phase time= %d \t,period= %d \t,execution_time= %d \t,relative deadline= %d\n",task->phase_time,task->period,task->execution_time,task->relative_deadline);      
}

void print_first_job (job_t * job){ 
    printf ("\nJob : ");   
    printf ("ready time= %d \t,remain execution time= %d \t,absolute deadline= %d\n",job->ready_time,job->remain_execution_time,job->absolute_deadline);    
}

void print_utilization(linked_list_t * list){
    link_t * link;
    link = (link_t*)calloc (1, sizeof (link_t)); 
    link = list->first;   
    for(int i=0;i<list->count;i++){
        printf("%1.3f\n",((task_t*)link->data)->utilization);  
        link = link->next;
    }          
}

void print_job_queue_empety_or_not( linked_list_t * job_queue){
    if(job_queue->first==0)
        printf("Empty.\n");
    else{ 
        printf("Remain.\n");
        job_traverse(job_queue, 0, print_job);
    }
}


int gcd(int m, int n){
        int tmp;
        while(m) { tmp = m; m = n % m; n = tmp; }       
        return n;
} 
 
int lcm(int m, int n){
        return m / gcd(m, n) * n;
}

int MAX_phase_in_task_queue(linked_list_t * list){
    link_t * link;
    link = (link_t*)calloc (1, sizeof (link_t));   
    link = list->first;    
    int Max = 0;//Here could change

	for(int i=0;i<list->count;i++){//phase_time¤jªº¯d¤U=MAX 
        if(Max < ((task_t*)link->data)->phase_time)                
             Max = ((task_t*)link->data)->phase_time;
        link = link->next;
    }    
    //printf("The minimum phase in task_queue is : %d\t\n",min); 
    return Max;
}

int LCM_of_all_the_tasks_period(linked_list_t * list){
    link_t * link;
    link = list->first;    
    int LCM=1;

	for(int i=0;i<list->count;i++){                 
        LCM = lcm(LCM,((task_t*)link->data)->period);
        link = link->next;
    }    
    //printf("The LCM in task_queue is : %d\t\n",LCM); 
    return LCM;
}

double SUM_of_the_task_utilization(linked_list_t * task_queue){
    link_t * link;
    link = (link_t*)calloc (1, sizeof (link_t)); 
    link = task_queue->first;   

    double utilization=0;
    for(int i=0;i<task_queue->count;i++){
        if(((task_t*)link->data)->period > ((task_t*)link->data)->relative_deadline)//min(Pi,Di) EDF
            utilization=utilization+(double)((task_t*)link->data)->execution_time/(double)((task_t*)link->data)->relative_deadline;
        else             
            utilization=utilization+(double)((task_t*)link->data)->execution_time/(double)((task_t*)link->data)->period; 
                
        link = link->next;
    }
    task_queue->utilization=utilization;
    printf("%1.3f\n",utilization);  
    return utilization;           
}

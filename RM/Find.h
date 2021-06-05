
link_t* find_the_i_link_of_queue(linked_list_t * list,int count){
       link_t * link;
       link = (link_t*)calloc (1, sizeof (link_t));
       link = list->first;
       for(int i=0;i<count;i++){
           link = link->next;                  
       }
       return link;
}
//使用在 RM sorting
//job的period = ( job的ready time - task的phase time ) / task的count = task的period 
//job(1,2) = ( 5 - task(1,?) ) / task->count 
int find_the_period_of_the_job(linked_list_t * task_queue ,linked_list_t * job_queue ,job_t * job){
    link_t * link_task;
    link_task = (link_t*)calloc (1, sizeof (link_t));
    link_task = task_queue->first;
     
    for(int i=0;i<task_queue->count;i++){
         if(((task_t*)link_task->data)->task_id==job->task_id){
              //printf("%d\n",((task_t*)link_task->data)->period);
              return ((task_t*)link_task->data)->period;
              break;                                                               
         }
         link_task=link_task->next;
    }
} 
/*
//------------------------------------Scan_Task_To_Job_Queue--------------------------------------------
int find_the_total_num_of_same_phase_in_task_queue(linked_list_t * list,int Clock){
    link_t * link;
    link = (link_t*)calloc (1, sizeof (link_t));
    link = list->first;    
    int total=0;
    
	for(int i=0;i<list->count;i++){                 
        if(((task_t*)link->data)->phase_time == Clock)
             total++;
        link = link->next;                 
    } 
    return total;        
}

link_t* find_the_first_link_of_task_queue_with_same_phase(linked_list_t * list,int phase){
    link_t * link;
    link = (link_t*)calloc (1, sizeof (link_t));
    link = list->first;    

	for(int i=0;i<list->count;i++){                 
        if(((task_t*)link->data)->phase_time + ((task_t*)link->data)->count*((task_t*)link->data)->period== phase){
             return link;                       
        }
        else if(link == list->last)
             return 0;           
        link = link->next;
    }    
}

link_t* find_the_next_link_of_task_queue_with_same_phase(linked_list_t * list,link_t * next,int phase){
    link_t * link;
    link = (link_t*)calloc (1, sizeof (link_t));
       
	for(int i=0;i<=list->count;i++){            
        if(i==0)
            link =next;
        else 
            link = link->next; 
                           
        if(((task_t*)link->data)->phase_time == phase){
             //print_one_task((task_t*)link->data);
             //printf("\nfind_task_next : %d\n",link);
             return link;                       
        }
        else if(link == list->last)
             return 0;           
    }    
}*/

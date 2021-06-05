
void sort_task_queue_in_utilization(linked_list_t * task_queue) {
    link_t * link;
    link = (link_t*)calloc (1, sizeof (link_t));
    link = task_queue->first;
    
    link_t * task;
    task = (link_t*)calloc (1, sizeof (link_t));    
    
    for(int i=0;i<task_queue->count;i++){ 
        task=find_the_i_link_of_queue(task_queue,i);    
                   
        for(int j=0;j<task_queue->count;j++){
             if(((task_t*)task->data)->utilization <((task_t*)link->data)->utilization){                 
                  task_t *tmp;             
                  tmp= (task_t*)task->data;               
                  task->data=link->data;                               
                  link->data=tmp;                              
             } 
             link = link->next;                          
        }
        link = task_queue->first;          
    }              
}

void EDF(linked_list_t * job_queue) {
    link_t * link;
    link = (link_t*)calloc (1, sizeof (link_t));
    link = job_queue->first;
    
    link_t * link_job;//用來連接((job_t*)link_job->data) 因為tmp不能link->data=(void)tmp; 
    link_job = (link_t*)calloc (1, sizeof (link_t));    
    
    for(int i=0;i<job_queue->count;i++){ 
        link_job=find_the_i_link_of_queue(job_queue,i);    
                   
        for(int j=0;j<job_queue->count;j++){
             if(((job_t*)link_job->data)->absolute_deadline <((job_t*)link->data)->absolute_deadline){                 
                  job_t *tmp;             
                  tmp= (job_t*)link_job->data;               
                  link_job->data=link->data;                               
                  link->data=tmp;                              
             } 
             else if(((job_t*)link_job->data)->absolute_deadline ==((job_t*)link->data)->absolute_deadline)
                  if(((job_t*)link_job->data)->task_id >((job_t*)link->data)->task_id){                 
                       job_t *tmp;             
                       tmp= (job_t*)link_job->data;               
                       link_job->data=link->data;                               
                       link->data=tmp;                              
             } 
             
             link = link->next;                          
        }
        link = job_queue->first;          
    }              
}

void RM(linked_list_t * task_queue ,linked_list_t * job_queue) {
    link_t * link;
    link = (link_t*)calloc (1, sizeof (link_t));
    link = job_queue->first;
    
    link_t * link_job;
    link_job = (link_t*)calloc (1, sizeof (link_t));       

    for(int i=0;i<job_queue->count;i++){ 
        link_job=find_the_i_link_of_queue(job_queue,i);    
                  
        for(int j=0;j<job_queue->count;j++){
             if(find_the_period_of_the_job(task_queue ,job_queue,((job_t*)link_job->data)) < find_the_period_of_the_job(task_queue ,job_queue,((job_t*)link->data))){                 
                  job_t *tmp;             
                  tmp= (job_t*)link_job->data;               
                  link_job->data=link->data;                               
                  link->data=tmp;                              
             } 
             else if(find_the_period_of_the_job(task_queue ,job_queue,((job_t*)link_job->data)) == find_the_period_of_the_job(task_queue ,job_queue,((job_t*)link->data))){
                  if(((job_t*)link_job->data)->task_id >((job_t*)link->data)->task_id){                 
                       job_t *tmp;             
                       tmp= (job_t*)link_job->data;               
                       link_job->data=link->data;                               
                       link->data=tmp;   
                  }          
             }
             link = link->next;                          
        }
        link = job_queue->first; 
    }            
}

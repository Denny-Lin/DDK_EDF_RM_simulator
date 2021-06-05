
int job_queue_empety_or_not_Boolean (linked_list_t * job_queue){
    if(job_queue->first==0)
        return 1;
    else 
        return 0;
}

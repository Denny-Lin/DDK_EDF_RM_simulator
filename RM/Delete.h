
void delete_first_link_of_queue (linked_list_t * list){
    link_t * link;
    link = (link_t*)calloc (1, sizeof (link_t));
    if(list->count>1){
        link = list->first; 
        list->first=link->next;
    }
    else{
        list->first=0;
        list->last=0; 
    }   
    list->count--;         
} 
    
static int delete_all (void * data){
    return 1;
}

void delete_job_when_miss_deadline(linked_list_t * job_queue,int Clock){
       
    for(int i=0;i<=job_queue->count;i++){  
        if(job_queue_empety_or_not_Boolean(job_queue)!=1  && (((job_t*)job_queue->first->data)->absolute_deadline) < Clock+(((job_t*)job_queue->first->data)->remain_execution_time)){
            printf("  J%d has been delete\n",((job_t*)job_queue->first->data)->job_id);
            delete_first_link_of_queue(job_queue);        
        }        
    }
}
 
void linked_list_delete (linked_list_t * list, link_t * link){
    link_t * prev;
    link_t * next;

    prev = link->prev;
    next = link->next;
    if (prev) {
        if (next) {
            prev->next = next;//Both the previous and next links are valid, so just
            next->prev = prev;//bypass "link" without altering "list" at all.
        }
        else {
            prev->next = 0;//Only the previous link is valid, so "prev" is now the
            list->last = prev;//last link in "list"
        }
    }
    else {
        if (next) {
            next->prev = 0;//Only the next link is valid, not the previous one, so
            list->first = next;// "next" is now the first link in "list".
        }
        else {
            list->first = 0;//Neither previous nor next links are valid, so the list
            list->last = 0;// is now empty.
        }
    }
    free (link);
    list->count--;
}

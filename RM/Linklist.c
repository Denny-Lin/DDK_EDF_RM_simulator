#include "Header.h"

void linked_list_init (linked_list_t * list){//初始化 
    list->first = list->last = 0;
    list->count = 0;
};

void check_queue(linked_list_t * task_queue , linked_list_t * job_queue,int Clock){
    link_t * link;//task_t * task; 不用task 是因為要用 task queue 的first來拜訪下個節點 
    link = (link_t*)calloc (1, sizeof (link_t));//task=(task_t *)task_queue->first->data;
    link = task_queue->first;
   
    for(int i=0;i<task_queue->count;i++){//((task_t *)link->data)=目前的task
         if(( Clock-((task_t *)link->data)->phase_time )>=0 && ( Clock-((task_t *)link->data)->phase_time )% ((task_t *)link->data)->period == 0){                                                                                                                                                                                                                                                                                         
              //system("pause");
              //printf("Yes.%d ,%d\n",((task_t *)link->data)->phase_time,((task_t *)link->data)->period);
              Scan_Task_To_Job_Queue(job_queue,((task_t *)link->data),Clock);                    
         }
         link=link->next;
    }      
}

void processor_execution(linked_list_t * task_queue , linked_list_t * job_queue){                               
    int Clock=0;
    int LCM=LCM_of_all_the_tasks_period(task_queue);   
        LCM += MAX_phase_in_task_queue(task_queue);//LCM加一段時間 用來觀察下個循環是不是重複    
                  
    while(Clock<=LCM){
         printf("%d\t",Clock); 
         
         check_queue(task_queue,job_queue,Clock);
         delete_job_when_miss_deadline(job_queue,Clock);
         
         if(job_queue_empety_or_not_Boolean(job_queue)!=1){
                                                            
             //EDF(job_queue);
             RM(task_queue,job_queue);//因為job queue沒有period 所以傳入task queue 
                                                                                        
             if(((job_t*)job_queue->first->data)->remain_execution_time>0){                                                                                                                                                       
                   //job_traverse(job_queue, 0, print_job);  
                   ((job_t*)job_queue->first->data)->remain_execution_time--;
                   printf("T%d",((job_t*)job_queue->first->data)->task_id);
                   if(((job_t*)job_queue->first->data)->remain_execution_time==0){                                                                            
                        delete_first_link_of_queue(job_queue);                                                               
                   }     
                   //LCM++;                    
             } 
         }      
         printf("\n");                        
         Clock++;    
    }           
}
 
void Scan_Task_To_Job_Queue(linked_list_t * job_queue,task_t * task,int Clock){
     job_t *job; 
     job = (job_t*)malloc (sizeof(job_t));                                       
                                     
     job->ready_time = task->phase_time + task->count*task->period;//count*period = 做了幾個job*task周期 = 經過時間 
     job->remain_execution_time = task->execution_time;
     job->absolute_deadline = task->phase_time + task->relative_deadline + task->count*task->period;//同上 
                                                      //RM = period
     job->task_id=task->task_id;
     task->count++;//目前的task產生新的job 所以+1  
     job->job_id=task->count; 
                        
     job_add(job_queue,job); 
}
task_t* phase_time(task_t * task,int Clock){
        
     return  task; 
}

void job_add (linked_list_t * job_queue,job_t * job){
    link_t * link;  
    link = (link_t*)calloc (1, sizeof (link_t));
       
    link->data = job;
    /* Join the two final links together. */ 
    if (job_queue->last) {      
        job_queue->last->next = link;
        link->prev = job_queue->last;
        job_queue->last = link;
    }
    else{
        job_queue->first = link;         
        job_queue->last = link;
    }
    job_queue->count++;//計算目前的job queue有幾個job       
}

linked_list_t Scan_File_To_Task_Queue(linked_list_t * task_queue){
    FILE *file;   
    char RPCD[LINE_SIZE];     
    char *RPCD_next;
    file=fopen("task.txt","r");
 
    while(fgets(RPCD,LINE_SIZE*10,file)!=NULL  ){                                              
         RPCD_next=strtok(RPCD," "); 
         int tmp[LINE_SIZE]={0};
         task_t * task;
         task = (task_t*)malloc (sizeof(task_t));
         
         for(int i=0;i<LINE_SIZE-1;i++){ //LINE_SIZE-'\0'
              tmp[i] =atoi(RPCD_next);//由空格分開的task資料取出存到tmp[]                                                       
              RPCD_next=strtok(NULL," ");  
         } 
    
         task->phase_time= tmp[0];
         task->period= tmp[1];
         task->execution_time= tmp[2];
         task->relative_deadline= tmp[3];
         task->count=0;
              
         task_add(task_queue,task);
    } 
    fclose(file);
    return *task_queue;
}

void task_add (linked_list_t * task_queue,task_t * task){//用在Scan_File_To_Task_Queue
    link_t * link;
    link = (link_t*)calloc (1, sizeof (link_t));
       
    link->data = task;
     /* Join the two final links together. */  
    if (task_queue->last) {  
        task_queue->last->next = link;
        link->prev = task_queue->last;
        task_queue->last = link;
    }
    else{
        task_queue->first = link;         
        task_queue->last = link;
    } 
        //RM P=D
        task->utilization=task->execution_time/(double)task->period;
    
    task_queue->count++;//計算目前的task queue有幾個task                 
    task->task_id=task_queue->count;//每個task set由1開始依序標上代號  
}                                   //ex: task_id=6 則第6個task set產生的job為(6,1)(6,2)... 

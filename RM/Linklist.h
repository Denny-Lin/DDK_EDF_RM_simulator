typedef struct link link_t;
struct link {/* A link_t contains one of the links of the linked list. */
    void * data;
    link_t * prev;
    link_t * next;
};

typedef struct linked_list{/* linked_list_t contains a linked list. */
    int count;//目前有幾個node ex:從file.txt讀進去5筆資料 count=5 
    double utilization;
    
    link_t * first;
    link_t * last;
}linked_list_t;

typedef struct job{
    int job_id;//目前第幾個job =task的count
    int task_id;//目前第幾個task =task的task id 
               //用來標示出目前是哪個task的第幾個job 
    int ready_time;
    int remain_execution_time;
    int absolute_deadline;
}job_t;

typedef struct task{ 
    int task_id;
    int count;//目前做到第幾個job; ex:產生第一個task的第一個job count=1   
    double utilization;
    
    int phase_time;
    int period;
    int execution_time;
    int relative_deadline;
}task_t;

void linked_list_init (linked_list_t *);

void processor_execution(linked_list_t *  , linked_list_t * );
linked_list_t Scan_File_To_Task_Queue(linked_list_t *);

void Scan_Task_To_Job_Queue(linked_list_t *,task_t *,int);

void task_traverse (linked_list_t * , void * ,void (*) (task_t *,task_t *));//callback輸出所有task queue的task
void print_task (task_t * , task_t * );//callback
void job_traverse (linked_list_t *, void * ,void (*) (job_t *,job_t *));//callback輸出所有job queue的job 
void print_job (job_t *, job_t *);//callback
void print_first_task (task_t *);
void print_first_job (job_t *);
void print_utilization(linked_list_t * );
void print_job_queue_empety_or_not( linked_list_t * );

void task_add (linked_list_t * list,task_t *);//加一筆task到task queue最後面 
void job_add (linked_list_t * list,job_t *);//加一筆job到task queue最後面

int MAX_phase_in_task_queue(linked_list_t *);
int LCM_of_all_the_tasks_period(linked_list_t *);

void sort_task_queue_in_utilization(linked_list_t *);//由小到大
void EDF(linked_list_t *);//job queue
void RM(linked_list_t * ,linked_list_t *);//job queue ,因為job沒有period
int find_the_period_of_the_job(linked_list_t *, linked_list_t *, job_t *); 

link_t* find_the_i_link_of_queue(linked_list_t *, int);
int job_queue_empety_or_not_Boolean (linked_list_t *);

void delete_first_link_of_queue (linked_list_t * );
static int delete_all (void * );
void delete_job_when_miss_deadline(linked_list_t * ,int);
void linked_list_delete(linked_list_t * , link_t * );//只能刪除中間和最後一個,刪第一個會錯 

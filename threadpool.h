#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<signal.h>
#include<errno.h>
#include<assert.h>

typedef struct
{
	void *(*function) (void *);
	void *arg;
} threadpool_task_t;
 
typedef struct threadpool_t {
	pthread_mutex_t lock;               
	pthread_mutex_t thread_counter;     
	pthread_cond_t queue_not_full;      
	pthread_cond_t queue_not_empty;     
 
	pthread_t *threads;                 
	pthread_t adjust_tid;               
	threadpool_task_t *task_queue;      
 
	int min_thr_num;                    
	int max_thr_num;                    
	int live_thr_num;                   
	int busy_thr_num;                   
	int wait_exit_thr_num;              
 
	int queue_front;                    
	int queue_rear;                     
	int queue_size;                     
	int queue_max_size;                 
 
	int shutdown;                       
} threadpool_t;

/* 创建线程池 */
threadpool_t *threadpool_create(int min_thr_num, int max_thr_num, int queue_max_size);

/* 向任务队列中， 添加一个任务 */
int threadpool_add(threadpool_t *pool, void *(*function)(void *arg), void *arg);

/* 销毁线程池 */
int threadpool_destroy(threadpool_t *pool);

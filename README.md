# C_Threadpool
C语言线程池

# 描述

**已修改:**

删除pthread_cond_broadcast冗余广播

修改线程池的释放的逻辑，无需死等或者任务未完成却exit掉

**待解决:**

threadpool_add,在堵塞阶段且都为耗时任务时，会低概率的情况出现arg还在使用却free掉了的安全问题(这一块的逻辑不太好改，暂时没啥好的思路)

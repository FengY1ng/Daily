#include<stdio.h>
#include<string.h>

struct job{
    char name[10];
    int starttime;
    int needtime;
    int runtime;
    int endtime;
    double dqzztime;
 
};

void FCFS(struct job jobs[50],int n)
{
   int i; 
   for(i=0;i<n;i++)
   {
    if(i==0) {
       jobs[i].runtime=jobs[i].needtime;
       jobs[i].endtime=jobs[i].starttime+jobs[i].needtime;  
    }
    else if(jobs[i].starttime>jobs[i-1].endtime){
       jobs[i].runtime=jobs[i].needtime;  
       jobs[i].endtime=jobs[i].starttime+jobs[i].needtime;  
    }
    else{
       jobs[i].runtime=jobs[i].needtime+jobs[i-1].endtime-jobs[i].starttime; 
       jobs[i].endtime=jobs[i].starttime+jobs[i].runtime;
    }
    jobs[i].dqzztime=jobs[i].runtime*1.0/jobs[i].needtime;
   }
}

void SJF(struct job jobs[50],int n)
{
   int i=0,b=0;
   char temp[10];
   int min;            
   for(i=0;i<n-1;i++)
      {
          if(jobs[i].starttime>jobs[i+1].starttime)
          {
              min=jobs[i].starttime;
              jobs[i].starttime=jobs[i+1].starttime;
              jobs[i+1].starttime=min;

              min=jobs[i].needtime;
              jobs[i].needtime=jobs[i+1].needtime;
              jobs[i+1].needtime=min;

              strcpy(temp,jobs[i].name);
              strcpy(jobs[i].name,jobs[i+1].name);
              strcpy(jobs[i+1].name,temp);
          }
      }                      

   jobs[0].endtime=jobs[0].starttime+jobs[0].needtime;
   jobs[0].runtime=jobs[0].needtime;
   jobs[0].dqzztime=jobs[0].runtime*1.0/jobs[0].needtime;


    for(i=1;i<n;i++)
    {
        if(jobs[i].starttime>jobs[0].endtime);
            else b=b+1;
    }

    for(i=1;i<=b-1;i++)
    {
        if(jobs[i].needtime>jobs[i+1].needtime)
        { 
          min=jobs[i].starttime;
          jobs[i].starttime=jobs[i+1].starttime;
          jobs[i+1].starttime=min;
                  
          min=jobs[i].needtime;
          jobs[i].needtime=jobs[i+1].needtime;
          jobs[i+1].needtime=min;

          strcpy(temp,jobs[i].name);
          strcpy(jobs[i].name,jobs[i+1].name);
          strcpy(jobs[i+1].name,temp);
        }
    }

    for(i=1;i<n;i++)
    {
      if(jobs[i].starttime>jobs[i-1].endtime)
      {
        jobs[i].endtime=jobs[i].starttime+jobs[i].needtime; 
        jobs[i].runtime=jobs[i].needtime;
      }
      else
      {
         jobs[i].endtime=jobs[i-1].endtime+jobs[i].needtime;
         jobs[i].runtime=jobs[i].endtime-jobs[i].starttime; 
      }
      jobs[i].dqzztime=jobs[i].runtime*1.0/jobs[i].needtime;
    }
}

void result(struct job jobs[50],int n)
{
    int i;
    double averruntime;
    double averdqzztime;
    int sum_runtime=0;
    double  sum_dqzztime=0.00;
    printf("作业名\t到达时间\t运行时间\t完成时间\t周转时间  带权周转时间\n");
    for(i=0;i<n;i++)
    {
    printf("%s\t     %d\t       %d\t       %d\t      %d            %.2f\n",jobs[i].name,jobs[i].starttime,jobs[i].needtime,jobs[i].endtime,jobs[i].runtime,jobs[i].dqzztime);
    
    sum_runtime=sum_runtime+jobs[i].runtime;
    sum_dqzztime=sum_dqzztime+jobs[i].dqzztime;
    }
    averruntime=sum_runtime*1.0/n;
    averdqzztime=sum_dqzztime*1.000/n;
    printf("平均周转时间:%.2f \n",averruntime);
    printf("平均带权周转时间:%.3f \n",averdqzztime);
    printf("\n");
}

void main()
{
    struct job jobs[50];
    int n,i;

    printf("输入作业个数:");
    scanf("%d",&n);
    printf("输入每个作业的作业名,到达时间,服务时间:\n");
    for(i=0;i<n;i++)
    {
        scanf("%s",jobs[i].name);
        scanf("%d",&jobs[i].starttime);
        scanf("%d",&jobs[i].needtime);
    }
    printf("\n");
    printf("作业名\t到达系统时间\t运行时间\n");
    for(i=0;i<n;i++)
    {
    printf("%s\t      %d\t         %d\n",jobs[i].name,jobs[i].starttime,jobs[i].needtime);
    }


    FCFS(jobs,n);
    printf("先来先服务（FCFS）算法运行结果：\n");
    result(jobs,n);


    SJF(jobs,n);
    printf("最短作业优先算法（SJF）运行结果：\n");
    result(jobs,n);
}



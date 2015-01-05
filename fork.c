#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>


int main(void)
{
   pid_t pid[3];
   int count = 3,i =0,status = -1;
   for (;i < 3 ;i++)
     pid[i]= 0;

   for(;count >  0 ; count--)
   {
	   if ((pid[count-1] =  fork()) < 0 )
	   {
		   printf("vfork failed \n");
		   exit(-1);
	   }
	   else if (pid[count-1] == 0)
	   {
		  // printf("child is starting \n");
		   printf("child[%d] \n child have stoped \n",getpid());
                   int result = 0;
                  // result = execlp("/home/zhangjiaming/code/github/ex.exe","000",(char*) 0);
                  // result = execl("/home/zhangjiaming/code/github/ex.exe",(char*) 0);
                   result = execl("/bin/sh","sh","-c","date",(char*) 0);
                   if (result < 0 )
                   {
                      printf("execle failed \n");
                      exit(-1);
                   }
                   if (count - 1 == 0 )
                     sleep(10);
		   exit(0);
	   }	   //printf("father[%d]\n",getpid());
	   //printf("fathere have stoped \n");
  }

  int rt_pid = 0;
  while (rt_pid = waitpid (-1,&status ,0) > 0 )
  {
     printf("have waited pid = %d \n",rt_pid);
     if (WIFEXITED(status))
        printf("exit normal \n");
     else if (WIFSIGNALED(status))
       printf("exit by error \n");
     else if (WIFSTOPPED(status))
       printf("process pause \n");
     else if (WIFCONTINUED(status))
       printf("process continues \n");
     else 
       printf("unkown status \n");
  }
  return (0);
}

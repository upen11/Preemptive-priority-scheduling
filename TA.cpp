#include<stdio.h>
	 
	struct process
	{
	      char p_name;
	      int a_time, b_time, ct, w_time, TA_time, priority;
	      int status;
	}p_queue[10];
	 
	int limit;
	 
	void ArrivalTimeSorting()
	{
	      struct process temp;
	      int m, n;
	      for(m=0; m<limit-1; m++)
	      {
	            for(n=m+1; n<limit; n++)
	            {
	                  if(p_queue[m].a_time > p_queue[n].a_time )
	                  {
	                        temp = p_queue[m];
	                        p_queue[m] = p_queue[n];
	                        p_queue[n] = temp;
	                  }
	            }
	      }
	}
	 
	int main()
	{
	      int m, time = 0, b_time = 0, largest;
	      char c;
	      float wait_time = 0, TA_time = 0, avg_w_time, avg_TA_time;
	      printf("\nEnter Total No. of Processes:\t");
	      scanf("%d", &limit);
	      for(m=0, c='A'; m<limit; m++, c++)
	      {
	            p_queue[m].p_name = c;
	            printf("\nEnter Details For Process[%C]:\n", p_queue[m].p_name);
	            printf("Enter Arrival Time:\t");
	            scanf("%d", &p_queue[m].a_time  );
	            printf("Enter Burst Time:\t");
	            scanf("%d", &p_queue[m].b_time);
	            printf("Enter Priority:\t");
	            scanf("%d", &p_queue[m].priority);
	            p_queue[m].status = 0;
	            b_time = b_time + p_queue[m].b_time;
	      }
	      ArrivalTimeSorting();
	      p_queue[9].priority = -9999;
	      printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
	      for(time = p_queue[0].a_time ; time < b_time;)
	      {
	            largest = 9;
	            for(m=0; m<limit; m++)
	            {
	                  if(p_queue[m].a_time <= time && p_queue[m].status != 1 && p_queue[m].priority > p_queue[largest].priority)
	                  {
	                        largest = m;
	                  }
	            }
	            time = time + p_queue[largest].b_time;
	            p_queue[largest].ct = time;
	            p_queue[largest].w_time = p_queue[largest].ct - p_queue[largest].a_time  - p_queue[largest].b_time;
	            p_queue[largest].TA_time = p_queue[largest].ct - p_queue[largest].a_time;
	            p_queue[largest].status = 1;
	            wait_time = wait_time + p_queue[largest].w_time;
	            TA_time = TA_time + p_queue[largest].TA_time;
	            printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", p_queue[largest].p_name, p_queue[largest].a_time , p_queue[largest].b_time, p_queue[largest].priority, p_queue[largest].w_time);
	      }
	      avg_w_time = wait_time / limit;
	      avg_TA_time = TA_time / limit;
	      printf("\n\nAverage waiting time:\t%f\n", avg_w_time);
	      printf("Average Turnaround Time:\t%f\n", avg_TA_time);
	
	}


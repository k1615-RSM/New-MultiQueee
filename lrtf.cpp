#include<stdio.h>
float turn=0,wait=0;
int limit=0;
struct student
{
	int rno;
	int take;
	int xyz;
	int arrival;
	int myvar;
};
int allocateval(struct student *s,int rno,int take,int arr,int myvar){
	s->rno=rno;
	s->arrival=arr;
	s->myvar=myvar;
	s->take=take;
}

int main()
{
	struct student a,b,c;
	int i=0;
	allocateval(&a,2132,2,0,-1);
	allocateval(&b,2102,4,0,-1);
	allocateval(&c,2453,8,0,-1);	

	int time=a.take+b.take+c.take;
	for(i=0;i<time;i++)
	{
		if(a.take>b.take && a.take>c.take)
		{
			Aeat(&a);
		}
		else if(b.take>a.take && b.take>c.take)
		{
			Beat(&b);
		}
		else if(c.take>a.take && c.take>b.take)
		{
			Ceat(&c);
		}
		else if(a.take==b.take)
		{
			if(a.rno<b.rno)
			{
				Aeat(&a);
			}
			else
			{
				Beat(&b);
			}
		}
		else if(a.take==c.take)
		{
			if(a.rno<c.rno)
			{
				Aeat(&a);
			}
			else
			{
				Ceat(&c);
			}
		}
		else if(b.take==c.take)
		{
			if(b.rno<c.rno)
			{
				Beat(&b);
			}
			else
			{
				Ceat(&c);
			}
		}
	}
	printf("\nThe average turnaround time is-: %f",turn/3);
	printf("\nThe average waiting time is-: %f",wait/3);
}
void Aeat(struct student *a)
{
	if(a->myvar==-1)
	{
		a->myvar=limit;
	}
	limit++;
	a->take--;
	if(a->take==0)
	{
		a->xyz=limit;
		turn=turn+(a->xyz-a->arrival);
		wait=wait+(a->xyz-a->myvar);
	}
}
void Beat(struct student *b)
{
	if(b->myvar==-1)
	{
		b->myvar=limit;
	}
	limit++;
	b->take--;
	if(b->take==0)
	{
		b->xyz=limit;
		turn=turn+(b->xyz-b->arrival);
		wait=wait+(b->xyz-b->myvar);
	}
}
void Ceat(struct student *c)
{
	if(c->myvar==-1)
	{
		c->myvar=limit;
	}
	limit++;
	c->take--;
	if(c->take==0)
	{
		c->xyz=limit;
		turn=turn+(c->xyz-c->arrival);
		wait=wait+(c->xyz-c->myvar);
	}
}

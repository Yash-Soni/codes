#include<iostream>
using namespace std;

typedef struct node
{
	int dest;
	int weight;
	node *next;
};

typedef struct list
{
	node *head;
};

typedef struct graph
{
	int V,e,count,t_edges,c_edges,b_edges,f_edges;
	list *A;
	int *d,*pie,*dis,*fin;
	int **tree_mat, **front_mat,**back_mat,**cross_mat,**edge_mat;
	char *color;

};

typedef struct stack
{
	int top;
	int *ar;
};

graph* createGraph(int, int);
void callDfs(graph*,int,stack*,stack*);
void Dfs(graph*,int ,int*);
void print(graph*,stack*,stack*);
void push(graph*,stack*,int);
int pop(graph*,stack*);
void Dfs_top(graph*, stack*,stack*,int ,int*);
void cycle(graph*,stack*);
stack* createStack(graph*);

void topological_sort(graph*,int);

void tree_edge(graph*);
void front_edge(graph*);
void back_edge(graph*);
void cross_edge(graph*);


int main()
{
	int v,e;
	cout<<"\nEnter number of vertices : ";
	cin>>v;
	cout<<"\nEnter number of edges : ";
	cin>>e;
	graph *g = createGraph(v,e);
	stack *st = createStack(g);
	stack *st2 = createStack(g);
	callDfs(g,v,st,st2);
	print(g,st,st2);
	//cout<<"\nEnter vertex for topological sort :";
	//cin>>v;
	//topological_sort(g,v);
}

stack* createStack(graph *g)
{
	stack *st = (stack*)calloc(1,sizeof(stack));
	st->ar = (int*)calloc(g->V,sizeof(int));
	st->top = -1;

	return st;
}

graph* createGraph(int n, int e)
{
	int u,v;
	graph *G = (graph*)calloc(1,sizeof(graph));
	//initializing verices and edges
	G->V = n;	G->e = e;				
	G->count = 0;
	G->b_edges =0;
	G->t_edges =0;
	G->c_edges =0;
	G->f_edges =0;
	
	G->edge_mat = (int**)calloc(G->V+1, sizeof(int*));

	for(int i = 0; i < G->V+1; i++)
	{
		G->edge_mat[i] = (int*)calloc(G->V+1, sizeof(int));
	}

	G->A = (list*)calloc(G->V+1,sizeof(int));
	for(int i = 0; i < G->e ; i++)
	{
		cout<<"\nEnter 2 vertices for directed edges: \n";
		cin>>u>>v;
		node *pt = (node*)calloc(1,sizeof(node));
		pt->next = NULL;
		pt->dest = v;
		pt->next = G->A[u].head;
		G->A[u].head = pt;
	}
	return G;
}

void callDfs(graph *g, int ver, stack *st,stack *st2)
{
	g->d = (int*)calloc(g->V+1,sizeof(int));
	g->dis = (int*)calloc(g->V+1,sizeof(int));
	g->fin = (int*)calloc(g->V+1,sizeof(int));
	g->color = (char*)calloc(g->V+1,sizeof(char));
	g->pie = (int*)calloc(g->V+1,sizeof(int));

	for(int i = 0; i< g->V+1; i++)
	{
		g->d[i] = 0;
		//g->pie[i] = 0;
		g->color[i] = 'w';
		g->dis[i] = INT_MAX;
		g->fin[i] = INT_MAX;
	}

	/*stack *st = (stack*)calloc(1,sizeof(stack));
	st->ar = (int*)calloc(g->V,sizeof(int));
	st->top = -1;*/

	int time = 0;
	for(int i = 1;i < g->V+1; i++)
	{
		if(g->color[i] == 'w')
		{
			g->pie[i] = 0;
			//counting connected components
			g->count++;

			//Dfs(g,i,&time);
			Dfs_top(g,st,st2,i,&time);			
		}
	}

}

void Dfs(graph *g, int u,int *time)
{
	int v;
	g->color[u] = 'g';
	*time = *time +1;
	g->dis[u] = *time;
	node *t = (node*)calloc(1,sizeof(node));
	t = g->A[u].head;
	while(t != NULL)
	{
		v = t->dest;
		if(g->color[v] == 'w')
		{
			g->pie[v] = u;
			Dfs(g,v,time);
		}
		t = t->next;
	}
	g->color[u] = 'b';
	*time = *time +1;
	g->fin[u] = *time;
}

void print(graph *g, stack *st,stack *st2)
{
	for(int i = 1; i < g->V+1; i++)
	{
		cout<<"\nVertex "<<i<<" has parent "<<g->pie[i]<<" and color "<<g->color[i]<<", it was discovered at "<<g->dis[i]<<" and finished at "<<g->fin[i]; 
	}
	cout<<"\nThis graph has "<<g->count<<" connected components.\n";

	cout<<"\nTree Edges = "<<g->t_edges;
	cout<<"\nBack Edges = "<<g->b_edges;
	cout<<"\nFront Edges = "<<g->f_edges;
	cout<<"\nCross Edges = "<<g->c_edges;
	cout<<"\n";
	if(g->b_edges == 0)
		cout<<"It is ACYCLIC Graph.\n";
	else
		{
			cout<<"It is CYCLIC Graph.\n";
			cycle(g,st);
		}
	cout<<"\nTopological Sort of the graph is :\n";
	while(st2->top != 0)
	{
		cout<<st2->ar[st2->top]<<" --> ";
		st2->top--;
	}
	cout<<st2->ar[st2->top];
}

int stack_top(stack *st)
{
	int i;
	i = st->ar[st->top];
	return i;
}

void push(graph *g,stack *st, int u)
{
	if(st->top == g->V-1)
	{
		cout<<"\nStack Full !!";
		exit(1);
	}
	else
	{
		st->top++;
		st->ar[st->top] = u;
	}
}

int pop(graph *g, stack *st)
{
	int i;
	if(st->top == -1)
	{
		cout<<"\nStack Empty!! ";
		exit(1);
	}
	else
	{
		i = st->ar[st->top];
		//st->top--;
	}
	return i;
}

void Dfs_top(graph *g, stack *st, stack *st2, int u, int *time)
{
	int v;
	*time = *time + 1;
	//stack *st2 = createStack(g);
	push(g,st, u);
	g->dis[u] = *time;
	node *pt; //= (node*)calloc(1,sizeof(node));
	node *tem = (node*)calloc(1,sizeof(node));
		
	while(st->top != -1)
	{
		u = stack_top(st);
		pt = g->A[u].head;
		g->color[u] ='g';
		while(pt!= NULL)
		{
			v = pt->dest;
			
			if((g->color[v] == 'b') && (g->edge_mat[u][v] != 1))
			{
				if(g->dis[u] < g->dis[v])		//fin[v] changed to dis[v]
				{
					front_edge(g);
					g->edge_mat[u][v] = 3;
				}
				else if(g->dis[u] > g->dis[v])		//finv[v] changed to dis[v]
				{
					cross_edge(g);
					g->edge_mat[u][v] = 4;
				}
			}
			else if(g->color[v] == 'g')					//dhyan rakhna yaha pr
			{
				int x;
				back_edge(g);
				g->edge_mat[u][v] = 2;
			}
			
			if(g->color[v] == 'w')
			{
				g->color[v] = 'g';
				g->pie[v] = u;
				*time = *time + 1;
				tree_edge(g);
				g->edge_mat[u][v] = 1;
				push(g, st, v);
				//u = pop(g, st);
				g->dis[v] = *time;
				pt = g->A[v].head;
				//pt->next = tem;
			}
			else
				pt = pt->next;
			//	pt->next = tem;
				//u = pop(g, st);
				u = stack_top(st);
			//}
			
			//pt = pt->next;
		}	
			g->color[u] = 'b';
			*time = *time + 1;
			g->fin[u] = *time;
			push(g,st2,u);
			st->top--;
		
		//g->color[u] = 'b';
	}
}

void tree_edge(graph *g)
{
	g->t_edges++;
}

void front_edge(graph *g)
{
	g->f_edges++;
}
void back_edge(graph *g)
{
	g->b_edges++;
}

void cross_edge(graph *g)
{
	g->c_edges++;
}

void cycle(graph *g, stack *st)
{
	int u,v,tem,i,j;
	for(i = 1; i <g->V+1; i++)
	{
		for(j = 1; j < g->V+1; j++)
		{
			if(g->edge_mat[i][j] == 2)
			{
				u = i; v = j;
				//yaha pr
				break;
			}
		}
	}
	L1:
	tem = u;
	node *pt;
	pt = g->A[u].head;
	push(g, st, u);
	cout<<"\nCycle is as follows :\n";
	while(tem != v)
	{
		v = pt->dest;
		u = stack_top(st);
		cout<<u<<" - ";
		push(g,st,v);
		pt = g->A[v].head;
	}
	cout<<tem<<"\n";
}

/*void topological_sort(graph *g, int u)
{
	stack *st1 = createStack(g);
	stack *st2 = createStack(g);
	int i,v,time = 0;
	node *pt;
	pt = g->A[u].head;
	push(g,st1,u);
	time++;
	g->dis[u] = time;
	while(st1->top != -1)
	{
		while(pt!= NULL)
		{
			v = pt->dest;
			push(g,st1,v);
			time++;
			g->dis[v] = time;
			pt = pt->next;
		}
		
	}

}*/
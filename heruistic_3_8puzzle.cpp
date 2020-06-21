#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class  state
{
public:
	int color;
	int a[3][3];
	int cost;//g(n)
	int evaluation_cost; //f(n)+g(n)
	 state()
	 {
	 	color=0;
	 	evaluation_cost=0;
	 	cost=0;
	 	for (int i = 0; i < 3; i++)
	 	{
	 		for(int j=0;j<3;j++)
	 		{

	 			a[i][j]=0;
	 		}
	 	}
	 	//a[0][2]=0;
	 }
	 bool operator <(const state & stateObj) const
	 {
	 	return evaluation_cost < stateObj.evaluation_cost;
	 }

	 void print()
	 {
	 	for(int i=0;i<3;i++)
	 	{
	 		for(int j=0;j<3;j++)
	 		{
	 			cout<<a[i][j]<<" ";
	 		}
	 		cout<<endl;
	 	}
	 	cout<<"path cost "<<cost<<endl;
	 	cout<<"evaluation_cost "<<evaluation_cost<<endl;
	 }
	 int heruistic3(state p)
	{
		int c=0;

		if(p.a[0][0]!=1)
		{
			c++;
		}
		if(p.a[0][1]!=2)
		{
			c++;
		}
		if(p.a[1][0]!=3)
		{
			c++;
		}
		if(p.a[1][1]!=4)
		{
			c++;
		}
		if(p.a[1][2]!=5)
		{
			c++;
		}
		if(p.a[2][0]!=6)
		{
			c++;
		}
		if(p.a[2][1]!=7)
		{
			c++;
		}
		if(p.a[2][2]!=-1)
		{
			c++;
		}
		return c;
	}

	 state* genNextState()
	 {
	 

	 	int initial_cost=cost;
	 	state *p=new state[4];
	 	int initial[3][3];
	 	state blank;

	 	int x1=0;
	 	int y1=0;
	 	int f=0;

	 	for (int i = 0; i < 3; ++i)
	 	{
	 		for(int j=0;j<3;j++)
	 		{
	 			initial[i][j]=a[i][j];
	 		}
	 	}



	 	//cout<<"move black tile to left"<<endl;
	 	p[0].cost=initial_cost+1;
	 	for (int i = 0; i < 3; i++)
	 	{
	 		for(int j=0;j<3;j++)
	 		{
	 			if(j==0)
	 			{
	 				p[0].a[i][j]=initial[i][j];
	 				//p[0].cost=initial_cost+100;
	 			}
	 			else
	 			{
	 				if(initial[i][j]==-1)
		 			{
		 				
		 				 p[0].a[i][j]=initial[i][j-1];
		 				 p[0].a[i][j-1]=-1;
		 				// p[0].cost=initial_cost+1;
		 				 f=1;
		 				
		 			}
		 			else
		 			{
		 				
			 			p[0].a[i][j]=initial[i][j];
		 			}
	 			}
	 			
	 		}
	 	
	 	} 	
	 	if (f==1)
	 	{
	 		p[0].evaluation_cost=p[0].cost+heruistic3(p[0]);
	 		//p[0].print();
	 	}
	 	else
	 	{
	 		p[0]=blank;
	 		//cout<<"blanking"<<endl;
	 		//p[0].print();
	 	}
	 	
	 	//cout<<t.heruistic1(p[0])<<endl;
	 	f=0;




	 	//cout<<"move black tile to right"<<endl;
	 	p[1].cost=initial_cost+1;
	 	for (int i = 0; i < 3; i++)
	 	{
	 		for(int j=0;j<3;j++)
	 		{
		 			if (f==1 && (i==x1 && j==y1))
		 			{
		 				
		 			}
		 			else
		 			{
		 				if(j==2)
			 			{
			 				p[1].a[i][j]=initial[i][j];
			 				//p[1].cost=initial_cost+100;
			 			}
			 			else
			 			{
			 				if(initial[i][j]==-1)
				 			{
				 				if (i==0 && j==1)
				 				{
				 					p[1].a[i][j]=initial[i][j];
				 				}
				 				else
				 				{
				 					p[1].a[i][j]=initial[i][j+1];
					 				 p[1].a[i][j+1]=-1;
					 				 x1=i;
					 				 y1=j+1;
					 				 f=1;
					 				 //p[1].cost=initial_cost+1;
				 				}
				 				
				 				 
				 			}
				 			else
				 			{
				 				
					 			p[1].a[i][j]=initial[i][j];
				 			}
			 			}
	 			}
	 			
	 			
	 		}
	 	
	 	} 	
	 	if (f==1)
	 	{
	 		p[1].evaluation_cost=p[1].cost+heruistic3(p[1]);
	 		//p[1].print();
	 	}
	 	else
	 	{

	 		p[1]=blank;
	 		//p[1].evaluation_cost=p[1].cost+heruistic1(p[1])+1000;
	 	}

	 	
	 	f=0;


	 		//cout<<"move black tile to up"<<endl;
	 		p[2].cost=initial_cost+1;
	 	for (int i = 0; i < 3; i++)
	 	{
	 		for(int j=0;j<3;j++)
	 		{
	 			if(i==0)
	 			{
	 				p[2].a[i][j]=initial[i][j];
	 				//p[2].cost=initial_cost+100;
	 			}
	 			else
	 			{
	 				if(initial[i][j]==-1)
		 			{
		 				 if(i==1 && j==2)
		 				 {
		 				 	p[2].a[i][j]=initial[i][j];
		 				 }
		 				 else
		 				 {
		 				 	 p[2].a[i][j]=initial[i-1][j];
		 					 p[2].a[i-1][j]=-1;
		 					 f=1;
		 					 //p[2].cost=initial_cost+1;
		 				 }
		 				
		 				
		 			}
		 			else
		 			{
		 				
			 			p[2].a[i][j]=initial[i][j];
		 				
		 			}
	 			}
	 			
	 		}
	 	
	 	}
	 	if (f==1)
	 	{
	 		p[2].evaluation_cost=p[2].cost+heruistic3(p[2]);
	 		//p[2].print();
	 	}
	 	else
	 	{
	 		p[2]=blank;
	 		//p[2].evaluation_cost=p[2].cost+heruistic1(p[2])+1000;
	 	}

	 	
	 	f=0;



	 		//cout<<"move black tile to down"<<endl;
	 		p[3].cost=initial_cost+1;
	 	for (int i = 0; i < 3; i++)
	 	{
	 		for(int j=0;j<3;j++)
	 		{
	 			if(f==1 && (i==x1 && j==y1))
	 			{

	 			}
	 			else
	 			{
		 			if(i==2)
		 			{
		 				p[3].a[i][j]=initial[i][j];
		 				//p[3].cost=initial_cost+100;
		 			}
		 			else
		 			{
		 				if(initial[i][j]==-1)
			 			{
			 				
			 				 p[3].a[i][j]=initial[i+1][j];
			 				 p[3].a[i+1][j]=-1;
			 				 x1=i+1;
			 				 y1=j;
			 				 f=1;
			 				//p[3].cost=initial_cost+1;
			 			}
			 			else
			 			{
			 			
				 			p[3].a[i][j]=initial[i][j];
			 			}
		 			}
	 			}
	 		
	 			
	 		}
	 	
	 	} 	
	 	if (f==1)
	 	{
	 		p[3].evaluation_cost=p[3].cost+heruistic3(p[3]);
	 		//p[3].print();
	 	}
	 	else
	 	{
	 		p[3]=blank;
	 		//p[3].evaluation_cost=p[3].cost+heruistic1(p[3])+1000;
	 	}

	 	
	 	f=0;



	 	return p;

	 }

	
};
state point_blank;
int c=0;
state final_goal_state;
state initial_state;
class mapping
{
	public:
	state parent;
	state child;
		
};
mapping *m=new mapping[1000000];

class a_star
{
public:
	list<state> li;


	a_star()
	{

	}
	bool eqtest(state p,state q)
	{
		//cout<<"eqtest"<<endl;
		int f=0;
		if((p.a[0][0]==q.a[0][0]) && p.a[0][1]==q.a[0][1])
		{
			if ((p.a[1][0]==q.a[1][0]) && (p.a[1][1]==q.a[1][1]) && (p.a[1][2]==q.a[1][2]))
			{
				if ((p.a[2][0]==q.a[2][0]) && (p.a[2][1]==q.a[2][1]) && (p.a[2][2]==q.a[2][2]))
				{
					f=1;
				}
			}
		}
		if(f==1)
		{
			//cout<<"equal"<<endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	void back_track(state p,state q)
	{
		
		list<state> pq;
		cout<<"Backtrack"<<endl;
		
	//	cout<<"Printing P and q"<<endl;
		//p.print();
	//	q.print();
		pq.push_back(q);
		
		cout<<endl;
		x:
		for (int i=0;i<c;i++)
		{

			if(eqtest(m[i].child,p))
			{
				//cout<<"clicking"<<endl;

			//	p.print();
				pq.push_back(p);
				
				//cout<<"Parent found"<<endl;
				p=m[i].parent;
				q=m[i].child;
			//	q.print();

				if(eqtest(p,initial_state))
				{
				//	p.print();
					
					pq.push_back(p);
					//cout<<"Source found"<<endl;
					break;
				}
				else
				{
					goto x;			
				}
				
			}
		}
		int k=0;
		pq.reverse();
		while(pq.size())
		{
			cout<<"Step : "<<k<<endl;
			state w=pq.front();
			w.print();
			//w.calc();
			cout<<endl;
			
			pq.pop_front();
			k++;
		}
		cout<<"Goal Reached"<<endl;
		
	}

	
	bool goalTest(state p)
	{
		int f=0;
		if (p.a[0][0]==1 && p.a[0][1]==2)
		{
			if(p.a[1][0]==3 && p.a[1][1]==4 && p.a[1][2]==5)
			{
				if(p.a[2][0]==6 && p.a[2][1]==7)
				{
					f=1;
				}
			} 

		}
		if(f==1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void run_A_star_heruistic3(state src)
	{
		if(goalTest(src))
		{
			cout<<"goal reached"<<endl;
		}
		else
		{
			int f=0;
			li.push_back(src);
		
			while(!li.empty())
			{
				state p=li.front();
				li.pop_front();
				//cout<<"genarating states for"<<endl;
				//p.print();
				
				//cout<<endl;

				state *q=p.genNextState();
				for(int i=0;i<4;i++)
				{
					if(goalTest(q[i]))
					{
						f=1;
						cout<<"goal reached"<<endl;
						q[i].print();
						back_track(p,q[i]);
						break;
					}
					else
					{
						if (q[i].color==0 && eqtest(q[i],point_blank)==false)
						{
							std::list<state>::iterator it;
							int f2=0;
							for(it = li.begin(); it != li.end(); it++){
							   // std::cout<<(it)->evaluation_cost<<" ";
							    if (it->a[0][0]==q[i].a[0][0] && it->a[0][1]==q[i].a[0][1])
							    {
							    	if (it->a[1][0]==q[i].a[1][0] && it->a[1][1]==q[i].a[1][1] && it->a[1][2]==q[i].a[1][2])
							    	{
							    		if (it->a[2][0]==q[i].a[2][0] && it->a[2][1]==q[i].a[2][1])
							    		{
							    			f2=1;
							    			break;
							    		}
							    	}
							    }

							}
							if (f2==1)
							{
								
							}
							else
							{
								//q[i].print();
								li.push_back(q[i]);
								q[i].color=1;
								m[c].child=q[i];
								m[c].parent=p;	
								c++;
							}
							
						}
						
						
						
					}
				}
				if (f==1)
				{
					break;
					/* code */
				}
				li.sort();

					// cout<<"list printing"<<endl;
					// std::list<state>::iterator it;
					// for(it = li.begin(); it != li.end(); ++it){
					//     std::cout<<(it)->evaluation_cost<<" ";
					// }
					// cout<<endl;

				


			}
		}
	
	}
	

	
};
int main()
{
	state p;
		p.a[0][0]=7;
	p.a[0][1]=6;
	p.a[0][2]=0;

	p.a[1][0]=4;
	p.a[1][1]=5;
	p.a[1][2]=3;

	p.a[2][0]=-1;
	p.a[2][1]=2;
	p.a[2][2]=1;
	//p.print();
	//p.genNextState();

	a_star a;
	initial_state=p;
	//point_blank.print();
	a.run_A_star_heruistic3(p);



}

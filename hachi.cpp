/* *********************************************************************************************
A Networking Site Friend Recommendation Program Using Friends of Friends Algorithm.
For each user a node is created and for each friend request links are added for that node.
Then we find friend recommendation for a particular user.
All the user are identified by a slno.
For the sample data there are 6 users.
For each user there is a slno
A->1
B->2
C->3
D->4
E->5
F->6
Now,what this program do is find friend recommendation for a particular user
Step 1: We input that user slno
Step 2: We look that user node,see all its friends
Step 3: For all its friends we see its adjacency list and include friend in recommendation except those that are already friends with user
Step 4: We increment count for each user
Step 5: Then we display the recommendation 

*************************************************************************************************/
#include<iostream>
#include<string>
using namespace std;
#include<conio.h>
//Global variable used for assigning unique value for each user
static int no=1;
//Structure for Graph node for each user
struct GraphNode
{
int slno;
char *name;
GraphNode *nextedge;
}*a,*b,*c,*d,*e,*f,*temp;
//Structure to store the Recommendations for an User
struct Recom
{
int slno;
char *name;
int count;
};
//Class for the user
class User 
{
      int slno;
      char name[20];
      int friend_count;
      public:
           User()
           {
            slno=no;
            no++;
            friend_count=0;    
           }
           void setName(char x[])
           {
            strcpy(name,x);
           }
           int getFriendCount()
           {
             return friend_count;
           }
           char* getName()
           {
            return name;
           }
           int getSerialNo()
           {
               return slno;
           }
           void addFriend(User x)
           {    
            friend_count++;
           }
};
//Member Function to create User Node
void createGraphNode(User u,GraphNode **x)
{
 GraphNode *q=new GraphNode();
 q->slno=u.getSerialNo();
 q->name=u.getName();
 q->nextedge=NULL;
 *x=q;
}
//Member Function to add Friend Node for an User

void createFriendNode(GraphNode **x,User y)
{
  GraphNode *head=*x;
  GraphNode *temp=head;
  GraphNode *p=new GraphNode();
  p->slno=y.getSerialNo();
  p->name=y.getName();
  p->nextedge=NULL;
    while(temp->nextedge!=NULL)
    {
       temp=temp->nextedge;
    }
  temp->nextedge=p;   
  *x=head;  
}

//Member FUnction to get the User node pointer by serial no
GraphNode getPointer(int n)
{
 switch(n)
 {
  case 1: return *a;
          break;
  case 2: return *b;
          break;   
  case 3: return *c;
          break;
  case 4: return *d;
          break;
  case 5: return *e;
          break;
  case 6: return *f;
          break;                                     
 }
}
//Member Function to get the Friend Recommendation
void getFriendRecommendation(int sln)
{
 GraphNode *temp;
 Recom r[5]={0,"Temp",0};//Default values
 int exists=0;
 int i=0,j=0,k=0;
 int friends[6]={0};//Array to store all the friends serial no
 *temp=getPointer(sln);
  while(temp->nextedge!=NULL)
  {
   temp=temp->nextedge;
   friends[i]=temp->slno;   
   i++;                     
  }

  for(i=0;friends[i]>0&&friends[i]<7;i++)
  {
    *temp=getPointer(friends[i]);
     temp=temp->nextedge;
     GraphNode *temp1=temp;
     while(temp1)
     {
        exists=0;
        for(int l=0;l<5;l++)
        {
         if(temp1->slno==friends[l]) {/*Checking the already friend condition ex: if B and C are friends of A 
         and we ask recommendation of A and B and C are friends of each other than they should not come in recommendation.*/
          exists=1; 
         }
        }
        if((temp1->slno!=sln)&&(exists==0))
        {
           for(k=0;k<5;k++)
           {
              if(r[k].slno==temp1->slno)//Incrementing Count of user which is friend with multiple friends of user
              {
               r[k].count++;
               exists=1;
               break; 
              }   
           }
           if(!exists)//User friend of only a single friend
           {                      
                 r[j].slno=temp1->slno;
                 r[j].name=temp1->name;
                 r[j].count=1;
                 j++;
           }
        }
     temp1=temp1->nextedge;                         
     }

  }
  cout<<"\nFriend Slno    Mutual Friends";
  for(k=0;k<5;k++)
  {
    if(r[k].count!=0)
    {
      cout<<"\n"<<r[k].slno<<"              "<<r[k].count;
    }               
  }
}
//Main Function
int main()
{ 
    User u,v,w,x,y,z;
    //Calling Member Functions to set the name for users
    u.setName("A");
    v.setName("B");
    w.setName("C");
    x.setName("D");
    y.setName("E");
    z.setName("F");
    
    //Creating GraphNode for each user
    createGraphNode(u,&a);
    createGraphNode(v,&b);
    createGraphNode(w,&c);
    createGraphNode(x,&d);
    createGraphNode(y,&e);
    createGraphNode(z,&f);
    
    /*Calling Member Functions for adding friend based on friend request
    Our Sample Data 
    A,B,C,D,E,F are 6 users.
    A is friend with B and C.
    B with A,C,D,E
    and similarly for C,D,E and F.
    [A]->B->C
    [B]->A->C->D->E
    [C]->A->B->D->F
    [D]->B->C
    [E]->B
    [F]->C
    */
    
    u.addFriend(v);
    u.addFriend(w);
    createFriendNode(&a,v);
    createFriendNode(&a,w);
    v.addFriend(u);
    v.addFriend(w);
    v.addFriend(x);
    v.addFriend(y);
    createFriendNode(&b,u);
    createFriendNode(&b,w);
    createFriendNode(&b,x);
    createFriendNode(&b,y);
    w.addFriend(u);
    w.addFriend(v);
    w.addFriend(x);
    w.addFriend(z);
    createFriendNode(&c,u);
    createFriendNode(&c,v);
    createFriendNode(&c,x);
    createFriendNode(&c,z);
    x.addFriend(v);
    x.addFriend(w);
    createFriendNode(&d,v);
    createFriendNode(&d,w);
    y.addFriend(v);
    createFriendNode(&e,v);
    z.addFriend(w);
    createFriendNode(&f,w);

    int inp_slno; 
    cout<<"Enter the user slno for whom you want the Friend Recommendations:";
    cin>>inp_slno;
    
    getFriendRecommendation(inp_slno);
    getch();
    return 0;
}

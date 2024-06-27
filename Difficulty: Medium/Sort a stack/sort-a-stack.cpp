//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
void InsertSort(stack<int>&st,int top){
    //now in the fisrst step we will check if our current top is already greater than
    // stack element. If yes then directly push the top into the stack
    // OR also in the scenerio where there is no element in the stack so then just push
    // the top into the stack
    if(st.empty() || st.top()<=top){
        st.push(top);
        return;
    }
    int currentTop=st.top();
    st.pop();
    InsertSort(st,top);
    //if top element was smaller than the our current present element then we pushed the top and now we are
    // adding the our current earlier top element.
    st.push(currentTop);
    return;
}

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
    //First we will try to make our stack small so that we can start comparing
    // with 2 values then we will go on.
   if(s.size()==1){
       return ;
   }
   int top=s.top();
   s.pop();
   sort();
   //now at this moment our stack contains only 1 value in initial insert calll
   // and now we will pass the stack and our top element of stack at the moment
   InsertSort(s,top);
   
}
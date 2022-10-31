#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        node *curr=head, *prevfirst=NULL;
        bool firstpass=true;
        while(curr!=NULL){
            node *first=curr,*prev=NULL;
            int count=0;
            while(curr!=NULL && count<k){
                node *temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
                count++;
            }
            if(firstpass){
                head=prev;
                firstpass=false;
            }
            else{
                prevfirst->next=prev;
            }
            prevfirst=first;
        }
        return head;
    }
};


int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

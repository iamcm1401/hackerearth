#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int coe;
    int xexp;
    int yexp;
    int zexp;
    struct node *link;
};


void create_head_node(struct node *k)
{
    struct node * temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->coe = 0;
    temp->xexp = -1;
    temp->yexp = -1;
    temp->zexp = -1;
    temp->link = temp;
    k->temp;
}

void insert_end(int co , int xe , int ye, int ze , struct node *p)
{
    struct node * temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->coe = co;
    temp->xexp = xe;
    temp->yexp = ye;
    temp->zexp = ze;
    p->link = temp;
    p->coe = p->coe + 1;
    temp->link = p;
}

void create_data_node(struct node *p)
{
    int n,co,xe,ye,ze;
    printf("enter the number of terms");
    scanf("%d",&co);
    for(int i=0;i<n;i++)
    {
        printf("enter the coefficient:");
        scanf("%d",&co);
        printf("enter the x component:");
        scanf("%d",&xe);
        printf("enter the y component:");
        scanf("%d",&ye);
        printf("enter the z component:");
        scanf("%d",&ze);
        insert_end(co,xe,ye,ze,p);
    }
}



void evaluate_poly(struct node *p)
{
    int sum = 0,x,y,z;
    struct node *t;
    t = p;
    t= t-> link;
    printf("enter the value for x,y,z\n");
    scanf("%d%d%d",&x,&y,&z);
    while(t!=p)
    {
        sum = sum + (t->coe * pow(x,t->xexp) * pow(y,t->yexp)* pow(z,t->zexp));
        t = t->link;
    }
    printf("the result of the evaluation of polynomial");

    
}

void display(struct node *p)
{
    struct node *t;
    t = p;
    t = t->link;
    while(t!= p)
    {
        if(t->coe < 0)
        {
            printf("-%d x^%d y^%d z^%d",t->coe,t->xexp,t->yexp,t->zexp);
        }
        else
        {
            printf("+%d x^%d y^%d z^%d",t->coe,t->xexp,t->yexp,t->zexp);
        }
    }
}

void addition(struct node *p1,struct node *p2,struct node *p3)
{
    int co;
    struct node *A,*B;
    A=p1;
    B=p2;
    A = A->link;
    B = B->link;
    if(A->xexp == B->xexp && A->yexp == B->yexp && A->zexp == B->zexp)
    {
        co = A->coe + B->coe;
        insert_end(co,A->xexp,A->yexp,A->zexp,p3);
        A = A->link;
        B = B->link;
    }
    else if(A->xexp > B->xexp)
    {
        insert_end(A->coe,A->xexp,A->yexp,A->zexp,p3);
        A = A ->link; 
    }
    else if((A->xexp == B->xexp) && (A->yexp == B->yexp))
    {
        insert_end(A->coe,A->xexp,A->yexp,A->zexp,p3);
        A = A ->link;
    }
    else if((A->xexp == B->xexp) && (A->yexp == B->yexp) && (A->zexp == B->zexp) )
    {
        A = A->link;
    }
    else
    {
        insert_end(B->coe,B->xexp,B->yexp,B->zexp,p3);
        B = B->link;
    }

    while(A != p1)
    {
        insert_end(A->coe,A->xexp,A->yexp,A->zexp,p3);
        A = A->link;
    }
     while(B != p2)
    {
        insert_end(B->coe,B->xexp,B->yexp,B->zexp,p3);
        B = B->link;
    }
}


void main()
{
    struct node *poly1 ,*poly2, *polyadd;
    create_head_node(poly1);
    create_data_node(poly1);
    evaluate_poly(poly1);
    display(poly1);
    // polyadd = addition(poly1,poly2);
    // display(polyadd);
}
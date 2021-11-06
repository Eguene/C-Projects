#include <iostream>
#include <string.h>
using namespace std;

typedef struct 
{
    int number;
    char model[100];
    int year;
} MOTORCYCLES;

typedef struct d_ex
{
    MOTORCYCLES b;
    struct d_ex* prev, * next;

} DESC;

DESC* head = NULL; DESC* tail = NULL;

void addobj(DESC* d, MOTORCYCLES moto)
{
    DESC* ptr = new DESC;
    ptr->b = moto;
    ptr->prev = d;
    ptr->next = (d==NULL) ? NULL: d->next;
    if(d!=NULL)
    {
        d->next = ptr;
        if(d->next!=NULL)
        {
            d->next->prev = ptr;
        }
    }
    if(ptr->prev == NULL)
    {
        head = ptr;
    }
    if(ptr->next == NULL)
    {
        tail = ptr;   
    }
}

void delobj(DESC* d)
{
    if(d == NULL)
    {
        return;
    }
    DESC* dprev = d->prev;
    DESC* dnext = d->next;

    cout<<"Motorcycle "<<d->b.model<<", "<<d->b.number<<" exited the queue."<<endl;
    delete d;
    if(dprev != NULL)
    {
        dprev->next = dnext;
    }
    else
    {
        head = dnext;
    }

    if(dnext != NULL)
    {
        dnext->prev = dprev;
    }
    else
    {
        tail = dprev;
    }
}

void printqueue()
{
    DESC* h = head;

    while(h != NULL)
    {
        cout<<" "<<endl;
        cout<<"Motorcycle number: "<<h->b.number<<endl;
        cout<<"Motorcycle model: "<<h->b.model<<endl;
        cout<<"Motorcycle release year: "<<h->b.year<<endl;
        h = h->next;
    }
}

int main()
{
    MOTORCYCLES moto = {11111111, "A", 1999};
    addobj(tail, moto);

    strcpy(moto.model, "B");
    moto.number = 22222222;
    moto.year = 2001; 
    addobj(tail, moto);

    strcpy(moto.model, "C");
    moto.number = 33333333;
    moto.year = 2005; 
    addobj(tail, moto);

    printqueue();

    cout<<" "<<endl;
    
    delobj(head);

    printqueue();
    
    return 0;
}


//var4
#include <iostream>
using namespace std;

struct node
{
    int el;
    node *l, *r;
};

node *tree = NULL;

void addel(int a, node **t) //функція додавання елементу
{
    if((*t) == NULL) //якщо дерева не існує
    {
        (*t) = new node; //виділення пам'яті
        (*t)->el = a; //зв'язування a та el
        (*t)->l = (*t)->r = NULL; //очищення пам'яті для наступного елементу
        return;
    }
    if(a > (*t)->el) addel(a, &(*t)->r); //якщо елемент більше від існуючого, він створюється справа
    else addel(a, &(*t)->l); //інакше зліва
}

void print(node *t, int u) //функція виведення дерева на екран
{
    if(t == NULL) return; //якщо дерева не існує, зупинитися
    else
    {
        print(t->l, ++u); //рекурсивно відвідуємо ліву гілку
        for(int i=0; i<u; i++) cout<<"- ";
        cout<<t->el<<endl; //виводимо елемент
        u--;
    }
    print(t->r, ++u); //таким же чином робимо з правою віткою   
}

int summ(node *t) //функція для знаходження суми елементів дерева
{
    int l, r;
    if(t != NULL){
        l = (t->l != NULL) ? summ(t->l) : 0; // якщо правда - результат зліва, ні - зправа.
        r = (t->r != NULL) ? summ(t->r) : 0;
        return l + r + t->el;
    }
    return 0;
}

int main()
{
    int n; //число елементів
    int num; //елемент
    cout<<"Enter number of elements:"; //введення числа елементів
    cin>>n;
    for (int i=0; i<n; ++i)
    {
        cout<<"Enter element:"; //введення елементів
        cin>>num;                       
        addel(num, &tree); //додавання елементу в дерево               
    }
    cout << "your tree\n";
    print(tree, 0); //виведення на екран дерева
    cout << "sum of elements\n";
    cout<<summ(tree); //сума елементів
    return 0;    
}
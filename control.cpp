#include <iostream>
#include <fstream>
using namespace std;

//варіант 4. Метод Шелла - це алгоритм сортування, названий в честь Дональда Шелла. Його суть заключається у тому, що елементи перебираються з деяким кроком, після чого з кроком менше і так декілька разів.

int shellMet(int* mas, int n); //прототип функції сортування масиву

int main()
{
    int i = 0;
    int n = 11;
    int mas[n]; //створюємо масив
    for(i=0; i<n; i++)
    {
        mas[i] = rand() % 100; //заповнюємо масив випадковими значеннями
    }
    for(i=0; i<n; i++)
    {
        cout<<mas[i]<<endl;; 
    }
    cout<<"mas printed"<<endl;
    shellMet(mas, 11);

    ofstream out; //відкриваємо потік для запису
	out.open("D:\\control.txt"); //відкриваємо файл, у який буде здійснено запис
	if (out.is_open())
    for(int i=0; i<n; i++)
    {
        out << mas[i] << endl; //здійснюємо запис до файлу
    }
    out.close(); //закриваємо файл

    return 0;
}

int shellMet(int* mas, int n)
{
    int i = 0; 
    int j; 
    int d = n/2; //крок для порівняння
    int el;
    while(d>0)
    {
        for(i=0; i<n-d; i++)
        {
            j = i;
            while(j>=0 && mas[j]>mas[j+d])
            {
                el = mas[j];
                mas[j] = mas[j+d];
                mas[j+d] = el;
                j--;
            }
        }
        d = d/2; //беремо новий крок для порівняння
    }
    for(i=0; i<n; i++)
    {
        cout<<mas[i]<<endl; //виведення масиву на екран
    } 
}
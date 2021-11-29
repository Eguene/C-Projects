#include <iostream>

class Flat
{
    std::string owner;
    int square;
    int rooms;
    int floor;

public:
    Flat(std::string own, int sq, int ro, int fl)
    {
        owner = own;
        square = sq;
        rooms = ro;
        floor = fl;
    }

    Flat()
    {
        owner = "unknown";
        square = 0;
        rooms = 0;
        floor = 0;
    }

    std::string get_owner()//геттери
    {
        return owner;
    }
    int get_square()
    {
        return square;
    }
    int get_rooms()
    {
        return rooms;
    }
    int get_floor()
    {
        return floor;
    }

    void set_owner(std::string own)//сеттери
    {
        owner = own;
    }
    void set_square(int sq)
    {
        square = sq;
    }
    void set_rooms(int ro)
    {
        rooms = ro;
    }
    void set_floor(int fl)
    {
        floor = fl;
    }

    void Print()//ф-ція виводу об'єкта на екран
    {
        std::cout<<"----------"<<std::endl<<"Info:"<<std::endl<<"Owner: "<<owner<<std::endl<<square<<" m^2"<<std::endl<<rooms<<" rooms"<<std::endl<<floor<<" floor"<<std::endl;
    }
    
    void Data(std::string own, int sq, int ro, int fl)//ф-ція зміни даних об'єкта
    {
        owner = own;
        square = sq;
        rooms = ro;
        floor = fl;
    }
    void search_owner_met(std::string own)//метод для ф-ції пошуку об'єкта за хозяїном
    {
        if(owner == own)
        {
            std::cout<<"----------"<<"Specified owner found:"<<std::endl<<"----------"<<std::endl<<"Info:"<<std::endl<<"Owner: "<<owner<<std::endl<<square<<" m^2"<<std::endl<<rooms<<" rooms"<<std::endl<<floor<<" floor"<<std::endl;
        }
        else
        {
            std::cout<<"Specified owner not found"<<std::endl;
        }
    }
};

Flat f[3];

void search_owner(std::string own);//функція пошуку елементу за хазяїном
void change_data(std::string own);//функція зміни даних елементу
void delete_data(std::string own);//функція видалення елементу

int main()
{
    int i = 0;
    Flat First("a", 0, 0, 0);
    Flat Second("b", 0, 0, 0);
    First.Data("Zubenko Mihail Petrovich", 250, 3, 7);
    Second.Data("Alibaba", 40, 40, 4);
    First.Print();
    First.get_owner();
    First.set_owner("Donald Trump");
    First.Print();
    Second.Print();
    First.Data("Ivan", 30, 4, 7);
    First.Print();

    f[0] = Flat("Zubenko Mihail Petrovich", 250, 3, 7);
    f[1] = Flat("Alibaba", 40, 40, 4);
    f[2] = Flat("Ivan", 30, 4, 7);
    std::cout<<f[0].get_owner()<<std::endl;

    search_owner("Alibaba");
    change_data("Ivan");
    delete_data("Ivan");
}

void search_owner(std::string own)//функція пошуку елементу за хазяїном
{
    int i = 0;
    for(i=0; i<=2; i++)
    {
        f[i].search_owner_met(own);
    }
}

void change_data(std::string own)//функція зміни даних елементу
{
    int i = 0;
    int sq = 0;
    int ro = 0;
    int fl = 0;
    for(i=0; i<=2; i++)
    {
        f[i].search_owner_met(own);
        std::cout<<"Result number: "<<i<<std::endl;
    }
    std::cout<<"Choose an element to change: "<<std::endl;
    std::cin>>i;
    std::cout<<"You have chosen element "<<i<<std::endl;
    f[i].Print();
    std::cout<<"Enter a new owner(type 'same' if owner should remain the same): "<<std::endl;
    std::cin>>own;
    std::cout<<"Enter new square(type '0' if square should remain the same): "<<std::endl;
    std::cin>>sq;
    std::cout<<"Enter new number of rooms(type '0' if number of rooms should remain the same): "<<std::endl;
    std::cin>>ro;
    std::cout<<"Enter new floor(type '0' if floor should remain the same): "<<std::endl;
    std::cin>>fl;
    if(own != "same")
    {
        f[i].set_owner(own);
    }
    else
    {
        own = own;
    }

    if(sq != 0)
    {
        f[i].set_square(sq);
    }
    else
    {
        sq = sq;
    }

    if(ro != 0)
    {
        f[i].set_rooms(ro);
    }
    else
    {
        ro = ro;
    }

    if(fl != 0)
    {
        f[i].set_floor(fl);
    }
    else
    {
        fl = fl;
    }
    std::cout<<"New element is: "<<std::endl;
    f[i].Print();
}

void delete_data(std::string own)//функція видалення елементу
{
    int i = 0;

    for(i=0; i<=2; i++)
    {
        f[i].search_owner_met(own);
        std::cout<<"Result number: "<<i<<std::endl;
    }
    std::cout<<"Choose an element to delete: "<<std::endl;
    std::cin>>i;
    f[i] = f[i+1];
    f[i+1] = Flat("unknown", 0, 0, 0);
    for(i = 0; i<=2; i++)
    {
        f[i].Print();
    }
}
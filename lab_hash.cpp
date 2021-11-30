#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<cstdlib>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <bits/stdc++.h>


#define HASHTAB_SIZE 120
#define HASHTAB_SIZE2 240

using namespace std;
  
template <typename K, typename V>
  
class HashNode 
{
public:
    V value;
    K key;
  
    HashNode(K key, V value)
    {
        this->value = value;
        this->key = key;
    }
};
  
template <typename K, typename V>
  
class HashTable 
{
    HashNode<K, V>** arr;
    int capacity;
    int size;
    HashNode<K, V>* dummy;
  
public:
    HashTable()
    {
        capacity = 100;
        size = 0;
        arr = new HashNode<K, V>*[capacity];
  
        for (int i = 0; i < capacity; i++)
            arr[i] = NULL;
  
        dummy = new HashNode<K, V>(-1, -1);
    }

    int hashCode(K key)
    {
        return key % capacity;
    }
  
    void insertNode(K key, V value)
    {
        HashNode<K, V>* temp = new HashNode<K, V>(key, value);
  
        int hashIndex = hashCode(key);
  		 
        while (arr[hashIndex] != NULL
               && arr[hashIndex]->key != key
               && arr[hashIndex]->key != -1) 
                {
                    hashIndex = hashIndex*hashIndex;
                    hashIndex %= capacity;
                }
        int selector = 0;
  		while ((arr[hashIndex] != NULL)
  				&& (arr[hashIndex]->key != -1))
                    {
  					    if (arr[hashIndex]->key == key)
  					    selector = 1;
  				    }

        if (selector == 0)
        {
        	
        
        if (arr[hashIndex] == NULL
            || arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = temp;
    }
    else
    {
    	for (int i = 0; i < 100; i++)
        {
    		hashIndex = (hashCode(key) + 1) % capacity;
    		if (arr[hashIndex] == NULL)
            {
    		    arr[hashIndex] = temp;
    			break;
    		}
    	}
    }
    }
  
    V deleteNode(int key)
    {
        int hashIndex = hashCode(key);
  
        while (arr[hashIndex] != NULL) 
        {
            if (arr[hashIndex]->key == key) 
            {
                HashNode<K, V>* temp = arr[hashIndex];
  
                arr[hashIndex] = dummy;
  
                size--;
                return temp->value;
            }
            hashIndex++;
            hashIndex %= capacity;
        }
  
        return NULL;
    }
  
    V get(int key)
    {
        int hashIndex = hashCode(key);
        int counter = 0;
   
        while (arr[hashIndex] != NULL) {
  
            if (counter++ > capacity)
                return NULL;
   
            if (arr[hashIndex]->key == key)
                return arr[hashIndex]->value;
            hashIndex++;
            hashIndex %= capacity;
        }
   
    return NULL;
    }
    
    int sizeofTable()
    {
        return size;
    }
  
    bool isEmpty()
    {
    	cout << "The table is empty." << endl;
        return size == 0;
    }
  
    void print()
    {
        for (int i = 0; i < capacity; i++) {
            if (arr[i] != NULL && arr[i]->key != -1)
                cout << "Key =  " << arr[i]->key
                     << "  Value = "
                     << arr[i]->value << endl;
        }
    }
};

int main()
{
    HashTable<int, int>* h = new HashTable<int, int>;
    h->insertNode(1, 123);
    h->insertNode(2, 23);
    h->insertNode(3, 34);
    h->insertNode(4, 8655);
    h->insertNode(5, 9);
    h->insertNode(6, 732);
    h->insertNode(7, 554);
    h->insertNode(8, 11);
    h->insertNode(9, 3);
    h->insertNode(10, 202);
    h->print();
    
    int K, V;
    int c; 
    while(1) 
    {
        cout << "       " << endl;
        cout<<"1.Insert to the table"<<endl;
        cout<<"2.Find an element using a key"<<endl;
        cout<<"3.Delete an element using a key" << endl;
        cout<<"4.Print the table" << endl;
        cout<<"5.Print the table size" << endl;
        cout<<"6.Exit the program"<<endl;
        cout << "       " << endl;
        cout<<"Enter the comand: ";
        cout << "       " << endl;
        cin>>c;
        switch(c) 
        {
            case 1:
            cout<<"Enter the value: ";
            cin>>V;
            cout<<"Enter the key: ";
            cin>>K;
            h->insertNode(K, V);
         break;
         case 2:
            cout<<"Enter the key to find an element: ";
            cin>>K;
            if(h->get(K) == -1) 
            {
               cout<<"No element with this key exists. "<<K<<endl;
               continue;
            } 
            else 
            {
               cout<<"Element with the key number "<<K<<" : ";
               cout<<h->get(K)<<endl;
            }
         break;
         case 3:
            cout<<"Enter the key you want to delete: ";
            cin>>K;
            h->deleteNode(K);
         break;
         case 4:
         	h->print();
         	break;
        case 5:
         	cout << "Table size: " << h->sizeofTable() << endl;
         	break;
         case 6:
            exit(1);
         default:
            cout<<"\nChoose right command\n";
        }
    }
   return 0;
}
  

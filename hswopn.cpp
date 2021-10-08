#include<bits/stdc++.h>
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

template<typename K, typename V>
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

template class HashNode<int, int>;
//template class HashNode<int, string>;
//template class HashNode<string, string>;

template<typename K, typename V>
class HashMap

{


    std::vector<HashNode<K, V>*> arr;

    int capacity;



    int size;



    HashNode<K, V>* dummy;
public:

    HashMap()

    {

        capacity = 20;

        size = 0;
        for (int f = 0; f < capacity; f++)
        {
            arr.push_back(new HashNode<K, V>(0,0));
        }
      //  arr = new HashNode<K, V>*[capacity];

      /*  for (int i = 0; i < capacity; i++)

            arr[i] = NULL;
            */
        dummy = new HashNode<K, V>(-1, -1);

    }

    int hashCode(K key)

    {

        return key % capacity;

    }

    void insertNode(K key, V value)
    {
        arr.push_back(new HashNode<K, V>(key, value));
        size++;
       /* HashNode<K, V>* temp = new HashNode<K, V>(key, value);

        int hashIndex = hashCode(key);

        while (arr[hashIndex] != NULL && arr[hashIndex]->key != key

            && arr[hashIndex]->key != -1)

        {

            hashIndex++;

            hashIndex %= capacity;

        }

        if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1)

            size++;

        arr[hashIndex] = temp;*/

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

        while (arr[hashIndex] != NULL)
        {
            int counter = 0;
            if (counter++ > capacity)

                return NULL;

            if (arr[hashIndex]->key == key)
                return arr[hashIndex]->value;
            hashIndex++;
            hashIndex %= capacity;
        }

        return NULL;

    }

    int sizeofMap()
    {

        return size;

    }

    bool isEmpty()
    {

        return size == 0;

    }


    void display() {

      /*  for (HashNode<int,int>* i : arr)
        {
            std::copy(i.begin(), i.end(), std::ostream_iterator<int>(std::cout, "\n"), [](HashNode<int, int>* x) { return x->key; });
        }*/

        //auto p = *arr;
        
        
            std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, "\n"), [](HashNode<int, int>* x) { return x->value; });
        
        //for (HashNode<int, int>* O_mas: arr)
        //{
        //    for (HashNode<int, int> j : O_mas)
        //    {
        //        std::cout << j.key;//int
        //        std::cout << j.value;//int

        //       //std::copy(j->key, j->key, std::ostream_iterator<int>(std::cout, " "));
        //       //std::copy(j->value.begin(), j->value.end(), std::ostream_iterator<int>(std::cout, " "));
        //    }
        //}
    }
    /*void display()
    {

        for (int i = 0; i < capacity; i++)
        {

            if (arr[i] != NULL && arr[i]->key != -1)
                std::cout << "key = " << arr[i]->key
                << "  value = " << arr[i]->value << std::endl;

        }

    }*/
        
};

int main()
{
    HashMap<int, int>* h = new HashMap<int, int>;
    typedef std::pair<int, int> HashNode;
    HashNode p1(1, 1);
    HashNode p2(2, 2);
    HashNode p3(2, 3);
    h->insertNode(p1.first, p1.second);
    h->insertNode(p2.first, p2.second);
    h->insertNode(p3.first, p3.second);
    h->display();
    
    std::cout << h->sizeofMap() << std::endl;
    std::cout << h->deleteNode(2) << std::endl;
    std::cout << h->sizeofMap() << std::endl;
    std::cout << h->isEmpty() << std::endl;
    std::cout << h->get(2);

    return 0;
}
//
//  main.cpp
//  DSHomework5
//
//  Created by apple on 2016/10/25.
//  Copyright © 2016年 YangZhiZhuang. All rights reserved.
//

#include <iostream>
template<class T>
class ArrayQueue
{
private:
    int maxSize;
    int front;
    int rear;
    int *queue;
    int tag;
public:
    ArrayQueue(int size)
    {
        maxSize=size;
        queue=new T[maxSize];
        tag=0;
        front=0;
        rear=0;
    }
    ArrayQueue(int num,T *item)
    {
        maxSize=num;
        queue=new T[maxSize];
        tag=0;
        front=0;
        rear=0;
        for(int i=0;i<num;i++)
        {
            EnQueue(*item);
            item++;
        }
    }
    ~ArrayQueue()
    {
        delete [] queue;
    }
    void Clear()
    {
        tag=0;
        front=0;
        rear=0;
    }
    bool EnQueue(const T item)
    {
        if(tag==1&&rear==front)
        {
            std::cout<<"Full Queue"<<std::endl;
            return false;
        }
        if(tag==0)
            tag=1;
        queue[rear]=item;
        rear=(rear+1)%maxSize;
        return true;
    }
    bool DeQueue(T &item)
    {
        if(tag==0)
        {
            std::cout<<"No Item"<<std::endl;
            return false;
        }
        item=queue[front];
        if((rear-front)==1||(front-rear)==maxSize-1)
        {
            tag=0;
        }
        front=(front+1)%maxSize;
        return true;
            
    }
    bool GetFront(T &item)
    {
        if(tag==0)
        {
            std::cout<<"No Item"<<std::endl;
            return false;
        }
        item=queue[front];
        return true;
    }
    bool IsEmpty()
    {
        if(tag==0)
            return true;
        return false;
    }
};
int main(int argc, const char * argv[])
{
    int value[3]={1,2,3};
    ArrayQueue<int> aq(3,value);
    aq.EnQueue(4);
    int temp;
    while(!aq.IsEmpty())
    {
        aq.DeQueue(temp);
        std::cout<<temp<<std::endl;
    }
    aq.DeQueue(temp);
    aq.Clear();
    
    aq.EnQueue(5);
    aq.EnQueue(6);
    aq.EnQueue(7);
    while(!aq.IsEmpty())
    {
        aq.DeQueue(temp);
        std::cout<<temp<<std::endl;
    }
    return 0;
}

#ifndef LIST_H
#define LIST_H

template<typename T>

class List
{
private:
    struct node;
    node* head;
    node* tail;
    int count;
public:
    List(){
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    List(List& list){
        head = nullptr;
        tail = nullptr;
        count = 0;

        node* tmp =list.head;

        while(tmp!=0)
        {
            addTail(tmp->value);
            tmp = tmp->next;
        }
    }
    ~List(){
        delAll();
    }

    int getCount()
    {
        return count;
    }
    node* getNode(int pos)
    {
        node* tmp =head;
        for(int i = 0; i< pos; i++)
        {
            tmp = tmp->next;
        }
        return tmp;
    }
    void delAll()
    {
        while(count!=0)
            del(1);
    }
    void del(int pos)
    {
        node * Del = head;

        for(int i = 1; i< pos;i++)
        {
           Del = Del->next;
        }

        node * PrevDel = Del->prev;
        node * AfterDel = Del->next;

        if(PrevDel != 0 && count != 1)
           PrevDel->next = AfterDel;
         if(AfterDel != 0 && count != 1)
           AfterDel->prev = PrevDel;

        if(pos == 1)
            head = AfterDel;
        if(pos == count)
            tail = PrevDel;

        delete Del;

        count--;
    }

    void insert(int pos, T data)
    {
        if(pos == count + 1)
        {
           addTail(data);
           return;
        }
        else if(pos == 1)
        {
           addHead(data);
           return;
        }

        node * Ins = head;

        for(int i = 1; i< pos;i++)
        {
           Ins = Ins->next;
        }

        node * PrevIns = Ins->prev;
        node * temp = new node;

        temp->value = data;

        if(PrevIns != 0 && count != 1)
           PrevIns->next = temp;

        temp->next = Ins;
        temp->prev = PrevIns;
        Ins->prev = temp;

        count++;
    }
    void addTail(T data)
    {
        node * temp = new node;
        temp->next = 0;
        temp->data = data;

        temp->prev = tail;

        if(tail != 0)
           tail->next = temp;

        if(count == 0)
           head = tail = temp;
        else
            tail = temp;

        count++;
    }
    void addHead(T data)
    {
        node * temp = new node;

        temp->prev = 0;
        temp->data = data;
        temp->next = head;

        if(head != 0)
           head->prev = temp;

        if(count == 0)
           head = tail = temp;
        else
           head = temp;

        count++;
    }
};

template<typename T>
struct List<T>::node
{
    T value;
    node *prev;
    node *next;
};



#endif // LIST_H

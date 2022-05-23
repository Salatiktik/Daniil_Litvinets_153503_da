#ifndef SHARED_PTR_H
#define SHARED_PTR_H

template <typename T>

class Shared_ptr
{
public:
    Shared_ptr ()
    {
        Ptr = nullptr;
        count = nullptr;
    }

    Shared_ptr(T* ptr)
    {
        Ptr = ptr;
        count = new unsigned(1);

    };
    Shared_ptr (Shared_ptr<T>& sh_pt)
    {

        Ptr = sh_pt.Ptr;
        count = sh_pt.count;
        (*count)++;
    };

    Shared_ptr<T>& operator*()
    {
        return *Ptr;
    };


    Shared_ptr<T>& operator= (Shared_ptr<T>& sh_pt)
    {
        if(this!=&sh_pt)
        {
            clear();

            Ptr = sh_pt.Ptr;
            count = sh_pt.count;
            (*count)++;
        }
        return *this;
    };

    T* operator->() const noexcept;

    T* get()
    {
        return Ptr;
    }

    unsigned* get_count()
    {
        return count;
    }

    void clear()
    {
        if (*count > 0)
            --(*count);
        if (*count == 0)
            delete Ptr;
    }

    bool is_unique()
    {
        return (*count==1);
    }

    ~Shared_ptr()
    {
        clear();
    };

    void set_Ptr(T* a)
    {
        Ptr = a;
    }


    void set_count(unsigned* a)
    {
        count = a;
    }

private:
    T* Ptr;
    unsigned* count;
};

#endif // SHARED_PTR_H

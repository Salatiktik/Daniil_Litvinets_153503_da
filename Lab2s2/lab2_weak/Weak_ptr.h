#ifndef WEAK_PTR_H
#define WEAK_PTR_H
#include <Shared_ptr.h>

template <typename T>

class Weak_ptr
{
public:
    Weak_ptr ()
    {
        Ptr = nullptr;
        count_w = nullptr;
    }

    Weak_ptr (Weak_ptr<T>& sh_pt)
    {
        Ptr = sh_pt.Ptr;
        count_w = sh_pt.count_w;
        count_s = sh_pt.count_s;
        (*count_w)++;
    };

    Weak_ptr (Shared_ptr<T>& sh_pt)
    {
        Ptr = sh_pt.get();
        count_s = sh_pt.get_count();
        count_w = new unsigned(1);
    };


    Weak_ptr<T>& operator= (Weak_ptr<T>& sh_pt)
    {
        if(this!=&sh_pt)
        {
            clear();

            Ptr = sh_pt.Ptr;
            count_w = sh_pt.get_wcount();
            count_s = sh_pt.get_scount();
            ++(*count_w);
            ++(*count_s);
        }
        return *this;
    };

    T* operator->() const noexcept;

    unsigned* get_scount()
    {
        return count_s;
    }

    unsigned* get_wcount()
    {
        return count_w;
    }

    void clear()
    {
        if (*count_w > 0)
            --(*count_w);
        if (*count_w == 0)
            delete Ptr;
    }

    Shared_ptr<T>& lock()
    {
        Shared_ptr<T> ptr (Ptr);
        ptr.set_count(count_s);
        (*count_s)++;
        return ptr;
    }

    ~Weak_ptr()
    {
        clear();
    };

private:
    T* Ptr;
    unsigned* count_w;
    unsigned* count_s;
};

#endif // WEAK_PTR_H

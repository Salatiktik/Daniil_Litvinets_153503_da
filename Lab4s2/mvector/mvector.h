#ifndef MVECTOR_H
#define MVECTOR_H

#include "mvector_global.h"

template<typename T>
class mvector {
public:

    class iterator {
    public:
        iterator(T* a)
        {
            ptr = a;
        }
        iterator operator++()
        {
            this->ptr++;
        }

        iterator operator--()
        {
            this->ptr--;
        }

        iterator operator*()
        {
            return *this->ptr;
        }

        bool operator ==(iterator a)
        {
            return a.ptr == this->ptr;
        }

        T* operator =(T* a)
        {
            this->ptr = a;
        }

        T* ptr = nullptr;
    };

    class reversed_iterator
    {
    public:
        reversed_iterator operator++()
        {
            this->ptr--;
            return this;
        }

        reversed_iterator operator--()
        {
            this->ptr++;
        }

        reversed_iterator operator*()
        {
            return *this->ptr;
        }

        bool operator ==(iterator a)
        {
            return a.ptr == this->ptr;
        }

        T* operator =(T* a)
        {
            this->ptr = a;
        }

        T* ptr = nullptr;
    };

    mvector() {
        mass = new T[1];
        free = 1;
    }
    mvector(size_t num, T val) : count(num), free(num)
    {
        mass = new T[count + free];
        for (size_t i = 0; i < count; i++)
        {
            mass[i] = val;
        }
    }
    mvector(const mvector<T>& a) : count(a.count), free(a.free), mass(new T[free + count])
    {
        for (size_t i = 0; i != count; ++i)
            mass[i] = a.mass[i];
    }
    ~mvector()
    {
        delete[] mass;
        count = 0;
        free = 0;
        mass = nullptr;
    }

    void assign(mvector<T> a)
    {
        delete[] mass;
        mass = new T[a.size()];
        for (int i = 0; i < a.size(); i++)
        {
            mass[i] = a[i];
        }
        delete a;
    }

    bool empty()
    {
        return count == 0;
    }

    T* begin()
    {
        return &mass[0];

    }

    const iterator cbegin()
    {
        const iterator it = &mass[0];
        return it;
    }

    T* end()
    {
        return &mass[count - 1];
    }

    const iterator cend()
    {
        const iterator it = &mass[count - 1];
        return it;
    }

    reversed_iterator rbegin()
    {
        reversed_iterator it = &mass[count - 1];
        return it;
    }

    const reversed_iterator crbegin()
    {
        const reversed_iterator it = &mass[count - 1];
        return it;
    }

    reversed_iterator rend()
    {
        reversed_iterator it = &mass[0];
        return it;
    }

    const reversed_iterator crend()
    {
        const reversed_iterator it = &mass[0];
        return it;
    }

    void resize(size_t new_size, T a = T())
    {
        free = 2 * new_size;
        T* mass_t = new T[free + new_size];
        for (size_t i = 0; i != std::min(count, new_size); ++i)
            mass_t[i] = mass[i];
        for (size_t i = std::min(count, new_size); i != new_size; ++i)
            mass_t[i] = a;

        delete[] mass;
        count = new_size;
        mass = mass_t;
    }

    void reserve(size_t newSize)
    {
        T* mass_t = new T[newSize];
        for (int i = 0; i < newSize && i < count; i++)
        {
            mass_t[i] = mass[i];
        }
        if (newSize > count)
        {
            free = newSize - count;
            delete[] mass;
            mass = mass_t;
        }
        else
        {
            delete[] mass_t;
        }

    }

    size_t size()
    {
        return count;
    }

    void push_back(T val)
    {
        if (free == 0)
        {
            reserve(count + 1);
            --count;
        }

        mass[count] = val;
        count++;
    }

    void pop_back()
    {
        if (count > 0)
            --count;
    }

    void erase(iterator position)
    {
        for (T* i = position; i != end(); ++i)
            *i = *(i + 1);
        --count;
        return position;
    }

    void erase(iterator first, iterator last)
    {
        size_t beg = first - begin();
        size_t end = last - begin();
        size_t new_size = count - end + beg;
        size_t new_free = new_size;

        T* mass_t = new T[new_free + new_size];

        for (size_t i = 0; i != beg; ++i)
            mass_t[i] = mass[i];

        for (size_t i = beg, j = end; j != count; ++i, ++j)
            mass_t[i] = mass[j];

        delete[] mass;

        count = new_size;
        free = new_free;
        mass = mass_t;
        return begin() + beg;
    }

    void insert(iterator position, const T a)
    {
        size_t tmp = position - begin();
        if (free < 1)
            resize(count + 1);
        else
            ++count;
        position = begin() + tmp;
        for (iterator i = end() - 1; i != position; --i)
            *i = *(i - 1);
        *position = a;
        return position;
    }

    void insert(iterator position, size_t n, const T a)
    {
        size_t tmp = position - begin();
        if (free < n)
            resize(count + n);
        else
            count += n;
        position = begin() + tmp;
        for (T* i = end() - 1; i != position + n - 1; --i)
            *i = *(i - n);
        for (T* i = position; i != position + n; ++i)
            *i = a;
    }

    void insert(iterator position, T* first, T* last)
    {
        size_t tmp = position - begin();
        size_t n = elm_count(first, last);
        if (free < n)
            resize(count + n);
        else
            count += n;
        position = begin() + tmp;
        for (T* i = end() - 1; i != position + n - 1; --i)
            *i = *(i - n);
        for (T* i = position; i != position + n && first != last; ++i)
            *i = *first++;
    }

    void emplace(iterator position, T a)
    {
        insert(position, a);
    }

    void emplace(iterator position, size_t n, const T a)
    {
        insert(position, n, a);
    }

    void emplace(iterator position, T* first, T* last)
    {
        insert(position, first, last);
    }

    void emplace_back(T val)
    {
        push_back(val);
    }

    T& front()
    {
        return at(0);
    }

    T& back()
    {
        return at(count);
    }

    T& at(size_t i)
    {
        if (i - 1 < count)
            return &mass[i - 1];
    }

    T* data()
    {
        return mass;
    }

    void clear()
    {
        delete[] mass;
        count = 0;
        free = 0;
        mass = nullptr;
    }

    size_t capacity()
    {
        return free + count;
    }

    size_t max_size()
    {
        return (pow(2, sizeof(size_t) * 8) - 1) / sizeof(T);
    }

    void swap(mvector<T> a, mvector<T> b)
    {
        T* tmp = a.mass;
        a.mass = b.mass;
        b.mass = tmp;

        a.count ^= b.count ^= a.count ^= b.count;
        a.free ^= b.free ^= a.free ^= b.free;
    }

    bool operator == (mvector<T>& a)
    {
        if (a.size() != this->size())
            return 0;

        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != mass[i])
                return 0;
        }
        return 1;
    }

    bool operator != (mvector<T>& a)
    {
        if (a.size() != this->size())
            return 1;

        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != mass[i])
                return 1;
        }
        return 0;
    }


    T& operator[] (size_t n)
    {
        return mass[n];
    }

    mvector<T>& operator= (mvector<T> a)
    {
        if (this != &a)
            swap(*this, a);
        return *this;
    }

private:
    size_t elm_count(T* beg, T* end)
    {
        T* tmp = beg;
        size_t res = 0;
        while (tmp != end)
        {
            ++res;
            ++tmp;
        }
        return res;
    }

    T* mass = nullptr;
    size_t count = 0;
    size_t free = 0;
};

template <class T1, class T2>
struct mpair
{
    T1 first;
    T2 second;
    mpair() {};

    mpair(mpair<T1, T2>& right)
    {
        first = right.first;
        second = right.second;
    };

    mpair(T1& Val1, T2& Val2)
    {
        first = Val1;
        second = Val2;
    }

    mpair& operator=(mpair p)
    {
        this->first = p.first;
        this->second = p.second;
        return *this;
    };

    bool operator <(mpair& p)
    {
        if (p.first > first)
            return 1;
        else
            if (first > p.first)
                return 0;
            else
                if (p.second > second)
                    return 1;
                else
                    return 0;
    }

    bool operator == (mpair& p)
    {
        return(p.first == this->first && p.second == this->second);
    }
};


#endif // MVECTOR_H

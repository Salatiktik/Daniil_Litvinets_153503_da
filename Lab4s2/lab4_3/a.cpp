#include <iostream>
#include <stdexcept>
#include <utility>
#include <iterator>
#include <cstddef>
using std::rel_ops::operator!=;
using std::rel_ops::operator>;
using std::rel_ops::operator<=;
using std::rel_ops::operator>=;

template <typename T>
class mvector
{
public:
    typedef T value_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* T*;
    typedef const T* const_iterator;
    typedef ptrdiff_t difference_type;
    typedef std::reverse_iterator<T*> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    mvector();
    explicit mvector( size_t, const T& val = T() );
    mvector( const mvector<T>& );
    template<typename Iterator>
    mvector( Iterator, Iterator );
    ~mvector();
    size_t size() const;
    size_t capacity() const;
    void resize( size_t, T = T() );
    template<typename Iterator>
    void assign( Iterator first, Iterator last );
    void assign (size_t n, const T& u );
    void push_back( const T& );
    void pop_back();
    T* erase( T* );
    T* erase( T*, T* );
    T* insert( T*, const T& );
    void insert( T*, size_t, const T& );
    template<typename Iterator>
    void insert( T*, T*, T* );
    void clear();
    void swap( mvector<T>& );
    T& front();
    T& back();
    T& at( size_t );
    const T& at( size_t ) const;
    bool empty() const;
    const mvector& operator= ( const mvector& );
    const T& operator[] ( size_t ) const;
    T& operator[] ( size_t );
    T* begin();
    const_iterator begin() const;
    T* end();
    const_iterator end() const;
    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend();
    const_reverse_iterator rend() const;
private:
    template <class Iterator>
    size_t _calc_size( Iterator, Iterator );
private:
    size_t _size;
    size_t _capacity;
    T *mass;
};

template <typename T>
mvector<T>::mvector():
_size( 0 ), _capacity( 2*_size ), mass( nullptr )
{
}

template <typename T>
mvector<T>::mvector( size_t num, const T& val ):
_size( num ), _capacity( 2*_size ), mass( new T[_capacity] )
{
    for ( size_t i = 0; i != _size; ++i )
        mass[i] = val;
}

template <typename T>
mvector<T>::mvector( const mvector<T>& c ):
_size( c._size ), _capacity( c._capacity ), mass( new T[_capacity] )
{
    for ( size_t i = 0; i != _size; ++i )
        mass[i] = c.mass[i];
}

template <typename T>
template<typename Iterator>
mvector<T>::mvector( Iterator start, Iterator end ):
_size( _calc_size( start, end ) ), _capacity( 2*_size ), mass( new T[_capacity] )
{
    for ( size_t i = 0; i != _size && start != end; ++i )
        mass[i] = *start++;
}

template <typename T>
mvector<T>::~mvector()
{
    delete [] mass;
    mass = nullptr;
    _size = 0;
    _capacity = 0;
}

template <typename T>
typename mvector<T>::size_t mvector<T>::size() const
{
    return _size;
}

template <typename T>
typename mvector<T>::size_t mvector<T>::capacity() const
{
    return _capacity;
}

template <typename T>
void mvector<T>::resize( size_t _new_size, T c )
{
    _capacity = 2 * _new_size;
    T *_newmass = new T[_capacity];
    for ( size_t i = 0; i != std::min( _size, _new_size ); ++i )
        _newmass[i] = mass[i];
    for ( size_t i = std::min( _size, _new_size ); i != _new_size; ++i )
        _newmass[i] = c;

    delete [] mass;
    _size = _new_size;
    mass = _newmass;
}

template <typename T>
template<typename Iterator>
void mvector<T>::assign( Iterator first, Iterator last )
{
    mvector<T>( first, last ).swap( *this );
}

template <typename T>
void mvector<T>::assign( size_t n, const T& u )
{
    mvector<T>( n, u ).swap( *this );
}

template <typename T>
void mvector<T>::push_back( const T& val )
{
    if ( _size == _capacity )
    {
        resize( _size + 1 );
        --_size;
    }

    mass[_size++] = val;
}

template <typename T>
void mvector<T>::pop_back()
{
    if ( _size > 0 )
        --_size;
}

template <typename T>
typename mvector<T>::T* mvector<T>::erase( T* position )
{
    for ( T* i = position; i != end(); ++i )
        *i = *( i + 1 );
    --_size;
    return position;
}

template <typename T>
typename mvector<T>::T* mvector<T>::erase( T* first, T* last )
{
    size_t beg = first - begin();
    size_t end = last - begin();
    size_t _new_size = _size - end + beg;
    size_t _new_capacity = 2 * _new_size;

    T *_newmass = new T[_new_capacity];

    for ( size_t i = 0; i != beg; ++i )
        _newmass[i] = mass[i];

    for ( size_t i = beg, j = end; j != _size; ++i, ++j )
        _newmass[i] = mass[j];

    delete [] mass;

    _size = _new_size;
    _capacity = _new_capacity;
    mass = _newmass;
    return begin() + beg;
}

template <typename T>
typename mvector<T>::T* mvector<T>::insert( T* position, const T& x )
{
    size_t tmp = position - begin();
    if ( _size + 1 > _capacity )
        resize( _size + 1 );
    else
        ++_size;
    position = begin() + tmp;
    for ( T* i = end() - 1; i != position; --i )
        *i = *( i - 1 );
    *position = x;
    return position;
}

template <typename T>
void mvector<T>::insert( T* position, size_t n, const T& x )
{
    size_t tmp = position - begin();
    if ( _size + n > _capacity )
        resize( _size + n );
    else
        _size += n;
    position = begin() + tmp;
    for ( T* i = end() - 1; i != position + n - 1; --i )
        *i = *( i - n );
    for ( T* i = position; i != position + n; ++i )
        *i = x;
}

template <typename T>
template <class Iterator>
void mvector<T>::insert( T* position, T* first, T* last )
{
    size_t tmp = position - begin();
    size_t n = _calc_size( first, last );
    if ( _size + n > _capacity )
        resize( _size + n );
    else
        _size += n;
    position = begin() + tmp;
    for ( T* i = end() - 1; i != position + n - 1; --i )
        *i = *( i - n );
    for ( T* i = position; i != position + n && first != last; ++i )
        *i = *first++;
}
//asd
template <typename T>
void mvector<T>::clear()
{
    delete [] mass;
    mass = nullptr;
    _size = 0;
    _capacity = 0;
}

template <typename T>
void mvector<T>::swap( mvector<T>& c )
{
    if ( this != &c )
    {
        std::swap( _size, c._size );
        std::swap( _capacity, c._capacity );
        std::swap( mass, c.mass );
    }
}

template <typename T>
T& mvector<T>::at( size_t index )
{
    if ( index >= _size )
        throw std::out_of_range( "Expression: vector subscript out of range." );
    return mass[index];
}

template <typename T>
const T& mvector<T>::at( size_t index ) const
{
    if ( index >= _size )
        throw std::out_of_range( "Expression: vector subscript out of range." );
    return mass[index];
}

template <typename T>
T& mvector<T>::front()
{
    return at( 0 );
}

template <typename T>
T& mvector<T>::back()
{
    return at( _size - 1 );
}

template <typename T>
bool mvector<T>::empty() const
{
    return _size == 0;
}

template <typename T>
const mvector<T>& mvector<T>::operator= ( const mvector<T>& c )
{
    if ( this != &c )
        mvector<T>( c ).swap( *this );
    return *this;
}

template <typename T>
const T& mvector<T>::operator[] ( size_t n ) const
{
    return mass[n];
}

template <typename T>
T& mvector<T>::operator[] ( size_t n )
{
    return mass[n];
}

template <typename T>
bool operator== ( const mvector<T>& c1, const mvector<T>& c2 )
{
    if (c1.size() != c2.size())
        return false;
    else
    {
        for ( int i = 0; i != c1.size(); ++i )
            if ( c1[i] != c2[i] )
                return false;
    }
    return true;
}

template <typename T>
bool operator< ( const mvector<T>& c1, const mvector<T>& c2 )
{
    if (c1.size() != c2.size())
        return c1.size() < c2.size();
    else
    {
        for ( int i = 0; i != c1.size(); ++i )
            if ( c1[i] != c2[i] )
                return c1[i] < c2[i];
    }
    return false;
}

template <typename T>
typename mvector<T>::T* mvector<T>::begin()
{
    return mass;
}

template <typename T>
typename mvector<T>::const_iterator mvector<T>::begin() const
{
    return mass;
}

template <typename T>
typename mvector<T>::T* mvector<T>::end()
{
    return mass + _size;
}

template <typename T>
typename mvector<T>::const_iterator mvector<T>::end() const
{
    return mass + _size;
}

template <typename T>
typename mvector<T>::reverse_iterator mvector<T>::rbegin()
{
    return reverse_iterator( end() );
}

template <typename T>
typename mvector<T>::const_reverse_iterator mvector<T>::rbegin() const
{
    return const_reverse_iterator( end() );
}

template <typename T>
typename mvector<T>::reverse_iterator mvector<T>::rend()
{
    return reverse_iterator( begin() );
}

template <typename T>
typename mvector<T>::const_reverse_iterator mvector<T>::rend() const
{
    return const_reverse_iterator( begin() );
}

template <typename T>
template <class Iterator>
typename mvector<T>::size_t mvector<T>::_calc_size( Iterator beg, Iterator end )
{
    Iterator tmp = beg;
    size_t res = 0;
    while ( tmp != end )
    {
        ++res;
        ++tmp;
    }
    return res;
}

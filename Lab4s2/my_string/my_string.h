#ifndef MY_STRING_H
#define MY_STRING_H

#include "my_string_global.h"

class mstring
{
    char* mstr = nullptr;
    const char* errors[134] {"Operation not permitted", "No such file or directory", "No such process", "Interrupted system call", "Input/output error", "No such device or address", "Argument list too long", "Exec format error", "Bad file descriptor", "No child processes", "Resource temporarily unavailable", "Resource temporarily unavailable", "Cannot allocate memory", "Permission denied", "Bad address", "Block device required", "Device or resource busy", "File exists", "Invalid cross-device link", "No such device", "Not a directory", "Is a directory", "Invalid argument", "Too many open files in system", "Too many open files", "Inappropriate ioctl for device", "Text file busy", "File too large", "No space left on device", "Illegal seek", "Read-only file system", "Too many links", "Broken pipe", "Numerical argument out of domain", "Numerical result out of range", "Resource deadlock avoided", "Resource deadlock avoided", "File name too long", "No locks available", "Function not implemented", "Directory not empty", "Too many levels of symbolic links", "No message of desired type", "Identifier removed", "Channel number out of range", "Level 2 not synchronized", "Level 3 halted", "Level 3 reset", "Link number out of range", "Protocol driver not attached", "No CSI structure available", "Level 2 halted", "Invalid exchange", "Invalid request descriptor", "Exchange full", "No anode", "Invalid request code", "Invalid slot", "Bad font file format", "Device not a stream", "No data available", "Timer expired", "Out of streams resources", "Machine is not on the network", "Package not installed", "Object is remote", "Link has been severed", "Advertise error", "Srmount error", "Communication error on send", "Protocol error", "Multihop attempted", "RFS specific error", "Bad message", "Value too large for defined data type", "Name not unique on network", "File descriptor in bad state", "Remote address changed", "Can not access a needed shared library", "Accessing a corrupted shared library", ".lib section in a.out corrupted", "Attempting to link in too many shared libraries", "Cannot exec a shared library directly", "Invalid or incomplete multibyte or wide character", "Interrupted system call should be restarted", "Streams pipe error", "Too many users", "Socket operation on non-socket", "Destination address required", "Message too long", "Protocol wrong type for socket", "Protocol not available", "Protocol not supported", "Socket type not supported", "Operation not supported", "Operation not supported", "Protocol family not supported", "Address family not supported by protocol", "Address already in use", "Cannot assign requested address", "Network is down", "Network is unreachable", "Network dropped connection on reset", "Software caused connection abort", "Connection reset by peer", "No buffer space available", "Transport endpoint is already connected", "Transport endpoint is not connected", "Cannot send after transport endpoint shutdown", "Too many references: cannot splice", "Connection timed out", "Connection refused", "Host is down", "No route to host", "Operation already in progress", "Operation now in progress", "Stale file handle", "Structure needs cleaning", "Not a XENIX named type file", "No XENIX semaphores available", "Is a named type file", "Remote I/O error", "Disk quota exceeded", "No medium found", "Wrong medium type", "Operation canceled", "Required key not available", "Key has expired", "Key has been revoked", "Key was rejected by service", "Owner died", "State not recoverable", "Operation not possible due to RF-kill", "Memory page has hardware error"};

public:
    char *strerror(int errnum) {
        char* strerror_buf;
        if (0 <= errnum && errnum < 134 && sys_errlist[errnum])
            strcpy(strerror_buf, sys_errlist[errnum]);
        else
            sprintf(strerror_buf, "Unknown error %d", errnum);
        return strerror_buf;
    }

    static std::string toStdString(char* a)
    {
        return std::string(a);
    }
    std::string& toCsStdString()
    {
        std::string* a = new string(this->mstr);
        return *a;
    }

    mstring(){};

    mstring(char* s1)
    {
        int count = 0;
        while(s1[count])count++;
        delete[] mstr;
        mstr = new char[count];
        for(size_t i = 0; i<count;i++)
        {
            mstr[i]=s1[i];
        }

    }
    mstring(mstring& s1)
    {
        delete[]mstr;
        mstr = new char[s1.len()];
        for(int i = 0;i<s1.len();i++)
        {
            mstr[i]=s1[i];
        }
    }
    ~mstring()
    {
        delete[]mstr;
    }

    static size_t len(const char* str)
    {
        size_t len = 0;
        while(str[len++]);
        return len;
    }
    size_t len()
    {
        size_t len = 0;
        while(mstr[len])len++;
        return len;
    };

    char operator [](int i)
    {
        return mstr[i];
    }

    static void* memcpy(void* s1, const void* s2, size_t n){
        char* p = (char *)s1;
        char* q = (char *)s2;
        while (n--)
        {
            *p = *q;
            p++;
            q++;
        }
        return s1;
    }

    static void* memmove(void* s1, const void* s2, size_t n){

        void * ret = s1;
        if (s1 <= s2 || (char*)s1 >= ((char*)s2 + n))
        {
            while (n--)
            {
                *(char*)s1 = *(char*)s2;
                s1 = (char*)s1 + 1;
                s2 = (char*)s2 + 1;
            }
        }
        else
        {
            s1 = (char*)s1 + n - 1;
            s2 = (char*)s2 + n - 1;
            while (n--)
            {
                *(char*)s1 = *(char*)s2;
                s1 = (char*)s1 - 1;
                s2 = (char*)s2 - 1;
            }
        }
        return ret;
    }

    char* strcpy(char* s1, const char* s2){
        size_t length = 0;
        for(; s2[length]; ++length);
        s1 = new char[length + 1];
        for(size_t i = 0; i < length; ++i){
            s1[i] = s2[i];
        }
        s1[length] = '\0';
        return s1;
    }

    char* strncpy(char* s1, const char* s2, size_t n){
        size_t length = 0;
        for(; s2[length]; ++length);
        if(n > length){
            n = length - 1;
        }
        for(size_t i = 0; i < n; ++i){
            s1[i] = s2[i];
        }
        s1[n] = '\0';
        return s1;
    }

    char* strcat(char* s1, const char* s2){
        int length = 0;
        for (int i = 0; s1[i]; ++i, ++length);
        for (int i = 0; s2[i]; ++i, ++length);
        char* s = new char[length];
        for (int i = 0; s1[i]; ++i) {
            s[i] = s1[i];
            length = i;
        }
        for(int i = length + 1, j = 0; s2[j]; ++i, ++j){
            s[i] = s2[j];
        }
        return s;
    }

    char* strncat(char* s1, const char* s2, size_t n){
        size_t length = 0;
        for (int i = 0; s1[i]; ++i, ++length);
        for (int i = 0; s2[i]; ++i, ++length);
        char* s;
        if (length < n){
            s = new char[length];
        }
        else{
            s = new char[n];
        }

        for (size_t i = 0; s1[i]; ++i) {
            s[i] = s1[i];
            length = i;
        }
        for(size_t i = length + 1, j = 0; s2[j] && j < n; ++i, ++j){
            s[i] = s2[j];
            length = i;
        }
        s[length + 1] = '\0';
        return s;
    }

    static int memcmp(const void* s1, const void* s2, size_t n)
    {
        int i=0;
        while(n--)
        {
            if(*((char*)s1+i)==*((char*)s2+i))
                continue;
            else
                if(*(char*)s1>*(char*)s2)
                    return 1;
                else
                    return -1;
            i++;
        }
        return 0;
    }

    static int strcmp(mstring str1, mstring str2){
        const char* s1 = str1.mstr;
        const char* s2 = str2.mstr;
        int i=0;
        while(s1[i]&&s2[i])
        {
            if(*((char*)s1+i)==*((char*)s2+i))
                continue;
            else
                if(*(char*)s1>*(char*)s2)
                    return 1;
                else
                    return -1;
            i++;
        }
        if(*((char*)s1+i)==*((char*)s2+i))
            return 0;
        else
            if(*(char*)s1>*(char*)s2)
                return 1;
            else
                return -1;
    }

    /*int strcoll(const char* s1, const char* s2)
    {
        int i=0;
        while(s1[i]&&s2[i])
        {
            if(*((char*)s1+i)==*((char*)s2+i))
                continue;
            else
                if(*(char*)s1>*(char*)s2)
                    return 1;
                else
                    return -1;
            i++;
        }
        if(*((char*)s1+i)==*((char*)s2+i))
            return 0;
        else
            if(*(char*)s1>*(char*)s2)
                return 1;
            else
                return -1;
    }
    */

    int strncmp(const char* s1, const char* s2, size_t n){
        int i=0;
        while(s1[i]&&s2[i]&&i<n-1)
        {
            if(*((char*)s1+i)==*((char*)s2+i))
                continue;
            else
                if(*(char*)s1>*(char*)s2)
                    return 1;
                else
                    return -1;
            i++;
        }
        if(*((char*)s1+i)==*((char*)s2+i))
            return 0;
        else
            if(*(char*)s1>*(char*)s2)
                return 1;
            else
                return -1;
    }

    int strncmp(mstring str1, mstring str2, size_t n){
        const char* s1 = str1.mstr;
        const char* s2 = str2.mstr;
        int i=0;
        while(s1[i]&&s2[i]&&i<n-1)
        {
            if(*((char*)s1+i)==*((char*)s2+i))
                continue;
            else
                if(*(char*)s1>*(char*)s2)
                    return 1;
                else
                    return -1;
            i++;
        }
        if(*((char*)s1+i)==*((char*)s2+i))
            return 0;
        else
            if(*(char*)s1>*(char*)s2)
                return 1;
            else
                return -1;
    }

    mstring& operator =(const char* a)
    {
        delete[] mstr;
        mstr = strcpy(mstr,a);
        return *this;
    }

    /*size_t strxfrm(char* s1, const char* s2, size_t n);*/

    static int count(const char* a, char b)
    {
        int count_f = 0;
        for(int i = 0; i<len(a);i++)
        {
            if(a[i]==b)
                count_f++;
        }
        return count_f;
    }

    static char* strtok(char* s1, char* s2)
    {

        size_t len = 0, len_lm = 0;
        int split_i = -1;

        while(s1[len])len++;
        while(s2[len_lm]) len_lm++;

        for(int i = 0; i <= len;i++)
        {

            for(int g = 0; g<=len_lm;g++)
            {

                if(s1[i]==s2[g])
                {

                    split_i = i;
                }
                break;
            }
            if(split_i!=-1)
                break;
        }
        char* tok = new char[split_i+2];
        tok[split_i+1]='\0';
        for(size_t i = 0; i<split_i;i++)
        {
            tok[i]=s1[0];
            s1= &s1[1];
        }
        return tok;
    };

    void* memset(void* s, int c, size_t n)
    {
        char* a = (char*)s;
        for(size_t i = 0; i<n;i++)
        {
            a[i] = c;
        }
    }

    mstring& operator+= (mstring a)
    {
        char* mass_t = new char[this->len()+a.len()+1];
        for(int i = 0; i<this->len();i++)
        {
            mass_t[i]=this->mstr[i];
        }
        for(int g = this->len(); g< this->len()+a.len();g++)
        {
            mass_t[g]=a[g-this->len()];
        }
        mass_t[a.len()+this->len()]='\0';
        delete [] this->mstr;
        this->mstr = mass_t;
    }
    mstring& operator+= (char* a)
    {
        char* mass_t = new char[this->len()+len(a)+1];
        for(int i = 0; i<this->len();i++)
        {
            mass_t[i]=this->mstr[i];
        }
        for(int g = this->len(); g< this->len()+len(a);g++)
        {
            mass_t[g]=a[g-this->len()];
        }
        mass_t[len(a)+this->len()]='\0';
        delete this->mstr;
        this->mstr = mass_t;
    }
    mstring& operator+= (const char* a)
    {
        char* mass_t = new char[this->len()+len(a)+1];
        for(int i = 0; i<this->len();i++)
        {
            mass_t[i]=this->mstr[i];
        }
        for(int g = this->len(); g< this->len()+len(a);g++)
        {
            mass_t[g]=a[g-this->len()];
        }
        mass_t[len(a)+this->len()]='\0';
        delete [] this->mstr;
        this->mstr = mass_t;
    }

    void erase(size_t start, size_t end) {
        if (!(len() - (end - start))) {
            delete[] mstr;
            mstr = nullptr;
            return;
        }
        char* mass_t = new char[len()-(end-start)];
        int k = 0;
        int g = 0;
        for(size_t i = 0; i<start;i++,g++)
        {
            mass_t[g]=mstr[i];
        }
        for (size_t i = start; i < end; i++,k++, g++) {
            mass_t[g] = mstr[end + k];
        }
        for (size_t i = end; i < len() - k; i++,g++) {
            mass_t[g] = mstr[i + k];
        }
        delete [] mstr;
        mstr = mass_t;
    }

    int find(mstring& s) {
        size_t i = 0;
        bool ch = false;
        size_t pos;
        for (; i < len(); i++) {
            if (mstr[i] != s[0]) {
                continue;
            }
            pos = i + 1;
            ch = true;
            for (size_t j = 1; j < s.len(); ++j, ++pos) {
                if (mstr[pos] != s[j]) {
                    ch = false;
                    break;
                }
            }
            if (ch) {
                return i;
            }
        }
        return -1;
    }

    int find(const char* s) {
        size_t i = 0;
        bool ch = false;
        size_t pos;
        for (; i < this->len(); i++) {
            if (mstr[i] != s[0]) {
                continue;
            }
            pos = i + 1;
            ch = true;
            for (size_t j = 1; j < len(s); ++j, ++pos) {
                if (mstr[pos] != s[j]) {
                    ch = false;
                    break;
                }
            }
            if (ch) {
                return i;
            }
        }
        return -1;
    }

    int find(char c) {
        for (size_t i = 0; i < this->len(); i++) {
            if (mstr[i] == c)
                return i;
        }
        return -1;
    }
    int find(size_t start, size_t stop, char c) {
        for (size_t i = start; i < stop; i++) {
            if (mstr[i] == c)
                return i;
        }
        return -1;
    }
    int find(size_t start, char c) {
        for (size_t i = start; i < this->len(); i++) {
            if (mstr[i] == c)
                return i;
        }
        return -1;
    }
};


#endif // MY_STRING_H

#ifndef structuri_hpp
#define structuri_hpp
using namespace std;

//---------------------------------------------------------------

//vector 
template <typename T> class Vector {

    size_t size;
    T* data;

public:

    Vector() {
        size = 0;
        data = NULL;
    }

    Vector(size_t k, T x) {
        size = k;
        data = new T[size];
        for (int i = 0; i < size; i++)
            data[i] = x;

    }

    ~Vector() {
        if (data != NULL)
            delete[] data;
    }

    Vector(const Vector& v) {
        int s = v.size;
        T* d = new T[s];
        for (int i = 0; i < s; i++)
            d[i] = v.data[i];

        data = d;
        size = s;
    }

    const Vector& operator=(Vector const& v) {
        delete[] data;
        size = v.size;
        data = new T[size];
        data = v.data;
    }

    friend std::ostream& operator << (std::ostream& out, const Vector& v) {
        for (int i = 0; i < v.size; i++)
            out << v.data[i];
        out << '\n';
        return out;
    };

    friend std::istream& operator >> (std::istream& in, Vector& v) {
        std::cout << "nr. elemente ";
        int n;
        std::cin >> n;
        v.size = n;

        if (v.data != NULL) {
            delete[] v.data;
            v.data = new T[n];
        }
        else
            v.data = new T[n];

        for (int i = 0; i < n; i++)
            in >> v.data[i];
        return in;
    };

    void push(T x) {
        size++;
        T* data_plus;
        data_plus = new T[size];
        for (int i = 0; i < size - 1; i++)
            data_plus[i] = data[i];
        data_plus[size - 1] = x;
        delete[] data;
        data = data_plus;
    };

    size_t ASKsize() {
        return size;
    };

    T get(int index) {
        return data[index];
    };
};

//---------------------------------------------------------------

//string
class MyString {
    size_t size;
    char* data;

public:
    MyString() {
        data = NULL;
        size = 0;
    }

    MyString(size_t k, char s) {
        size = k;
        data = new char[size + 1];
        for (int i = 0; i < size; i++)
            data[i] = s;
        data[size] = '\0';
    }

    MyString(const char* s) {
        size = str_size(s);
        data = new char[size + 1];
        for (int i = 0; i < size; i++)
            data[i] = s[i];
        data[size] = '\0';
    }

    ~MyString() {
        delete[] data;
    }

    MyString(const MyString& s) {
        size = s.size;
        data = new char[s.size + 1];
        for (int i = 0; i < size; i++)
            data[i] = s.data[i];
        data[size] = '\0';

    }

    void operator= (const MyString& s) {
        delete[] data;
        size = s.size;
        data = new char[s.size + 1];
        for (int i = 0; i < size; i++)
            data[i] = s.data[i];
        data[size] = '\0';

    }

    void replace_index(int x, char a) {
        data[x] = a;
    };

    friend std::ostream& operator << (std::ostream& out, const MyString& s);

    int str_size(const char* s) {
        int i, length = 0;
        for (i = 0; s[i] != '\0'; i++)
            length++;
        return length;
    };

    int str_size() {
        int i, length = 0;
        for (i = 0; data[i] != '\0'; i++)
            length++;
        return length;
    };

    void add(char c) {
        MyString* x = new MyString(size, 'x');
        for (int i = 0; i < size; i++)
            x->data[i] = data[i];
        delete[] data;
        data = new char[size + 2];
        for (int i = 0; i < size; i++)
            data[i] = x->data[i];
        size++;
        data[size - 1] = c;
        data[size] = '\0';
        delete x;
    };

    void add(const char* c) {
        MyString* x = new MyString(size, 'x');
        for (int i = 0; i < size; i++)
            x->data[i] = data[i];
        delete[] data;
        data = new char[size + str_size(c) + 1];
        for (int i = 0; i < size; i++)
            data[i] = x->data[i];
        for (int i = 0; i < str_size(c); i++)
            data[i + size] = c[i];
        size = size + str_size(c);
        data[size] = '\0';
        delete x;

    };

    bool src(const char* c) {
        int p = 0;
        for (int i = 0; data[i] != '\0'; i++) {
            if (data[i] == c[p])
                p++;
            else
                p = 0;
            if (p == str_size(c))
                return 1;
        };
        return 0;
    }

};

std::ostream& operator << (std::ostream& out, const MyString& s) {
    for (int i = 0; i < s.size; i++)
        out << s.data[i];
    return out;
};

int str_size(const char* c) {
    int i, length = 0;
    for (i = 0; c[i] != '\0'; i++)
        length++;
    return length;
};

#endif
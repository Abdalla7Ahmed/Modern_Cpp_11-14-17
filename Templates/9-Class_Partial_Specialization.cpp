#include <iostream>
#include <vector>
template <typename T, int columns>
class PrettyPrinter
{
private:
    T *m_data;

public:
    PrettyPrinter(T *data) : m_data(data) {}
    void print(void)
    {
        std::cout << "columns: " << columns << std::endl;
        std::cout << "{" << *m_data << "}" << std::endl;
    }

    T *GetData(void)
    {
        return m_data;
    }
    ~PrettyPrinter() = default;
};

template <typename T>
class PrettyPrinter<T, 80>
{
private:
    T *m_data;

public:
    PrettyPrinter(T *data) : m_data(data) {}
    void print(void)
    {
        std::cout << "using 80 columns: " << std::endl;
        std::cout << "{" << *m_data << "}" << std::endl;
    }

    T *GetData(void)
    {
        return m_data;
    }
    ~PrettyPrinter() = default;
};

template <typename T>
class SmartPointer
{
private:
    T *m_data;

public:
    SmartPointer(T *data) : m_data(data) {};
    T *operator->()
    {
        std::cout << " T *operator->()" << std::endl;
        return m_data;
    }
    T &operator*()
    {
        std::cout << "T &operator*()" << std::endl;
        return *m_data;
    }
    ~SmartPointer()
    {
        delete m_data;
    };
};

// partial specialization for the array type
template <typename T>
class SmartPointer<T[]>
{
private:
    T *m_data;

public:
    SmartPointer(T *data) : m_data(data) {};
    T &operator[](int index)
    {
        std::cout << "T &operator[](int index)" << std::endl;
        return m_data[index];
    }
    ~SmartPointer()
    {
        delete[] m_data;
    };
};
int main(int argc, char const *argv[])
{
    int var = 100;
    PrettyPrinter<int, 80> p1{&var};
    p1.print();

    SmartPointer<int> S1{new int(5)};
    std::cout << *S1 << std::endl;

    SmartPointer<int[]> S2{new int[5]};
    S2[0] = 10;
    std::cout << S2[0] << std::endl;
    return 0;
}

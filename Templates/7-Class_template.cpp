#include <iostream>
template <typename T, int SIZE>
class Stack
{
private:
    T m_stack[SIZE];
    int m_position = -1;

public:
    Stack() = default;

    Stack(const Stack<T, SIZE> &obj);
    ~Stack() = default;

    void push(T element);

    void pop();

    T Top();
    bool isEmpty();

    static Stack create();
};
template <typename T, int SIZE>
void Stack<T, SIZE>::push(T element)
{
    if (m_position == SIZE - 1)
    {
        std::cout << "there is no space to push" << std::endl;
        return;
    }
    m_stack[++m_position] = element;
}
template <typename T, int SIZE>
void Stack<T, SIZE>::pop()
{
    if (m_position < 0)
    {
        std::cout << "there is no data to pop" << std::endl;
        return;
    }
    --m_position;
}
template <typename T, int SIZE>
T Stack<T, SIZE>::Top()
{
    return m_stack[m_position];
}

template <typename T, int SIZE>
bool Stack<T, SIZE>::isEmpty()
{
    return m_position < 0 ? true : false;
}

template <typename T, int SIZE>
Stack<T, SIZE> Stack<T, SIZE>::create()
{
    return Stack<T, SIZE>();
}

template <typename T, int SIZE>
Stack<T, SIZE>::Stack(const Stack<T, SIZE> &obj)
{
    this->m_position = obj.m_position;
    for (int i = 0; i <= m_position; i++)
    {
        this->m_stack[i] = obj.m_stack[i];
    }
}

int main(int argc, const char **argv)
{

    Stack<int, 2> stack = Stack<int, 2>::create();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    Stack<int, 2> stack2(stack);
    while (!stack2.isEmpty())
    {
        std::cout << stack2.Top() << std::endl;
        stack2.pop();
    }

    return 0;
}

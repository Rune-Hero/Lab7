#include <iostream>
#include <vector>
#include <stdexcept>
#include <windows.h>

using namespace std;

template <class T>
class Stack 
{
private:
    vector<T> V;

public:
    Stack() = default;
    Stack(const Stack& other) = default;

    void push(T value)
    {
        V.push_back(value);
    }

    void pop()
    {
        if (V.empty())
            throw out_of_range("���� ������, ��������� �������� �������");
        V.pop_back();
    }

    T top()
    {
        if (V.empty())
            throw out_of_range("���� ������");
        return V.end();
    }

    bool isEmpty()
    {
        return V.empty();
    }

    void print()
    {
        for (auto i = V.rbegin(); i != V.rend(); ++i)
            cout << *i << " ";
        cout << endl;
    }


};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        Stack<int> I;

        I.push(-10);
        I.push(10);
        I.push(20);

        cout << "���� �����: ";
        I.print();

        Stack<int> copiedStack = I;
        
        I.pop();
        cout << "���� ����� ���� ��������� ��������: ";
        I.print();

        cout << "���� ��ﳿ �����: ";
        copiedStack.print();

        Stack<string> S;

        S.push("afsfs");
        S.push("hgkgh");
        cout << S.top();

    } catch (exception e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

#include "nonbinarypolishrecord.h"
namespace rdi
{
int unary_operation(int a, int b, char operation)
{
    switch (operation)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '/':
            return a / b;
        case '*':
            return a * b;
    }
    return -1;
}

bool isOperator(char c) { return c == '+' || c == '-' || c == '/' || c == '*'; }

int nonbinarypolishrecord(const std::string& s)
{
    // Стек операндов
    std::stack<int> operands;

    // Стек операций
    std::stack<char> operators;

    //переменная определяет сколько чисел не будет задействовано в следующей операций
    std::size_t count = 0;

    // Флаг определяет нужно ли полностью выгружать стек операндов
    bool flag = false;

    for (char c : s)
    {
        if (isOperator(c))
        {
            operators.push(c);
        }
        else if (c == '(')
        {
            flag = false;
        }
        else if (isdigit(c))
        {
            operands.push(c - '0');
        }
        else if (c == ')')
        {
            if (flag)
            {
                count = 0;
            }
            char __operator = operators.top();
            operators.pop();
            while (operands.size() >= 2 + count)
            {
                int n1 = operands.top();
                operands.pop();
                operands.top() = unary_operation(operands.top(), n1, __operator);
            }
            flag = true;
            ++count;
        }
    }
    return operands.top();
}

}  // namespace rdi

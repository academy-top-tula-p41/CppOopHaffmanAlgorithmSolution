#include <iostream>

#include <stack>
#include <queue>

#include "Examples.h"

int main()
{
    // Examples::ContainresExample();

    const int size{ 10 };
    int arrayInit[size]{ 30, 10, 60, 20, 90, 40, 50, 70, 80, 50 };


    std::stack<int> stackInt;
    std::queue<int> queueInt;
    std::priority_queue<int> priorityInt;

    for (int i{}; i < size; i++)
    {
        stackInt.push(arrayInit[i]);
        queueInt.push(arrayInit[i]);
        priorityInt.push(arrayInit[i]);
    }

    while (!stackInt.empty())
    {
        std::cout << stackInt.top() << " ";
        stackInt.pop();
    }
    std::cout << "\n";

    while (!queueInt.empty())
    {
        std::cout << queueInt.front() << " ";
        queueInt.pop();
    }
    std::cout << "\n";

    while (!priorityInt.empty())
    {
        std::cout << priorityInt.top() << " ";
        priorityInt.pop();
    }
    std::cout << "\n";
}

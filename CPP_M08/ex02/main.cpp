#include "MutantStack.hpp"
#include <iostream>
#include <list>


int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    //same but with lists
    std::cout << "\nWith list:" << std::endl;
    std::list <int> mylist;
    mylist.push_back(5);
    mylist.push_back(17);
    std::cout << mylist.back() << std::endl;
    mylist.pop_back();
    std::cout << mylist.size() << std::endl;
    mylist.push_back(3);
    mylist.push_back(5);
    mylist.push_back(737);
    //[...]
    mylist.push_back(0);
    std::list<int>::iterator it_l = mylist.begin();
    std::list<int>::iterator ite_l = mylist.end();
    ++it_l;
    --it_l;
    while (it_l != ite_l)
    {
        std::cout << *it_l << std::endl;
        ++it_l;
    }
    std::list<int> s_l(mylist);
    return 0;
}
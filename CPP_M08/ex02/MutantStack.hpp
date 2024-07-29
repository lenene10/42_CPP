#pragma once

#include <deque>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
    private:
        typedef std::stack<T> stacktype;
    public:
        typedef typename std::deque<T>::iterator iterator;
        MutantStack () : std::stack<T>() {}
        MutantStack (MutantStack const &other) : std::stack<T>(other) {}
        ~MutantStack () {}
        MutantStack &operator=(MutantStack const&) {}

        iterator begin() {
            return stacktype::c.begin();
        }

        iterator end() {
            return stacktype::c.end();
        }
};
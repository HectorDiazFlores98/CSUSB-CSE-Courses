#include <vector>
#include <iostream>

using namespace std;
template <typename T>
class Stack
{
        public:
            Stack();
            void push(T);
            void pop();   
            T setTop();
            bool isEmpty();
                                
        private:
            vector<T> stack;
};

template <typename T>
Stack<T>::Stack()
{
        
}

template <typename T>
void Stack<T>::push(T x)
{
        stack.push_back(x);
}

template <typename T>
void  Stack<T>::pop()
{
        stack.pop_back();
}

template<typename T>
T Stack<T>::setTop()
{ 
        return stack[stack.size()-1];
}

template <typename T>
bool Stack<T>::isEmpty()
{
        if(stack.size() == 0)
                {
                            return true;
                                }
                                    else return false;
}

int main()
{
        //Stack <double>s=Stack<double>(); or
            Stack <double> s;
                s.push(3.14);
                    cout << s.setTop() << "\n";
                        s.pop();
}

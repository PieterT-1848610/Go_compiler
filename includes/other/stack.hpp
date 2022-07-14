#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

#include <iostream>
#include <vector>

template <class T>
class Stack{
    public:
        Stack(): values{} {};
        ~Stack() {};

        bool empty(){
            return values.empty();
        }

        T pop(){
            if(empty()){
                std::cout<<"we empty, error";
                return;
            }

            auto value = values.back();
            values.pop_back();
            return value;

        }

        T top(){
            if(empty()){
                std::cout<<"we are empty, error";
                return;
            }

            return values.back();
        }


        void push(T value){
            values.push_back(value);
        }


    private:
        std::vector<T> values;

};


#endif
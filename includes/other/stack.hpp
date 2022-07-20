#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

#include <iostream>
#include <vector>
#include <exception>

class EmptyStackException: public std::exception{
    public:
        EmptyStackException(std::string msg): msg{msg}{}

    private:
        std::string msg;
};


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
                throw new EmptyStackException("empyt stack");
            }

            auto value = values.back();
            values.pop_back();
            return value;

        }

        T top(){
            if(empty()){
                throw new EmptyStackException("empyt stack");

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
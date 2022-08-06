#ifndef SYMBOLTABLE_HPP
#define SYMBOLTABLE_HPP

#include <unordered_map>
#include <string>
#include <exception>

class SymbolException: public std::exception{
    public:
        SymbolException(std::string msg): msg{msg}{}

    private:
        std::string msg;
};


template <class T>
class SymbolTable{
    public:
        //ook wel ene unordered map aanmaken (global)
        SymbolTable() : table{} {
            table = std::vector<std::unordered_map<std::string, T>> {};
            table.push_back(std::unordered_map<std::string, T> {});
        };
        ~SymbolTable() = default; //possible memory leaks, if T is pointer

        //TODO: van achter naar voor checken, niet bestaat error
        T get(std::string key) {
            for(int i = table.size() - 1; i>=0; i--){
                
                if(this->table[i].count(key)>0){
                    return table[i][key];
                }
            }
            throw new SymbolException("Symbool don't exist");
        };

        //TODO:maybe problem for assign
        void set(std::string key, T value) {
            int a = table.size() - 1;
            table[a].insert(std::make_pair(key, value));
            //this->table.back()[key] = value;
            
        };

        void setOther(std::string key, T value){
            this->table.back()[key] = value;
        }


        //No nbeed anymore fixed with [key]
        void replace(std::string key, T value){
            int place = checkcontain(key);
            if(place == -1){
                set(key, value);
            }else{
                table[place].erase(key);
                table[place].insert(std::make_pair(key, value));
            }
        }

        int checkcontain(std::string key){
            for(int i = table.size()-1; i>=0; i--){
                if(this->table[i].count(key)>0){
                    return i;
                }
            }
            return -1;
        }
        
        //TODO: alles aflopen nog 
        std::vector<std::vector<std::string>> keys() {
            
                std::vector<std::vector<std::string>>  keys;

                keys.reserve(table.size());
                for(int i =0; i<table.size(); i++){
                    std::vector<std::string> temp = {};
                
                    for(auto kv: table[i]){
                        temp.push_back(kv.first);
                    }
                    keys.push_back(temp);
                }

            return keys;
        };



        //check current scope only for key?
        bool contains(std::string key) {
            int i = table.size() -1;
            return(this->table[i].count(key)>0);  
        };
        //een aan maken in block
        void newScope() {
            table.push_back(std::unordered_map<std::string, T>{});

        };
        //altijd 1 laat staan (global)
        
        //na uitgaan block
        void removeScope() {
            table.pop_back();
        } 

    private:
        std::vector<std::unordered_map<std::string, T>> table;


};


#endif
#ifndef SYMBOLTABLE_HPP
#define SYMBOLTABLE_HPP

#include <unordered_map>
#include <string>



template <class T>
class SymbolTable{
    public:
        //ook wel ene unordered map aanmaken (global)
        SymbolTable() : table{} {};
        ~SymbolTable() = default; //possible memory leaks, if T is pointer

        //TODO: van achter naar voor checken, niet bestaat error
        T get(std::string key) {
            return table[key];
        };

        //TODO: in achterste vector komt staan
        void set(std::string key, T value) {
            table[key] = value;
        };
        
        //TODO: alles aflopen nog 
        std::vector<std::vector<std::string>> keys() {
            std::vector<std::string>  keys;
            keys.reserve(table.size());
            for(auto kv: table){
                keys.push_back(kv.first);
            }
            return keys;
        };

        bool contains(std::string key) {
            return this->table.contains(key);
        };
        //een aan maken in block
        void newScope() {/*todo*/}
        //altijd 1 laat staan (global)
        
        //na uitgaan block
        void removeScope() {/*todo*/} 

    private:
        std::vector<std::unordered_map<std::string, T>> table;


};


#endif
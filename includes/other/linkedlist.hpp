#include <vector>
#include <stdexcept>
/*
*   possible still has fault in it !!!
*/


template <class T>
class LinkNode{
    public:
        LinkNode(){
            this->next = NULL;
        }
        
        void toVector(std::vector<T> &vec){
            vec.push_back(value);
            if(next!=NULL){
                next->toVector(vec);
            }
        }

    private:
        T value;
        LinkNode<T>* next;
        template<class U>friend class LinkedList;


};


template <class T>
class LinkedList{
    public:
        LinkedList(){
            this->head = NULL;
        }

        ~LinkedList(){
            delete this->head;
        }

        long length(){
            long len = 0;
            LinkNode<T>* temp = head;
            while(temp != NULL){    //run until null
                len++;
                temp = temp->next;
            }
            return len;
        }

        T get(long index) const{
            if(head==NULL){
                throw std::runtime_error("ERROR: head is NULL");
            }
            if(index >= length()){
                throw std::runtime_error("ERROR: index out of bounds");
            }
            if(index==0){
                return head->value;
            }
            long count=0;
            T result;
            LinkNode<T>* temp = head;
            while(temp!=NULL){
                if(count++ == index){
                    result = temp->value;
                    break;
                }
                temp= temp->next;
            }
            return result;
        }

        void add(long index, T item){
            if(index > length()){   //check if inbound
                throw std::runtime_error("ERROR: Index out of bounds");
            }

            //make node
            LinkNode<T>* node = new LinkNode<T> {};
            node->value = item;

            //set count
            long count = 0;

            //set temp to head
            LinkNode<T>* temp = head;
            
    
            //add to front
            if(index == count){
                node->next = head;
                head = node;
                return;
            }

            while(count < index) {
                count ++;
                temp = temp->next;
            }

            if(count -1 == index){
                node->next = temp->next;
                temp->next = node;
            }


        }

        std::vector<T> toVector() const{
            std::vector<T> result;
            if(head !=NULL){
                head->toVector(result);
            }
            return result;
        }

    private:
            LinkNode<T> *head;

};

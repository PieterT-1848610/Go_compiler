#include <vector>

template <class T>
class LinkNode{
private:
    T value;
    LinkNode<T>* next;
    template<class U>friend class LinkedList;
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

};


template <class T>
class LinkedList{
private:
    LinkNode<T> *head;
public:
    LinkedList(){
        this->head = NULL;
    }

    ~LinkedList(){
        delete this->head;
    }

    long length(){
        long len = 0;
        LinkNode<int>* temp = head;
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
        LinkNode<T>* temp= head;
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
        LinkNode<T>* node = new LinkNode<T>[1];
        node->value = item;
        long count = 0;
        LinkNode<T>* temp = head;
        while(temp != NULL && count < index){
            if(count == index -1){
                if(temp->next != NULL){//Full in between elements
                    node->next = temp->next;
                }
                temp->next = node;
                break;
            }
            count ++;
            temp = temp->next;
        }
    }

    std::vector<T> toVector() const{
        std::vector<T> result;
        if(head !=NULL){
            head->toVector(result);
        }
        return result;
    }
};

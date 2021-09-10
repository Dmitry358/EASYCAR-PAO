#ifndef CONTAINER_H
#define CONTAINER_H


template <class T>
class Container{
private:
    T* vector;
    unsigned int _size;
    unsigned int _capacity;

    bool full() const;


public:
    class iterator{
         friend class Container<T>;

    private:
        Container<T>* container;
        T* pointer;
        bool past_the_end;

    public:
        iterator();
        iterator(Container<T>* cont, T* ptr, bool pte=false);
        iterator(const iterator&);
        iterator& operator=(const iterator&);

        T* operator->() const;
        T& operator*() const;
        T& operator[](unsigned int) const;

        bool isValid() const;
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
        bool operator>(const iterator&) const;
        bool operator<(const iterator&) const;
        bool operator>=(const iterator&) const;
        bool operator<=(const iterator&) const;


        iterator& operator++();
        iterator  operator++(int);
        iterator& operator--();
        iterator  operator--(int);
        iterator& operator+=(unsigned int);
        iterator& operator-=(unsigned int);
        iterator  operator+(unsigned int) const;
        iterator  operator-(unsigned int) const;
    };

    class const_iterator {
        friend class Container<T>;

    private:
        const Container<T>* container;
        const T* pointer;
        bool past_the_end;

    public:
        const_iterator();
        const_iterator(const Container<T>* cont, const T* ptr, bool pte=false);
        const_iterator(const const_iterator&);
        const_iterator& operator=(const const_iterator&);

        const T* operator->() const;
        const T& operator*() const;
        const T& operator[](unsigned int) const;

        bool isValid() const;
        bool operator==(const const_iterator&) const;
        bool operator!=(const const_iterator&) const;
        bool operator>(const const_iterator&) const;
        bool operator<(const const_iterator&) const;
        bool operator>=(const const_iterator&) const;
        bool operator<=(const const_iterator&) const;

        const_iterator& operator++();
        const_iterator  operator++(int);
        const_iterator& operator--();
        const_iterator  operator--(int);
        const_iterator& operator+=(unsigned int);
        const_iterator& operator-=(unsigned int);
        const_iterator  operator+(unsigned int) const;
        const_iterator  operator-(unsigned int) const;
};

    explicit Container(unsigned int s=0, const T& t = T());
    Container(const Container&);
    Container& operator=(const Container&);
    ~Container();

    bool operator==(const Container&) const;
    unsigned int size() const;
    unsigned int capacity() const;
    bool empty() const;

    iterator begin() const;
    const_iterator cbegin() const;
    iterator end() const;
    const_iterator cend() const;

    T& operator[](unsigned int);
    const T& operator[](unsigned int) const;
    T& operator[](const iterator&) const;
    const T& operator[](const const_iterator&) const;

    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    void push_back(const T&);
    void pop_back();

    iterator insert(iterator, const T&);

    iterator erase(iterator);


    void clear();

};


template<class T>
Container<T>::Container(unsigned int s, const T& t): vector(s == 0 ? nullptr : new T[s]), _size(s), _capacity(s){
    for(unsigned int i=0; i<s; ++i) vector[i]=t;
}

template<class T>
Container<T>::Container(const Container<T>& c): vector(c._size == 0 ? nullptr : new T[c._size]), _size(c._size), _capacity(c._size){
    for(unsigned int i=0; i<c._size; ++i) vector[i]=c.vector[i];
}

template<class T>
Container<T>& Container<T>::operator=(const Container<T>& c){
    if(this != &c){
        delete[] vector;
        _size = c._size;
        _capacity = c._size;
        vector = c._size == 0 ? nullptr : new T[c._size];
        for(unsigned int i=0; i < c._size; ++i) vector[i]=c.vector[i];
    }

    return *this;
}

template<class T>
Container<T>::~Container() { if(vector) delete[] vector; }

template<class T>
bool Container<T>::operator==(const Container<T>& c) const {
    if(this == &c) return true;
    if(_size != c._size) return false;
    for(unsigned int i=0; i<_size; i++){
          if(vector[i] != c.vector[i]) return false;
    }

    return true;
}

template<class T>
unsigned int Container<T>::size() const { return _size; }

template<class T>
unsigned int Container<T>::capacity() const { return _capacity; }

template<class T>
bool Container<T>::empty() const { return _size==0; }

template<class T>
bool Container<T>::full() const { return _size==_capacity; }

template<class T>
typename Container<T>::iterator Container<T>::begin() const {
    if(_size==0) return iterator();
    return iterator(const_cast<Container<T>*>(this), vector);
}

template<class T>
typename Container<T>::const_iterator Container<T>::cbegin() const {
    if(_size==0) return const_iterator();
    return const_iterator(this, vector);
}

template<class T>
typename Container<T>::iterator Container<T>::end() const {
    if(_size==0) return iterator();
    return iterator(const_cast<Container<T>*>(this), vector+_size, true);
}

template<class T>
typename Container<T>::const_iterator Container<T>::cend() const {
    if(_size==0) return const_iterator();
    return const_iterator(this, vector+_size, true);
}

template<class T>
T& Container<T>::operator[](unsigned int i) { return vector[i]; }

template<class T>
const T& Container<T>::operator[](unsigned int i) const { return vector[i]; }

template<class T>
T& Container<T>::operator[](const iterator& it) const { return *(it.pointer); }

template<class T>
const T& Container<T>::operator[](const const_iterator& it) const { return *(it.pointer); }

template<class T>
T& Container<T>::front(){ return *vector; }

template<class T>
const T& Container<T>::front() const { return *vector; }

template<class T>
T& Container<T>::back(){ return vector[_size-1]; }

template<class T>
const T& Container<T>::back() const { return vector[_size-1]; }

template<class T>
void Container<T>::push_back(const T& val){
    if(!vector){
        vector=new T[1];
        *vector=val;
        ++_capacity;
    }

    else if(full()){
        T* aux=new T[_capacity*2];
        for(unsigned int i=0; i<_size; ++i) aux[i]=vector[i];
        aux[_size]=val;
        delete[] vector;
        vector=aux;
        _capacity*=2;
    }

    else vector[_size]=val;

    ++_size;
}

template<class T>
void Container<T>::pop_back(){ if(!empty()) --_size; }

template<class T>
typename Container<T>::iterator Container<T>::insert(iterator pos, const T& val){
    if(pos.pointer && pos>=begin() && pos<=end()){
        if(full()){
            T* aux= new T[_capacity*2];

            int i=0;
            auto it=begin();
            for(; it<pos; ++it){
                aux[i]=*it;
                ++i;
            }

            i=_size;
            it=end()-1;
            for(; it>=pos; --it){
                aux[i]=*it;
                --i;
            }

            aux[i]=val;

            delete[] vector;
            ++_size;
            _capacity*=2;
            vector=aux;

            return iterator(this, vector+i);
        }

        else {
            for(auto it=end(); it>pos; --it) *it=*(it-1);
            ++_size;
            *pos=val;
            return pos;
        }
   }

   return iterator();
}

template<class T>
typename Container<T>::iterator Container<T>::erase(iterator pos){
    if(pos.pointer && pos>=begin() && pos<end()){
        if(pos==end()-1){
            --_size;
            return iterator(this, pos.pointer, true);
        }

        else{
            for(auto aux=pos; aux<end()-1; ++aux) *(aux)=*(aux+1);
            --_size;
            return pos;
        }
    }

    return iterator();
}

template<class T>
void Container<T>::clear(){
    if(!empty()){
        delete[] vector;
        vector=new T[_capacity];
        _size=0;
    }
}

template<class T>
Container<T>::iterator::iterator(): container(nullptr), pointer(nullptr), past_the_end(false){}

template<class T>
Container<T>::iterator::iterator(Container<T>* cont, T* ptr, bool pte): container(cont), pointer(ptr), past_the_end(pte){}

template<class T>
Container<T>::iterator::iterator(const iterator& it): container(it.container), pointer(it.pointer), past_the_end(it.past_the_end){}

template<class T>
typename Container<T>::iterator& Container<T>::iterator::operator=(const iterator& it){
    if(this!=&it){
        container=it.container;
        pointer=it.pointer;
        past_the_end=it.past_the_end;
    }

    return *this;
}

template<class T>
T* Container<T>::iterator::operator->() const { return pointer; }

template<class T>
T& Container<T>::iterator::operator*() const { return *pointer; }

template<class T>
T& Container<T>::iterator::operator[](unsigned int i) const { return *(pointer+i); }

template<class T>
bool Container<T>::iterator::isValid() const { return pointer!=nullptr; }

template<class T>
bool Container<T>::iterator::operator==(const iterator& it) const { return pointer == it.pointer; }

template<class T>
bool Container<T>::iterator::operator!=(const iterator& it) const { return pointer != it.pointer; }

template<class T>
bool Container<T>::iterator::operator>(const iterator& it) const { return pointer > it.pointer; }

template<class T>
bool Container<T>::iterator::operator<(const iterator& it) const { return pointer < it.pointer; }

template<class T>
bool Container<T>::iterator::operator>=(const iterator& it) const { return pointer >= it.pointer; }

template<class T>
bool Container<T>::iterator::operator<=(const iterator& it) const { return pointer <= it.pointer; }

template<class T>
typename Container<T>::iterator& Container<T>::iterator::operator++(){
    if(pointer){
        if(!past_the_end){
            ++pointer;
            if(pointer == container->vector + container->size()) past_the_end = true;
        }
    }

    return *this;
}

template<class T>
typename Container<T>::iterator Container<T>::iterator::operator++(int){
    iterator aux(*this);
    if(pointer){
        if(!past_the_end){
            ++pointer;
            if(pointer == container->vector + container->size()) past_the_end = true;
        }
    }

    return aux;
}

template<class T>
typename Container<T>::iterator& Container<T>::iterator::operator--(){
    if(pointer){
        if(past_the_end) past_the_end=false;

        if(pointer==container->vector){
            container=nullptr;
            pointer=nullptr;
        }

        else --pointer;
    }

    return *this;
}

template<class T>
typename Container<T>::iterator Container<T>::iterator::operator--(int){
    iterator aux(*this);
    if(pointer){
        if(past_the_end) past_the_end=false;

        if(pointer==container->vector){
            container=nullptr;
            pointer=nullptr;
        }

        else --pointer;
    }

    return aux;
}

template<class T>
typename Container<T>::iterator& Container<T>::iterator::operator+=(unsigned int i){
    if(pointer){
        if(!past_the_end){
            if(pointer+i >= container->vector + container->size()){
                past_the_end = true;
                pointer = container->vector + container->size();
            }

            else pointer+=i;
        }
    }

    return *this;
}

template<class T>
typename Container<T>::iterator& Container<T>::iterator::operator-=(unsigned int i){
    if(pointer){
        if(past_the_end) past_the_end=false;

        if(pointer-i >= container->vector) pointer-=i;

        else{
            pointer=nullptr;
            container=nullptr;
        }
    }

    return *this;
}

template<class T>
typename Container<T>::iterator Container<T>::iterator::operator+(unsigned int i) const {
    iterator temp(*this);

    if(temp.pointer){
        if(!temp.past_the_end){
            if(temp.pointer+i >= temp.container->vector + temp.container->size()){
                temp.past_the_end = true;
                temp.pointer = temp.container->vector + temp.container->size();
            }

            else temp.pointer+=i;
        }
    }

    return temp;
}

template<class T>
typename Container<T>::iterator Container<T>::iterator::operator-(unsigned int i) const {
    iterator temp(*this);

    if(temp.pointer){
        if(temp.past_the_end) temp.past_the_end=false;

        if(temp.pointer-i >= temp.container->vector) temp.pointer-=i;

        else{
            temp.container=nullptr;
            temp.pointer=nullptr;
        }
    }

    return temp;
}

template<class T>
Container<T>::const_iterator::const_iterator(): container(nullptr), pointer(nullptr), past_the_end(false){}

template<class T>
Container<T>::const_iterator::const_iterator(const Container<T>* cont, const T* ptr, bool pte):
                                             container(cont), pointer(ptr), past_the_end(pte){}

template<class T>
Container<T>::const_iterator::const_iterator(const const_iterator& cit): container(cit.container),
                                             pointer(cit.pointer), past_the_end(cit.past_the_end){}

template<class T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator=(const const_iterator& cit){
    if(this!=&cit){
        container=cit.container;
        pointer=cit.pointer;
        past_the_end=cit.past_the_end;
    }

    return *this;
}

template<class T>
const T* Container<T>::const_iterator::operator->() const { return pointer; }

template<class T>
const T& Container<T>::const_iterator::operator*() const { return *pointer; }

template<class T>
const T& Container<T>::const_iterator::operator[](unsigned int i) const { return *(pointer+i); }

template<class T>
bool Container<T>::const_iterator::isValid() const { return pointer!=nullptr; }

template<class T>
bool Container<T>::const_iterator::operator==(const const_iterator& cit) const { return pointer == cit.pointer; }

template<class T>
bool Container<T>::const_iterator::operator!=(const const_iterator& cit) const { return pointer != cit.pointer; }

template<class T>
bool Container<T>::const_iterator::operator>(const const_iterator& cit) const { return pointer > cit.pointer; }

template<class T>
bool Container<T>::const_iterator::operator<(const const_iterator& cit) const { return pointer < cit.pointer; }

template<class T>
bool Container<T>::const_iterator::operator>=(const const_iterator& cit) const { return pointer >= cit.pointer; }

template<class T>
bool Container<T>::const_iterator::operator<=(const const_iterator& cit) const { return pointer <= cit.pointer; }

template<class T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator++(){
    if(pointer){
        if(!past_the_end){
            ++pointer;
            if(pointer == container->vector + container->size()) past_the_end = true;
        }
    }

    return *this;
}

template<class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator++(int){
    const_iterator aux(*this);

    if(pointer){
        if(!past_the_end){
            ++pointer;
            if(pointer == container->vector + container->size()) past_the_end = true;
        }
    }

    return aux;
}

template<class T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator--(){
    if(pointer){
        if(past_the_end) past_the_end=false;

        if(pointer==container->vector){
            container=nullptr;
            pointer=nullptr;
        }

        else --pointer;
    }

    return *this;
}

template<class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator--(int){
    const_iterator aux(*this);
    if(pointer){
        if(past_the_end) past_the_end=false;

        if(pointer==container->vector){
            container=nullptr;
            pointer=nullptr;
        }

        else --pointer;
    }

    return aux;
}

template<class T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator+=(unsigned int i){
    if(pointer){
        if(!past_the_end){
            if(pointer+i >= container->vector + container->size()){
                past_the_end = true;
                pointer = container->vector + container->size();
            }

            else pointer+=i;
        }
    }

    return *this;
}

template<class T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator-=(unsigned int i){
    if(pointer){
        if(past_the_end) past_the_end=false;

        if(pointer-i >= container->vector) pointer-=i;

        else{
            pointer=nullptr;
            container=nullptr;
        }
    }

    return *this;
}

template<class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator+(unsigned int i) const {
    const_iterator temp(*this);

    if(temp.pointer){
        if(!temp.past_the_end){
            if(temp.pointer+i >= temp.container->vector + temp.container->size()){
                temp.past_the_end = true;
                temp.pointer = temp.container->vector + temp.container->size();
            }

            else temp.pointer+=i;
        }
    }

    return temp;
}

template<class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator-(unsigned int i) const {
    const_iterator temp(*this);

    if(temp.pointer){
        if(temp.past_the_end) temp.past_the_end=false;

        if(temp.pointer-i >= temp.container->vector) temp.pointer-=i;

        else{
            temp.container=nullptr;
            temp.pointer=nullptr;
        }
    }

    return temp;
}


#endif // CONTAINER_H

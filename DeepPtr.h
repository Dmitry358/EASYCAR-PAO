#ifndef DEEPPTR_H
#define DEEPPTR_H

template<class T>
class DeepPtr {
private:
    T* pointer;

public:
    DeepPtr(T* = nullptr);
    DeepPtr(const DeepPtr&);
    DeepPtr& operator=(const DeepPtr&);
    ~DeepPtr();

    bool operator==(const DeepPtr&) const;
    bool operator!=(const DeepPtr&) const;

    T* operator->() const;
    T& operator*() const;

    operator bool() const;
    T* get() const;
    T* release();
    void swap(DeepPtr& dp);

};

template<class T>
DeepPtr<T>::DeepPtr(T* ptr): pointer(ptr) {}

template<class T>
DeepPtr<T>::DeepPtr(const DeepPtr& dp): pointer(dp.pointer == nullptr ? nullptr : (dp.pointer)->clone()) {}

template <class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr& dp) {
    if(this != &dp){
        if(pointer) { delete pointer; }
        pointer = dp.pointer == nullptr ? nullptr : (dp.pointer)->clone();
    }

    return *this;
}

template<class T>
DeepPtr<T>::~DeepPtr(){ if(pointer) delete pointer; }

template <class T>
bool DeepPtr<T>::operator==(const DeepPtr& dp) const { return pointer == dp.pointer; }

template <class T>
bool DeepPtr<T>::operator!=(const DeepPtr& dp) const { return pointer != dp.pointer; }

template<class T>
T* DeepPtr<T>::operator->() const { return pointer; }

template <class T>
T& DeepPtr<T>::operator*() const { return *pointer; }

template<class T>
T* DeepPtr<T>::get() const { return pointer; }

template<class T>
DeepPtr<T>::operator bool() const { return pointer != nullptr; }

template<class T>
T* DeepPtr<T>::release() {
    T* aux=pointer;
    pointer=nullptr;
    return aux;
}

template<class T>
void DeepPtr<T>::swap(DeepPtr& dp) {
    T* aux=pointer;
    pointer=dp.pointer;
    dp.pointer=aux;
 }

#endif // DEEPPTR_H

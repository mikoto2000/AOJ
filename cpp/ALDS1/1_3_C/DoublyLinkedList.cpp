#include <iostream>

using namespace std;

template <class T>
class DoubleLinkedListItem {
    private:
        DoubleLinkedListItem<T>* next;
        DoubleLinkedListItem<T>* prev;
        T content;
    public:
        DoubleLinkedListItem(
            DoubleLinkedListItem<T>* next,
            DoubleLinkedListItem<T>* prev,
            T content) : next(next), prev(prev), content(content) { }
        void setNext(DoubleLinkedListItem<T>* next);
        void setPrev(DoubleLinkedListItem<T>* prev);
        DoubleLinkedListItem<T>* getNext();
        DoubleLinkedListItem<T>* getPrev();
        T getContent();
        void deleteThis();
};

template <class T>
void DoubleLinkedListItem<T>::setNext(DoubleLinkedListItem<T>* next) {
    this->next = next;
}

template <class T>
void DoubleLinkedListItem<T>::setPrev(DoubleLinkedListItem<T>* prev) {
    this->prev = prev;
}

template <class T>
DoubleLinkedListItem<T>* DoubleLinkedListItem<T>::getNext() {
    return this->next;
}

template <class T>
DoubleLinkedListItem<T>*  DoubleLinkedListItem<T>::getPrev() {
    return this->prev;
}

template <class T>
T  DoubleLinkedListItem<T>::getContent() {
    return this->content;
}

template <class T>
void DoubleLinkedListItem<T>::deleteThis() {

    DoubleLinkedListItem<T>* newNext = this->next;
    DoubleLinkedListItem<T>* newPrev = this->prev;

    if (this->next != NULL) {
        this->next->prev = newPrev;
    }

    if (this->prev != NULL) {
        this->prev->next = newNext;
    }
}

template <class T>
class DoubleLinkedList {
    private:
        DoubleLinkedListItem<T>* first;
        DoubleLinkedListItem<T>* last;
    public:
        void insertContent(T content);
        void deleteContent(T content);
        void deleteFirst();
        void deleteLast();
        void print();
};

template <class T>
void DoubleLinkedList<T>::insertContent(T content) {
    if (this->first == NULL) {
        this->first = new DoubleLinkedListItem<T>(NULL, NULL, content);
        this->last = this->first;
        return;
    }

    // 新アイテムの next, 現在の先頭の prev を更新
    DoubleLinkedListItem<T>* newItem = new DoubleLinkedListItem<T>(this->first, NULL, content);
    this->first->setPrev(newItem);

    // リストの先頭情報更新
    this->first = newItem;
}

template <class T>
void DoubleLinkedList<T>::deleteContent(T content) {
    if (this->first == NULL) return;

    DoubleLinkedListItem<T>* currentItem = this->first;
    do {
        if (content == currentItem->getContent()) {
            currentItem->deleteThis();

            if (currentItem == this->first) {
                this->first = currentItem->getNext();
            }

            if (currentItem == this->last) {
                this->last = currentItem->getPrev();
            }

            delete currentItem;

            return;
        }
    } while ((currentItem = currentItem->getNext()) != NULL);
}

template <class T>
void DoubleLinkedList<T>::deleteFirst() {
    if (this->first == NULL) return;

    DoubleLinkedListItem<T>* currentItem = this->first;
    this->first = currentItem->getNext();

    currentItem->deleteThis();

    if (currentItem == this->first) {
        this->first = currentItem->getNext();
    }

    if (currentItem == this->last) {
        this->last = currentItem->getPrev();
    }

    delete currentItem;
}

template <class T>
void DoubleLinkedList<T>::deleteLast() {
    if (this->last == NULL) return;

    DoubleLinkedListItem<T>* currentItem = this->last;
    this->last = currentItem->getPrev();

    currentItem->deleteThis();

    if (currentItem == this->first) {
        this->first = currentItem->getNext();
    }

    if (currentItem == this->last) {
        this->last = currentItem->getPrev();
    }

    delete currentItem;
}

template <class T>
void DoubleLinkedList<T>::print() {
    if (this->first == NULL) return;

    bool first = true;

    DoubleLinkedListItem<T>* currentItem = this->first;
    do {
        if (!first) {
            cout << " ";
        }
        cout << currentItem->getContent();
        first = false;
    } while ((currentItem = currentItem->getNext()) != NULL);
    cout << endl;
}

int main(int argc, char* argv[]) {

    // 命令数を取得
    unsigned int n;
    cin >> n;

    DoubleLinkedList<unsigned int>* ll = new DoubleLinkedList<unsigned int>();

    for (int i = 0; i < n; i++) {
        string operation;
        unsigned int key;
        cin >> operation;
        if (operation == "insert") {
            cin >> key;
            ll->insertContent(key);
        } else if (operation == "delete") {
            cin >> key;
            ll->deleteContent(key);
        } else if (operation == "deleteFirst") {
            ll->deleteFirst();
        } else if (operation == "deleteLast") {
            ll->deleteLast();
        }
    }

    ll->print();

    return 0;
}


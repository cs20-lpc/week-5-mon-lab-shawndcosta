template <typename T>
DoublyList<T>::DoublyList()
: header(new Node), trailer(new Node) {
    header->next  = trailer;
    trailer->prev = header;
}

template <typename T>
DoublyList<T>::DoublyList(const DoublyList<T>& copyObj)
: header(new Node), trailer(new Node) {
    copy(copyObj);
}

template <typename T>
DoublyList<T>& DoublyList<T>::operator=(const DoublyList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
DoublyList<T>::~DoublyList() {
    clear();
    delete header;
    delete trailer;
    header = trailer = nullptr;
}

template <typename T>
void DoublyList<T>::append(const T& elem) {
    // TO DO: Implement the code for the append
     Node* newNode = new Node(elem);
    newNode->prev = trailer->prev;
    newNode->next = trailer;

    trailer->prev->next = newNode;
    trailer->prev = newNode;

    ++this->length;
}

template <typename T>
void DoublyList<T>::clear() {
    for (Node* curr = nullptr; header->next != trailer; ) {
        curr = header->next->next;
        delete header->next;
        header->next = curr;
    }

    trailer->prev = header;
    this->length  = 0;
}

template <typename T>
void DoublyList<T>::copy(const DoublyList<T>& copyObj) {
    this->length   = copyObj.length;
    Node* myCurr   = header;
    Node* copyCurr = copyObj.header->next;

    while (copyCurr != copyObj.trailer) {
        Node* n      = new Node(copyCurr->value);
        myCurr->next = n;
        n->prev      = myCurr;
        myCurr       = n;
        copyCurr     = copyCurr->next;
    }

    myCurr->next  = trailer;
    trailer->prev = myCurr;
}

template <typename T>
T DoublyList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw out_of_range("invalid input");
    }

    Node* curr = header->next;
    for (int i = 0; i < position; ++i) {
        curr = curr->next;
    }

    return curr->value;}

template <typename T>
int DoublyList<T>::getLength() const {
    return this->length;
}


template <typename T>
void DoublyList<T>::insert(int position, const T& elem) {
    if (position < 0 || position > this->length) {
        throw out_of_range("invalid input");
    }

    Node* curr = header;
    for (int i = 0; i < position; ++i) {
        curr = curr->next;
    }

    Node* nodeAfter = curr->next;
    Node* newNode = new Node(elem, nodeAfter, curr);

    curr->next = newNode;
    nodeAfter->prev = newNode;

    ++this->length;
}




template <typename T>
bool DoublyList<T>::isEmpty() const {
    return this->length  == 0
        && header->next  == trailer
        && trailer->prev == header;
}

template <typename T>
void DoublyList<T>::remove(int position) {
    // TO DO: Implement code to remove element at given position
    if (position < 0 || position >= this->length) {
        throw out_of_range("remove: Invalid index.");
    }

    Node* curr = header->next;
    for (int i = 0; i < position; ++i) {
        curr = curr->next;
    }

    Node* nodeBefore = curr->prev;
    Node* nodeAfter  = curr->next;

    nodeBefore->next = nodeAfter;
    nodeAfter->prev  = nodeBefore;

    delete curr;
    --this->length;
}

template <typename T>
bool DoublyList<T>::search(const T& elem) const {
    // TO DO: Implement code to search for element
   
    Node* curr = header->next;

    while (curr != trailer) {
        if (curr->value == elem) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

template <typename T>
void DoublyList<T>::replace(int position, const T& elem) {
    // TO DO: Add code for replace method
    if (position < 0 || position >= this->length) {
        throw out_of_range("replace: Invalid index.");
    }

    Node* curr = header->next;
    for (int i = 0; i < position; ++i) {
        curr = curr->next;
    }

    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const DoublyList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename DoublyList<T>::Node* curr = myObj.header->next;
        while (curr != myObj.trailer) {
            outStream << curr->value;
            if (curr->next != myObj.trailer) {
                outStream << " <--> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}

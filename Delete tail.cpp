#include <iostream>
using namespace std;

class Node {
public:
    char id;
    Node* next;
    
    Node() {
        next = NULL; 
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    
    LinkedList() {
        head = tail = NULL;
    }

    void insertToHead(char data) {
        Node* node = new Node();
        node->id = data;
        
        Node* tmp = head;
        head = node;
        node->next = tmp;
    }

    void insertToTail(char data) {
        Node* node = new Node();
        node->id = data;
        node->next = NULL; 
        if (head == NULL) {
            
            head = tail = node;
        } else {
           
            tail->next = node;
            tail = node;
        }
    }

    void printAll() {
        if (head == NULL) {
            cout << "Linked list kosong." << endl;
            return;
        }

        Node* tmp = head;
        while (tmp != NULL) {
            cout << tmp->id << "->";
            tmp = tmp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteTail() {
       
        if (head == NULL) {
            cout << "Linked list kosong. Tidak ada yang perlu dihapus." << endl;
            return;
        }
        
       
        if (head->next == NULL) {
            delete head;
            head = tail = NULL;
            cout << "Menghapus satu-satunya node dalam linked list." << endl;
            return;
        }
        
        
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        
    
        delete tail;
        tail = temp;
        tail->next = NULL;
        
        cout << "Tail node berhasil dihapus." << endl;
    }
};

int main(int argc, char** argv) {
    
    LinkedList* link1 = new LinkedList();
    
    Node* node1 = new Node();
    node1->id = 'A';
    
    link1->head = node1;
    link1->tail = node1;
    
    cout << link1->head->id << endl;
    cout << node1 << endl;
    
    Node* node2 = new Node();
    node2->id = 'B';
    
    link1->tail->next = node2;
    link1->tail = node2;
    
    cout << link1->head->id << endl;
    cout << link1->tail->id << endl;
    
    Node* nodeX = new Node();
    nodeX->id = 'X';
    
    Node* tmp = link1->head;
    nodeX->next = tmp;
    
    cout << link1->head->id << endl;
    cout << link1->tail->id << endl;
    
    link1->insertToHead('Y');
    link1->insertToTail('C');
    
    cout << link1->head->id << endl;
    cout << link1->tail->id << endl;
    
    cout << "Linked list sebelum dihapus: ";
    link1->printAll();
    cout << endl;
    
   
    link1->deleteTail();
    
    cout << "Linked list setelah penghapusan: ";
    link1->printAll();
    cout << endl;

    return 0;
}


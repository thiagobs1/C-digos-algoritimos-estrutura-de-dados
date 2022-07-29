#include <iostream>
using namespace std;

class node{
    public:
    int info;
    node *next;
    node(){
        next = 0;
    }
    node(int el, node *ptr = 0){
        info = el;
        next = ptr;
    }
};

class lista{
    private:
        node *head, *tail;
    public:
        lista(){
            head = tail = 0;
        }
        int isEmpty(){
            return head == 0;
        }
        void addToHead(int el);
        void addToTail(int el);
        void deleteNode(int el);
        void print();
        int countElements(lista l){
            node *tmp;
            int elementos = 0;
            for(tmp = head; tmp != NULL; tmp = tmp->next){
                elementos = elementos + 1;
            }
            return elementos;
        }
        void concat(lista l1, lista l2){
        	int elementos1, elementos2;
        	node *tmp;
//        	int i = 0; fazer loopings com os ponteiros criados //
			elementos1 = countElements(l1);
			elementos2 = countElements(l2);
			if(elementos1 == 0 || elementos2 == 0){
				cout << "As listas devem estar preenchidas";
			} else {
				
				tmp = l2.head; // tmp recebe o head da lista 2
				cout << "\n\n info: " << tmp->info;
				cout<<"\n\n elemento2: " << elementos2;
				while(tmp != NULL){
					l1.addToTail(tmp->info); // o valor do head de l2 será adicionado a tail de l1
					tmp = tmp->next; // tmp recebe o proximo elemento da lista 2 e vai adicionar ao tail de l1
					i++;
				}
				
			}
		}
};

void lista::addToHead(int el){
    head = new node(el, head);
    if(tail == 0){
        tail = head;
    }
};

void lista::addToTail(int el){
    if(tail != 0){
        tail->next = new node(el);
        tail = tail->next; 
    } else {
        head = tail = new node(el);
    }
};

void lista::deleteNode(int el){
	if(head != 0){ // lista não está vazia //
		if(head == tail && el == head->info){
			delete head;
			head = tail = 0;
		}
		else if(el == head->info){
			node *tmp = head;
			head = head->next;
			delete tmp;
		}
		else {
			node *pred, *tmp;
			for(pred = head, tmp = head->next; tmp != 0 && (tmp->info != el); pred = pred->next, tmp = tmp->next);
			if(tmp != 0){
				pred->next = tmp->next; // o nó pred->next irá apontar para o elemnto depois do tmp //
				if(tmp == tail){
					tail = pred;
				} 
				delete tmp;
			}
		}
	}
}

void lista::print(){
	node *p = head;
	while(p != NULL){
		cout << "\n\n p->info=" << p->info; //*p é do tipo node, não retorna o inteiro, por isso deve apontar para info // 
		cout << "\n p=" << p;
		cout << "\n p->next=" << p->next;
		p = p->next;
	}
}

int main()
{
    lista l1, l2;
    l1.addToHead(4);
    l1.addToHead(7);
    l1.addToTail(5);
    l1.addToHead(9);
    l1.print();
    cout << "\n\n Elementos na lista: " << l1.countElements(l1);
    l1.deleteNode(4);
    l1.print();
    
    l2.addToHead(3);
    l2.addToHead(4);
    l2.addToHead(11);
    l2.addToHead(19);
    l1.concat(l1,l2);
    l1.print();
    
    
    
    cout << l1.countElements(l1);
}


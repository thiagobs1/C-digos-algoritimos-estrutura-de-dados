#include <iostream>
using namespace std;

class node{
	public:
		int info;
		node *next;
		
		node(){
			next = 0;
		}
		node(int el, node *pr){
			info = el;
			next = pr;
		}
};

class stack{
	private: 
		node *head;
	public:
		stack(){
			head = 0;
		}
		bool isEmpty(){
			return head = NULL;
		}
		void push(int el);
		void pop();
		void printStack();
		void invert();
		int evenElements();
		int SumEvenOdd(int *s1, int *s2);
		void StackEquals(stack *l1, stack *l2);
		int *EvenElements(int qtd); // para que a função retorne um ponteiro de arrays ela precisa ser do tipo int * //
		int QttEven(){
			node *tmp = head;
			int qtt = 0;
			while(tmp != NULL){
				if(tmp->info % 2 == 0){
					qtt++;
				}
				tmp = tmp->next;
			}
			return qtt;
		}
};

void stack::push(int el){
	head = new node(el, head);
	head->info = el;
}

void stack::pop(){
	if(head != NULL){
		node *tmp = head;
		head = head->next;
		delete tmp;
	}
}

void stack::printStack(){
	node *tmp=head;
	while(tmp != NULL){
		cout << "\n" << tmp->info;
		tmp = tmp->next;
	}
}

void stack::invert(){
	node *tmp = head;
	stack s2;
	while(tmp != NULL){
		s2.push(tmp->info);
		tmp = tmp->next;
	}
	head=s2.head;
}

int stack::evenElements(){
	node *tmp = head;
	int qtd;
	for(tmp = head; tmp != NULL; tmp = tmp->next){
		if(tmp->info % 2 == 0){
			qtd++;
		
		}	
	}
	return qtd;
}

int stack::SumEvenOdd(int *s2, int *s1){
	node *tmp = head;
	*s1 = 0;
	*s2 = 0;
	
	while(tmp != NULL){
		if(tmp->info % 2 == 0){
			*s1 = *s1 + tmp->info;
		
		}
		else if(tmp->info % 2  != 0){
			*s2 = *s2 + tmp->info;
		}
		tmp = tmp->next;
	}
	
}

void stack::StackEquals(stack *l1, stack *l2){
	node *tmp1, *tmp2;
	tmp1 = l1->head; // nesses casos como queremos atribuir ao head de novas pilhas, precisamos fazer a chamada como ponteiros para acessar o head da lista //
	tmp2 = l2->head;
	bool isDiff = false;
	
	while((tmp2 != NULL) && (tmp1 != NULL)){
		if(tmp1->info != tmp2->info){
			isDiff = true;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	if(isDiff == true){
		cout << "\n\n As pilhas sao diferentes";
	}else {
		cout << "\n\n As pilhas sao iguais";
	}
}

//int stack::EvenElements(int qtd, int *pt){
//	int i = 0;
//	node *tmp = head;
//	while(tmp != NULL){
//		if(tmp->info % 2 == 0){
//			*(pt+i) = tmp->info;
//			i++;
//		}
//	    
//		tmp = tmp->next;
//	}
// // como retornar esse ponteiro?
//}

int *stack::EvenElements(int qtd){
	int i = 0;
	int *pt = new int(qtd);
	node *tmp = head;
	while(tmp != NULL){
		if(tmp->info % 2 == 0){
			*(pt+i) = tmp->info;
			i++;
		}
	    
		tmp = tmp->next;
	}
 return pt;// como retornar esse ponteiro?
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	stack s1, s2;
	int soma1, soma2, i = 0;
		
	s1.push(2);
	s1.push(3);
	s1.push(6);
	s1.push(1);
	s1.push(5);
	
	s2.push(2);
	s2.push(3);
	s2.push(6);
	s2.push(1);
	s2.push(5);
	s2.push(2);
	
	int quantidade = s1.evenElements();
	cout << "quantidade: "<<quantidade;
	
	
	int *v = s1.EvenElements(quantidade); 
	while(i < quantidade){
		cout << "\nElemento par:" << *(v+i);
		i++;
	}
	delete v;
	s1.StackEquals(&s1, &s2);
	
	s1.printStack();
	cout << "\n\nQuantidade de pares: " << s1.evenElements();
	s1.SumEvenOdd(&soma2,&soma1);
	
	cout << "\nSoma dos pares: " << soma1;
	cout << "\nSoma dos impares: " << soma2;
	
	s1.invert();
	s1.printStack();
	return 0;
}

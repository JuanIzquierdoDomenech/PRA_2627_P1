#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
	Node<T> *first;
	int n;
public:
	ListLinked() {
		first = nullptr;
		n = 0;
	}

	~ListLinked() {
		while (first != nullptr) {
			Node<T>* aux = first->next;
			delete first;
			first = aux;
		}

		n = 0;		
	}

	T operator[](int pos) {
		if (pos < 0 || pos >= n) {
			throw std::out_of_range("Posicion fuera de rango");
		}

		Node<T>* aux = first;

		for (int i = 0; i < pos; i++) {
			aux = aux->next;
		}

		return aux->data;
	}

	friend std::ostream& operator<<(std::ostream &out, ListLinked<T> &list) {
		out << "List => [" << std::endl;

		for (int i = 0; i < list.n; i++) {
			out << "\t" << list[i] << std::endl;
		}

		out << "]";
		return out;
	}

	void insert(int pos, T e) override {
		if (pos < 0 || pos > n) {
			throw std::out_of_range("Posicion fuera de rango");
		}

		if (pos == 0) {
			first = new Node<T>(e, first);
		} else {
			Node<T>* aux = first;

			for (int i = 0; i < pos - 1; i++) {
				aux = aux->next;
			}

			Node<T>* nuevo = new Node<T>(e, aux->next);
			aux->next = nuevo;
		}

		n++;
	}
	
	void append(T e) override {
		insert(n, e);
	}
	
	void prepend(T e) override {
		insert(0, e);
	}
	
	T remove(int pos) override {
		if (pos < 0 || pos >= n) {
			throw std::out_of_range("Posicion fuera de rango");
		}

		Node<T>* deleted;

		if (pos == 0) {
			deleted = first;
			first = first->next;
		} else {
			Node<T>* aux = first;

			for (int i = 0; i < pos - 1; i++) {
				aux = aux->next;
			}

			deleted = aux->next;
			aux->next = deleted->next;
		}

		T data = deleted->data;
		delete deleted;
		n--;

		return data;
	}
	
	T get(int pos) override {
		if (pos < 0 || pos >= n) {
			throw std::out_of_range("Posicion fuera de rango");
		}

		Node<T>* aux = first;

		for (int i = 0; i < pos; i++) {
			aux = aux->next;
		}

		return aux->data;
	}
	
	int search(T e) override {
		Node<T>* aux = first;
		int pos = 0;

		while (aux != nullptr) {
			if (aux->data == e) {
				return pos;
			}

			aux = aux->next;
			pos++;
		}

		return -1;
	}
	
	bool empty() override {
		return n == 0;
	}
	
	int size() override {
		return n;
	}

};

#endif

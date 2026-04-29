#include <iostream>
#include <vector>

using namespace std;

class MinStack {
private:
	vector<int> elementos;
	vector<int> menorValor;
	int topo;

public:
    explicit MinStack(int cap) {
		// TODO
    	this->menorValor = vector<int>(cap);
    	this->topo = -1;
    	this->elementos = vector<int>(cap);
    }
    
    void push(int val) {
		// TODO
    	if (this->topo == (int)elementos.size() - 1) {
    		cout << "Pilha cheia" << endl;
    		return;
    	}
    	this->topo++;
    	this->elementos[this->topo] = val;

    	if (this->topo == 0) {
    		this->menorValor[this->topo] = val;
    	} else if (val < this->menorValor[this->topo - 1]) {
    		this->menorValor[this->topo] = val;
    	} else {
    		this->menorValor[this->topo] = this->menorValor[this->topo - 1];
    	}
    }
    
    void pop() {
		// TODO
    	if (this->topo == -1) {
    		cout << "Pilha vazia" << endl;
    		return;
    	}

    	this->topo--;
    }
    
    int top() const {
		// TODO
    	if (topo == -1) {
    		cout << "Pilha vazia" << endl;
    	}
    	return this->elementos[this->topo];
    }
    
    int getMin() const {
		// TODO
		return this->menorValor[this->topo];
    }
};

int main() {

    MinStack minStack(10);
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // -3
    minStack.pop();
    cout << minStack.getMin() << endl; // -2
    minStack.push(-10);
    minStack.push(-10);
    cout << minStack.getMin() << endl; // -10
    minStack.pop();
    cout << minStack.getMin() << endl; // -10
    minStack.pop();
    cout << minStack.getMin() << endl; // -2

    return 0;
}
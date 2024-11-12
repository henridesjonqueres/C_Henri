#include <iostream>


struct IntStack10 {
    int tab[10];    
    int i;          

    void init() {
        i = -1;
    }

    void push(int l) {
        if (i == 9) { 
            std::cout << "La pile est pleine, impossible d'empiler.\n";
        }
        else {
            i++;
            tab[i] = l;
        }
    }

    int pop() {
        if (i == -1) { 
            std::cout << "La pile est vide, impossible de dépiler.\n";
            return -1;  
        }
        else {
            return tab[i--]; 
        }
    }

    void print() {
        if (i == -1) { 
            std::cout << "La pile est vide.\n";
        }
        else {
            std::cout << "Contenu de la pile : ";
            for (int j = 0; j <= i; j++) { 
                std::cout << tab[j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    IntStack10 stack;
    stack.init();

    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.print();

    std::cout << "Dépile : " << stack.pop() << std::endl;
    std::cout << "Dépile : " << stack.pop() << std::endl;

    stack.print();

    return 0;
}

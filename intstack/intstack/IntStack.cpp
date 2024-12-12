//#include <iostream>
//
//
//struct IntStack10 {
//    int tab[10];    
//    int i;          
//
//    void init() {
//        i = -1;
//    }
//
//    void push(int l) {
//        if (i == 9) { 
//            std::cout << "La pile est pleine, impossible d'empiler.\n";
//        }
//        else {
//            i++;
//            tab[i] = l;
//        }
//    }
//
//    int pop() {
//        if (i == -1) { 
//            std::cout << "La pile est vide, impossible de dépiler.\n";
//            return -1;  
//        }
//        else {
//            return tab[i--]; 
//        }
//    }
//
//    void print() {
//        if (i == -1) { 
//            std::cout << "La pile est vide.\n";
//        }
//        else {
//            std::cout << "Contenu de la pile : ";
//            for (int j = 0; j <= i; j++) { 
//                std::cout << tab[j] << " ";
//            }
//            std::cout << std::endl;
//        }
//    }
//};

#include <iostream>

struct Shape {
    int x, y;
    Shape() : x(0), y(0) {}
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
    virtual float area() const = 0; 
    virtual ~Shape() {}
};

struct Circle : public Shape {
    int radius;
    Circle(int r) : radius(r) {} 
    float area() const override {
        return 3.14159f * radius * radius;
    }
};

struct Square : public Shape {
    int side;
    Square(int s) : side(s) {} 
    float area() const override {
        return side * side;
    }
};

struct IntStack 
{
    Shape** stack;  
    int i;         
    int size;      

    void init(int n) {
        stack = new Shape * [n]; 
        i = -1;                
        size = n;
    }

    void desinit() {
        for (int j = 0; j <= i; j++) {
            delete stack[j];
        }
        delete[] stack;
        stack = nullptr;
    }

    void push(Shape* shape) {
        if (i == size - 1) {
            std::cout << "La pile est pleine, impossible d'empiler.\n";
        }
        else {
            stack[++i] = shape;
        }
    }

    Shape* pop() {
        if (i == -1) {
            std::cout << "La pile est vide, impossible de dépiler.\n";
            return nullptr;
        }
        else {
            return stack[i--];
        }
    }

    void print() {
        if (i == -1) {
            std::cout << "La pile est vide.\n";
        }
        else {
            std::cout << "Contenu de la pile :\n";
            for (int j = 0; j <= i; j++) {
                std::cout << " - Aire : " << stack[j]->area() << std::endl;
            }
        }
    }
};

int main() {
    IntStack stack;
    stack.init(4);

    
    stack.push(new Circle(20));     
    stack.push(new Square(10));     

    
    stack.stack[0]->move(100, 100);
    stack.stack[1]->move(50, 50);  

    stack.print();

 
    Shape* s = stack.pop();
    std::cout << "Dépilé : Aire = " << s->area() << std::endl;
    delete s;

    stack.print();


    stack.desinit();

    return 0;
}

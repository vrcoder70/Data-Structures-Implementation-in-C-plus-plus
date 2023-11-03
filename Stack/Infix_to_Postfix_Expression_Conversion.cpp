#include<iostream> // Include the input-output stream library for C++.

using namespace std; // Use the standard C++ namespace.

class Expresion{
    int Top, Capacity; // Declare variables to keep track of the top of the stack and the stack's capacity.
    char *String; // Declare a character array to store the expression.
public:
    Expresion* Create(); // Function to create an expression stack.
    void Push(Expresion* S, char s); // Function to push a character onto the expression stack.
    char Pop(Expresion* S); // Function to pop a character from the expression stack.
    void View(Expresion* S); // Function to view the characters in the expression stack.
    int Isempty(Expresion* S); // Function to check if the expression stack is empty.
};

int Expresion::Isempty(Expresion* S){
    if(S->Top == -1)
        return 0; // The stack is empty.
    else
        return 1; // The stack is not empty.
}

Expresion* Expresion::Create(){
    Expresion *S; // Declare a pointer to an expression stack.
    S = new Expresion; // Create a new expression stack object.
    cout << "Capacity:- ";
    cin >> S->Capacity; // Prompt the user to enter the stack's capacity and store it in the expression stack object.
    S->String = new char[S->Capacity]; // Allocate memory for the expression array.
    S->Top = -1; // Initialize the top of the expression stack to -1 (empty).
    return (S); // Return the created expression stack object.
}

void Expresion::Push(Expresion* S, char s){
    S->Top++; // Increment the top to prepare for the push operation.
    if(S->Top >= S->Capacity - 1){
        cout << "Stack is Full" << endl; // Stack is full, cannot push more characters.
        return;
    }
    else{
        S->String[S->Top] = s; // Push the character onto the expression stack.
    }
}

char Expresion::Pop(Expresion* S){
    char s = S->String[S->Top]; // Copy the character being popped.
    S->Top--; // Decrement the top to perform the pop operation.
    return (s); // Return the popped character.
}

void Expresion::View(Expresion* S){
    int N = 0;
    while(N <= S->Top){
        cout << S->String[N] << " "; // Print the characters in the expression stack.
        N++;
    }
    cout << endl;
}

int menu(){
    cout << "1: Enter" << endl << "2: Print" << endl << "3: Exit:- ";
    int i;
    cin >> i; // Prompt the user to enter a menu choice and store it in i.
    return (i); // Return the menu choice.
}

int main(){
    Expresion *E, *O, *In, Obj1, Obj2, Obj3; // Declare expression stack objects.
    In = Obj3.Create(); // Create an input expression stack.
    E = Obj1.Create(); // Create a postfix expression stack.
    O = Obj2.Create(); // Create an operator stack.

    while(1){
        switch(menu()){
        case 1:
            char s;
            cout << "Enter Data:- ";
            cin >> s; // Prompt the user to enter a character and store it in s.

            if(s >= 65 && s <= 90){ // Check if the character is an uppercase letter (A-Z).
                Obj3.Push(In, s); // Push the character onto the input expression stack.
                Obj1.Push(E, s); // Push the character onto the postfix expression stack.
            }
            else if(s == 43 || s == 45){ // Check if the character is '+' or '-'.
                if(!Obj2.Isempty(O))
                    Obj2.Push(O, s);
                else{
                    char T;
                    T = Obj2.Pop(O);
                    while(T != 40 && Obj2.Isempty(O)){
                        Obj1.Push(E, T);
                        T = Obj2.Pop(O);
                    }
                    if(T == 40)
                        Obj1.Push(O, T);
                    if(!Obj2.Isempty(O))
                        Obj1.Push(E, T);
                    Obj2.Push(O, s);
                }
                Obj3.Push(In, s);
            }
            else if(s == 42 || s == 47){ // Check if the character is '*' or '/'.
                Obj3.Push(In, s);
                if(!Obj2.Isempty(O))
                    Obj2.Push(O, s);
                else{
                    char Te = Obj2.Pop(O);
                    if(Te == 42 || Te == 47){
                        Obj1.Push(E, Te);
                        Obj2.Push(O, s);
                    }
                    else{
                        Obj2.Push(O, Te);
                        Obj2.Push(O, s);
                    }
                }
            }
            else{
                Obj3.Push(In, s);
                if(s == 40)
                    Obj2.Push(O, s);
                else{
                    char Temp;
                    Temp = Obj2.Pop(O);
                    while(Temp != 40){
                        Obj1.Push(E, Temp);
                        Temp = Obj2.Pop(O);
                    }
                }
            }
            break;

        case 2:
            char t;
            while(Obj2.Isempty(O)){
                t = Obj2.Pop(O);
                Obj1.Push(E, t);
            }
            cout << "Infix:- ";
            Obj3.View(In);
            cout << "Postfix:- ";
            Obj1.View(E);
            break;

        case 3:
            return 0; // Exit the program.

        default:
            cout << "Invalid" << endl; // Invalid menu choice.
        }
    }
}

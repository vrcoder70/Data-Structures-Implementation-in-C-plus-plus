#include<iostream> // Include the input-output stream library for C++.

using namespace std; // Use the standard C++ namespace.

class Expresion{
    int Top, Capacity; // Declare variables to keep track of the top of the stack and the stack's capacity.
    char *String; // Declare a character array to store the expression.
public:
    int ReturnTop(Expresion* S); // Function to return the top of the stack.
    Expresion* Create(int Cap); // Function to create an expression stack with a specified capacity.
    void Push(Expresion* S, char s); // Function to push a character onto the expression stack.
    char Pop(Expresion* S); // Function to pop a character from the expression stack.
    void View(Expresion* S); // Function to view the characters in the expression stack.
    int Isempty(Expresion* S); // Function to check if the expression stack is empty.
};

int Expresion::ReturnTop(Expresion* S){
    return (S->Top); // Return the current top of the expression stack.
}

int Expresion::Isempty(Expresion* S){
    if(S->Top == -1)
        return 0; // The stack is empty.
    else
        return 1; // The stack is not empty.
}

Expresion* Expresion::Create(int Cap){
    Expresion *S; // Declare a pointer to an expression stack.
    S = new Expresion; // Create a new expression stack object.
    S->Capacity = Cap; // Set the stack's capacity to the specified value.
    S->String = new char[S->Capacity]; // Allocate memory for the expression array.
    S->Top = -1; // Initialize the top of the expression stack to -1 (empty).
    return (S); // Return the created expression stack object.
}

void Expresion::Push(Expresion* S, char s){
    S->Top++; // Increment the top to prepare for the push operation.
    if(S->Top >= S->Capacity){
        cout << "Stack is Full" << endl; // Stack is full, cannot push more characters.
        S->Top--;
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

int main(){
    Expresion *T, *E, *O, *In, *R, Obj; // Declare expression stack objects.
    char S, s; int i, N; // Declare character variables and integer variables.

    cout << "Enter Capacity:- ";
    cin >> N; // Prompt the user to enter the stack's capacity and store it in N.

    T = Obj.Create(N); E = Obj.Create(N); O = Obj.Create(N); In = Obj.Create(N); R = Obj.Create(N);
    // Create expression stacks for various purposes.

    cout << "Enter 'Z' when finished" << endl;
    cout << "Enter Infix Expression:- ";

    for(i = 0; i < N; i++){
        cin >> S; // Prompt the user to enter a character and store it in S.

        if(S == 90){
            i--;
            break;
        }
        else if(S == 40){
            S = 41;
            Obj.Push(T, S);
        }
        else if(S == 41){
            S = 40;
            Obj.Push(T, S);
        }
        else
            Obj.Push(T, S);
    }
    // Read and process the input infix expression, converting some characters for proper handling.

    for(int j = 0; j <= i; j++){
        s = Obj.Pop(T);
        if(s >= 65 && s <= 90){
            Obj.Push(In, s);
            Obj.Push(E, s);
        }
        else if(s == 43 || s == 45){
            if(!Obj.Isempty(O))
                Obj.Push(O, s);
            else{
                char T;
                T = Obj.Pop(O);
                while(T != 40 && Obj.Isempty(O)){
                    Obj.Push(E, T);
                    T = Obj.Pop(O);
                }
                if(T == 40)
                    Obj.Push(O, T);
                if(!Obj.Isempty(O))
                    Obj.Push(E, T);
                Obj.Push(O, s);
            }
            Obj.Push(In, s);
        }
        else if(s == 42 || s == 47){
            Obj.Push(In, s);
            if(!Obj.Isempty(O))
                Obj.Push(O, s);
            else{
                char Te = Obj.Pop(O);
                if(Te == 42 || Te == 47){
                    Obj.Push(E, Te);
                    Obj.Push(O, s);
                }
                else{
                    Obj.Push(O, Te);
                    Obj.Push(O, s);
                }
            }
        }
        else{
            Obj.Push(In, s);
            if(s == 40)
                Obj.Push(O, s);
            else{
                char Temp;
                Temp = Obj.Pop(O);
                while(Temp != 40){
                    Obj.Push(E, Temp);
                    Temp = Obj.Pop(O);
                }
            }
        }
    }
    // Process the infix expression and convert it to postfix form.

    char t;
    while(Obj.Isempty(O)){
        t = Obj.Pop(O);
        Obj.Push(E, t);
    }
    // Clear the operator stack and push any remaining operators onto the postfix expression stack.

    cout << "Infix:- ";
    Obj.View(In);
    cout << endl;

    Obj.View(E);
    cout << endl;

    for(int j = 0; j <= i; j++){
        s = Obj.Pop(E);
        Obj.Push(R, s);
    }
    // Reverse the postfix expression to obtain the prefix expression.

    cout << "Prefix:- ";
    Obj.View(R);
    // Display the resulting prefix expression.
}
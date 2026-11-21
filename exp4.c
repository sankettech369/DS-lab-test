
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int x) {
    stack[++top] = x;
}

// Pop operation
int pop() {
    return stack[top--];
}

int main() {
    char postfix[MAX];
    int i, a, b, result;
    char ch;

    printf("Enter the postfix expression: ");
    scanf("%99s", postfix);

    for(i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        // If operand, push into stack
        if(isdigit(ch)) {
            push(ch - '0');
        }

        // If operator, perform operation
        else {
            b = pop();
            a = pop();

            switch(ch) {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;
            }

            push(result);
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}

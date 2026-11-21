
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    switch(x) {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '(':
            return 0;
    }
    return -1;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char ch;

    printf("Enter the infix expression: ");
    scanf("%99s", infix);

    for(i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        switch(ch) {
            case '+':
            case '-':
            case '*':
            case '/':
                while(top != -1 && priority(stack[top]) >= priority(ch)) {
                    postfix[j++] = pop();
                }
                push(ch);
                break;

            case '(':
                push(ch);
                break;

            case ')':
                while(top != -1 && stack[top] != '(') {
                    postfix[j++] = pop();
                }
                if(top != -1)
                    pop();
                break;

            default:
                postfix[j++] = ch;
        }
    }

    while(top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("The postfix expression is: %s", postfix);

    return 0;
}

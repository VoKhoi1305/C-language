#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Hàm kiểm tra xem một ký tự có phải là toán hạng hay không
int isOperand(char ch) {
    return (ch >= '1' && ch <= '9') || (ch >= 'A' && ch <= 'Z');
}

// Hàm kiểm tra xem một ký tự có phải là toán tử hay không
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Hàm lấy độ ưu tiên của toán tử
int getPriority(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

// Hàm chuyển đổi biểu thức trung tố sang hậu tố
void infixToPostfix(char *infix, char *postfix) {
    int i, j;
    int top = -1;
    char stack[MAX_SIZE];
    char ch;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isOperand(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top != -1 && stack[top] != '(') {
                printf("Invalid infix expression\n");
                return;
            } else {
                top--;
            }
        } else if (isOperator(ch)) {
            while (top != -1 && getPriority(stack[top]) > getPriority(ch)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];


    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        printf("%c ",postfix[i]);
    }
    return 0;
}

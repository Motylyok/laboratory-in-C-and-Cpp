#include <stdio.h>

int CalculateExpression(int a, int b, char operation) {
    if (operation == '-') return a - b;
    if (operation == '+') return a + b;
    if (operation == '*') return a * b;
    if (operation == '/') return a / b;
    if (operation == '%') return a % b;
}

int Calculate(char *expression) {
    int xPos = 0, equalPos = 0;

    for (int i = 0; i < 5; i++) {
        if (expression[i] == 'x') {
            xPos = i;
            break;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (expression[i] == '=') {
            equalPos = i;
            break;
        }
    }

    if (xPos == 0 && equalPos == 1)
        return CalculateExpression(expression[2] - '0', expression[4] - '0', expression[3]);

    if (xPos == 2 && equalPos == 1) {
        int a = expression[0] - '0', b = expression[4] - '0';
        char operation = expression[3];

        switch (operation) {
            case '-':
                return CalculateExpression(a, b, '+');
            case '+':
                return CalculateExpression(a, b, '-');
            case '*':
                return CalculateExpression(a, b, '/');
            case '/':
                return CalculateExpression(a, b, '*');
            case '%':
                return CalculateExpression(a, b, '+');
        }
    }

    if (xPos == 4 && equalPos == 1) {
        int a = expression[0] - '0', b = expression[2] - '0';
        char operation = expression[3];

        switch (operation) {
            case '-':
                return CalculateExpression(a, b, '/');
            case '+':
                return CalculateExpression(a, b, '-');
            case '*':
                return CalculateExpression(a, b, '/');
            case '/':
                return CalculateExpression(b, a, '/');
            case '%':
                return CalculateExpression(b, a, '-');
        }
    }

    if (xPos == 4 && equalPos == 3)
        return CalculateExpression(expression[0] - '0', expression[2] - '0', expression[1]);

    if (xPos == 2 && equalPos == 3) {
        int a = expression[0] - '0', b = expression[4] - '0';
        char operation = expression[1];

        switch (operation) {
            case '-':
                return CalculateExpression(a, b, '-');
            case '+':
                return CalculateExpression(b, a, '-');
            case '*':
                return CalculateExpression(b, a, '/');
            case '/':
                return CalculateExpression(a, b, '/');
            case '%':
                return CalculateExpression(a, b, '-');
        }
    }

    if (xPos == 0 && equalPos == 3) {
        int a = expression[4] - '0', b = expression[2] - '0';
        char operation = expression[1];

        switch (operation) {
            case '-':
                return CalculateExpression(a, b, '+');
            case '+':
                return CalculateExpression(a, b, '-');
            case '*':
                return CalculateExpression(a, b, '/');
            case '/':
                return CalculateExpression(a, b, '*');
            case '%':
                return CalculateExpression(a, b, '+');
        }
    }

    return 0;
}

int main(void) {
    char *expressions[] =
            {
                    "6/5=x", "6*2=x", "6=x+1", "5=x-2", "8=x/4",
                    "4=x*2", "x=3+1", "x=6-1", "x=8/2", "x=3*2",
                    "6%5=x", "6%2=x", "6=x%1", "5=x%2", "8=x%4",
                    "4=1+x", "8=9-x", "3=6/x", "8=4*x","x%2=1",
                    "x-1=5", "x/2=3", "x*3=6", "3+x=4","6-x=2",
                    "9/x=1", "2*x=6", "1+2=x", "2-1=x",
            };

    int len = sizeof(expressions) / sizeof(char *);
    for (int i = 0; i < len; ++i)
        printf("%s  %d\n", expressions[i], Calculate(expressions[i]));

    return 0;
}

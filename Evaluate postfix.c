#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define SIZE 20

struct stacks
{
    int top;
    float data[SIZE];
};

typedef struct stacks STACK;

void push(STACK *s, float item)
{
    s->data[++(s->top)] = item;
}

float pop(STACK *s)
{
    return s->data[(s->top)--];
}

float compute(float oper1, char symbol, float oper2)
{
    switch (symbol)
    {
        case '+':
            return oper1 + oper2;

        case '-':
            return oper1 - oper2;

        case '*':
            return oper1 * oper2;

        case '/':
            return oper1 / oper2;

        case '^':
            return pow(oper1, oper2);

        default:
            printf("Invalid operator\n");
            exit(1);
    }
}

float evalpostfix(STACK *s, char postfix[SIZE])
{
    int i;
    char symbol;
    float oper1, oper2, res;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        symbol = postfix[i];

        if (isdigit(symbol))
        {
            push(s, symbol - '0');
        }
        else
        {
            oper2 = pop(s);
            oper1 = pop(s);

            res = compute(oper1, symbol, oper2);
            push(s, res);
        }
    }

    return pop(s);
}

int main()
{
    char postfix[SIZE];
    STACK s;
    float ans;

    s.top = -1;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    ans = evalpostfix(&s, postfix);

    printf("The final result = %.2f\n", ans);

    return 0;
}


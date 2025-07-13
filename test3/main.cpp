#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>

#define MAX_SIZE 20
#define MAX_LEN 32

char szQueue[MAX_SIZE][MAX_LEN];
char szStack[MAX_SIZE][MAX_LEN];

struct Stack {
    char data[MAX_SIZE][MAX_LEN];
    int top;
};

struct Queue {
    char data[MAX_SIZE][MAX_LEN];
    int front;
    int rear;
};

void InitQueue(Queue* q);
int InQueue(Queue* q, const char* str);
int OutQueue(Queue* q, char* str);

void InitStack(Stack* s);
int Push(Stack* s, const char* str);
int Pop(Stack* s, char* str);
int Top(Stack* s, char* str);
int IsEmpty(Stack* s);

int Priority(const char* op);
float Compute(float a, float b, const char* op);

int main() {
    Queue exprQueue;
    Stack opStack, valStack;

    InitQueue(&exprQueue);
    InitStack(&opStack);
    InitStack(&valStack);

    char input[256];
    std::cout << "输入算术表达式（以分号结尾）: ";
    std::cin.getline(input, 256);

    int i = 0;
    while (input[i]) {
        if (isdigit(input[i]) || input[i] == '.') {
            char num[MAX_LEN] = {0};
            int j = 0;
            while (isdigit(input[i]) || input[i] == '.') {
                num[j++] = input[i++];
            }
            InQueue(&exprQueue, num);
        } else if (strchr("+-*/^;", input[i])) {
            char op[2] = {input[i], 0};
            InQueue(&exprQueue, op);
            i++;
        } else {
            i++; // 忽略空格或非法字符
        }
    }

    char token[MAX_LEN];
    while (OutQueue(&exprQueue, token)) {
        if (isdigit(token[0])) {
            Push(&valStack, token);
        } else if (strcmp(token, ";") == 0) {
            char op[MAX_LEN];
            while (!IsEmpty(&opStack)) {
                Pop(&opStack, op);
                char b_str[MAX_LEN], a_str[MAX_LEN];
                Pop(&valStack, b_str);
                Pop(&valStack, a_str);
                float a = atof(a_str);
                float b = atof(b_str);
                float res = Compute(a, b, op);
                char res_str[MAX_LEN];
                sprintf(res_str, "%f", res);
                Push(&valStack, res_str);
            }
        } else {
            char top_op[MAX_LEN];
            while (!IsEmpty(&opStack)) {
                Top(&opStack, top_op);
                if (Priority(top_op) >= Priority(token)) {
                    Pop(&opStack, top_op);
                    char b_str[MAX_LEN], a_str[MAX_LEN];
                    Pop(&valStack, b_str);
                    Pop(&valStack, a_str);
                    float a = atof(a_str);
                    float b = atof(b_str);
                    float res = Compute(a, b, top_op);
                    char res_str[MAX_LEN];
                    sprintf(res_str, "%f", res);
                    Push(&valStack, res_str);
                } else {
                    break;
                }
            }
            Push(&opStack, token);
        }
    }

    char result[MAX_LEN];
    Pop(&valStack, result);
    std::cout << "表达式结果为: " << result << std::endl;
    return 0;
}

void InitQueue(Queue* q) {
    q->front = q->rear = 0;
}

int InQueue(Queue* q, const char* str) {
    if ((q->rear + 1) % MAX_SIZE == q->front)
        return 0;
    strcpy(q->data[q->rear], str);
    q->rear = (q->rear + 1) % MAX_SIZE;
    return 1;
}

int OutQueue(Queue* q, char* str) {
    if (q->front == q->rear)
        return 0;
    strcpy(str, q->data[q->front]);
    q->front = (q->front + 1) % MAX_SIZE;
    return 1;
}

void InitStack(Stack* s) {
    s->top = -1;
}

int Push(Stack* s, const char* str) {
    if (s->top >= MAX_SIZE - 1)
        return 0;
    strcpy(s->data[++s->top], str);
    return 1;
}

int Pop(Stack* s, char* str) {
    if (s->top < 0)
        return 0;
    strcpy(str, s->data[s->top--]);
    return 1;
}

int Top(Stack* s, char* str) {
    if (s->top < 0)
        return 0;
    strcpy(str, s->data[s->top]);
    return 1;
}

int IsEmpty(Stack* s) {
    return s->top < 0;
}

int Priority(const char* op) {
    if (strcmp(op, "^") == 0) return 3;
    if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0) return 2;
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return 1;
    return 0;
}

float Compute(float a, float b, const char* op) {
    if (strcmp(op, "+") == 0) return a + b;
    if (strcmp(op, "-") == 0) return a - b;
    if (strcmp(op, "*") == 0) return a * b;
    if (strcmp(op, "/") == 0) return a / b;
    if (strcmp(op, "^") == 0) return pow(a, b);
    return 0;
}

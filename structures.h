#define MAX_SIZE 10
#define RISE_V_STACK 10
#define POISON 1984
struct Stack        //���� ����������� ��������
{
    long long int canary1 = 0;
    long long int* canary2 = nullptr;
    int capacity = 0;
    int ssize = 0;
    int *data = nullptr;
};

//�������� ������� ��� �����

void StackCtr (Stack *sstack);

void StackPush(Stack *sstack, int value);

int StackPop(Stack *sstack);

void StackDctor(Stack* sstack);

//������ �����

enum ERRORS_NAMES
{
    NULL_STACK_POINTER = 1,
    STACK_UNDERFLOW,
    NEGATIVE_CAPACITY,
    STACK_OVERFLOW,
    NULL_DATA_POINTER,
    NULL_CANARI_POINTER,
    CANARY1_DAMAGE,
    CANARY2_DAMAGE
};

int StackOK (Stack *sstack);
void StackDump (Stack *sstack);
void ErrorPrint(int ERROR);
void StackPrint(Stack *sstack);

void FullofPoison (Stack* sstack, int start, int ennd);

//��� V1 of CPU

int command_compare(char *data1, int length1, char *data2, int length2);

int inf_proc (Stack *S, char user_ch);

void CPU (int COMMAND_NUM, int user_number, Stack *S);

void User_Work(Stack *S);

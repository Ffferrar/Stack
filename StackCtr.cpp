#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

void FullofPoison (Stack* sstack, int start, int ennd)
{
    for (int i = start; i < ennd+1; i++)         //+1 ������ ��� ���� ������ ��������� ��� ������ ��� start==end
    {
        sstack->data[i] = POISON;
    }

}

void StackCtr (Stack* sstack)
{

    //memset(sstack->data, 0, sizeof(sstack->data)); segfault
    sstack->capacity = MAX_SIZE;
    sstack->data = (int*) calloc (MAX_SIZE + 2 * (sizeof(long long int) / sizeof(int)), sizeof(int));  //������ ������� ��������?
    sstack->ssize = 0;


    //������ ���������

    sstack->canary2 = (long long int*) (sstack->data);
    sstack->data = sstack->data + (sizeof(long long int) / sizeof(int));

    FullofPoison (sstack, 0, MAX_SIZE);

    sstack->canary1 = 0xDED27BED;
    *sstack->canary2 = 0xBED27DED;

    if(StackOK(sstack) != 0)
    {
        StackDump(sstack);
        exit(0);
    }
}

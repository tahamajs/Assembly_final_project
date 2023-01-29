#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ZERO 0
#define ONE 1
#define MAX_NUMBER 2147483647
#define MIN_NUMBER -2147483648

// global list for registers
int s[32] = {}; // defult 0 for all
FILE *file;
int lineNumbers;
int LineNumber();
int status[8] = {}; // for status register

char *bradcast1(char *name);
char *bradcast2(char *name);
char *bradcast3(char *name);
char *bradcast4(char *name);
int input(char *name);
int STRtoINT(char *name);
void LoadFile();
int jump(int step);
int checkOneBionary(int number);
void check(int regNumber);
void save();
void overflowSub(int reg1, int reg2);
void overflowAdd(int reg1, int reg2);
int argERR(int x, int y, int z);
int argERR1(int x, int y, int z);
int argERR2(int x, int y, int z);

int main()
{
    char inputTemp[100];
    printf("Enter File Name : ");
    scanf("%s", inputTemp);
    if (strcmp(inputTemp, "in.txt") == 0)
    {
        file = fopen("in.txt", "r");
        lineNumbers = LineNumber();
        printf("");
        LoadFile();
        fclose(file);
    }
    else
    {
        printf("Wrong File");
    }
}

/* this function is dvide name to three names and return secend part */
char *bradcast1(char *name)
{
    char *name1;
    int len = strlen(name) + ONE;

    name1 = (char *)malloc(len * sizeof(char));

    int i = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        name1[i] = name[i];
        i++;
    }

    if (strlen(name1) == ZERO)
    {
        return NULL;
    }
    else
    {
        name1 = (char *)realloc(name1, (strlen(name1) + ONE) * sizeof(char));
        return name1;
    }
}

/* this function is dvide name to three names and return secend part */
char *bradcast2(char *name)
{
    char *name2;
    int len = strlen(name) + ONE;

    name2 = (char *)malloc(len * sizeof(char));

    int i = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        i++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }

    int j = ZERO;
    while (name[i] != ' ' && name[i] != '\0' && name[i] != ',')
    {
        name2[j] = name[i];
        i++;
        j++;
    }

    if (strlen(name2) == ZERO)
    {
        return NULL;
    }
    else
    {
        name2 = (char *)realloc(name2, (strlen(name2) + ONE) * sizeof(char));
        return name2;
    }
}

/* this function is dvide name to three names and return secend part */
char *bradcast3(char *name)
{
    char *name3;
    int len = strlen(name) + ONE;
    name3 = (char *)malloc(len * sizeof(char));

    int i = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        i++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }

    int j = ZERO;
    while (name[i] != ' ' && name[i] != '\0' && name[i] != ',')
    {
        i++;
        j++;
    }
    if (name[i] == ',')
    {
        i++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }

    j = ZERO;
    while (name[i] != ' ' && name[i] != '\0' && name[i] != ',')
    {
        name3[j] = name[i];
        i++;
        j++;
    }

    if (strlen(name3) == ZERO)
    {
        return NULL;
    }
    else
    {
        name3 = (char *)realloc(name3, (strlen(name3) + ONE) * sizeof(char));
        return name3;
    }
}

/* this function is dvide name to three names and return secend part */
char *bradcast4(char *name)
{
    char *name4;
    int len = strlen(name) + ONE;

    name4 = (char *)malloc(len * sizeof(char));

    int i = ZERO;
    while (name[i] != ' ' && name[i] != '\0')
    {
        i++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }

    int j = ZERO;
    while (name[i] != ' ' && name[i] != '\0' && name[i] != ',')
    {
        i++;
        j++;
    }
    if (name[i] == ',')
    {
        i++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }

    j = ZERO;
    while (name[i] != ' ' && name[i] != '\0' && name[i] != ',')
    {
        i++;
        j++;
    }
    if (name[i] == ',')
    {
        i++;
    }
    while (name[i] == ' ' && name[i] != '\0')
    {
        i++;
    }

    j = ZERO;
    while (name[i] != ' ' && name[i] != '\0' && name[i] != ',')
    {
        name4[j] = name[i];
        i++;
        j++;
    }

    if (strlen(name4) == ZERO)
    {
        return NULL;
    }
    else
    {
        name4 = (char *)realloc(name4, (strlen(name4) + ONE) * sizeof(char));
        return name4;
    }
}

// this function is for get input for each prosses
int input(char *name)
{

    // devide each names
    char *name1 = bradcast1(name);
    char *name2 = bradcast2(name);
    char *name3 = bradcast3(name);
    char *name4 = bradcast4(name);
    int x, y, z;
    // for each instructs
    if (strcmp(name1, "ADD") == ZERO)
    {
        if ((sscanf(name, "ADD S%d, S%d, S%d", &x, &y, &z)) != 0 && argERR(x, y, z) == 1)
        {
            s[STRtoINT(name2)] = s[STRtoINT(name3)] + s[STRtoINT(name4)];
            check(STRtoINT(name2));
            overflowAdd(STRtoINT(name3), STRtoINT(name4));
            return 1;
        }
        else
        {
            printf("Wrong Input \n");
            return 1;
        }
    }

    else if (strcmp(name1, "SUB") == ZERO)
    {
        if ((sscanf(name, "SUB S%d, S%d, S%d", &x, &y, &z)) != 0 && argERR(x, y, z) == 1)
        {

            s[STRtoINT(name2)] = s[STRtoINT(name3)] - s[STRtoINT(name4)];
            check(STRtoINT(name2));
            overflowSub(STRtoINT(name3), STRtoINT(name4));
            return 1;
        }
        else
        {
            printf("Wrong Input \n");
            return 1;
        }
    }

    else if (strcmp(name1, "AND") == ZERO)
    {
        if ((sscanf(name, "AND S%d, S%d, S%d", &x, &y, &z)) != 0 && argERR(x, y, z) == 1)
        {
            s[STRtoINT(name2)] = s[STRtoINT(name3)] & s[STRtoINT(name4)];
            check(STRtoINT(name2));
            return 1;
        }
        else
        {
            printf("Wrong Input \n");
            return 1;
        }
    }

    else if (strcmp(name1, "XOR") == ZERO)
    {
        if ((sscanf(name, "XOR S%d, S%d, S%d", &x, &y, &z)) != 0 && argERR(x, y, z) == 1)
        {

            s[STRtoINT(name2)] = (s[STRtoINT(name3)]) ^ (s[STRtoINT(name4)]);
            check(STRtoINT(name2));
            return 1;
        }
        else
        {
            printf("Wrong Input \n");
            return 1;
        }
    }

    else if (strcmp(name1, "OR") == ZERO)
    {
        if ((sscanf(name, "OR S%d, S%d, S%d", &x, &y, &z)) != 0 && argERR(x, y, z) == 1)
        {
            s[STRtoINT(name2)] = s[STRtoINT(name3)] | s[STRtoINT(name4)];
            check(STRtoINT(name2));
            return 1;
        }
        else
        {
            printf("Wrong Input \n");
            return 1;
        }
    }

    else if (strcmp(name1, "ADDI") == ZERO)
    {
        if ((sscanf(name, "ADDI S%d, S%d, %d", &x, &y, &z)) != 0 && argERR1(x, y, z) == 1)
        {
            s[STRtoINT(name2)] = s[STRtoINT(name3)] + atoi(name4);
            check(STRtoINT(name2));
            return 1;
        }
        else
        {
            printf("Wrong Input \n");
            return 1;
        }
    }

    else if (strcmp(name1, "SUBI") == ZERO)
    {
        if ((sscanf(name, "SUBI S%d, S%d, %d", &x, &y, &z)) != 0 && argERR1(x, y, z) == 1)
        {
            s[STRtoINT(name2)] = s[STRtoINT(name3)] - atoi(name4);
            check(STRtoINT(name2));
            overflowSub(STRtoINT(name3), atoi(name4));
            return 1;
        }
        else
        {
            printf("Wrong Input \n");
            return 1;
        }
    }

    else if (strcmp(name1, "ANDI") == ZERO)
    {
        if ((sscanf(name, "ANDI S%d, S%d, %d", &x, &y, &z)) != 0 && argERR1(x, y, z) == 1)
        {
            s[STRtoINT(name2)] = s[STRtoINT(name3)] & atoi(name4);
            check(STRtoINT(name2));
            overflowAdd(STRtoINT(name3), atoi(name4));
            return 1;
        }
        else
        {
            printf("Wrong Input \n");
            return 1;
        }
    }

    else if (strcmp(name1, "XORI") == ZERO)
    {
        if ((sscanf(name, "XORI S%d, S%d, %d", &x, &y, &z)) != 0 && argERR1(x, y, z) == 1)
        {
            s[STRtoINT(name2)] = s[STRtoINT(name3)] ^ atoi(name4);
            check(STRtoINT(name2));
            return 1;
        }
        else
        {
            printf("Wrong Input \n");
            return 1;
        }
    }

    else if (strcmp(name1, "ORI") == ZERO)
    {
        if ((sscanf(name, "ORI S%d, S%d, %d", &x, &y, &z)) != 0 && argERR1(x, y, z) == 1)
        {
            s[STRtoINT(name2)] = s[STRtoINT(name3)] | atoi(name4);
            check(STRtoINT(name2));
            return 1;
        }
        else
        {
            printf("Wrong Input \n");
            return 1;
        }
    }

    else if (strcmp(name1, "MOV") == ZERO)
    {
        if (name3[0] == 'S')
        {
            if ((sscanf(name, "MOV S%d, S%d", &x, &y)) != 0 && argERR1(x, y, 0) == 1)
            {

                s[STRtoINT(name2)] = s[STRtoINT(name3)];
                return 1;
            }
            else
            {

                printf("Wrong Input \n");
                return 1;
            }
        }
        else
        {
            if ((sscanf(name, "MOV S%d, %d", &x, &y)) != 0 && argERR2(x, y, 0) == 1)
            {

                s[STRtoINT(name2)] = atoi(name3);
                return 1;
            }
            else
            {
                printf("Wrong Input \n");
                return 1;
            }
        }
    }

    else if (strcmp(name1, "SWP") == ZERO)
    {
        if ((sscanf(name, "SWP S%d, S%d", &x, &y)) != 0 && argERR1(x, y, 0) == 1)
        {
            int temp;
            temp = s[STRtoINT(name2)];
            s[STRtoINT(name2)] = s[STRtoINT(name3)];
            s[STRtoINT(name3)] = temp;
            return 1;
        }
        else
        {
            printf("Wrong Input \n");
            return 1;
        }
    }

    else if (strcmp(name1, "DUMP_REGS") == ZERO)
    {
        for (int i = 0; i < 32; i++)
        {
            printf("%d ", s[i]);
        }
        printf("\n");
        for (int i = 0; i < 8; i++)
        {
            printf("%d ", status[i]);
        }
        printf("\n");
        return 1;
    }
    else if (strcmp(name1, "DUMP_REGS_F") == ZERO)
    {
        save();
        return 1;
    }
    else if (strcmp(name1, "INPUT") == ZERO)
    {
        char itemp[7];
        printf("Input intiger : \n");
        scanf("%s", itemp);
        s[0] = atoi(itemp);
        return 1;
    }
    else if (strcmp(name1, "OUTPUT") == ZERO)
    {
        printf("%d \n", s[0]);
        return 1;
    }
    else if (strcmp(name1, "JMP") == ZERO)
    {

        if (jump(atoi(name2)))
        {
            return 1;
        }
        else
        {
            printf("incurrect input");
            return 1;
        }
    }
    else if (strcmp(name1, "EXIT") == ZERO)
    {
        return 1;
    }
    return 0;
}

// to convert string to intiger
int STRtoINT(char *name)
{
    if (name[0] == 'S')
    {
        if (strlen(name) == 2)
        {
            return name[1] - '0';
        }
        else
        {
            return (name[2] - '0') + ((name[1] - '0') * 10);
        }
    }
    else
    {
        return -1;
    }
}

void LoadFile()
{
    char c;
    int count , temp;
    char name[100];
    while (c != EOF)
    {
        c = fgetc(file);
        count = 0;
        while ((c) != '\n' && (c) != EOF)
        {
            name[count] = c;
            count++;
            c = fgetc(file);
        }
        name[count] = '\0';
        if (strlen(name) != 0)
        {
            temp = input(name);
            if (temp == 0)
            {
                printf("Incorrect Input \n");
            }
        }
    }
}

int jump(int step)
{
    if (step > lineNumbers)
    {
        return 0;
    }

    char c;
    for (int i = 0; i < step - 1; i++)
    {
        c = fgetc(file);
        while ((c) != '\n' && (c) != EOF)
        {
            c = fgetc(file);
        }
    }
    return 1;
}

int LineNumber()
{
    char c;
    int count = 0, i = 0;
    char name[100];
    while (c != EOF)
    {

        c = fgetc(file);
        count = 0;
        while ((c) != '\n' && (c) != EOF)
        {
            name[count] = (char)c;
            count++;
            c = fgetc(file);
        }
        name[count] = '\0';
        if (strlen(name) != 0)
        {
            i++;
        }
    }
    fseek(file, 0, SEEK_SET);
    return i;
}

// this function is for set status of cpu
void check(int regNumber)
{
    // for check zero flag
    if (s[regNumber] == 0)
    {
        status[1] = 1;
    }
    else
    {
        status[1] = 0;
    }

    // for check signflag
    if (s[regNumber] < 0)
    {
        status[2] = 1;
    }
    else
    {
        status[2] = 0;
    }

    // for check ones in bionary numbers
    if (checkOneBionary(s[regNumber]))
    {
        status[0] = 1;
    }
    else
    {
        status[0] = 0;
    }
}

// for check ones in bionary number
int checkOneBionary(int number)
{
    int cnt = 0;
    while (number != 0)
    {
        if (number % 2 == 1)
        {
            cnt++;
        }
        number /= 2;
    }

    if (cnt % 2 == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void save()
{
    FILE *sfile = fopen("regs.txt", "w");
    for (int i = 0; i < 32; i++)
    {
        fprintf(sfile, "%d ", s[i]);
    }
    fclose(sfile);
}

void overflowAdd(int reg1, int reg2)
{
    if (s[reg1] + reg2 > MAX_NUMBER && s[reg1] + s[reg2] < MIN_NUMBER)
    {
        status[5] = 1;
    }
    else
    {
        status[5] = 0;
    }
}

void overflowSub(int reg1, int reg2)
{
    if (s[reg1] - reg2 > MAX_NUMBER && s[reg1] - s[reg2] < MIN_NUMBER)
    {
        status[5] = 1;
    }
    else
    {
        status[5] = 0;
    }
}

// for check error
int argERR(int x, int y, int z)
{
    if (x < 32 && x >= 0 && y < 32 && y >= 0 && z < 32 && z >= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// for check error
int argERR1(int x, int y, int z)
{
    if (x < 32 && x >= 0 && y < 32 && y >= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int argERR2(int x, int y, int z)
{
    if (x < 32 && x >= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
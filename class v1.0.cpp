/*
 * @Author: RocksonLee 
 * @Date: 2020-09-22 22:04:06 
 * @Last Modified by: RocksonLee
 * @Last Modified time: 2020-09-25 13:59:02
 */
#include <bits/stdc++.h>
#include <io.h>
using namespace std;
int Map[10][10];
bool BoolMap[10][10], tempbool, tempmodebool;
char tempchar;
int i = 1, temp1, ERRORi, temp2, count1, COUNT = 1, num, tempmode, tempx;
enum index
{
    warn
};
struct a
{
    bool check[9][9];
    bool deset[70];
    bool ok;
} student[70];
struct ERROR
{
    string mode;
    int num;
} ERROR[10000];
bool check(a x, int i1, int i2)
{
        if (!x.deset[Map[i1 - 1][i2 - 1]])
            if (!x.deset[Map[i1 - 1][i2]])
                if (!x.deset[Map[i1 - 1][i2 + 1]])
                    if (!x.deset[Map[i1][i2 - 1]])
                        if (!x.deset[Map[i1][i2 + 1]])
                            if (!x.deset[Map[i1 + 1][i2 - 1]])
                                if (!x.deset[Map[i1 + 1][i2]])
                                    if (!x.deset[Map[i1 + 1][i2 + 1]])
                                        return true;
    return false;
}

void example();

void info()
{
    // setlocale(LC_ALL, "Chinese-simplified");
    printf("===============================\n"
           "     Rand 排序小工具            \n"
           "            V 1.0 ( fixed )    \n"
           "                  By RocksonLee\n"
           "===============================\n"
           "WARNING：JS 2021届4班专用\n"
           "===============================\n"
           "使用方法：\n"
           "1、你的每一行输入都是“模式”+“座号”+“数值”（eg：s 1 3）\n"
           "2、在输入完成后，再加多一行只有数字‘0’，以便程序开始运行\n"
           "3、模式有2种， s 和 r\n"
           "4、s代表的是不让座号为n的人在第m行\n"
           " （举个例子，“s 26 5”，意思是，不让26号在第5行）\n"
           "5、r代表的是不让座号为n的人和座号为m的人紧邻\n"
           " （举个例子，“r 26 27”，意思是，不让26号在27号周围）\n"
           "6、由于程序的不完善，存在bug，如果没有结果导出，或者出现“ERROR”这样的字眼，请将输入的数据告知作者，以便重现\n"
           "===============================\n"
           "键入数据：\n");
    if (_access("test.true", 0) == 0)
    {
        freopen("Example().txt", "w", stdout);
        example();
        //freopen("help().txt", "w", stdout);
        freopen("CON", "w", stdout);
    }
    freopen("CON", "r", stdin);
    if (_access("in.txt", 0) == 0)
        freopen("in.txt", "r", stdin);
    // setlocale(LC_ALL, "C");
}
int main()
{
    // int n;
    // scanf("%d", &n);
    // srand(time(NULL));
    // for (int ii = 0; ii < n; ii++)
    // {
    //     i++;
    //     scanf("%d %d", &temp1, &temp2);
    //     if (temp1 >= 9 || temp2 >= 9 || temp1 <= 0 | temp2 <= 0)
    //     {
    //         cout << "ERROR CODE = S" << i << endl;
    //     }
    //     else
    //         for (int i2 = 1; i2 < 9; i2++)
    //         {
    //             student[temp1].check[temp2][i2] = true;
    //         }
    // }
    info();
    while (1 == 1)
    {
        tempchar = getchar();
        if (tempchar >= '0' && tempchar <= '9')
        {
            if (tempbool)
                tempx = tempchar - '0' + tempx * 10;
            else
            {
                tempx = tempchar - '0';
                tempbool = true;
            }
        }
        if (tempmodebool == false && (tempchar == 's' || tempchar == 'r' || tempchar == '0'))
        {
            tempmodebool = true;
            tempmode = tempchar;
            if (tempmode == '0')
                break;
        }
        if (tempchar == ' ' || tempchar == '\n')
        {
            if (temp1 == 0 && tempbool)
            {
                temp1 = tempx;
            }
            else if (temp2 == 0 && tempbool)
            {
                temp2 = tempx;
            }
            tempbool = false;
        }
        if (tempchar == '\n')
        {
            if (tempmodebool = false)
            {
                ERROR[ERRORi].mode = "A";
                ERROR[ERRORi].num = i;
                ERRORi++;
                break;
            }
            tempmodebool = false;
            i++;
            if (tempmode == 's')
            {
                if (temp1 >= 65 || temp2 >= 9 || temp1 <= 0 | temp2 <= 0)
                {
                    ERROR[ERRORi].mode = "s";
                    ERROR[ERRORi].num = i;
                    ERRORi++;
                }
                else
                    for (int i1 = 1; i1 < 9; i1++)
                    {
                        student[temp1].check[temp2][i1] = true;
                    }
            }
            if (tempmode == 'r')
            {
                if (temp1 >= 65 || temp2 >= 65 || temp1 <= 0 | temp2 <= 0)
                {
                    ERROR[ERRORi].mode = "r";
                    ERROR[ERRORi].num = i;
                    ERRORi++;
                }
                student[temp1].deset[temp2] = true;
                student[temp2].deset[temp1] = true;
            }
            tempmode = ' ';
            temp1 = 0;
            temp2 = 0;
        }
    }
    bool checkbool;
    for (int i1 = 0; i1 <= 64; i1++)
    {
        checkbool = true;
        for (int i2 = 0; i2 <= 8; i2++)
        {
            for (int i3 = 0; i3 <= 8; i3++)
            {
                if (!student[i1].check[i2][i3])
                    checkbool = false;
            }
        }
        if (checkbool)
        {
            ERROR[ERRORi].mode = "Check";
            ERROR[ERRORi].num = i1;
            ERRORi++;
        }
    }

    while (1 == 1)
    {
        cout << "try " << COUNT << " times" << endl;
        COUNT++;
        try
        {
            for (int i1 = 1; i1 <= 8; i1++)
            {
                for (int i2 = 1; i2 <= 8; i2++)
                {
                    for (int i3 = 1; i3 <= 64; i3++)
                    {
                        if (student[i3].check[i1][i2] == false && !student[i3].ok && check(student[i3], i1, i2))
                            count1++;
                    }
                    if (count1 == 0)
                    {
                        throw warn;
                    }
                    num = rand() % count1 + 1;
                    for (int i3 = 0, i4 = 1; i4 <= 64; i4++)
                    {
                        if (student[i4].check[i1][i2] == false && !student[i4].ok && check(student[i4], i1, i2))
                            i3++;
                        if (num == i3 && student[i4].check[i1][i2] == false && !student[i4].ok && check(student[i4], i1, i2))
                        {
                            Map[i1][i2] = i4;
                            student[i4].ok = true;
                        }
                    }
                    count1 = 0;
                }
            }
            cout << "finish!" << endl;
            break;
        }
        catch (index error)
        {
            if (error == warn)
            {
                for (int i1 = 1; i1 < 9; i1++)
                {
                    for (int i2 = 1; i2 < 9; i2++)
                    {
                        Map[i1][i2] = 0;
                        student[(i1 - 1) * 8 + i2].ok = false;
                    }
                }
            }
        }
    }
    for (int i1 = 1; i1 <= 8; i1++)
    {
        for (int i2 = 1; i2 <= 8; i2++)
        {
            if (Map[i1][i2] < 10)
                cout << "0";
            cout << Map[i1][i2] << " ";
        }
        cout << endl;
    }
    if (ERRORi != 0)
    {
        printf("ERROR:(Inform the author)\n");
        for (int i = 0; i < ERRORi; i++)
        {
            printf("ERROR Code = ");
            cout << ERROR[i].mode << ERROR[i].num << endl;
        }
    }
    system("pause");
    freopen("out.txt", "w", stdout);
    for (int i1 = 1; i1 <= 8; i1++)
    {
        for (int i2 = 1; i2 <= 8; i2++)
        {
            if (Map[i1][i2] < 10)
                cout << "0";
            cout << Map[i1][i2] << " ";
        }
        cout << endl;
    }
    if (ERRORi != 0)
    {
        printf("ERROR:(Inform the author)\n");
        for (int i = 0; i < ERRORi; i++)
        {
            printf("ERROR Code = ");
            cout << ERROR[i].mode << ERROR[i].num << endl;
        }
    }
    return 0;
}

void example()
{
    printf(
        "s 1 1\n"
        "s 1 2\n"
        "s 1 3\n"
        "s 1 4\n"
        "s 1 6\n"
        "s 1 7\n"
        "s 1 8\n"
        "r 1 2\n"
        "r 1 3\n"
        "r 1 4\n"
        "r 1 5\n"
        "r 1 6\n"
        "r 1 8\n"
        "r 1 9\n"
        "r 1 10\n"
        "r 1 11\n"
        "r 1 12\n"
        "r 1 13\n"
        "r 1 14\n"
        "r 1 15\n"
        "r 1 16\n"
        "r 1 17\n"
        "r 1 18\n"
        "r 1 19\n"
        "r 1 20\n"
        "r 1 21\n"
        "r 1 22\n"
        "r 1 23\n"
        "r 1 24\n"
        "r 1 25\n"
        "r 1 27\n"
        "r 1 28\n"
        "r 1 29\n"
        "r 1 30\n"
        "r 1 31\n"
        "r 1 32\n"
        "r 1 33\n"
        "r 1 34\n"
        "r 1 35\n"
        "r 1 36\n"
        "r 1 38\n"
        "r 1 39\n"
        "r 1 40\n"
        "r 1 41\n"
        "r 1 42\n"
        "r 1 43\n"
        "r 1 44\n"
        "r 1 47\n"
        "r 1 48\n"
        "r 1 49\n"
        "r 1 50\n"
        "r 1 51\n"
        "r 1 52\n"
        "r 1 54\n"
        "r 1 55\n"
        "r 1 56\n"
        "r 1 62\n"
        "r 1 63\n"
        "r 1 64\n"
        "r 1 57\n"
        "r 1 58\n"
        "r 1 59\n"
        "0\n");
}
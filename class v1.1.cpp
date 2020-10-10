#include <bits/stdc++.h>
#include <io.h>
using namespace std;
const int Class_num = 64;
enum index
{
    warn
};
struct a
{
    bool check[9][9];
    bool deset[70];
    bool ok;
    int i;
} student[70];
struct ERROR
{
    string mode;
    int num;
} ERROR[10000];
struct temp
{
    bool check(char x)
    {
        char example[5] = {'s', 'r', '0', 'y'};
        for (int i = 0; i < 4; i++)
        {
            if (x == example[i])
                return true;
        }
        return false;
    }
    int i;
    int x;
    int num1;
    int num2;
    int num3;
    char ch;
    bool modebool;
    bool numbool;
    char mode;
} temp;

int ybool[70];
int finish[10][10];
int Map[10][10];
int recheck[9][9];
int ERRORi;

void example();
void info();
bool check(a x, int i1, int i2);

void in();
void out();

int main()
{
#ifndef test
    info();
#endif

    if (_access("example.txt", 0) == -1)
    {
        freopen("example.txt", "w", stdout);
        example();
        return 0;
    }
    if (_access("in.txt", 4) == 0)
    {
        freopen("in.txt", "r", stdin);
        in();
        freopen("CON", "r", stdin);
    }
    in();
    int COUNT = 0;
    int num = 0, count1 = 0;
    srand(time(NULL));
    for (int i = 0; i <= 65; i++)
    {
        student[i].i = i;
    }
    while (1 == 1)
    {
        COUNT++;
        try
        {
            for (int i1 = 1; i1 <= 8; i1++)
                for (int i2 = 1; i2 <= 8; i2++)
                    Map[i1][i2] = finish[i1][i2];

            for (int i1 = 1; i1 <= 8; i1++)
            {
                for (int i2 = 1; i2 <= 8; i2++)
                {
                    if (Map[i1][i2] != 0)
                        continue;
                    for (int i3 = 1; i3 <= 64; i3++)
                    {
                        if (check(student[i3], i1, i2))
                            count1++;
                    }
                    if (count1 == 0)
                    {
                        throw warn;
                    }
                    num = rand() % count1 + 1;
                    for (int i3 = 1, i4 = 0; i3 <= 64; i3++)
                    {
                        if (check(student[i3], i1, i2))
                            i4++;
                        if (num == i4 && check(student[i3], i1, i2))
                        {
                            Map[i1][i2] = i3;
                            student[i3].ok = true;
                        }
                    }
                    count1 = 0;
                }
            }
#ifndef test
            cout << "try " << COUNT << " times" << endl;
            cout << "finish!" << endl;
#endif
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
#ifndef test
        if (COUNT > 100)
            if (COUNT % 100 == 0)
                cout << "try " << COUNT << " times" << endl;
            else
                ;
        else
            cout << "try " << COUNT << " times" << endl;
#endif
    }
    out();
#ifndef test
    system("pause");
    freopen("out.txt", "w", stdout);
#endif
    out();
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
        "y 1 4 5\n"
        "0\n");
}

void info()
{
    printf("===============================\n"
           "     Rand 排序小工具            \n"
           "            V 1.1              \n"
           "                  By RocksonLee\n"
           "===============================\n"
           "WARNING：JS 2021届4班专用\n"
           "===============================\n"
           "使用方法：\n"
           "1、你的每一行输入都是“模式”+“座号”+“数值”（eg：s 1 3）\n"
           "2、在输入完成后，再加多一行只有数字‘0’，以便程序开始运行\n"
           "3、模式有3种， s 和 r , y\n"
           "4、s代表的是不让座号为n的人在第m行\n"
           " （举个例子，“s 26 5”，意思是，不让26号在第5行）\n"
           "5、r代表的是不让座号为n的人和座号为m的人紧邻\n"
           " （举个例子，“r 26 27”，意思是，不让26号在27号周围）\n"
           "6、y代表的是让座号为n的人坐在坐标 (x,y) 的位置\n"
           " （举个例子，“y 1 4 5”, 意思是，让1号坐在第4行第5列的座位上）\n"
           "当然这样限定座位有点问题，所以，大可直接用s 1 1，s 1 2，重复使用，这样可以限定在某几行\n"
           "7、由于程序的不完善，存在bug，如果没有结果导出，或者出现“ERROR”这样的字眼，请将输入的数据告知作者，以便重现\n"
           "===============================\n"
           "键入数据：\n");
}

bool check(a x, int i1, int i2)
{
    bool xbool;
    if (!x.check[i1][i2] && !x.ok && !ybool[x.i])
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

void in()
{
    while (1 == 1)
    {
        temp.ch = getchar();
        if (temp.modebool == false && temp.check(temp.ch))
        {
            temp.modebool = true;
            temp.mode = temp.ch;
            if (temp.mode == '0')
                break;
        }
        if (temp.ch >= '0' && temp.ch <= '9')
        {
            if (temp.numbool)
                temp.x = temp.ch - '0' + temp.x * 10;
            else
            {
                temp.x = temp.ch - '0';
                temp.numbool = true;
            }
        }
        if (temp.ch == ' ' || temp.ch == '\n')
        {
            if (temp.num1 == 0 && temp.numbool)
            {
                temp.num1 = temp.x;
            }
            else if (temp.num2 == 0 && temp.numbool)
            {
                temp.num2 = temp.x;
            }
            else if (temp.num3 == 0 && temp.numbool)
            {
                temp.num3 = temp.x;
            }
            temp.numbool = false;
        }
        if (temp.ch == '\n')
        {
            if (temp.modebool == false)
            {
                ERROR[ERRORi].mode = "A";
                ERROR[ERRORi].num = temp.i;
                ERRORi++;
                break;
            }
            temp.modebool = false;
            temp.i++;
            if (temp.mode == 's')
            {
                if (temp.num1 > Class_num || temp.num2 >= 9 || temp.num1 <= 0 || temp.num2 <= 0)
                {
                    ERROR[ERRORi].mode = "s";
                    ERROR[ERRORi].num = temp.i;
                    ERRORi++;
                }
                else
                {
                    for (int i1 = 1; i1 < 9; i1++)
                    {
                        student[temp.num1].check[temp.num2][i1] = true;
                    }
                }
            }
            if (temp.mode == 'r')
            {
                if (temp.num1 > Class_num || temp.num2 > Class_num || temp.num1 <= 0 || temp.num2 <= 0)
                {
                    ERROR[ERRORi].mode = "r";
                    ERROR[ERRORi].num = temp.i;
                    ERRORi++;
                }
                else
                {
                    student[temp.num1].deset[temp.num2] = true;
                    student[temp.num2].deset[temp.num1] = true;
                }
            }
            if (temp.mode == 'y')
            {
                if (temp.num1 > Class_num || temp.num2 > Class_num || temp.num1 <= 0 || temp.num2 <= 0)
                {
                    ERROR[ERRORi].mode = "y";
                    ERROR[ERRORi].num = temp.i;
                    ERRORi++;
                }
                else
                {
                    ybool[temp.num1] = true;
                    finish[temp.num2][temp.num3] = temp.num1;
                }
            }
            temp.mode = ' ';
            temp.num1 = 0;
            temp.num2 = 0;
            temp.num3 = 0;
        }
    }
}

void out()
{
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
}

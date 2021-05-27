#include <windows.h>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <iostream>
using namespace std;

class kasa {
private:
    string Department;
    struct tovar {
        string name;
        float price;
        int count;
    } tovars[5];
    float sum;
    float nds;
    float sumnds;
    struct tm {
        int tm_sec; //
        int tm_min; //
        int tm_hour; //
    } time;
    struct dt {
        int dt_day; //
        int dt_month; //
        int dt_year; //
    } date;

public:
    kasa()
    {
        Department = "food";
        tovars[1].count = 0;
        tovars[1].name = "milk";
        tovars[1].price = 20;
        tovars[2].count = 0;
        tovars[2].name = "brod";
        tovars[2].price = 10;
        tovars[3].count = 0;
        tovars[3].name = "apple";
        tovars[3].price = 30;
        tovars[4].count = 0;
        tovars[4].name = "banana";
        tovars[4].price = 35;
        tovars[0].count = 0;
        tovars[0].name = "meat";
        tovars[0].price = 100;
    }

    void set_department(string name)
    {
        Department = name;
    }

    void set_tovar(int num, string name, int price)
    {
        tovars[num].name = name;
        tovars[num].price = price;
    }
    void menu()
    {
        int count;
        int num;
        printf("выберите номер товара \n");

        for (int i = 0; i < 5; i++) {
            cout << i + 1 << " " << tovars[i].name << "..........." << tovars[i].price << endl;
        }
        do {
            cout<<"введите номер товара - "<<endl;
            cin >> num;
            cout<<"введите количество товара - "<<endl;
            cin >> count;
            tovars[num - 1].count += count;
            int ans;
            printf("Для продолжения нажмите любую букву,цифру. Если хотите выйти, нажмите 0\n");
            cin >> ans;
            if (ans == 0)
                break;
        }
        //проверка на нум
        while (count != 0);
    }
    float sumtovar(int num)
    {return (tovars[num].count > 0) ? (tovars[num].price * tovars[num].count) : 0; }
    

    void print()
    {
        cout << Department << endl;
        cout << " товар " << " цена " << " кол " << " НДС " << endl;
        double total = 0;               // Общая стоимость
        for (int i = 0; i < 5; i++)
        {
            if (tovars[i].count > 0)
                printf("%8s %.2f %10d %.2f \n", tovars[i].name.c_str(), tovars[i].price, tovars[i].count, sumtovar(i));
            total += sumtovar(i);       // суммирует все
        }
        cout << "Общая стоимость: " << total << " руб." << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    float allsum()
    {
        float naz = 0;
        for (int i = 0; i < 5; i++) {
            naz += sumtovar(i);
        }
        sum = naz;
        return naz;
    }
    float get_nds()
    {
        nds = 0.2 * allsum();
        return nds;
    }
    float get_sumnds()
    {
        sumnds = 1.2 * allsum();
        return sumnds;
    }
};

int main()
{
    setlocale(LC_CTYPE, "rus");
    kasa fort;
    fort.menu();
    fort.print();

    SYSTEMTIME st;
    GetLocalTime(&st);
    cout << st.wHour << ":" << st.wMinute << ":" << st.wDay << ":" << st.wMonth << ":" << st.wYear;
    cout << endl;
    system("pause");

    return 0;
}
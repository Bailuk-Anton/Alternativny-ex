#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include<cmath>
#include <cstring>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

char num[11] = "0123456789";

void SetCursorPosition(short x, short y) {
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x , y };
    SetConsoleCursorPosition(output, pos);
};
void commandW(unsigned short* column) {
    (*column)--;
    SetCursorPosition(9, *column);
    cout << ">";
    SetCursorPosition(9, *column + 1);
    cout << " ";
    SetCursorPosition(0, 0);
}
void commandS(unsigned short* column) {
    (*column)++;
    SetCursorPosition(9, *column - 1);
    cout << " ";
    SetCursorPosition(9, *column);
    cout << ">";
    SetCursorPosition(0, 0);
}

unsigned long ProverkaNum() {
    string S = "";
    vector<char>Str;
    char com = ' ';
    int ii = 0;
    while ((com != (char)13)) {
        com = _getch();
        if ((com == '0') && (ii == 0)) { com = ' '; }
        if (com == (char)8) { printf("\b \b"); Str.pop_back(); ii--; }
        if (ii == 17) { break; }
        for (int i = 0; i < 10; i++) {
            if (com == num[i]) { cout << com; Str.push_back(com); ii++; break; }
        }
    }
    for (int i = 0; i < Str.size(); i++) {
        S += Str[i];
    }
    if (S == "") { S = "1"; }
    unsigned long n = atoi(S.c_str());
    return n;
}
unsigned long NOD(unsigned long a, unsigned long b) {
    if (a < b) {
        swap(a, b);
    }
    while (a % b != 0) {
        a = a % b;
        swap(a, b);
    }
    return b;
}
unsigned long Ferma_for_AKS() {
    SetCursorPosition(40, 3);
    cout << "тест по Малой Теореме Ферма";
    unsigned long a, p;
    cout << endl << "Введите основание, по которому будет проверяться число(основание должно быть меньше проверяемого числа): ";
    a = ProverkaNum();
    cout <<endl<< "Введите число на проверку:";
    p = ProverkaNum();
    cout << endl;
    if (a >= p) {
        if (p == 1) { cout << p << " простое число ( малая теорема Ферма ) "; cout << endl; return p; }
        if (p != 1) { a = p - 1; cout << "Основание заменено на " << a << endl; }
    }
    unsigned long anum = a;
    for (int i = 2; i < p; i++) {
        anum = anum * a;
        if (anum > p) {
            while (anum > p) {
                anum -= p;
            }
        }
    }
    if (anum == 1) { cout<<endl << p << " псевдопростое число по основанию " << a <<" (малая теорема Ферма)" << endl; return p; }
    if (anum != 1) { cout<<endl << p << " не является псевдопростым по основанию ( малая теорема Ферма )"; return 0; }
    cout << endl << endl << "Для продолжения нажмите \'e\'";
}

void Static(unsigned short str) {
    system("cls");
    SetCursorPosition(40, 0);
    cout << "Семь алгоритмов проверки простых чисел";
    SetCursorPosition(10, 5);
    cout << "Решето Эратосфена";
    SetCursorPosition(10, 6);
    cout << "Малая теорема Ферма";
    SetCursorPosition(10, 7);
    cout << "Критерий Вильсона";
    SetCursorPosition(10, 8);
    cout << "Числа Кармайкла";
    SetCursorPosition(10, 9);
    cout << "Тест Соловея - Штрассена";
    SetCursorPosition(10, 10);
    cout << "Тест Рабина - Миллера";
    SetCursorPosition(10, 11);
    cout << "Полиминальный тест";
    SetCursorPosition(9, str);
    cout << ">";
    SetCursorPosition(70, 5);
    cout << "\'w\' - двмжение курсора вверх";
    SetCursorPosition(70, 6);
    cout << "\'s\' - двмжение курсора вниз";
    SetCursorPosition(70, 7);
    cout << "Enter - перейти в тест";
    SetCursorPosition(70, 8);
    cout << "\'q\' - выход";
}
void inf_Eratos() {
    system("cls");
    SetCursorPosition(40, 0);
    cout << "Решето Эратосфена";
    SetCursorPosition(120, 1);
    cout << "Название «решето» метод получил потому, что во времена Эратосфена писали ";
    SetCursorPosition(120, 2);
    cout << "числа на дощечке, покрытой воском, и прокалывали дырочки в тех местах, где ";
    SetCursorPosition(120, 3);
    cout << "были написаны составные числа. Поэтому дощечка являлась неким подобием ";
    SetCursorPosition(120, 4);
    cout << "решета, через которое «просеивались» все составные числа, а оставались ";
    SetCursorPosition(120, 5);
    cout << "только числа простые.";
    SetCursorPosition(120, 6);
    cout << "Программа выводит все простые числа из интервала выбранного пользователем.";
    SetCursorPosition(0,1);  
    cout << "Введите интервал, на котором будут вывдены простые числа(максимальная разница между числами 94000). "<<endl<<endl;
    cout << "Начальная граница интервала: ";
    cout << endl << "Конечная граница интервала: ";
}
void inf_Ferma() {
    system("cls");
    SetCursorPosition(40, 0);
    cout << "тест по Малой Теореме Ферма";
    SetCursorPosition(120, 1);
    cout << "Малая теорема Ферма утверждает, что если n простое, то выполняет";
    SetCursorPosition(120, 2);
    cout << "условие: при всех  а принадлежащих {2,3,...,n-1}  имеет место быть сравнение ";
    SetCursorPosition(140, 3);
    cout << " a^(n-1) сравнимо с 1 по модулю n.";
    SetCursorPosition(120, 4);
    cout << "Из теоремы следует, что если вышеприведенное сравнение не выполнено хотя  ";
    SetCursorPosition(120, 5);
    cout << "бы для одного а, то n - составное. Данный алгоритм является необходимым, но ";
    SetCursorPosition(120, 6);
    cout << "не достаточным. ";
    SetCursorPosition(120, 6);
    cout << "Программа выведет псевдопростое число по основанию а.";
}
void inf_Wilson() {
    system("cls");
    SetCursorPosition(40, 0);
    cout << "Критерий Вильсона"<<endl;   
    SetCursorPosition(120, 1);
    cout << "Теорема. Для любого n следующие условия эквивалентны: ";
    SetCursorPosition(120, 2);
    cout << "а) n – простое";
    SetCursorPosition(120, 3);
    cout << "б) (n-1)! сравнимо с -1 по модулю n";
    SetCursorPosition(120, 4);
    cout << "Результат работы алгоритма ответ на вопрос:";
    SetCursorPosition(120, 5);
    cout << "Является ли введеное число простым?";
}
void inf_Carmaikl() {
    system("cls");
    SetCursorPosition(40, 0);
    cout << "Числа Кармайкла";
    SetCursorPosition(120, 1);
    cout << "а) если n mod p^2: = 0, p>1, то n не является числом Кармайкла ";
    SetCursorPosition(120, 2);
    cout << "б) если  n=p1*p2…*pk, 𝑝_𝑖≠𝑝_𝑘 , то n – число Кармайкла в том и только в том случае,";
    SetCursorPosition(120, 3);
    cout << "когда при всех i выполнено условие (n-1)%(pi-1) = 0";
    SetCursorPosition(120, 4);
    cout << "в) n = p1*p2*...*pk – число Кармайкла, то k>2. ";
    
}
void inf_S_Sh() {
    system("cls");
    SetCursorPosition(40, 0);
    cout << "тест Соловея - Штрассена" << endl;
    SetCursorPosition(120, 1);
    cout << "Если a^((n-1)/2) сравнимо с числом якоби (a/n) по модулю n,";
    SetCursorPosition(120, 2);
    cout << "то число n c вероятностью 1 - 2^(-k) простое.";
    SetCursorPosition(120, 3);
    cout << "Число k - это количество раундов проверки числа.";
    SetCursorPosition(120, 4);
    cout << "Результат работы алгоритма это значение вероятности простоты числа.";
}
void inf_R_M() {
    system("cls");
    SetCursorPosition(40, 0);
    cout << "тест Рабина - Миллера";
    SetCursorPosition(120, 1);
    cout << "Пользователь выбирает число для проверки n,параметр точности k.";
    SetCursorPosition(120, 2);
    cout << "Во время работы программы пользователь будет";
    SetCursorPosition(120, 3);
    cout << "выбирать число a принадлежащее {2,..,n-1}";
    SetCursorPosition(120, 4);
    cout << "С помощью формулы n-1 = 2^s * t получаем переменные,";
    SetCursorPosition(120, 5);
    cout << "с которыми в дальнейшем будем работать.";
    SetCursorPosition(120, 6);
    cout << "Программа будет сравнивать числа a^t,a^(2*t),..,a^(2^(s-1)) по модулю n.";
    SetCursorPosition(120, 7);
    cout << "Если при сравнении программа встречает -1, то с точностью 1-4^k число простое.";
}
void inf_AKS() {
    system("cls");
    SetCursorPosition(40, 0);
    cout << "Полимиальный тест" << endl;
    SetCursorPosition(120, 1);
    cout << "Пользователь выбирает число для проверки n,затем с помощью.";
    SetCursorPosition(120, 2);
    cout << "малой теоремы Ферма оно проверяется на псевдопростоту";
    SetCursorPosition(120, 3);
    cout << "Если малая теорема Ферма выполнена, то алгоритм приступает ко второй части,";
    SetCursorPosition(120, 4);
    cout << "а именно полиномиальному тесту.";
    SetCursorPosition(120, 5);
    cout << "В нем программа будет рассматривать сочетания от 1 до (n-1)/2.";
    SetCursorPosition(120, 6);
    cout << "Если все соетания нацело делятся на n, то со 100% вероятностью число n - простое.";
}

void Eratos() { 
    inf_Eratos();
    unsigned long n,n1,ii=0,prime_cnt=0;
    long proverka;
    SetCursorPosition(29, 3);
    n = ProverkaNum();
    SetCursorPosition(28, 4);
    n1 = ProverkaNum();
    SetCursorPosition(29, 4); cout << "                            ";
    SetCursorPosition(28, 4); cout << n1;
    if (n > n1) { n1 = n; }
    if (n == n1) { 
        proverka = n1 - 94000;
        if (proverka < 0) { n = 1; }
        else { n = proverka; }
        SetCursorPosition(29, 3);
        for (int i = 0; i < 18; i++) {
            cout << " ";
        }
        SetCursorPosition(29, 3);
        cout << n;
        SetCursorPosition(28, 4);
        for (int i = 0; i < 18; i++) {
            cout << " ";
        }
        SetCursorPosition(28, 4);
        cout << n1;
    }
    if ((n1 - n) > 94000) {
        n = n1 - 94000;       
        SetCursorPosition(29, 3);
        for (int i = 0; i < 18; i++) {
        cout << " ";
        }
    SetCursorPosition(29, 3);
    cout << n;
    }
    SetCursorPosition(0, 6);
    vector<char> prime(n1 + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n1; ++i)
        if (prime[i])
            if (i * 1ll * i <= n1)
                for (int j = i * i; j <= n1; j += i)
                    prime[j] = false;
    for (int i = n; i <= n1; ++i)
        if (prime[i] == true) {
            cout << i <<endl;
            prime_cnt++;
        }
    char h = ' ';
    cout << endl << endl << "Для продолжения нажмите \'e\'";
    SetCursorPosition(0, 5);
    if (prime_cnt % 10 == 1) {
        cout << "Найдено " << prime_cnt << " простое число";
    }
    if (prime_cnt % 10 != 1) {
        cout << "Найдено " << prime_cnt << " простых чисел";
    }
    prime.clear();
    while ((h != 'e')) {
        h = _getch();
        if (h == 'e') { h = 'e'; break; }
    }
}
void Ferma() {
    inf_Ferma();
    SetCursorPosition(0, 1);
    unsigned long a, p, anum;
    cout<< "Введите основание, по которому будет проверяться число(основание должно быть меньше проверяемого числа): ";
    a = ProverkaNum();
    cout <<endl<< "Введите число на проверку:";
    p = ProverkaNum();
    if (a >= p) { 
        a = a%p;
        if (a == 1) { a = 2; }
        cout <<endl<< "Основание заменено на "<<a<<endl; }
    anum = a;
    for (int i = 2; i < p; i++) {
        anum = anum * a;
        if (anum > p) {
            while (anum > p) {
                anum -= p;
            }
        }
    }
    cout << endl;
    if (anum == 1) { cout << a << "^(" << p - 1 << ") сравнимо по модулю " << p << " с единицей" << endl; cout << p << " псевдопростое число по основанию " << a << endl;}
    if (anum != 1) { cout << a << "^(" << p - 1 << ") не сравнимо по модулю " << p << " с единицей" << endl; cout << p << " не является псевдопростым по основанию "<< a;}
}
void Wilson() {
    inf_Wilson();
    SetCursorPosition(0, 1);
    cout << "Введите число для проверки: ";
    unsigned long m = ProverkaNum(); 
    cout << endl;
    unsigned long N = m - 1, rest = 1;
    if (m != 1) {
        for (unsigned long i = 2; i <= N; i++)
            rest = (rest * i) % m;
    }
    if (m == 1){ cout << m << " простое число"; }
    if (rest == m - 1) { cout << m << " простое число"; }
    if ((rest != m - 1)&&(m != 1)) { cout << m << " не является простым числом"; }
    char h = ' ';
    cout << endl << endl << "Для продолжения нажмите \'e\'";
    while ((h != 'e')) {
        h = _getch();
        if (h == 'e') { h = 'e'; break; }
    }    
}
void Carmaikl() {
    inf_Carmaikl();
    SetCursorPosition(0, 1);
    cout << "Введите число для проверки: ";
    unsigned long n, div = 3, cnt = 1, num;
    n = ProverkaNum();
    num = n;
    cout << endl;
    vector<int>divv;
    while (n > 1)
    {
        if (n % 2 == 0) { cnt = 0; break; }
        while (n % div == 0)
        {
            n = n / div; divv.push_back(div);
        }       
        div++;
    }
    if (divv.size() > 2) {
        for (int i = 0; i < divv.size(); i++) {
            if ((n - 1) % (divv[i] - 1) != 0) { cnt = 0; break; }
        }
    }
    if ((cnt == 1)&&(divv.size() > 2)) { cout << endl << num << " число Кармайкла "; }
    if  (cnt == 0) { cout << endl << num << " не является числом Кармайкла"; }
    else if(divv.size() < 3){ cout << endl << num << " не является числом Кармайкла"; }
    divv.clear();
    char h = ' ';
    cout << endl << endl << "Для продолжения нажмите \'e\'";
    while ((h != 'e')) {
        h = _getch();
        if (h == 'e') { h = 'e'; break; }
    }
}
void Solov_Shtr() {
    inf_S_Sh();
    SetCursorPosition(0, 1);
    unsigned long n, nod, num,  a = 1, anum, k, kcount = 0,  cnt = 0;
    unsigned short prime = 1;
    vector<unsigned long>Slv;
    cout << "Введите число на проверку простоты: "; 
    n = ProverkaNum();
    num = n; 
    if (n > 94000){ cout << endl << "Параметр точности(MAX " << 94000 << "): "; }
    if (n < 94000) { cout << endl << "Параметр точности(MAX " << n - 1 << "): "; }
    k = ProverkaNum();
    cout << endl;
    Slv.clear();
        Slv.push_back(1);
        for (int i = 1; i < n; i++) {
           unsigned long m = i*i ;
           while (m > n) {
               m = m - n;
           }
            Slv.push_back(m);
        }
        for (int i = 0; i < num; i++) {
            for (int j = i + 1; j < num - 1; j++) {
                auto iter = Slv.cbegin();
                if (Slv[i] == Slv[j]) {
                    Slv.erase(iter + j);
                    num--;
                }
            }
        }
        unsigned long kkcount = 0;
        if (k > n - 1) { k = n - 1; if (k > 94000) { k = 94000; }SetCursorPosition(19, 2); cout << k << endl; }
    while (kcount != n-1) {
        if (n == 1) { prime = 0; cout << "Число " << n << " с вероятностью " << 1 << " простое"; break; }
        num = n;
        a++; 
        if (a == n) { break; }
        if (kkcount < k) {
            cout << kkcount + 1 << ".Число для проверки: " << a << endl;
            kkcount++;
        }
        anum = (a*a)%n;
        cnt = -1;
        if (cnt == -1) {
            for (int i = 0; i < Slv.size(); i++) {
                if (a == Slv[i]) { cnt = 1; break; }
            }
        }
        num = (n - 1) / 2;
        anum = a;
        for (int i = 1; i < num; i++) {
            anum = anum * a;
            if (anum > n) { anum = anum % n; }
        }
        if (cnt == 1) {
            if (anum != 1) { cout << n << " не является простым 446"; prime = 0; break; }
            if (anum == 1) { prime = 1; }
        }
        if (cnt == -1) {
            if (anum != n - 1) { cout << n << " не является простым 449"; prime = 0; break; }
            if (anum == n-1) { prime = 1; }
        }
        kcount++;
    }
    if (prime == 1) { cout << "Число " << n << " с вероятностью " << 1 - 1 / (pow(2, k)) << " простое"; }
    char h = ' ';
    Slv.clear();
    cout << endl << endl << "Для продолжения нажмите \'e\'";
    while ((h != 'e')) {
        h = _getch();
        if (h == 'e') { h = 'e'; break; }
    }
}
void Rabin_Mill() {   
    inf_R_M();
    SetCursorPosition(0, 1);
    unsigned long n, nod, num, cnt = 0, a = 1, anum = 1, k, kcount = 0, cnt2step = 0, prime = 1, kkcount = 0;;
    cout << "Число на проверку: ";
    n = ProverkaNum();
    num = n; 
    cout << endl;
    if (n == 1) { prime = 0; cnt = 1; k = 150; }
    if ((n % 2 != 0)&&(prime==1)) {
        unsigned long num2 = n - 1;
        while (num2 % 2 == 0) {
            num2 = num2 / 2;
            cnt2step++;
        }
        if (n > 94000) { cout << endl << "Параметр точности(MAX " << 94000 << "): "; }
        if (n < 94000) { cout << endl << "Параметр точности(MAX " << n - 1 << "): "; }
         k = ProverkaNum();
         cout << endl;
         if (k > n - 1) { k = n - 1; if (k > 94000) { k = 94000; }SetCursorPosition(19, 2); cout << k << endl; }
         while (kcount != n-1) {
             a++;
            if (kkcount < k) {
                cout << kcount + 1 << ".Число на проверку: " << a << endl;
                kkcount++;
            }             
            nod = NOD(n, a);
            if (nod == 1) {
                for (int j = 1; j <= cnt2step; j++) {
                    for (int i = 1; i <= num2; i++) {
                        anum = anum * a;
                        if (anum > num) {
                            while (anum > num) {
                                anum -= num;
                            }
                        }
                    }
                    if (anum == num - 1) { cnt++; }
                }
            }
            if (nod != 1) { cnt = 0; break; }
            kcount++;
         }
    }
    if (n == 2) { cnt = 1; k = 15; }
    if (cnt != 0) { cout << num << " простое число с вероятностью " << 1 - 1 / (pow(4, k)); }
    if (cnt == 0) { cout << num << " не является простым числом "; }
    char h = ' ';  
    cout << endl << endl << "Для продолжения нажмите \'e\'";
    while ((h != 'e')) {
        h = _getch();
        if (h == 'e') { h = 'e'; break; }
    }
}
void AKS() {   
    inf_AKS();
int n, num,cnt=0;
    n = Ferma_for_AKS();
    char com = ' ';
    if (n==1){ cout << n << " простое число ( Полиномиальный тест )" << endl; }
    if ((n % 2 != 0)&&(n!=1)) {
        vector<unsigned long>AK;
        vector<unsigned long>AKdel;
        num = (n - 1) / 2;      
            for (int i = 1; i <= num; i++) {
                AK.push_back(n - i + 1);
                AKdel.push_back(i);
            }
            for (int i = 1; i < AK.size(); i++) {
                for (int j = 0; j < AKdel.size(); j++) {
                    if (AK[i] % AKdel[j] == 0) {
                        AK[i] = AK[i] / AKdel[j];
                    }
                }
            }
            for (int i = 0; i < AK.size(); i++) {
                if (AK[i] % n == 0) { cnt++; break; }
            } 
            if (cnt != 0) { cout << n << " простое число ( Полиномиальный тест )"<<endl; }
            if (cnt == 0) { cout << n << " не является простым числом ( Полиномиальный тест )"; }
      AK.clear();
      AKdel.clear();
    }    
    cout << endl << endl << "Для продолжения нажмите \'e\'";
    while (com != 'e') {
          com = _getch();
    }
}

int main()
{     
    setlocale(LC_ALL, "ru");
    unsigned short str = 5;
    unsigned char com = ' ';
    int ferma;
    cout << "Для полноценного использования программы перейдите в полноформатный режим!"<<endl<<"Нажмите Enter.";
    while (com != (char)13) {
        com = _getch();
    }
    com = ' ';
    Static(str);
    SetCursorPosition(0, 0);
    while (com != 'q') {
        if ((com == 'w') && (str > 5)) { commandW(&str); }
        if ((com == 's') && (str < 11)) { commandS(&str); }
        if ((com == (char)13) && (str == 5)) {
            Eratos();
            Static(str);
        }
        if ((com == (char)13) && (str == 6)) {
           Ferma();
           char h = ' '; 
           cout << endl << endl << "Для продолжения нажмите \'e\'";
           while ((h != 'e')) {
               h = _getch();
               if (h == 'e') { h = 'e'; break; }
           }
           Static(str);
        }
        if ((com == (char)13) && (str == 7)) {
            Wilson();
            Static(str);
        }
        if ((com == (char)13) && (str == 8)) {
            Carmaikl();
            Static(str);
        }
        if ((com == (char)13) && (str == 9)) {
            Solov_Shtr();
            Static(str);
        }
        if ((com == (char)13) && (str == 10)) {
            Rabin_Mill();
            Static(str);
        }
        if ((com == (char)13) && (str == 11)) {
            AKS();
            Static(str);
        }
        com = _getch();
    }
    SetCursorPosition(0, 16);
    return 0;    
}
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    char s[256]; //1 строка
    char t[256]; // 2 строка
    char f[] = "%s";


    char m[514];
    __asm
    {
        //заполнение 1 строки
        lea esi, s
        push esi
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        mov ecx, -1
        dec esi

        //заполнение 2 строки
        lea esi, t
        push esi
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        mov ecx, -1
        dec esi
        
        //соединение
        lea esi, [s]
        lea edi, [m]
        b1:
        lodsb
        stosb
        cmp al, 0
        jnz b1

        lea esi, [t]
        dec edi

        b2 :
        lodsb
        stosb
        cmp al, 0
        jnz b2

    }
    std::cout << m;

}


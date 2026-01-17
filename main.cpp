
#include <iostream>
#include <unknwn.h>
#include <objbase.h>

#include "interfaces.h"

using namespace std;

int main () {
    SetConsoleOutputCP(CP_UTF8);

    HRESULT hr;

    cout << "IUnknown указатель получен" << endl;
    IUnknown* pIUnknown = CreateInstance();

    cout << "\n1) Указатель на IX" << endl;
    // Определяем указатель на интерфейс
    IX* pIX = NULL;
    // Запрашиваем интерфейс IX
    hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
    if (SUCCEEDED(hr)) {
        cout << "Клиент: указатель на IX успешно получен" << endl;
        pIX->Fx(); // Использовать интерфейс IX
    };

    cout << "\n2) Указатель на IY" << endl;
    IY* pIY = NULL;
    hr = pIUnknown->QueryInterface(IID_IY, (void**)&pIY);
    if (SUCCEEDED(hr)) {
        cout << "Клиент: указатель на IY успешно получен" << endl;
        pIY->Fy(); // Использовать интерфейс IY
    };

    cout << "\n3) Неподдерживаемый интерфейс" << endl;
    SomeInterface* pSomeInterface = NULL;
    hr = pIUnknown->QueryInterface(IID_SomeInterface, (void**)&pSomeInterface);
    if(SUCCEEDED(hr)) {
        cout << "SomeInterface успешно получен" << endl;
    } else {
        cout << "Не удается получить доступ к SomeInterface" << endl;
    };


    cout << "\n4) Указатель на IY через IX" << endl;
    IY* pIYfromIX = NULL;
    hr = pIX->QueryInterface(IID_IY, (void**)&pIYfromIX);
    if(SUCCEEDED(hr)) {
        cout<< "IY успешно получен" << endl;
        pIYfromIX->Fy();
    } else {
        cout << "Невозможно получить указатель" << endl;
    }

    // Удалить компонент
    delete pIUnknown;

    return 0;
};
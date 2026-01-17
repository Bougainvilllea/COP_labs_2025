
#include <iostream>
#include <unknwn.h>
#include <objbase.h>

using namespace std;

extern const IID IID_IX;
extern const IID IID_IY;
extern const IID IID_SomeInterface;
extern const IID IID_IUnknown1;

interface IX : IUnknown {
    virtual void __stdcall Fx() = 0;
};

interface IY : IUnknown {
    virtual void __stdcall Fy() = 0;
};

interface SomeInterface : IUnknown {
    virtual void __stdcall Fz() = 0;
};

// Компонент
class CA : public IX, public IY {
    // Реализация методов класса IUnknown
    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();
    virtual HRESULT __stdcall QueryInterface(const IID &iid, void **ppv);

    virtual void __stdcall Fx();
    virtual void __stdcall Fy();
};

// Функция создания компонента
IUnknown* CreateInstance();
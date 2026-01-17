#include <iostream>
using namespace std;


class IPrinter {
public:
    virtual void PrintHeader() = 0;
    virtual void PrintContent() = 0;
};


class ICalculator {
public:
    virtual void CalculateSum(double a, double b) = 0;
    virtual void CalculateMult(double a, double b) = 0;
};


class MultiFunctionDevice : public IPrinter,
                           public ICalculator {
public:
    virtual void PrintHeader() override { cout << "=== Report Header ===" << endl; }
    virtual void PrintContent() override { cout << "1 2 3\n4 5 6\n7 8 9\n  0" << endl; }

    virtual void CalculateSum(double a, double b) override { cout << a * b << endl; }
    virtual void CalculateMult(double a, double b) override { cout << a * b << endl; }
};

void demoInterfaces() {
    cout << "DEMO 1" << endl;
    cout << "Creating multi-function device..." << endl;
    MultiFunctionDevice* device = new MultiFunctionDevice;

    IPrinter* printer = device;
    cout << "Using printer interface:" << endl;
    printer->PrintHeader();
    printer->PrintContent();

    ICalculator* calculator = device;
    cout << "Using calculator interface:" << endl;
    calculator->CalculateSum(2, 2);
    calculator->CalculateMult(4, 4);

    cout << "Deleting device..." << endl;
    delete device;

    cout << endl << endl;
}

// -----------------------------------------------------------------------------


class INumberOperations {
public:
    double result1;
    double result2;
    double result3;
    double result4;

    virtual void ShowResult1() = 0;
    virtual void ShowResult2() = 0;
    virtual void ShowResult3() = 0;
    virtual void ShowResult4() = 0;
};

class Incrementer : public INumberOperations {
public:
    virtual void ShowResult1() override { cout << result1 << " (base value +1)" << endl; }
    virtual void ShowResult2() override { cout << result2 << " (base value +2)" << endl; }
    virtual void ShowResult3() override { cout << result3 << " (base value +3)" << endl; }
    virtual void ShowResult4() override { cout << result4 << " (base value +4)" << endl; }

    Incrementer(double value) {
        result1 = value + 1;
        result2 = value + 2;
        result3 = value + 3;
        result4 = value + 4;
    }
};

class Decrementer : public INumberOperations {
public:
    virtual void ShowResult1() override { cout << result1 << " (base value -1)" << endl; }
    virtual void ShowResult2() override { cout << result2 << " (base value -2)" << endl; }
    virtual void ShowResult3() override { cout << result3 << " (base value -3)" << endl; }
    virtual void ShowResult4() override { cout << result4 << " (base value -4)" << endl; }

    Decrementer(double value) {
        result1 = value - 1;
        result2 = value - 2;
        result3 = value - 3;
        result4 = value - 4;
    }
};

void demoNumberOperations() {
    cout << "DEMO 2: Number Operations" << endl;
    Incrementer* incrementer = new Incrementer(10);
    Decrementer* decrementer = new Decrementer(10);

    cout << "Incrementer results (base value = 10):" << endl;
    incrementer->ShowResult1();
    incrementer->ShowResult2();
    incrementer->ShowResult3();
    incrementer->ShowResult4();

    cout << "\nDecrementer results (base value = 10):" << endl;
    decrementer->ShowResult1();
    decrementer->ShowResult2();
    decrementer->ShowResult3();
    decrementer->ShowResult4();

    delete incrementer;
    delete decrementer;
}

int main() {
    demoInterfaces();
    demoNumberOperations();

    return 0;
}

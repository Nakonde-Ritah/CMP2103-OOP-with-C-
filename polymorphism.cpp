
#include <iostream>
#include <string>
using namespace std;

class Payment {
protected:
    double amount;
public:
    Payment(double a) : amount(a) {}

    virtual void pay() const {                 // virtual: can be overridden
        cout << "Generic payment of UGX " << amount << endl;
    }
    virtual ~Payment() {}                      // virtual destructor
};

class MobileMoneyPayment : public Payment {
public:
    MobileMoneyPayment(double a) : Payment(a) {}
    void pay() const override {
        double fee = amount * 0.01;            // 1% fee
        cout << "Mobile Money: paid UGX " << amount
             << " + fee UGX " << fee << " via USSD PIN." << endl;
    }
};

class CardPayment : public Payment {
public:
    CardPayment(double a) : Payment(a) {}
    void pay() const override {
        double fee = amount * 0.025;           // 2.5% fee
        cout << "Card: paid UGX " << amount
             << " + fee UGX " << fee << " via POS/online." << endl;
    }
};

class CashPayment : public Payment {
public:
    CashPayment(double a) : Payment(a) {}
    void pay() const override {
        cout << "Cash: paid UGX " << amount
             << ", no fee, handed over in person." << endl;
    }
};

// Works with ANY payment type through a base-class reference
void checkout(const Payment& p) {
    p.pay();
}

int main() {
    // Base-class pointers holding derived objects
    Payment* list[3];
    list[0] = new MobileMoneyPayment(50000);
    list[1] = new CardPayment(120000);
    list[2] = new CashPayment(20000);

    cout << "--- Using base-class pointers ---" << endl;
    for (int i = 0; i < 3; i++) {
        list[i]->pay();                        // same call, different behaviour
    }

    cout << "\n--- Using a base-class reference ---" << endl;
    CardPayment c(75000);
    checkout(c);

    for (int i = 0; i < 3; i++) delete list[i];
    return 0;
}
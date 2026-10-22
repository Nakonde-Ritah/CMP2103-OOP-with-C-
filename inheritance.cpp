
#include <iostream>
#include <string>
using namespace std;

// LEVEL 1: base class
class Device {
protected:
    string brand;
    long price;
public:
    Device(string b, long p) : brand(b), price(p) {}

    void powerOn() const {
        cout << brand << " is powering on..." << endl;
    }
    void showBasic() const {
        cout << "Brand: " << brand << endl;
        cout << "Price: UGX " << price << endl;
    }
};

// LEVEL 2: derived from Device
class Computer : public Device {
protected:
    int ramGB;
    string processor;
public:
    Computer(string b, long p, int r, string proc)
        : Device(b, p), ramGB(r), processor(proc) {}

    void runProgram(const string& prog) const {
        cout << "Running " << prog << " on " << brand << endl;   // brand is inherited
    }
    void showSpecs() const {
        showBasic();                                             // inherited function
        cout << "RAM: " << ramGB << " GB" << endl;
        cout << "Processor: " << processor << endl;
    }
};

// LEVEL 3: derived from Computer (so also from Device)
class Laptop : public Computer {
private:
    int batteryHours;
    bool touchscreen;
public:
    Laptop(string b, long p, int r, string proc, int bat, bool touch)
        : Computer(b, p, r, proc), batteryHours(bat), touchscreen(touch) {}

    void closeLid() const {
        cout << brand << " lid closed, entering sleep mode." << endl;
    }
    void showLaptopDetails() const {
        showSpecs();                                             // inherited from Computer
        cout << "Battery: " << batteryHours << " hours" << endl;
        cout << "Touchscreen: " << (touchscreen ? "Yes" : "No") << endl;
    }
};

int main() {
    cout << "--- Computer object ---" << endl;
    Computer pc("HP Desktop", 1800000, 8, "Intel i5");
    pc.powerOn();                    // from Device
    pc.showSpecs();                  // from Computer

    cout << "\n--- Laptop object ---" << endl;
    Laptop lp("Dell", 2500000, 16, "Intel i7", 8, false);
    lp.powerOn();                    // inherited from Device (2 levels up)
    lp.runProgram("MATLAB");         // inherited from Computer (1 level up)
    lp.showLaptopDetails();          // defined in Laptop itself
    lp.closeLid();                   // local to Laptop
    return 0;
}
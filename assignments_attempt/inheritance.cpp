#include <iostream>
#include <string>
using namespace std;

class Sensor {
protected:
    string id;
    double reading;

public:
    Sensor(const string& id) : id(id), reading(0.0) {}
    virtual ~Sensor() {}

    void read(double value) { reading = value; }

    virtual void describe() const {
        cout << "Sensor " << id << ": " << reading << endl;
    }
};

class AnalogSensor : public Sensor {
protected:
    double vRef;
    int adcBits;

public:
    AnalogSensor(const string& id, double vRef, int adcBits)
        : Sensor(id), vRef(vRef), adcBits(adcBits) {}

    double adcToVoltage(int code) const {
        return code * vRef / ((1 << adcBits) - 1);
    }
};

class TemperatureSensor : public AnalogSensor {
public:
    TemperatureSensor(const string& id)
        : AnalogSensor(id, 3.3, 10) {}

    // LM35: 10 mV per degree C
    double voltageToCelsius(double v) const { return v * 100; }

    void readFromAdc(int code) {
        read(voltageToCelsius(adcToVoltage(code)));
    }

    void describe() const override {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "TemperatureSensor " << id << ": " << reading << " C" << endl;
    }
};

int main() {
    TemperatureSensor t("T1");
    t.readFromAdc(100);

    Sensor& s = t;      // base-class reference
    s.describe();       // virtual call, runs TemperatureSensor::describe()
    return 0;
}
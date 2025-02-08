#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

//n1
struct Monitor {
    string name;
    int warranty;
    double price;
};

bool displaycomp(const Monitor& a, const Monitor& b) {
    return a.price > b.price;
}

void monitorsdown() {
    vector<Monitor> monitors = {
        {"Xiaomi", 12, 1488},
        {"Samsung", 24, 552},
        {"MSI", 12, 442}
    };
    sort(monitors.begin(), monitors.end(), displaycomp);

    cout << "за спаданням ціни:\n";
    for (const auto& m : monitors) {
        cout << m.name << " - " << m.price << " грн , гарантія: " << m.warranty << " місяців\n";
    }
}

//n2
struct CarDetails {
    string engine;
    string color;
    int owners;
};
struct Car {
    string brand;
    string model;
    int year;
    double price;
    bool bargaining;
    CarDetails details;
};
void tablecar(const vector<Car>& cars) {
    cout << left << setw(10) << "марка" << setw(10) << "модель" << setw(6) << "рік" << setw(10) << "ціна"
        << setw(8) << "торг" << setw(15) << "двигун" << setw(10) << "колір" << "власники" << endl;
    cout << string(70, '-') << endl;
    for (const auto& c : cars) {
        cout << setw(10) << c.brand << setw(10) << c.model << setw(6) << c.year << setw(10) << c.price
            << setw(8) << (c.bargaining ? "так" : "ні") << setw(15) << c.details.engine
            << setw(10) << c.details.color << c.details.owners << endl;
    }
}
void carstable() {
    vector<Car> cars = {
        {"Toyota", "Camry", 2020, 25000, true, {"2.5L", "білий", 1}},
        {"BMW", "X5", 2018, 35000, false, {"3.0L", "чорний", 2}},
        {"Ford", "Focus", 2016, 12000, true, {"1.6L", "синій", 3}}
    };
    tablecar(cars);
}

//n3
typedef struct {
    string surname;
    char gender;
    double average_grade;
} Student;
void points() {
    vector<Student> students = {
        {"Туяхов", 'M', 85.2},
        {"Хтось", 'F', 52.0},
        {"Нападайло", 'M', 83.1},
        {"Кагабайло", 'F', 85.5}
    };
    double sumMale = 0, sumFemale = 0;
    int countMale = 0, countFemale = 0;
    for (const auto& s : students) {
        if (s.gender == 'M') {
            sumMale += s.average_grade;
            countMale++;
        }
        else {
            sumFemale += s.average_grade;
            countFemale++;
        }
    }
    double avgMale = countMale ? sumMale / countMale : 0;
    double avgFemale = countFemale ? sumFemale / countFemale : 0;
    cout << "хлопці середній бал: " << avgMale << endl;
    cout << "дівчата середній бал: " << avgFemale << endl;
    cout << (avgMale > avgFemale ? "хлопці мають вищий бал." : "дівчата мають вищий бал.") << endl;
}
int main() {
    system("chcp 1251>nul");
    cout << "n1:\n";
    monitorsdown();

    cout << "n2:\n";
    carstable();

    cout << "n3:\n";
    points();

    return 0;
}

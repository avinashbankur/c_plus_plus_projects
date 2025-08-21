#include <iostream>

using namespace std;

void lengthConversion() {
    double meters;
    cout << "Enter length in meters: ";
    cin >> meters;

    cout << meters << " meters is equal to:" << endl;
    cout << meters / 1000 << " kilometers" << endl;
    cout << meters * 100 << " centimeters" << endl;
    cout << meters * 39.3701 << " inches" << endl;
}

void weightConversion() {
    double kilograms;
    cout << "Enter weight in kilograms: ";
    cin >> kilograms;

    cout << kilograms << " kilograms is equal to:" << endl;
    cout << kilograms * 1000 << " grams" << endl;
    cout << kilograms * 2.20462 << " pounds" << endl;
}

void temperatureConversion() {
    double celsius;
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    double fahrenheit = (celsius * 9.0 / 5.0) + 32;
    cout << celsius << " degrees Celsius is equal to " << fahrenheit << " degrees Fahrenheit." << endl;
}

int main() {
    int choice;

    do {
        cout << "\nSimple Unit Conversion Program" << endl;
        cout << "1. Length Conversion (meters)" << endl;
        cout << "2. Weight Conversion (kilograms)" << endl;
        cout << "3. Temperature Conversion (Celsius to Fahrenheit)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lengthConversion();
                break;
            case 2:
                weightConversion();
                break;
            case 3:
                temperatureConversion();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Car {
private:
    string model;
    int year;
    double price;
    bool sold;

public:
    Car(string model, int year, double price) {
        this->model = model;
        this->year = year;
        this->price = price;
        this->sold = false;
    }

    void sell() {
        sold = true;
    }

    bool isSold() const {
        return sold;
    }

    string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    double getPrice() const {
        return price;
    }

    string toString() const {
        stringstream ss;
        ss << model << "," << year << "," << price << "," << (sold ? "true" : "false");
        return ss.str();
    }

   
    double calculateTotalPriceByValue(vector<Car> cars) const {
        double total = 0.0;
        for (const Car& car : cars) {
            if (car.isSold()) {
                total += car.getPrice();
            }
        }
        return total;
    }

  
    double calculateTotalPriceByReference(const vector<Car>& cars) const {
        double total = 0.0;
        for (const Car& car : cars) {
            if (car.isSold()) {
                total += car.getPrice();
            }
        }
        return total;
    }
};

vector<Car> readCarsFromFile(const string& filename) {
    vector<Car> cars;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string model;
            int year;
            double price;
            string soldStr;

            getline(ss, model, ',');
            ss >> year;
            ss.ignore();
            ss >> price;
            ss.ignore();
            getline(ss, soldStr);

            bool sold = (soldStr == "true");
            cars.push_back(Car(model, year, price));
            if (sold) {
                cars.back().sell();
            }
        }
        file.close();
    } else {
        cout << "File '" << filename << "' does not exist or cannot be opened. Creating new cars..." << endl;
        
        cars.push_back(Car("Toyota Camry", 2020, 25000.0));
        cars.push_back(Car("Honda Accord", 2019, 22000.0));
        cars.push_back(Car("Ford Mustang", 2021, 35000.0));
    }
    return cars;
}

void writeCarsToFile(const string& filename, const vector<Car>& cars) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const Car& car : cars) {
            file << car.toString() << endl;
        }
        file.close();
        cout << "Cars successfully saved to file '" << filename << "'" << endl;
    } else {
        cout << "Unable to open file for writing: " << filename << endl;
    }
}

int main() {
    string filename = "cars.txt";

    vector<Car> cars = readCarsFromFile(filename);

 
    if (cars.size() > 1) {
        cars[1].sell();
    }


    cars.push_back(Car("Chevrolet Corvette", 2022, 60000.0));

    writeCarsToFile(filename, cars);

    cout << "Car Details:" << endl;
    for (const Car& car : cars) {
        cout << "Model: " << car.getModel() << endl;
        cout << "Year: " << car.getYear() << endl;
        cout << "Price: $" << car.getPrice() << endl;
        if (car.isSold()) {
            cout << "Status: Sold" << endl;
        } else {
            cout << "Status: Unsold" << endl;
        }
        cout << endl;
    }

  
    double totalPriceByValue = cars[1].calculateTotalPriceByValue(cars);
    double totalPriceByReference = cars[1].calculateTotalPriceByReference(cars);

    cout << "Total Price of Sold Cars : $" << totalPriceByValue << endl;
    cout << "Total Price of Sold Cars : $" << totalPriceByReference << endl;

    return 0;
}






outtput 

/tmp/5OoA8VlQYT.o
File 'cars.txt' does not exist or cannot be opened. Creating new cars...
Unable to open file for writing: cars.txt
Car Details:
Model: Toyota Camry
Year: 2020
Price: $25000
Status: Unsold

Model: Honda Accord
Year: 2019
Price: $22000
Status: Sold

Model: Ford Mustang
Year: 2021
Price: $35000
Status: Unsold

Model: Chevrolet Corvette
Year: 2022
Price: $60000
Status: Unsold

Total Price of Sold Cars : $22000
Total Price of Sold Cars : $22000


=== Code Execution Successful ===/tmp/5OoA8VlQYT.o
File 'cars.txt' does not exist or cannot be opened. Creating new cars...
Unable to open file for writing: cars.txt
Car Details:
Model: Toyota Camry
Year: 2020
Price: $25000
Status: Unsold

Model: Honda Accord
Year: 2019
Price: $22000
Status: Sold

Model: Ford Mustang
Year: 2021
Price: $35000
Status: Unsold

Model: Chevrolet Corvette
Year: 2022
Price: $60000
Status: Unsold

Total Price of Sold Cars : $22000
Total Price of Sold Cars : $22000


=== Code Execution Successful ===
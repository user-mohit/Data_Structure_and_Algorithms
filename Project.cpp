#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate equivalent resistance of resistors in series
double calculateSeriesResistance(const vector<double>& resistors) {
    double totalResistance = 0.0;
    for (double resistance : resistors) {
        totalResistance += resistance;
    }
    return totalResistance;
}

// Function to calculate equivalent resistance of resistors in parallel
double calculateParallelResistance(const vector<double>& resistors) {
    double totalInverseResistance = 0.0;
    for (double resistance : resistors) {
        totalInverseResistance += 1.0 / resistance;
    }
    return 1.0 / totalInverseResistance;
}
// Function to generate all combinations of resistors
void generateCombinations(const vector<double>& resistors, vector<vector<double>>& combinations, size_t length, size_t start, vector<double>& current) {
    if (length == 0) {
        combinations.push_back(current);
        return;
    }

    for (size_t i = start; i < resistors.size(); ++i) {
        current.push_back(resistors[i]);
        generateCombinations(resistors, combinations, length - 1, i + 1, current);
        current.pop_back(); 
    }
}

int main() {
    // Define the resistance values
    vector<double> resistances = {1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4,
                                  2.7, 3.0, 3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2,
                                  6.8, 7.5, 8.2, 9.1};

    // Get user input for desired resistance
    double desiredResistance;
    cout << "Enter the desired resistance value: ";
    cin >> desiredResistance;

    // Find combination of up to 4 resistors to achieve the desired resistance
    bool resistanceAchieved = false;
    vector<vector<double>> combinations;
    vector<double> currentCombination;
    for (size_t i = 1; i <= min(resistances.size(), (size_t)4); ++i) {
        generateCombinations(resistances, combinations, i, 0, currentCombination);
        for (const auto& combination : combinations) {
            double calculatedResistance = calculateSeriesResistance(combination);
            if (fabs(calculatedResistance - desiredResistance) < 1e-6) {
                cout << "Resistance achieved using resistors in series:" << endl;
                for (double resistor : combination) {
                    cout << resistor << " ";
                }
                cout << endl;
                resistanceAchieved = true;
                break;
            }
            calculatedResistance = calculateParallelResistance(combination);
            if (fabs(calculatedResistance - desiredResistance) < 1e-6) {
                cout << "Resistance achieved using resistors in parallel:" << endl;
                for (double resistor : combination) {
                    cout << resistor << " ";
                }
                cout << endl;
                resistanceAchieved = true;
                break;
            }
        }
        if (resistanceAchieved)
            break;
        combinations.clear(); // Clear combinations for the next iteration
    }

    if (!resistanceAchieved) {
        cout << "Desired resistance cannot be achieved with up to 4 resistors from the provided values." << endl;
    }

    return 0;
}

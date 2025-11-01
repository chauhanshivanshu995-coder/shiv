#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Function to perform Basic COCOMO estimation
void cocomoEstimation(string projectName, string mode, double KLOC) {
    double a, b, c, d;

    // Choose constants based on mode
    if (mode == "organic") {
        a = 2.4; b = 1.05; c = 2.5; d = 0.38;
    } else if (mode == "semi-detached") {
        a = 3.0; b = 1.12; c = 2.5; d = 0.35;
    } else if (mode == "embedded") {
        a = 3.6; b = 1.20; c = 2.5; d = 0.32;
    } else {
        cout << "Invalid mode. Use 'organic', 'semi-detached', or 'embedded'.\n";
        return;
    }

    // Calculate effort and development time
    double effort = a * pow(KLOC, b);      // Person-Months
    double devTime = c * pow(effort, d);   // Months
    double staff = effort / devTime;       // Persons
    double productivity = KLOC / effort;   // KLOC per person-month

    // Display results
    cout << "\n=== COCOMO Estimation Report ===";
    cout << "\nProject: " << projectName;
    cout << "\nMode: " << mode;
    cout << "\nSize (KLOC): " << KLOC << " KLOC";
    cout << "\n--------------------------------";
    cout << "\nEffort Required: " << effort << " Person-Months";
    cout << "\nDevelopment Time: " << devTime << " Months";
    cout << "\nAverage Staff Required: " << staff << " Persons";
    cout << "\nProductivity: " << productivity << " KLOC/Person-Month";
    cout << "\n================================\n";
}

int main() {
    string projectName = "ATM System";
    string mode;
    double KLOC;

    cout << "Enter development mode (organic/semi-detached/embedded): ";
    cin >> mode;
    cout << "Enter estimated size of project (in KLOC): ";
    cin >> KLOC;

    cocomoEstimation(projectName, mode, KLOC);

    return 0;
}


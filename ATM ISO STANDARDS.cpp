#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Structure to hold quality attributes
struct QualityAttribute {
    string name;
    string description;
    string isoReference;
    double rating; // user input 1–5
};

// Function to display the attributes and accept ratings
void evaluateQuality(QualityAttribute qa[], int n) {
    cout << "\n=== ATM System Quality Evaluation ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nAttribute " << i + 1 << ": " << qa[i].name;
        cout << "\nDescription: " << qa[i].description;
        cout << "\nISO Reference: " << qa[i].isoReference;
        cout << "\nRate this attribute (1–5): ";
        cin >> qa[i].rating;
    }
}

// Function to display summary
void displaySummary(QualityAttribute qa[], int n) {
    double total = 0;
    cout << "\n\n===== Quality Summary Report =====\n";
    cout << left << setw(25) << "Attribute" 
         << setw(15) << "Rating"
         << setw(20) << "ISO Reference" << endl;
    cout << "---------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(25) << qa[i].name 
             << setw(15) << qa[i].rating
             << setw(20) << qa[i].isoReference << endl;
        total += qa[i].rating;
    }

    double avg = total / n;
    cout << "---------------------------------------------\n";
    cout << "Average Quality Rating: " << fixed << setprecision(2) << avg << " / 5.00\n";

    if (avg >= 4.5) cout << "Overall Quality Level: Excellent ?\n";
    else if (avg >= 3.5) cout << "Overall Quality Level: Good ??\n";
    else if (avg >= 2.5) cout << "Overall Quality Level: Average ??\n";
    else cout << "Overall Quality Level: Needs Improvement ??\n";
}

int main() {
    const int n = 6;
    QualityAttribute qa[n] = {
        {"Functionality", "Ensures correct banking operations and transactions.", "ISO 9126-1: Functionality", 0},
        {"Reliability", "Performs consistently under load and failures.", "ISO 9126-1: Reliability", 0},
        {"Usability", "Easy to use for customers of all levels.", "ISO 9126-1: Usability", 0},
        {"Efficiency", "Responds quickly to user requests and transactions.", "ISO 9126-1: Efficiency", 0},
        {"Maintainability", "Easily updated or fixed without downtime.", "ISO 9126-1: Maintainability", 0},
        {"Security", "Protects user data and prevents unauthorized access.", "ISO/IEC 27001: Information Security", 0}
    };

    cout << "===== ATM System Quality Planning (ISO-Based) =====\n";
    cout << "This program evaluates software quality attributes as per ISO standards.\n";

    evaluateQuality(qa, n);
    displaySummary(qa, n);

    return 0;
}


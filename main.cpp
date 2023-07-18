#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void sortData(double[], int);
void displayArray(double arr[], int size);
double mean(double[], int);
double median(double[], int);
double calcRange(double[], int);
double calcVariance(double[], int);
double calcSD(double[], int);
void computeModes(double arr[], int size);

int main() {
    const int size = 200;
    double set1[size];
    int index = 0;

    string input;

    //Collect dataset example from class
    do {
        cout << "Enter a value for your X set, leave blank to quit: ";
        getline(cin, input);

        if(!input.empty()) {
            if(!isdigit(input[0]) && !(input[0] == '-' && isdigit(input[1])))
                cout << "Please type numbers only." << endl;
            else {
                set1[index++] = stod(input);
                cout << "Adding " << stod(input) << "." << endl;
            }
        };

    } while (!input.empty());

    // Create a copy of Dataset 1

    double set2[index];

    for (int i = 0; i < index; i++) {
        set2[i] = set1[i];
    };

    // Sort Dataset 2
    sortData(set2, index);

    // Print User inputted data
    cout << endl;
    cout << "Original Dataset: ";
    displayArray(set2, index);
    cout << "Sorted Dataset: ";
    displayArray(set2, index);




    // Print Central Tendency
    cout << endl;
    cout << "CENTRAL TENDENCY" << endl;
    cout << "Mean: " << mean(set2, index) << endl;
    cout << "Median: " << median(set2, index) << endl;
    cout << "Mode: ";
    computeModes(set2, index);
    cout << endl << endl;

    // Print Dispersion
    cout << "DISPERSION" << endl;
    cout << "Range: " << calcRange(set2, index) << endl;
    cout << "Sample Variance: " << calcVariance(set2, index) << endl;
    cout << "Sample Standard Deviation: " << calcSD(set2, index) << endl;


}

void sortData(double dataset[], int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i; j < size; j++)
            if(dataset[j] < dataset[minIndex])
                minIndex = j;

        double tempValue = dataset[i];
        dataset[i] = dataset[minIndex];
        dataset[minIndex] = tempValue;
    }
}

void displayArray(double arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << '[' << arr[i] << "]";
    cout << endl;
}

double mean(double arr[], int size) {
    double total = 0;
    for (int i = 0; i <= size; i++)
        total = total + arr[i];

    return total / size;
}

double median(double arr[], int size) {
    if (size % 2 == 0) {
        int midIndex1 = size / 2 - 1;
        int midIndex2 = size / 2;
        double median = (arr[midIndex1] + arr[midIndex2]) / 2.0;
        return median;
    } else {
        int midIndex = size / 2;
        return arr[midIndex];
    }
}
double calcRange(double arr[], int size) {
    return arr[size - 1] - arr[0];
}

double calcVariance(double arr[], int size) {
    double total = 0;
    double sSquared = 0;
    for (int i = 0; i <= size; i++)
        total = total + arr[i];

    double mean = total / size;
    double denominator = size - 1;

    for (int i = 0; i < size; ++i) {
        double numX = pow((arr[i] - mean), 2) / denominator;
        sSquared = sSquared + numX;
    }

    return sSquared;
}

double calcSD(double arr[], int size) {
    return sqrt(calcVariance(arr, size));
}

void computeModes(double arr[], int size) {
    string modes;
    int maxFrequency = 0;
    int currentFrequency = 1;

    for (int i = 1; i < size; ++i) {
        if (arr[i] == arr[i - 1]) {
            currentFrequency++;
        } else {
            if (currentFrequency > maxFrequency) {
                maxFrequency = currentFrequency;
                modes = "[" + to_string(arr[i - 1]) + "]";
            } else if (currentFrequency == maxFrequency) {
                modes += "[" + to_string(arr[i - 1]) + "]";
            }

            currentFrequency = 1;
        }
    }

    if (currentFrequency > maxFrequency) {
        modes = "[" + to_string(arr[size - 1]) + "]";
    } else if (currentFrequency == maxFrequency) {
        modes += "[" + to_string(arr[size - 1]) + "]";
    }

    cout << modes;
}


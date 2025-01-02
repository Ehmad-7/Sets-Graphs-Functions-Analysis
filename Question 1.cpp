//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//// Utility function for input validation
//void validatedInput(int& value, int lowerBound = 0, int upperBound = 1000000) {
//    cin >> value;
//    if (value >= lowerBound && value <= upperBound && !cin.fail()) {
//        return;
//    }
//    else {
//        cin.clear();
//        cin.ignore(1000, '\n');
//        cout << "\nPLEASE ENTER A NUMBER GREATER THAN " << lowerBound << ": ";
//        validatedInput(value, lowerBound, upperBound);
//    }
//}
//
//class RelationSet {
//private:
//    int* setX;        // First set
//    int* setY;        // Second set
//    int** cartesianProduct; // Cartesian product of X and Y
//    int countX, countY, totalPairs;
//    int diagPairs, nonDiagPairs;
//
//    // Function to display elements of a set
//    void displaySet(const int* arr, int length) {
//        cout << "{ ";
//        for (int idx = 0; idx < length; idx++) {
//            cout << arr[idx] << " ";
//        }
//        cout << "}";
//    }
//
//    // Function to compute union of two sets
//    vector<int> computeUnion() {
//        vector<int> unionResult(setX, setX + countX);
//        for (int idx = 0; idx < countY; idx++) {
//            if (find(unionResult.begin(), unionResult.end(), setY[idx]) == unionResult.end()) {
//                unionResult.push_back(setY[idx]);
//            }
//        }
//        return unionResult;
//    }
//
//    // Function to compute intersection of two sets
//    vector<int> computeIntersection() {
//        vector<int> intersectionResult;
//        for (int idx = 0; idx < countX; idx++) {
//            if (find(setY, setY + countY, setX[idx]) != setY + countY) {
//                intersectionResult.push_back(setX[idx]);
//            }
//        }
//        return intersectionResult;
//    }
//
//    // Function to compute set difference
//    vector<int> computeDifference(const int* firstSet, int sizeFirst, const int* secondSet, int sizeSecond) {
//        vector<int> differenceResult;
//        for (int idx = 0; idx < sizeFirst; idx++) {
//            if (find(secondSet, secondSet + sizeSecond, firstSet[idx]) == secondSet + sizeSecond) {
//                differenceResult.push_back(firstSet[idx]);
//            }
//        }
//        return differenceResult;
//    }
//
//    // Calculate diagonal and non-diagonal elements in Cartesian product
//    void analyzePairs() {
//        diagPairs = 0;
//        nonDiagPairs = 0;
//        for (int idx = 0; idx < totalPairs; idx++) {
//            if (cartesianProduct[idx][0] == cartesianProduct[idx][1]) {
//                diagPairs++;
//            }
//            else {
//                nonDiagPairs++;
//            }
//        }
//    }
//
//public:
//    // Constructor
//    RelationSet() : setX(nullptr), setY(nullptr), cartesianProduct(nullptr),
//        countX(0), countY(0), totalPairs(0), diagPairs(0), nonDiagPairs(0) {}
//
//    // Destructor
//    ~RelationSet() {
//        delete[] setX;
//        delete[] setY;
//        for (int idx = 0; idx < totalPairs; idx++) {
//            delete[] cartesianProduct[idx];
//        }
//        delete[] cartesianProduct;
//    }
//
//    // Input the sizes of the two sets
//    void initializeSizes() {
//        cout << "ENTER SIZE FOR SET X: ";
//        validatedInput(countX, 3);
//        setX = new int[countX];
//        cout << "ENTER SIZE FOR SET Y: ";
//        validatedInput(countY, 3);
//        setY = new int[countY];
//    }
//
//    // Input elements for set X
//    void inputSetX() {
//        for (int idx = 0; idx < countX; idx++) {
//            cout << "ENTER ELEMENT FOR X[" << idx + 1 << "]: ";
//            validatedInput(setX[idx]);
//        }
//    }
//
//    // Input elements for set Y
//    void inputSetY() {
//        for (int idx = 0; idx < countY; idx++) {
//            cout << "ENTER ELEMENT FOR Y[" << idx + 1 << "]: ";
//            validatedInput(setY[idx]);
//        }
//    }
//
//    // Compute Cartesian product
//    void calculateCartesianProduct() {
//        totalPairs = countX * countY;
//        cartesianProduct = new int* [totalPairs];
//        for (int idx = 0; idx < totalPairs; idx++) {
//            cartesianProduct[idx] = new int[2];
//        }
//        int index = 0;
//        for (int xIdx = 0; xIdx < countX; xIdx++) {
//            for (int yIdx = 0; yIdx < countY; yIdx++, index++) {
//                cartesianProduct[index][0] = setX[xIdx];
//                cartesianProduct[index][1] = setY[yIdx];
//            }
//        }
//    }
//
//    // Display Cartesian product
//    void showCartesianProduct() {
//        cout << "{ ";
//        for (int idx = 0; idx < totalPairs; idx++) {
//            cout << "( " << cartesianProduct[idx][0] << ", " << cartesianProduct[idx][1] << " ) ";
//        }
//        cout << "}" << endl;
//    }
//
//    // Check reflexivity of the relation
//    bool checkReflexivity() {
//        for (int xIdx = 0; xIdx < countX; xIdx++) {
//            bool isPresent = false;
//            for (int pairIdx = 0; pairIdx < totalPairs; pairIdx++) {
//                if (setX[xIdx] == cartesianProduct[pairIdx][0] && setX[xIdx] == cartesianProduct[pairIdx][1]) {
//                    isPresent = true;
//                    break;
//                }
//            }
//            if (!isPresent) return false;
//        }
//        return true;
//    }
//
//    // Calculate total relations
//    int totalRelations() {
//        return pow(2, totalPairs);
//    }
//
//    // Count reflexive relations
//    int reflexiveRelationsCount() {
//        analyzePairs();
//        return pow(2, nonDiagPairs);
//    }
//
//    // Count symmetric relations
//    int symmetricRelationsCount() {
//        analyzePairs();
//        return pow(2, diagPairs) * pow(2, nonDiagPairs / 2);
//    }
//
//    // Count anti-symmetric relations
//    int antisymmetricRelationsCount() {
//        analyzePairs();
//        return pow(2, diagPairs) * pow(3, nonDiagPairs / 2);
//    }
//
//    // Menu for interaction
//    void displayMenu() {
//        while (true) {
//            system("pause");
//            system("cls");
//            cout << "\n--- MENU ---\n";
//            cout << "1) Initialize sets X and Y\n";
//            cout << "2) Display X, Y, and Cartesian product\n";
//            cout << "3) Union of X and Y\n";
//            cout << "4) Intersection of X and Y\n";
//            cout << "5) X - Y\n";
//            cout << "6) Y - X\n";
//            cout << "7) Check reflexivity\n";
//            cout << "8) Reflexive relations count\n";
//            cout << "9) Symmetric relations count\n";
//            cout << "10) Anti-symmetric relations count\n";
//            cout << "11) Exit\n";
//            cout << "Enter your choice: ";
//
//            int option;
//            validatedInput(option, 1, 11);
//
//            switch (option) {
//            case 1:
//                initializeSizes();
//                inputSetX();
//                inputSetY();
//                break;
//            case 2:
//                cout << "Set X: ";
//                displaySet(setX, countX);
//                cout << "\nSet Y: ";
//                displaySet(setY, countY);
//                cout << "\nCartesian Product: ";
//                calculateCartesianProduct();
//                showCartesianProduct();
//                break;
//            case 3:
//                cout << "Union of X and Y: ";
//                displaySet(computeUnion().data(), computeUnion().size());
//                cout << endl;
//                break;
//            case 4:
//                cout << "Intersection of X and Y: ";
//                displaySet(computeIntersection().data(), computeIntersection().size());
//                cout << endl;
//                break;
//            case 5:
//                cout << "X - Y: ";
//                displaySet(computeDifference(setX, countX, setY, countY).data(), computeDifference(setX, countX, setY, countY).size());
//                cout << endl;
//                break;
//            case 6:
//                cout << "Y - X: ";
//                displaySet(computeDifference(setY, countY, setX, countX).data(), computeDifference(setY, countY, setX, countX).size());
//                cout << endl;
//                break;
//            case 7:
//                cout << (checkReflexivity() ? "Relation is reflexive.\n" : "Relation is not reflexive.\n");
//                break;
//            case 8:
//                cout << "Reflexive relations count: " << reflexiveRelationsCount() << endl;
//                break;
//            case 9:
//                cout << "Symmetric relations count: " << symmetricRelationsCount() << endl;
//                break;
//            case 10:
//                cout << "Anti-symmetric relations count: " << antisymmetricRelationsCount() << endl;
//                break;
//            case 11:
//                cout << "Exiting program.\n";
//                return;
//            default:
//                cout << "Invalid option. Try again.\n";
//            }
//        }
//    }
//};
//
//int main() {
//    RelationSet relationManager;
//    relationManager.displayMenu();
//    return 0;
//}

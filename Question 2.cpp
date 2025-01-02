//#include <iostream>
//#include <unordered_map>
//#include <unordered_set>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//class FunctionAnalysis
//{
//public:
//    unordered_map<string, string> functionMap; // Map Domain Values To Codomain Values
//    vector<string> domainValues; // Store Domain Values
//    vector<string> codomainValues; // Store Codomain Values
//
//    // Add Mapping
//    void addMapping()
//    {
//        for (size_t i = 0; i < domainValues.size(); ++i)
//        {
//            functionMap[domainValues[i]] = codomainValues[i]; // Map Domain Value & Corresponding Codomain Values
//        }
//    }
//
//    // Check If The Function Is "Into"
//    bool isInto()
//    {
//        unordered_set<string> codomainSet(codomainValues.begin(), codomainValues.end());
//        for (const auto& pair : functionMap)
//        {
//            codomainSet.erase(pair.second); // Remove CoDomain Value When It's Covered
//        }
//        return !codomainSet.empty(); // If Codomain Values Are Not All Covered
//    }
//
//    // Check If The Function Is "Onto"
//    bool isOnto(unordered_set<string>& codomainSet)
//    {
//        for (auto& pair : functionMap)
//        {
//            codomainSet.erase(pair.second); // Remove CoDomain Value When It's Covered
//        }
//        return codomainSet.empty(); // If Codomain Values Are All Covered
//    }
//
//    // Check If The Function Is "One-To-One"
//    bool isOneToOne()
//    {
//        unordered_set<string> seenCodomainValues;
//        for (auto& pair : functionMap)
//        {
//            if (seenCodomainValues.find(pair.second) != seenCodomainValues.end())
//            {
//                return false; // Check For Duplicate Values
//            }
//            seenCodomainValues.insert(pair.second);
//        }
//        return true;
//    }
//
//    // Check If The Function Is "Inverse"
//    bool isInverse(unordered_set<string>& codomainValues)
//    {
//        return isOneToOne() && isOnto(codomainValues);
//    }
//
//    // Display Inverse Function
//    void displayInverse()
//    {
//        unordered_map<string, string> inverseMap;
//        for (const auto& pair : functionMap)
//        {
//            inverseMap[pair.second] = pair.first; // Reverse the mapping
//        }
//        cout << "Inverse Function: " << endl;
//        for (const auto& pair : inverseMap)
//        {
//            cout << pair.first << " -> " << pair.second << endl;
//        }
//    }
//
//    // Display Function
//    void displayFunction()
//    {
//        cout << "Function Mapping: " << endl;
//        for (const auto& pair : functionMap)
//        {
//            cout << pair.first << " -> " << pair.second << endl;
//        }
//    }
//};
//
//void composeFunctions(FunctionAnalysis& f1, FunctionAnalysis& f2)
//{
//    unordered_map<string, string> compositionMap;
//    for (const auto& pair1 : f1.functionMap)
//    {
//        auto it = f2.functionMap.find(pair1.second);
//        if (it != f2.functionMap.end())
//        {
//            compositionMap[pair1.first] = it->second; // f2(f1(x))
//        }
//    }
//    cout << "Composition of Functions: " << endl;
//    for (const auto& pair : compositionMap)
//    {
//        cout << pair.first << " -> " << pair.second << endl;
//    }
//}
//
//void clearScreen()
//{
//    system("cls");
//}
//
//int main()
//{
//    vector<FunctionAnalysis> functions;
//    int choice;
//
//    do {
//        clearScreen(); // Clear the screen before showing the menu
//
//        cout << "Menu:\n";
//        cout << "1. Define a new function\n";
//        cout << "2. Check if a function is 'into'\n";
//        cout << "3. Check if a function is 'onto'\n";
//        cout << "4. Check if a function has an inverse\n";
//        cout << "5. Display the inverse function\n";
//        cout << "6. Compose two functions\n";
//        cout << "7. Display all functions\n";
//        cout << "0. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//        cout << endl;
//        switch (choice)
//        {
//        case 1:
//        {
//            clearScreen(); // Clear the screen before showing error or menu
//            FunctionAnalysis func;
//            unordered_set <string> codomainSet;
//            int domainSize, codomainSize;
//
//            // Get Sizes
//            cout << "Enter The Size Of The Domain: ";
//            cin >> domainSize;
//
//            cout << "Enter The Size Of The Co-Domain: ";
//            cin >> codomainSize;
//
//            // Resize domainValues and codomainValues vectors
//            func.domainValues.resize(domainSize);
//            func.codomainValues.resize(codomainSize+1);
//
//            // Get Domain Values (exactly domainSize values)
//            cout << "Enter " << domainSize << " Domain Values: ";
//            for (int i = 0; i < domainSize; ++i)
//            {
//                cin >> func.domainValues[i]; // Take input for each domain value
//            }
//
//            // Get Co-Domain Values (exactly codomainSize values)
//            cout << "Enter " << codomainSize << " Co-Domain Values: ";
//            for (int i = 0; i < codomainSize; ++i)
//            {
//                cin >> func.codomainValues[i]; // Take input for each codomain value
//                codomainSet.insert(func.codomainValues[i]); // Insert into codomainSet
//            }
//
//            func.addMapping(); // Map the domain and codomain values
//            functions.push_back(func);  // Add the function to the list
//            cout << "Function added successfully!" << endl;
//            system("pause");
//            break;
//        }
//        case 2:
//        {
//            if (functions.empty())
//            {
//                clearScreen();
//                cout << "Error: No functions defined yet. Please define a function first." << endl;
//                system("pause");
//                break;
//            }
//            int index;
//            cout << "Enter the index of the function to check (0 to " << functions.size() - 1 << "): ";
//            cin >> index;
//            while (index < 0 || index >= functions.size())
//            {
//                clearScreen();
//                cout << "Invalid index. Please enter again (0 to " << functions.size() - 1 << "): ";
//                cin >> index;
//            }
//            cout << (functions[index].isInto() ? "The function is 'into'." : "The function is not 'into'.") << endl;
//            system("pause");
//            break;
//        }
//        case 3:
//        {
//            if (functions.empty())
//            {
//                clearScreen();
//                cout << "Error: No functions defined yet. Please define a function first." << endl;
//                system("pause");
//                break;
//            }
//            int index;
//            cout << "Enter the index of the function to check (0 to " << functions.size() - 1 << "): ";
//            cin >> index;
//            while (index < 0 || index >= functions.size())
//            {
//                clearScreen();
//                cout << "Invalid index. Please enter again (0 to " << functions.size() - 1 << "): ";
//                cin >> index;
//            }
//            unordered_set<string> codomainSet(functions[index].codomainValues.begin(), functions[index].codomainValues.end());
//            cout << (functions[index].isOnto(codomainSet) ? "The function is 'onto'." : "The function is not 'onto'.") << endl;
//            system("pause");
//            break;
//        }
//        case 4:
//        {
//            if (functions.empty())
//            {
//                clearScreen();
//                cout << "Error: No functions defined yet. Please define a function first." << endl;
//                system("pause");
//                break;
//            }
//            int index;
//            cout << "Enter the index of the function to check for inverse (0 to " << functions.size() - 1 << "): ";
//            cin >> index;
//            while (index < 0 || index >= functions.size())
//            {
//                clearScreen();
//                cout << "Invalid index. Please enter again (0 to " << functions.size() - 1 << "): ";
//                cin >> index;
//            }
//            unordered_set<string> codomainSet(functions[index].codomainValues.begin(), functions[index].codomainValues.end());
//            cout << (functions[index].isInverse(codomainSet) ? "The function has an inverse." : "The function does not have an inverse.") << endl;
//            system("pause");
//            break;
//        }
//        case 5:
//        {
//            if (functions.empty())
//            {
//                clearScreen();
//                cout << "Error: No functions defined yet. Please define a function first." << endl;
//                system("pause");
//                break;
//            }
//            int index;
//            cout << "Enter the index of the function to display inverse (0 to " << functions.size() - 1 << "): ";
//            cin >> index;
//            while (index < 0 || index >= functions.size())
//            {
//                clearScreen();
//                cout << "Invalid index. Please enter again (0 to " << functions.size() - 1 << "): ";
//                cin >> index;
//            }
//            functions[index].displayInverse(); // Display inverse of the function
//            system("pause");
//            break;
//        }
//        case 6:
//        {
//            if (functions.size() < 2)
//            {
//                clearScreen();
//                cout << "Error: At least two functions are required to compose." << endl;
//                system("pause");
//                break;
//            }
//            int index1, index2;
//            cout << "Enter the index of the first function to compose (0 to " << functions.size() - 1 << "): ";
//            cin >> index1;
//            cout << "Enter the index of the second function to compose (0 to " << functions.size() - 1 << "): ";
//            cin >> index2;
//            while (index1 < 0 || index1 >= functions.size() || index2 < 0 || index2 >= functions.size())
//            {
//                clearScreen();
//                cout << "Invalid indices. Please enter again (0 to " << functions.size() - 1 << "): ";
//                cin >> index1 >> index2;
//            }
//            composeFunctions(functions[index1], functions[index2]); // Compose two functions
//            system("pause");
//            break;
//        }
//        case 7:
//        {
//            clearScreen();
//            for (size_t i = 0; i < functions.size(); ++i)
//            {
//                cout << "Function " << i << ":" << endl;
//                functions[i].displayFunction(); // Display all functions
//            }
//            system("pause");
//            break;
//        }
//        case 0:
//            break;
//        default:
//            clearScreen();
//            cout << "Invalid choice. Please try again." << endl;
//            system("pause");
//            break;
//        }
//
//    } while (choice != 0);
//
//    return 0;
//}

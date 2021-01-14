#include <iostream>
#include "Translate.h"

int main() {
    setlocale(LC_ALL, "Russian");
    using namespace std;
    int SizeOfString = 500;
    char *str = new char[SizeOfString];
    cout << "Write a string smaller than " << SizeOfString << " symbols" << endl;
    cin.getline(str, SizeOfString);
    cout << GetTranslate(str);
}
#include <iostream>
using namespace std;
//
const char* EnglishSym[] =
        {
                "a", "b", "v", "g", "d", "e", "jo", "zh", "z", "i", "j", "k", "l", "m", "n", "o", "p", "r", "s", "t", "u", "f", "kh", "ts", "ch", "sh", "shch", "\"", "y", "\'", "eh", "ju", "ja",
                "A", "B", "V", "G", "D", "E", "Jo", "Zh", "Z", "I", "J", "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "F", "Kh", "Ts", "Ch", "Sh", "Shch", "", "Y", "", "Eh", "Ju", "Ja"
        };
const char* RussianSym[] =
        {
                "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я",
                "А", "Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я"
        };


bool IsCyrrilic(char sym) // Проверка на русские символы
{
    if (sym == '\xD0' || sym == '\xD1')
        return true;
    else
        return false;
}

bool isEndOfString(char sym, int num){
    if (sym == '\0' || num >= 500)
        return false;
    else
        return true;
}

void add(char* res, unsigned int& iRes, const char* symbols, char maxi = 1)
{
    char i = 0;
    while (symbols[i] != '\0' && i < maxi)
    {
        res[iRes++] = symbols[i++];
    }
}
void TryToFind (char* result, const char* str, unsigned int& i, unsigned int& k) { // Проверям символ
    bool Found = false;
    char j = 0;
    while (j < 66 && !Found) {
        if (RussianSym[j][0] == str[i] && RussianSym[j][1] == str[i + 1]) {
            add(result, k, EnglishSym[j], 4);
            Found = true;
        }
        j++;
    }
    if (!Found)
        add(result, k, &str[i], 2);
    i += 2;
}
char* GetTranslate(const char* str)
{
    unsigned int i = 0; // счетчик / позиция в str
    unsigned int k = 0; // позиция символа в result
    char* result = new char [500];

    while (isEndOfString(str[i], i)) {
        if (IsCyrrilic(str[i]))
            TryToFind(result, str, i,k);
        else {
            add(result, k, &str[i]);
            i++;
        }
    }
    result[k] = '\0';
    return result;
}

#include <iostream>
#include <string>
#include <string.h>

void printString(const std::string & str) {
    std::cout << str << std::endl;
}

int main() {

    // C-style

    const char * name = "Miguel";
    std::cout << name << std::endl;

    name = "Brites";
    std::cout << name << std::endl;

    char address[18] = {'R', 'u', 'a', ' ', 'P', 'e', 'd', 'r', 'o', ' ', 'H', 'i', 's', 'p', 'a', 'n', 'o', '\0'};
    std::cout << address << std::endl;

    char floor[] = "6o Esq"; // This creates a modifiable C-style string in writable memory
    std::cout << floor << std::endl;

    floor[3] = 'D';
    floor[4] = 'i';
    floor[5] = 'r';

    std::cout << floor << std::endl;

    char * test = (char *) "Miguel"; // This cast DOES NOT ALLOW YOU TO MAKE CHANGES TO THE STRING LITERAL.
    std::cout << test << std::endl;

    std::cout << strlen(test) << std::endl; // This function is defined in the "string.h" header. It counts the number of characters until a null-terminator character

    // C++ style

    std::string countryAndCity = "Portugal";
    std::cout << countryAndCity << std::endl;
    countryAndCity += ", Oeiras";

    // You can also do: std::string countryAndCity = std::string("Portugal") + ", Oeiras";

    bool contains = countryAndCity.find(",") != std::string::npos; // Just to exemplify 'npos'. It is a constant value in C++ that can be used to confirm whether a string literal (or substring) is not found in a std::string.

    using namespace std::string_literals;

    std::string name0 = "Miguel"s + " hello";
    std::cout << name0 << std::endl;

    // Widestrings

    const wchar_t * bigName = L"MIGUEL!"; // 2-bytes on Windows; 4-bytes on Linux/MacOS
    const char16_t* bigName2 = u"MARTINS!"; // 2 bytes
    const char32_t* bigName3 = U"BRITES!"; // 4-bytes

    std::wstring bigName4 = L"MIGUEEEEEEEL";
    std::wcout << bigName4 << std::endl;

    const char * example = R"(Line1
Line2
Line3
Line4)"; // Useful for multi-line strings. Though you can also use '\n'

    const char * example1 = "Line1\nLine2\nLine3";

    std::cout << example1 << std::endl;

}
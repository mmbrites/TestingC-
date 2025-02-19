#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

int main()
{
    std::u16string u16_text = u"Hello, 世界!";

    // Convert UTF-16 to UTF-8 because you cannot print UTF-16 to the console
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
    std::string utf8_text = converter.to_bytes(u16_text);
    std::cout << utf8_text << std::endl;

    return 0;
}
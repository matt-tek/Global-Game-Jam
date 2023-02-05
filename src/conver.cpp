
#include <locale>
#include <codecvt>
#include <string>

std::wstring s2ws(std::string &str)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    return (converter.from_bytes(str));
}
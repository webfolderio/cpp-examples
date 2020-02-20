#include <iostream>
#include <utility>
#include <locale>
#include <clocale>

#ifdef _MSC_VER
#include <Windows.h>
#include <wchar.h>
#include <WinNls.h>
#endif

class Person {
private:
    std::string name_;

public:
    explicit Person(std::string name) : name_(std::move(name)) { }

    std::string name() {
        return name_;
    }

    static void print(const std::shared_ptr<Person>& person) {
        std::cout << person->name() << std::endl;
    }
};

static std::string GetLocale() {
#ifdef _MSC_VER
    wchar_t locale[LOCALE_NAME_MAX_LENGTH] = {};
    int ret = GetUserDefaultLocaleName(locale, sizeof(locale) / sizeof(*(locale)));
    if(ret == 0) {
        return "";
    }
    std::wstring wlocale(locale);
    return std::string(wlocale.begin(), wlocale.end());
#elif
    return "";
#endif
}

int main(int argc, char** argv) {
    auto str = GetLocale();
    if (!str.empty()) {
        std::wcout.imbue(std::locale(str + ".utf8")); // configure C++ I/O
        std::setlocale(LC_ALL, (str + ".utf8").c_str()); // needed if C++ I/O goes through C I/O
    }
    auto me = std::make_shared<Person>(Person{"Turkish Lang Test: öÖçÇşŞiİğĞüÜıI"});
    Person::print(me);
    return 0;
}

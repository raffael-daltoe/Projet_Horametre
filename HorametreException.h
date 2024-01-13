#ifndef HORAMETREEXCEPTION_H
#define HORAMETREEXCEPTION_H


#include <stdexcept>
#include <typeinfo>
#include <exception>

using namespace std;

class HorametreException : public exception{
    public:
        enum Raison{
            FILE_PROBLEM,
            STRING_TROP_GD
        };
        HorametreException(Raison cs) noexcept;
        const char* what() const noexcept;
    private:
        Raison cause;
};

#endif

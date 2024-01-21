#ifndef IHMHORAMETREEXCEPTION_H
#define IHMHORAMETREEXCEPTION_H


#include <stdexcept>
#include <typeinfo>
#include <exception>

using namespace std;

class IhmHorametreException : public exception{
    public:
        enum Raison{
            FILE_PROBLEM,
            STRING_TROP_GD,
            NB_NEGATIF
        };
        IhmHorametreException(Raison cs) noexcept;
        const char* what() const noexcept;
    private:
        Raison cause;
};

#endif

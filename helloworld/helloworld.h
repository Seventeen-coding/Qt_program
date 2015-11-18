#ifndef HELLOWORLD_H
#define HELLOWORLD_H

#include "helloworld_global.h"
#include "dialog.h"
class HELLOWORLDSHARED_EXPORT Helloworld
{

public:
    Helloworld();
};


extern "C" Q_DECL_EXPORT void print_str(QString str);
extern "C" Q_DECL_EXPORT QDialog *showDialog();
#endif // HELLOWORLD_H

#ifndef UTILITIES_H
#define UTILITIES_H

#include <QString>
#include <QStringList>

#include "song.h"

class Utilities{
public:
    Utilities();
    ~Utilities();
public:
    bool static checkFiles(QString filename);
    QStringList static extractData(QString filename);
    static Song* convert2song(QString filename);
};


#endif // UTILITIES_H


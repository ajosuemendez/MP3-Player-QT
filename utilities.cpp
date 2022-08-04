#include "utilities.h"
#include <QString>
Utilities::Utilities(){

}

bool Utilities::checkFiles(QString filename){
    return filename.endsWith(".mp3");
}

QStringList Utilities::extractData(QString filename){
    QString splitFormat = "_-_";
    QStringList splitedPath = filename.split("/", Qt::SkipEmptyParts);
    QStringList splitFileName = splitedPath.takeLast().split(splitFormat);
    return splitFileName;
}

Song* Utilities::convert2song(QString filename){
    QString splitFormat = "_-_";
    QStringList splitedPath = filename.split("/", Qt::SkipEmptyParts);
    QStringList splitFileName = splitedPath.takeLast().split(splitFormat);
    Song *createdSong = new Song(splitFileName[0], splitFileName[1], filename);
    return createdSong;
}
;

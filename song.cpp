#include "song.h"
#include <QString>
#include <QStringList>
#include <QAudioOutput>
#include <QUrl>



Song::Song(){
    this->author = "default";
    this->album = "default";
    this->year = "default";
    this->songDuration = "default";
}


Song::Song(QString author, QString album, QString year, QString duration){
    this->author = author;
    this->year = year;
    this->album = album;
    this->songDuration = duration;
}

Song::Song(QString author, QString name, QString fileLocation){
    this->author = author;
    this->name = name;
    this->fileLocation = fileLocation;
    this->setAudioOutput(new QAudioOutput());
    this->setSource(QUrl(fileLocation));
}

QStringList Song::getListInfo(){
    QStringList info;
    info.append(this->author);
    info.append(this->year);
    info.append(this->album);
    info.append(this->songDuration);

    return info;
    }

QString Song::getInfo(){
    return QString(this->name + "\n" + this->author +"\n");
}

QString Song::getSongName(){
    return this->name;
}

QString Song::getFileLocation(){
    return this->fileLocation;

}
QString Song::getAuthorName(){
    return this->author;
}
QString Song::getSongDuration(){
    int totalSeconds = static_cast<int>(this->duration())/(1000);
    int min = totalSeconds/60;
    int sec = totalSeconds % 60;
    QString symbol;

    if(sec<10){
        symbol = ":0";
    }
    else{
        symbol = ":";
    }
    return QString::number(min) + symbol + QString::number(sec);
}

void Song::setNextStateTag(QString tag){
    this->nexStateTag = tag;
}

QString Song::getNexStateTag(){
    return this->nexStateTag;

}
;

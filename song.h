#ifndef SONG_H
#define SONG_H

#include <QString>
#include <QStringList>
#include <QMediaPlayer>


class Song : public QMediaPlayer{
private:
    QString name;
    QString author;
    QString album;
    QString year;
    QString songDuration;
    QString fileLocation;
    QString nexStateTag;


public:
    Song();
    Song(QString author, QString name, QString fileLocation);
    Song(QString author, QString album, QString year, QString duration);
public:
    QStringList getListInfo();
    QString getInfo();
    QString getSongName();
    QString getAuthorName();
    QString getFileLocation();
    QString getSongDuration();
    void setNextStateTag(QString tag);
    QString getNexStateTag();

};

#endif // SONG_H

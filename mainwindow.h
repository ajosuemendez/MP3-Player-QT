#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "library.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    Library lib;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    void displaySongInfo(Song* selectedSong);

public slots:
    void openActionClick();
    void loadMP3ActionClick();
    void updateSongTime();
    void playPauseClick();
    void nextSongClick();
    void backClick();


private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

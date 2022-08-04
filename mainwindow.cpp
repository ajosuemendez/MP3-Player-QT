#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities.h"
//#include "song.h"
//#include "controlManager.h"
#include <vector>
#include <string>

#include <QFileDialog>
#include <QThread>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowTitle("my cool app");

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openActionClick);
    //connect(ui->actionOpen, &QAction::triggered, [=](){ui->label1->setText("Open Clicked...");}); //lambda
    connect(ui->actionMp3_Files, &QAction::triggered, this, &MainWindow::loadMP3ActionClick);
    connect(ui->addSongsPushButton, &QAbstractButton::clicked, this, &MainWindow::loadMP3ActionClick);
    connect(ui->playPushButton, &QAbstractButton::clicked, this, &MainWindow::playPauseClick);
    connect(ui->SongsList, &QListWidget::itemDoubleClicked, this, &MainWindow::playPauseClick);
    connect(ui->nextPushButton, &QAbstractButton::clicked, this, &MainWindow:: nextSongClick);
    connect(ui->backPushButton, &QAbstractButton::clicked, this, &MainWindow::backClick);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openActionClick()
{
    QString filename = QFileDialog::getOpenFileName();
    //ui->label1->setText(filename);
    statusBar()->showMessage("this is the status bar",1000); //(text, delete in ms)

    QMediaPlayer* qm = new QMediaPlayer();
    qm->setAudioOutput(new QAudioOutput());
    qm->setSource(QUrl(filename));
    qm->play();
}


void MainWindow::loadMP3ActionClick()
{
    QStringList filename = QFileDialog::getOpenFileNames();
    for(int i=0;i<filename.size();i++){
        if(Utilities::checkFiles(filename[i])){
           lib.addSong(Utilities::convert2song(filename[i]));
           ui->SongsList->addItem(lib.getlastSong()->getSongName());
        }
        else {
            QMessageBox* message = new QMessageBox();
            message->setText("Wrong format....make sure to add a '.mp3' format file");
            message->exec();
            delete message;
        }
    }
}


void MainWindow::playPauseClick(){
    if(lib.getTotalSongs() < 1){return;}
    int listSongIndex = ui->SongsList->currentRow();
    lib.setCurrentSong(lib.getSongAtIndex(listSongIndex));
    lib.updateLibraryIndex(listSongIndex);
    lib.performAction();
    this->displaySongInfo(lib.getCurrentSong());
}

void MainWindow::updateSongTime(){
    return;
}

void MainWindow::nextSongClick(){
    if(lib.getTotalSongs() < 1){return;}
    lib.setNextSong(true); // we want to set the next song on the list
    ui->SongsList->setCurrentRow(lib.getLibraryIndex());
    lib.performAction();
    this->displaySongInfo(lib.getCurrentSong());
}

void MainWindow::backClick(){
    if(lib.getTotalSongs() < 1){return;}
    lib.setNextSong(false); //we want to set the previous song on the list instead
    ui->SongsList->setCurrentRow(lib.getLibraryIndex());
    lib.performAction();
    this->displaySongInfo(lib.getCurrentSong());
}

void MainWindow::displaySongInfo(Song* selectedSong){
    ui->songLabel->setText(selectedSong->getSongName());
    ui->authorLabel->setText(selectedSong->getAuthorName());
    ui->timeLabel->setText(selectedSong->getSongDuration());
    ui->playPushButton->setText(selectedSong->getNexStateTag());
}

;

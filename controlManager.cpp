/*
#include "controlManager.h"
#include "song.h"

controlManager::controlManager(){
    this->stack = new Library;
}

controlManager::controlManager(Library *lib){
    this->stack = lib;
}

void controlManager::startPlaying(Song song){
    this->stack->setCurrentSong(song);
    this->stack->play();
    this->currentState = State::Playing;
}

void controlManager::stopPlaying(){
    this->stack->stop();
}

void controlManager::resumePlaying(){
    this->stack->pause();
}

*/

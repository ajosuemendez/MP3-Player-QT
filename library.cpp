#include "library.h"
#include "song.h"
#include "utilities.h"

Library::Library(){
    this->m_totalSongs = 0;
    this->m_library_index = 0;
    this->currentState = StateMedia::Stop;
    this->m_currentSong = NULL;
}

int Library::getTotalSongs(){
    return this->m_totalSongs;
}
Song* Library::getCurrentSong(){
    return this->m_currentSong;
}

Song* Library::getSongAtIndex(int index){
    return m_songCollection[index];
}

std::vector<Song*> Library::getSongCollection(){
    return m_songCollection;
}

void Library::addSong(Song* song){
    //adding song to collection
    m_songCollection.push_back(song);
    this->m_totalSongs +=1;
    return;
}

void Library::deleteSong(Song* song){
    //search for requested song
    //deleting song from collection
    return;
}

void Library::updateLibraryIndex(int index){
    this->m_library_index = index;
}

int Library::getLibraryIndex(){
    return this->m_library_index;
}

void Library::setNextSong(bool previous=false){
    this->setLastSetSong(m_currentSong);
    this->setNextLibraryIndex(previous);
    this->m_currentSong = m_songCollection[m_library_index];
    this->setCurrentSong(m_currentSong);
    return;
 }

void Library::setNextLibraryIndex(bool previous){
    if(this->m_library_index <= 0 && previous==true){
        this->m_library_index = this->m_totalSongs-1;
        return;
    }
    if(this->m_library_index >= 0 && this->m_library_index <= this->m_totalSongs-2 && previous==false){
        this->m_library_index += 1;
        return;
    }
    if(this->m_library_index >= 1 && this->m_library_index <= this->m_totalSongs-1 && previous==true){
        this->m_library_index -= 1;
        return;
    }
    if(this->m_library_index == m_totalSongs-1 && previous==false){
        this->m_library_index =0;
        return;
    }
}

void Library::setCurrentSong(Song* song){
    this->m_currentSong = song;
}

Song* Library::getlastSong(){
    return m_songCollection.back();
}

Song* Library::getLastSetSong(){
    return this->m_last_set_song;
}

void Library::setLastSetSong(Song* currentSong){
    this->m_last_set_song = currentSong;
}

Library::StateMedia Library::getCurrentState(){
    return this->currentState;
}

void Library::CheckingState(){
    switch(this->getCurrentState()){
    case StateMedia::Playing:
        this->sameSongPlayingCheck();
        break;
    case StateMedia::Stop:
        this->startSong();
        break;
    case StateMedia::Paused:
        this->sameSongPausedCheck();
        break;
    }
    return;
}

void Library::setCurrentState(StateMedia state){
    this->currentState = state;
}

void Library::sameSongPlayingCheck(){
    if(this->getLastSetSong()->getSongName() == this->getCurrentSong()->getSongName()){
        this->getCurrentSong()->pause();
        this->getCurrentSong()->setNextStateTag("Play");
        this->setCurrentState(StateMedia::Paused);
        return;
    }
    this->getLastSetSong()->stop();
    this->setCurrentState(StateMedia::Stop);
    this->getCurrentSong()->play();
    this->getCurrentSong()->setNextStateTag("Pause");
    this->setCurrentState(StateMedia::Playing);
    return;
}

void Library::startSong(){
    this->updateNewSong();
    this->getCurrentSong()->play();
    this->setCurrentState(StateMedia::Playing);
    this->getCurrentSong()->setNextStateTag("Pause");
    return;
}

void Library::sameSongPausedCheck(){
    if(this->getLastSetSong()->getSongName() == this->getCurrentSong()->getSongName()){
        this->getCurrentSong()->play();
        this->setCurrentState(StateMedia::Playing);
        this->getCurrentSong()->setNextStateTag("Pause");
        return;
    }
    this->getLastSetSong()->stop();
    this->setCurrentState(StateMedia::Stop);
    this->updateNewSong();
    this->getCurrentSong()->play();
    this->setCurrentState(StateMedia::Playing);
    this->getCurrentSong()->setNextStateTag("Pause");

    return;
}

void Library::updateNewSong(){
    this->setLastSetSong(this->getCurrentSong());
}

void Library::performAction(){
    this->CheckingState();
    this->updateNewSong();
}

;

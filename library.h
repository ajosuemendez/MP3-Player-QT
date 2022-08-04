#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "song.h"
#include <QMediaPlayer>

class Library{

public:
    enum class StateMedia{Stop, Playing, Paused};

private:

    StateMedia currentState;
    int m_totalSongs;
    std::vector<Song*> m_songCollection;
    Song* m_currentSong;
    int m_library_index;
    Song* m_last_set_song;


public:
    //Getters
    int getTotalSongs();
    Song* getCurrentSong();
    Song* getSongAtIndex(int index);
    Song* getlastSong();
    Song* getLastSetSong();
    std::vector<Song*> getSongCollection();
    int getLibraryIndex();
    StateMedia getCurrentState();

    //Setters
    void setNextSong(bool previous);
    void setCurrentSong(Song* song);
    void setLastSetSong(Song* currentSong);
    void setCurrentState(StateMedia);
    void setNextLibraryIndex(bool previous);

    //Library Modifiers
    void addSong(Song* toAddSong);
    void deleteSong(Song* toDeleteSong);

    //Updates
    void updateNewSong();
    void updateLibraryIndex(int index);

    //Auxilliary Methods
    void CheckingState();
    void performAction();
    void sameSongPlayingCheck();
    void startSong();
    void sameSongPausedCheck();



public:
    Library();
    //~Library();

};

#endif // LIBRARY_H

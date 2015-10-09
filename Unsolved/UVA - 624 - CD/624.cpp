#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Playlist{
  set<pair<int,int>> tracks;
  int duration;
};

/*void backtrackRec(Playlist &actual, set<pair<int,int>> &available, Playlist &best, int max){
  if(actual.duration <= max){
    if((actual.duration > best.duration) || ((actual.duration == best.duration) && (actual.tracks.size() > best.tracks.size()))){
      best = actual;
      if(best.duration == max){
        return;
      }
    }
    for(auto x : available){
      pair<int,int> a = x;
      available.erase(x);
      actual.tracks.insert(a);
      actual.duration += a.first;
      backtrackRec(actual, available, best, max);
      actual.duration -= a.first;
      actual.tracks.erase(a);
      available.insert(x);
    }
  }
}

Playlist backtrack(set<pair<int,int>> tracksAvailable, int max){
  set<pair<int,int>> temp;
  int d = 0;
  Playlist best;
  best.tracks = temp;
  best.duration = d;
  for(auto x : tracksAvailable){
    set<pair<int,int>> tracks = tracksAvailable;
    tracks.erase(x);
    Playlist temp;
    temp.duration = x.first;
    temp.tracks.insert(x);
    backtrackRec(temp, tracks, best, max);
    //temp.tracks.erase(x);
    //tracks.insert(x);
  }
  return best;
}*/
/*void backtrack(deque<int> &tracksChosen, int currentDuration, deque<int> &tracksAvailable, int maxDuration,map<deque<int>, int> &playlists){
  if(currentDuration > maxDuration){
    return;
  }
  deque<int> removed;
  while(!tracksAvailable.empty()){
    int x = tracksAvailable[0];
    tracksAvailable.erase(tracksAvailable.begin());
    removed.push_back(x);
    tracksChosen.push_back(x);
    backtrack(tracksChosen, currentDuration+x, tracksAvailable, maxDuration, playlists);
    tracksChosen.erase(tracksChosen.end());
  }*/
  /*if(currentDuration < maxDuration){
    for(auto i = tracksAvailable.begin(); i != tracksAvailable.end(); i++){
      if(currentDuration + i <= maxDuration){
        auto lastOne = tracksAvailable.end();
        lastOne--;
        auto next = i;
        next++;
        int value = i;
        tracksChosen.push_back(i);
        if(i == tracksAvailable.begin()){
          tracksAvailable.erase(i);
          backtrack(tracksChosen, currentDuration+vaue, tracksAvailable, maxDuration, playlists);
          tracksAvailable
        } else if(i == last){
          tracksAvailable.erase(i);
          backtrack(tracksChosen, currentDuration+vaue, tracksAvailable, maxDuration, playlists);
        } else{
          tracksAvailable.erase(i);
          backtrack(tracksChosen, currentDuration+vaue, tracksAvailable, maxDuration, playlists);
        }
      }
    }
  }
}
void backtrackPlaylists(set<int> chosen, int duration, set<int> available, int max, map<set<int>, int> &playlists){
  if(duration < max){
    for(int x : available){
      if(duration + x <= max){
        set<int> temp = available;
        temp.erase(x);
        chosen.insert(x);
        playlists[chosen]=duration+x;
        backtrackPlaylists(chosen, duration+x, temp, max, playlists);
        chosen.erase(x);
      }
    }
  }
}*/

int main(int argc, char const *argv[]) {
  int maxMin;

  while(cin >> maxMin){
    int nTracks;
    set<pair<int,int>> tracks;
    cin >> nTracks;
    //map<int, int> position;
    map<int, int> inversePosition;

    for(int i = 1; i <= nTracks; i++){
      int temp;
      cin >> temp;
      tracks.insert(pair<int,int>(temp, i));
      //position[temp] = i;
    }
    for(auto i : tracks){
      inversePosition[i.second] = i.first;
    }
    set<int> temp;
    map<set<int>, int> playlists;

    //backtrackPlaylists(temp, 0, tracks, maxMin, playlists);
    Playlist best = backtrack(tracks, maxMin);

    /*pair<set<int>, int> resultPlaylist;
    resultPlaylist.second = -1;
    for(auto x : playlists){
      if(x.second > resultPlaylist.second){
        resultPlaylist = x;
      }
    }*/
    vector<int> resultPlaylistUnsorted;

    for(auto x : best.tracks){
      int temp = x.second;
      resultPlaylistUnsorted.push_back(temp);
    }

    sort(resultPlaylistUnsorted.begin(), resultPlaylistUnsorted.end());

    for(int i = 0; i < resultPlaylistUnsorted.size(); i++){
      resultPlaylistUnsorted[i] = inversePosition[resultPlaylistUnsorted[i]];
    }
    //resultPlaylistUnsorted.second = resultPlaylist.second;
    for(auto x : resultPlaylistUnsorted){
      cout << x << " ";
    }
    cout << "sum:" << best.duration << "\n";
  }
  return 0;
}

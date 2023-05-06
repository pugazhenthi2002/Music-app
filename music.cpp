#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> songDetails = {
  {"Beliver","hiphop","Imagine Dragons","Album1","100","2003"},
  {"Hello","hiphopp","Imagine Dragons ","Album2","200","2003"},
  {"Dont let me down","melody","ChainSmokers","Album3","150","2003"},
  {"closer","melody","ChainSmokers","Album4","120","2003"},
  {"Alone","rock","Alan Walker","Album4","160","2003"},
  {"Faded","rock","Alan Walker","Album5","120","2003"}
};

//songName genreType artistName albumName Year
class Songs{
public:
static int songCount; 
int songId;
string songName;
int albumId;
int genreId;
int artistId;
int year;
}songs[100];


class Genre{
  public:
  static int genreCount;
  int genreId;
  string genreType;
}genre[100];

class Album{
  public:
  static int albumCount;
  int albumId;
  string albumName;
  int artistId;
  int subscription;
  int price;
}album[100];
class Artist{
  public:
  static int artistCount;
  int artistId;
  string artistName;
}artist[100];

class PlayList{
  public:
  static int playListCount;
  int playListId;
  string playListName;
  int songsCount;
  vector<Songs>songsList;
};
vector<PlayList>playListList;

int Songs::songCount = 0;
int Genre::genreCount = 0;
int Album::albumCount = 0;
int Artist::artistCount = 0;
int PlayList::playListCount = 0;

void displaySong()
{
  system("cls");
  for(int i=0;i<Songs::songCount;i++)
  {
    if(album[(songs[i].albumId)-1].subscription == true)
    {
      cout<<songs[i].songId<<" ";
      cout<<songs[i].songName<<" ";
      cout<<genre[(songs[i].genreId)-1].genreType<<" ";
      cout<<artist[(songs[i].artistId)-1].artistName<<" ";
      cout<<album[(songs[i].albumId)-1].albumName<<" ";
      cout<<songs[i].albumId<<" ";
      cout<<songs[i].artistId<<" ";
      cout<<songs[i].year<<endl;
    }
  }
}

void buySongs()
{
  system("cls");
  cout<<"---------Available Songs-----------"<<endl;
  for(int i=0;i<Album::albumCount;i++)
  {
    if(album[i].subscription != true)
    cout<<album[i].albumId<<"   "<<album[i].albumName<<" "<<album[i].price<<"   "<<endl;
  }
  cout<<"Enter the album id to buy the album"<<endl;
  int albumId;
  while(1)
  {
    cin>>albumId;
    if(albumId >Album::albumCount)
    {
      cout<<"Enter a valid Id or press 0 to exit"<<endl;
    }
    else if(albumId == 0)
    {
      break;
    }
    else
    {
      album[albumId-1].subscription = true;
      break;
    }
  }
}

void playAlbum()
{
  system("cls");
  cout<<"---------Available Albums-----------"<<endl;
  for(int i=0;i<Album::albumCount;i++)
  {
    
    if(album[i].subscription == true)
    {
      cout<<album[i].albumId<<"   "<<album[i].albumName<<"   "<<endl;
      cout<<"------------Songs in the album-----------------"<<endl;
      for(int j=0;j<Songs::songCount;j++)
      {
        if(songs[j].albumId == album[i].albumId)
        {
          cout<<songs[j].songId<<" ";
          cout<<songs[j].songName<<" ";
          cout<<genre[(songs[j].genreId)-1].genreType<<" ";
          cout<<artist[(songs[j].artistId)-1].artistName<<" ";
          cout<<album[(songs[j].albumId)-1].albumName<<" ";
          cout<<songs[j].year<<endl;
        }
      }
    }
    
  }
  cout<<"Enter the album id to play the album"<<endl;
  int albumId;
  
  while(1)
  {
    cin>>albumId;
    cout<<albumId<<endl;
    if(albumId >Album::albumCount)
    {
      cout<<"Enter a valid Id or press 0 to exit"<<endl;
    }
    else if(albumId == 0)
    {
      break;
    }
    else
    {
      break;
    }
  }
  vector<Songs>songList;
  for(int i=0;i<Songs::songCount;i++)
  {
    if(songs[i].albumId == albumId)
    {
      songList.push_back(songs[i]);
    }
  }
  int size = songList.size(), index = 0;
  for(int i=0;i<size;i++)
  {
    cout<<songList[i].songName<<endl;
  }
  while(1)
  {
    cout<<songList[index].songId<<"   "<<songList[index].songName<<"   "<<artist[(songList[index].artistId)-1].artistName<<endl;
    cout<<"1.For previous Song"<<endl;
    cout<<"2.For next song"<<endl;
    cout<<"3.To exxit"<<endl;
    int choice;
    cin>>choice;
    if(choice >= 1 && choice <=3)
    {
      if(choice == 1)
      {
        if(index == 0)
        {
          cout<<"No previous song"<<endl;
        }
        else
        {
          --index;
        }
      }
      else if(choice == 2)
      {
        if(index >= size-1)
        {
          cout<<"No next song"<<endl;
        }
        else{
          index++;
        }
      }
      else {
        break;
      }
    }
    else
    {
      cout<<" Enter a valid choice"s<<endl;
    }
  }
}

void createPlayList()
{
    PlayList newPlayList;
    PlayList::playListCount++;
    newPlayList.songsCount=0;
    cout<<"Enter the playList name"<<endl;
    newPlayList.playListId = PlayList::playListCount;
    cin>>newPlayList.playListName;
    while(1)
    {
      displaySong();
      cout<<"Enter the song Id to add"<<endl;
      cout<<"Enter 0 to exit"<<endl;
      int choice;
      cin>>choice;
      if(choice)
      {
        for(int i=0;i<Songs::songCount;i++)
        {
          if(songs[i].songId == choice)
          {
            newPlayList.songsList.push_back(songs[i]);
            newPlayList.songsCount++;
            cout<<"Successfully added"<<endl;
            break;
          }
        }
      }
      else{
        break;
      }
    }
    playListList.push_back(newPlayList);

}

void playPlayList(){
  cout<<"------------------Select a Playlist--------------------------"<<endl;
  for(int i=0;i<PlayList::playListCount;i++)
  {
    cout<<playListList[i].playListId<<"   "<<playListList[i].playListName<<endl;
  }
  cout<<"Enter the playList id to play"<<endl;
  int choice;
  cin>>choice;
  int size = playListList[choice-1].songsCount, index = 0;
  for(int i=0;i<size;i++)
  {
    cout<<playListList[choice-1].songsList[i].songName<<endl;
  }
  while(1)
  {
    cout<<playListList[choice-1].songsList[index].songId<<"   "<<playListList[choice-1].songsList[index].songName<<"   "<<endl;
    cout<<"1.For previous Song"<<endl;
    cout<<"2.For next song"<<endl;
    cout<<"3.To exxit"<<endl;
    int choice;
    cin>>choice;
    system("cls");
    if(choice >= 1 && choice <=3)
    {
      if(choice == 1)
      {
        if(index == 0)
        {
          cout<<"No previous song"<<endl;
        }
        else
        {
          --index;
        }
      }
      else if(choice == 2)
      {
        if(index >= size-1)
        {
          cout<<"No next song"<<endl;
        }
        else{
          index++;
        }
      }
      else {
        break;
      }
    }
    else
    {
      cout<<" Enter a valid choice"s<<endl;
    }
  }
}
int main()
{

  //songName genreType artistName albumName Year
  for(auto a:songDetails)
  {
    int songId = ++Songs::songCount;

    //Song Id
    songs[songId-1].songId = songId;
    songs[songId-1].songName = a[0];
    int flag = 0;

    //Genre Id
    int genreId;
    for(int i=0;i<Genre::genreCount;i++)
    {
      if(a[1] == genre[i].genreType)
      {
        flag = 1;
        genreId = genre[i].genreId;
        break;
      }
    }
    if(!flag)
    {
      genreId = ++Genre::genreCount;
      genre[genreId-1].genreId = genreId;
      genre[genreId-1].genreType = a[1];
    }
    songs[songId-1].genreId = genreId;

    //artist Name
    int artistId;
    for(int i=0;i<Artist::artistCount;i++)
    {
      if(a[2] == artist[i].artistName)
      {
        flag = 1;
        artistId = artist[i].artistId;
        break;
      }
    }
    if(!flag)
    {
      artistId = ++Artist::artistCount;
      artist[artistId-1].artistId = artistId;
      artist[artistId-1].artistName = a[2];
    }
    songs[songId-1].artistId = artistId;

    //AlbumId

    int albumid;
    for(int i=0;i<Album::albumCount;i++)
    {
      if(a[3] == album[i].albumName)
      {
        flag = 1;
        albumid = album[i].albumId;
        break;
      }
    }
    if(!flag)
    {
      albumid = ++Album::albumCount;
      album[albumid-1].albumId = albumid; 
      album[albumid-1].albumName = a[3]; 
      album[albumid-1].subscription = false;
      album[albumid-1].price = stoi(a[4]);
    }
    songs[songId-1].albumId = albumid;

    //year
    songs[songId-1].year = stoi(a[5]);  
  }
 
 while(1)
 {
  int choice;
  cout<<"---------------------------Spotify--------------------------"<<endl; 
  cout<<"1.To display all the songs"<<endl;
  cout<<"2.To buy songs"<<endl;
  cout<<"3.To play a albumm"<<endl;
  cout<<"4.Create a Play list"<<endl;
  cout<<"5.Play a Play list"<<endl;
  cout<<"6.To close the app"<<endl;
  cout<<"Enter your choice"<<endl;
  cin>>choice;
  if(choice == 6)
  {
    break;
  }
  switch(choice){
    case 1:displaySong();
    break;
    case 2:
    buySongs();
    break;
    case 3:
    playAlbum();
    break;
    case 4:
    createPlayList();
    break;
    case 5:
    playPlayList();
    break;
    default:
    cout<<"Enter a valid choice"<<endl;
    break;
  }
 }
  return 0;
}

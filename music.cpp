#include <bits/stdc++.h>
using namespace std;



class Songs{
	public:
		int songid;
		string songname;
		int artist_ID;
		int albumid;
		int genreid;
		int year;
};

class PlayList
{
	public:
		string playlistname;
		vector<Songs>playlistsongs;
};

class Artist{
	public:
		int artistID;
		string artistname;
		Songs* art_head;
		Songs* art_tail;
};
class Album{
	public:
		int albumID;
		string albumname;
		string purchased;
//		int artistID;
		
//		Songs* al_head;
//		Songs* al_tail;
};
class Genre{
	public:
		int genreID;
		string genreName;
		Songs* gen_head;
		Songs* gen_tail;
};
class User{
	private:
		string password;
	public:
		string username;
		string name;
		long long int phone_no; 
		int userid;
		vector<Songs>song_details;
		vector<Album>album_details;
		vector<Artist>artist_details;
		vector<Genre>genre_details;
		vector<PlayList>playlist_details;
		static int count;
		User()
		{
			count++;
			userid=count;
		}
		void createpassword()
		{
			string re_pass;
			cin>>password;
			while(1)
			{
				cout<<"\nRe-enter the Password: ";
				cin>>re_pass;
				if(re_pass==password)
				{
					cout<<"\nAccount Created\n\n";
					break;
				}
				else
				{
					cout<<"\nRe-enter your Password";
				}
			}
		}
		bool isauthorised(string password)
		{
			if(this->password==password)
			{
				return true;
			}
			return false;
		}
		void createsongs(Songs s[],Artist ar[],Album a[],Genre g[])
		{
			for(int ctr=0;ctr<15;ctr++)
			{
				song_details.push_back(s[ctr]);
			}
			for(int ctr=0;ctr<8;ctr++)
			{
				album_details.push_back(a[ctr]);
			}
			for(int ctr=0;ctr<6;ctr++)
			{
				artist_details.push_back(ar[ctr]);
			}
			for(int ctr=0;ctr<5;ctr++)
			{
				genre_details.push_back(g[ctr]);
			}
		}
};
vector<User>user_details;
int User::count=0;



class traverse{
	public:
		int songID;
		Songs* prev_genre;
		Songs* next_genre;	
		Songs* prev_album;
		Songs* next_album;
		Songs* prev_artist;
		Songs* next_artist;
		Songs* prev_year;
		Songs* next_year;	
};

void mysongs(User u)
{
	int key=0,flag=0;
	for(int ctr=0;ctr<u.song_details.size();ctr++)
	{
		key=u.song_details[ctr].albumid;
		if(u.album_details[key-1].purchased=="Yes")
		{
			flag=1;
			cout<<u.song_details[ctr].songid<<"\t"<<u.song_details[ctr].songname<<"\t"<<u.song_details[ctr].artist_ID<<"\t"<<u.song_details[ctr].albumid<<"\t"<<u.song_details[ctr].genreid<<"\t"<<u.song_details[ctr].year<<endl;
		}
	}
	if(flag==0)
	{
		cout<<"No Songs Available\n";
	}
}

void albums(User& u)
{
	string token;int token_id;
	for(int ctr=0;ctr<u.album_details.size();ctr++)
	{
		if(u.album_details[ctr].purchased=="No")
		{
			cout<<u.album_details[ctr].albumID<<"\t"<<u.album_details[ctr].albumname<<endl;
		}
	}
	
	while(1)
	{
		cout<<"\nDo you want to Purchase any albums?\t";
		cin>>token;
		
		if(token=="No" || token=="NO")
		{
			break;
		}
		
		cout<<"Enter the Album ID which you want to purchase: ";
		cin>>token_id;
		
		u.album_details[token_id-1].purchased="Yes";
		
		for(int ctr=0;ctr<u.song_details.size();ctr++)
		{
			int x=u.song_details[ctr].albumid;
			cout<<u.song_details[ctr].songid<<"\t"<<u.song_details[ctr].songname<<"\t"<<u.album_details[x-1].purchased<<"\t\t"<<endl;
		}
		
	}
	
	
}

void createplaylist(User& u)
{
	PlayList p;
	string playlist_name;
	
	int key=0,flag=0;
	for(int ctr=0;ctr<u.song_details.size();ctr++)
	{
		key=u.song_details[ctr].albumid;
		if(u.album_details[key-1].purchased=="Yes")
		{
			flag=1;
			cout<<u.song_details[ctr].songid<<"\t"<<u.song_details[ctr].songname<<"\t"<<u.song_details[ctr].artist_ID<<"\t"<<u.song_details[ctr].albumid<<"\t"<<u.song_details[ctr].genreid<<"\t"<<u.song_details[ctr].year<<endl;
		}
	}
	
	cout<<"Create Playlist Name:\t";
	cin>>p.playlistname;
	int token;
	while(1)
	{
		cout<<"Add Songs to the Playlist "<<p.playlistname<<endl;
		cout<<"Enter Song ID\n";
		cout<<"Or Enter 0 to EXIT\n";
		cin>>token;
		if(token==0)
		{
			break;
		}
		p.playlistsongs.push_back(u.song_details[token-1]);
	}
}

void viewplaylist(User& u)
{
	for(int ctr=0;ctr<u.playlist_details.size();ctr++)
	{
		cout<<u.playlist_details[ctr].playlistname<<endl;
		for(int ptr=0;ptr<u.playlist_details[ctr].playlistsongs.size();ptr++)
		{
			cout<<u.playlist_details[ctr].playlistsongs[ptr].songid<<"\t"<<u.playlist_details[ctr].playlistsongs[ptr].songname<<endl;
		}
		cout<<"---------------------------------------------------------------\n";
	}
}

void playlist(User& u)
{
int choice;	
	while(1)
	{
		cout<<"-----------------------------------------\n1.\t Create Playlist\n2.\t View Playlist\n0.\t EXIT\n-----------------------------------------\n";
		cout<<"Enter the Token:\t";
		cin>>choice;
		if(choice==0)
		{
			break;
		}
		switch(choice)
		{
			case 1: createplaylist(u);
			case 2: viewplaylist(u);
			default: cout<<"INVALID TOKEN\n";
		}
		
	}
	
	
}

void login()
{
	string login_user,login_pass;
	cout<<"\nUsername: ";
	cin>>login_user;
	cout<<"\nPassword: ";
	cin>>login_pass;
	int token;
	for(int ctr=0;ctr<user_details.size();ctr++)
	{
		if(user_details[ctr].username==login_user && user_details[ctr].isauthorised(login_pass))
		{
			while(1)
			{
//				for(int ptr=0;ptr<user_details[ctr].song_details.size();ptr++)
//				{
//					cout<<user_details[ctr].song_details[ptr].songname<<endl;
//				}

				cout<<"-----------------------------------------\n1.\tMy Songs\n2.\tAlbums\n3.\tPlaylist\n-----------------------------------------\n";
				cout<<"\nEnter the Token: ";
				cin>>token;
				if(token==0)
				{
					cout<<"\n************\tLOG OUT\t************\n\n";
					break;
				}
				switch(token)
				{
					case 1: mysongs(user_details[ctr]);break;
					case 2: albums(user_details[ctr]);break;
					case 3: playlist(user_details[ctr]);break;
					default: cout<<"\nINVALID TOKEN\n";break;
				}
			}			
		}
	}
}
void register_acc()
{
	Songs* genrehead=NULL;
	Songs* albumhead=NULL;
	Songs* artisthead=NULL;
	Songs s[30];
	s[0]={1,"Arabic Kuthu",1,1,1,2022};
	s[1]={2,"Aathichodi",2,2,1,2011};
	s[2]={3,"Ullaala",1,3,1,2018};
	s[3]={4,"Petta Parakh",1,3,2,2018};
	s[4]={5,"Marana Mass",1,3,1,2018};
	s[5]={6,"Engayum Kadhal",3,4,3,2012};
	s[6]={7,"Believer",4,5,4,2017};
	s[7]={8,"Animal",4,5,4,2018};
	s[8]={9,"SuperMan",5,6,4,2019};
	s[9]={10,"Bones",4,5,4,2020};
	s[10]={11,"Arabic Kadal",3,4,3,2002};
	s[11]={12,"Hosana",3,7,3,2014};
	s[12]={13,"Yethi Yethi",6,8,1,2015};
	s[13]={14,"Anjala",6,8,5,2015};
	s[14]={15,"Adiyae Kolludhae",6,8,3,2015};
	
	Artist a[6];
	a[0]={1,"Anirudh"};
	a[1]={2,"Vj Antony"};
	a[2]={3,"ARR"};
	a[3]={4,"Imagine Dragons"};
	a[4]={5,"Eminem"};
	a[5]={6,"HJ"};
	
	Album al[8];
	al[0]={1,"Beast","No"};
	al[1]={2,"VA1","No"};
	al[2]={3,"Petta","No"};
	al[3]={4,"EK","No"};
	al[4]={5,"ID1","No"};	
	al[5]={6,"EM1","No"};
	al[6]={7,"VTV","No"};
	al[7]={8,"V1000","No"};
	
	Genre g[5];
	g[0]={1,"Kuthu"};
	g[1]={2,"Beats"};
	g[2]={3,"Melody"};
	g[3]={4,"English"};
	g[4]={5,"Sad"};
	
	
	User u;
	cout<<"\nEnter your name: ";
	cin>>u.name;
	cout<<"\nEnter your Phone Number: ";
	cin>>u.phone_no;
	cout<<"\nCreate your username: ";
	cin>>u.username;
	cout<<"Create Password: ";
	u.createpassword();
	u.createsongs(s,a,al,g);
	user_details.push_back(u);
}
int main()
{
	
	
	int token;
	while(1)
	{
		cout<<"-----------------------------------------\n1.\tLogin\n2.\tRegister\n0.\tExit\n-----------------------------------------\n";
		cout<<"Enter the Token: ";	
		cin>>token;
		if(token==0)
		{
			cout<<"\n************\tTHANK YOU\t************\n\n";
			break;
		}
		switch(token)
		{
			case 1: login();break;
			case 2: register_acc();break;
			default: cout<<"\nINVALID TOKEN\n\n";
		}
	}
}

#include <iostream>
#include <exception>
#include <typeinfo>
using namespace std;

class GameEntry { 
public:
	GameEntry(const string &n = "", int s = 0); 
	string getName() const;						
	int getScore() const;						
private:
	string name; 
	int score;	 
};
GameEntry::GameEntry(const string &n, int s) : name(n), score(s) {
}
string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }
class Scores { 
public:
	Scores(int maxEnt = 10);				  
	~Scores();								  
	void add(const GameEntry &e);			  
	GameEntry remove(int i) ; 
	void printAllScores();
    void printPlayersCount();
private:
	int maxEntries;		// maximum number of entries
	int numEntries;		// actual number of entries
	GameEntry *entries; // array of game entries
};
Scores::Scores(int maxEnt) {			 // constructor
	maxEntries = maxEnt;				 // save the max size
	entries = new GameEntry[maxEntries]; // allocate array storage
	numEntries = 0;						 // initially no elements
}
Scores::~Scores() { 
	delete[] entries;
}
void Scores::add(const GameEntry &e) {
	int newScore = e.getScore(); // score to add
	if (numEntries == maxEntries) { // the array is full
		if (newScore <= entries[maxEntries - 1].getScore())
			return; // not high enough - ignore
	}
	else
		numEntries++; // if not full, one more entry
	int i = numEntries - 2; // start with the next to last
	while (i >= 0 && newScore > entries[i].getScore() ) {
		entries[i + 1] = entries[i]; // shift right if smaller
		i--;
	}
	entries[i + 1] = e; // put e in the empty spot
}
GameEntry Scores::remove(int i) 
{
	if ((i < 0) || (i >= numEntries)) // invalid index
		throw("IndexOutOfBounds - Invalid index");
	GameEntry e = entries[i]; // save the removed object
	for (int j = i + 1; j < numEntries; j++)
		entries[j - 1] = entries[j]; // shift entries left
	numEntries--;					 // one fewer entry
	return e;						 // return the removed object
}
void Scores::printAllScores()
{
	for (int i = 0; i < numEntries; i++)
	{
		cout << entries[i].getName() << " : " << entries[i].getScore() << "\n";
	}
}
void Scores::printPlayersCount() {
    bool isPicked[numEntries]{false};
    for (int i = 0; i < numEntries; i++)
    {
        if (isPicked[i]) // this player was considered previously
            continue;
        string playerName = entries[i].getName();
        int playerCount = 1;

        for (int j = i + 1; j < numEntries; j++)
        {
            if (isPicked[j]) // this player was considered previously
                continue;
            
            if (entries[j].getName()==playerName)
            {
                playerCount++;
                isPicked[j] = true;
            }
        //Compare the name of ith player with jth player and if they are
        // equal then increment the player count for ith player and also
        // update the isPicked table’s flag for jth player to True. If
        // they are not equal, then skip and go to next jth player (Task2)
        }
        cout << playerName << " : " << playerCount << endl;
    }
}
void showOptions()
{
	cout
		<< "1:	Add Player\n"
		<< "2:	Remove Player By Index\n"
		<< "3:	Print Scores\n"
		<< "4:	Count Players\n"
        << "5:	Exit\n";

}
int main()
{
	Scores scoresObj;
	int option;
	string playerName;
	int score;

	while (1)
	{
		showOptions();
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "Enter Player Name and Score\n";
			cin >> playerName >> score;
			scoresObj.add(GameEntry(playerName, score));
			break;
		case 2:
			int index;
			cout << "Enter the index\n";
			cin >> index;
			scoresObj.remove(index);
			break;
		case 3:
			scoresObj.printAllScores();
			break;
		case 4:
			scoresObj.printPlayersCount();
            break;
        case 5:
			return EXIT_SUCCESS;
        default:
            break;
		}
	}
}
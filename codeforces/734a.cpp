#include <iostream>
#include <string>

class ChessGame {
  private:
    int gamesAntonWon;
    int gamesDanikWon;
    int numberOfGames;
    std::string results;

    void getResults(){
      for(int i = 0; i < this->numberOfGames; i++){
        if(this->results[i] == 'A'){
          this->gamesAntonWon++;
          continue;
        }
        this->gamesDanikWon++;
      }
    }

  public:

    ChessGame(std::string results, int numberOfGamesPlayed){
      this->results = results;
      this->gamesAntonWon = 0;
      this->gamesDanikWon = 0;
      this->numberOfGames = numberOfGamesPlayed;
      this->getResults();
    }  

    std::string getBiggestWinner(){
      if(this->gamesAntonWon > this->gamesDanikWon)
        return "Anton\n";
      if(this->gamesDanikWon > this->gamesAntonWon)
        return "Danik\n";
      return "Friendship\n";
    }
};

int main(){
  int numberOfGamesPlayed = 0;
  std::string games;
  std::cin >> numberOfGamesPlayed >> games;
  ChessGame game(games, numberOfGamesPlayed);
  std::cout << game.getBiggestWinner();
  return 0;
}
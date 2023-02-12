#include <iostream>
#include <cstring>

class Word{
  private:
    std::string word, upperCaseWord, lowerCaseWord;
    unsigned lowerCaseCount, upperCaseCount;
  public:
    Word(std::string word){
      this->word = word;
      this->lowerCaseCount = 0;
      this->upperCaseCount = 0;
    }
    void getLetterCaseCount(){
      for(int i = 0; i < this->word.size(); i++){
        char letter = this->word[i];
        if(letter == tolower(this->word[i])){
          this->lowerCaseCount++;
        }
        else
          this->upperCaseCount++;

        this->updateLowerUpperCaseWords(letter);
      }
    }

    void updateLowerUpperCaseWords(char letter){
      this->lowerCaseWord += tolower(letter);
      this->upperCaseWord += toupper(letter);
    }

    std::string getWordInPredominantCase(){
      return (this->upperCaseCount > this->lowerCaseCount) ? this->upperCaseWord : this->lowerCaseWord; 
    }
};

int main(){
  std::string s;
  std::cin >> s;

  Word word(s);
  word.getLetterCaseCount();
  std::cout << word.getWordInPredominantCase() << "\n";

  return 0;
}
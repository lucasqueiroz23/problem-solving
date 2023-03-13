#include <iostream>
#include <vector>

std::vector<int> getFriendsHeight(int numberOfFriends){
  std::vector<int> friends;
  while(numberOfFriends--){
    int friendHeight = 0;
    std::cin >> friendHeight;
    friends.push_back(friendHeight);
  }

  return friends;
}

int getMinimumFenceWidth(std::vector<int> friends, int fenceHeight){
  int maxWidth = 0;
  for(int i = 0; i < friends.size(); i++){
    maxWidth = (friends[i] > fenceHeight) ? maxWidth + 2 : maxWidth + 1;
  }
  return maxWidth;
}

void solve(int numberOfFriends, int fenceHeight){
  std::cout << getMinimumFenceWidth(getFriendsHeight(numberOfFriends), fenceHeight) << "\n";
}

int main(){
  int numberOfFriends, fenceHeight;
  std::cin >> numberOfFriends >> fenceHeight;
  
  solve(numberOfFriends, fenceHeight);

  return 0;
}
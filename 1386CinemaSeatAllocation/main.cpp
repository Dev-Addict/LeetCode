#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, vector<int>> seats;

    for (int i = 0; i < reservedSeats.size(); i++) {
      vector<int> seat = reservedSeats[i];

      if (seats.find(seat[0] - 1) == seats.end())
        seats[seat[0] - 1] = vector<int>();

      seats[seat[0] - 1].push_back(seat[1] - 1);
    }

    int result = (n - seats.size()) * 2;

    for (const auto& pair : seats)
      result += maxNumberOfFamiliesInARow(pair.second);

    return result;
  }

  int maxNumberOfFamiliesInARow(vector<int> seats) {
    bool splitFamilyOneExists = true;
    bool splitFamilyTwoExists = true;
    bool familyExists = true;

    for (int i = 0; i < seats.size(); i++) {
      if (seats[i] >= 1 && seats[i] <= 4)
        splitFamilyOneExists = false;
      else if (seats[i] >= 5 && seats[i] <= 8)
        splitFamilyTwoExists = false;
      if (seats[i] >= 3 && seats[i] <= 6)
        familyExists = false;
    }

    if (splitFamilyOneExists || splitFamilyTwoExists)
      return splitFamilyOneExists + splitFamilyTwoExists;
    return familyExists;
  }
};



#include <iostream>
#include <string>

using namespace std;

string ConvertArabicToRoman(int number) {
  int ArabicNumbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  string RomanNumbers[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  string result = "";
  
  for (int ArabicIndex = 0; ArabicIndex < sizeof(ArabicNumbers) / sizeof(ArabicNumbers[0]); ++ArabicIndex) {
    while (number >= ArabicNumbers[ArabicIndex]) {
      result += RomanNumbers[ArabicIndex];
      number -= ArabicNumbers[ArabicIndex];
    }
  }
  return result;
}

int ConvertRomanToArabic(string roman) {
  int result = 0;
  int RomanIndex = 0;
  while (RomanIndex < roman.length()) {
    if (roman[RomanIndex] == 'M') {
      result += 1000;
      ++RomanIndex;
    } else if (roman[RomanIndex] == 'D') {
      result += 500;
      ++RomanIndex;
    } else if (roman[RomanIndex] == 'C') {
      if (RomanIndex + 1 < roman.length() && roman[RomanIndex + 1] == 'M') {
        result += 900;
        RomanIndex += 2;
      } else if (RomanIndex + 1 < roman.length() && roman[RomanIndex + 1] == 'D') {
        result += 400;
        RomanIndex += 2;
      } else {
        result += 100;
        ++RomanIndex;
      }
    } else if (roman[RomanIndex] == 'L') {
      result += 50;
      ++RomanIndex;
    } else if (roman[RomanIndex] == 'X') {
      if (RomanIndex + 1 < roman.length() && roman[RomanIndex + 1] == 'C') {
        result += 90;
        RomanIndex += 2;
      } else if (RomanIndex + 1 < roman.length() && roman[RomanIndex + 1] == 'L') {
        result += 40;
        RomanIndex += 2;
      } else {
        result += 10;
        ++RomanIndex;
      }
    } else if (roman[RomanIndex] == 'V') {
      result += 5;
      ++RomanIndex;
    } else if (roman[RomanIndex] == 'I') {
      if (RomanIndex + 1 < roman.length() && roman[RomanIndex + 1] == 'X') {
        result += 9;
        RomanIndex += 2;
      } else if (RomanIndex + 1 < roman.length() && roman[RomanIndex + 1] == 'V') {
        result += 4;
        RomanIndex += 2;
      } else {
        result += 1;
        ++RomanIndex;
      }
    }
  }
  return result;
}

int main() {
  int InputArabic;
  cout << "Enter a number in arabic numerals: ";
  cin >> InputArabic;
  cout << "In roman numerals: " << ConvertArabicToRoman(InputArabic) << endl;

  string InputRoman;
  cout << "Enter a number in roman numerals: ";
  cin >> InputRoman;
  cout << "In arabic numerals: " << ConvertRomanToArabic(InputRoman) << endl;

  return 0;
}

#include <iostream>

#include "encrytext.h"
#include "maketable.h"
#include "msgtreat.h"
#include "dependfunc.h"


int enplayfair() {
  array<array<char, 5>, 5> pftable{};

  // get user input
  cout << "Enter the key: ";
  string key;
  getline(cin, key);

  pftable = build_table(key);

  cout << "Enter the plaintext(default \"hello world\"): ";
  string str = "hello world";
  getline(cin, str);
  string treatedstr = msgprogress(str);

  cout << "The treated string: " << treatedstr << endl << endl;

  cout << "Table display:" << endl;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << pftable[i][j];
    }
    cout << endl;
  }

  cout << endl << "Encryed text: " << endl;
  string aftertext = encrytext(treatedstr, pftable);
  cout << aftertext << endl;

  return 0;
}

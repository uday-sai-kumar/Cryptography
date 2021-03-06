#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Must specify file!";
    return 0;
  }
  if (argc > 2) {
    std::cerr << "Too many arguments!";
    return 0;
  }
  unsigned char S[256];
  int i = 0;
  for (i = 0; i < 256; i++) S[i] = i;
  int j = 0, choice = 0;
  while (choice != 1 && choice != 2) {
    std::cout << "Encryption: 1, decryption: 2: ";
    std::cin >> choice;
  }
  std::string key;
  std::cout << "Enter the key: ";
  std::cin >> key;
  for (i = 0; i < 256; i++) {
    j = (j + S[i] + key.at(i % key.length())) % 256;
    std::swap(S[i], S[j]);
  }
  std::string argv1 = argv[1], printFile;
  std::ifstream read(argv1, std::ios::binary);
  if (choice == 1) printFile = argv1 + ".rc4";
  if (choice == 2) printFile = "decrypted_" + argv1.substr(0, argv1.length() - 4);
  std::ofstream print(printFile, std::ios::binary);
  char x;
  j = 0;
  i = 0;
  while (read.read(&x, 1)) {
    i = (i + 1) % 256;
    j = (j + S[i]) % 256;
    std::swap(S[i], S[j]);
    char temp = S[(S[i] + S[j]) % 256] ^ x;
    print.write(&temp, 1);
  }
}
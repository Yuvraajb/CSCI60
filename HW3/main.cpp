#include <iostream>
#include "lexicon.h"

using namespace std;

void yourTestCode();
void foundingDocs();
void annaKarenina();

int main() {
  yourTestCode();
  foundingDocs();
  annaKarenina();
  return 0;
}


void yourTestCode() {
  Lexicon l("decl.txt");
  cout << "First test: " << l.size() << endl;
  cout << l << endl;
}
void foundingDocs() {
  Lexicon constitution("const.txt");
  Lexicon declaration("decl.txt");
  size_t nConst = constitution.size(), nDecl = declaration.size();
  cout << "\nThe US Constitution contains " << nConst << " distinct words.\n";
  cout << "The Declaration of Independence contains " << nDecl
    << " distinct words.\n";
Lexicon both = constitution & declaration;
Lexicon either = constitution | declaration;
Lexicon exactlyOne = constitution ^ declaration;
size_t nCommon=both.size(), nTotal=either.size(), nDiff=exactlyOne.size();
cout << "The two documents have " << nCommon << " words in common.\n";
cout << "There are " << nDiff << " words in their symmetric difference.\n";
if (nTotal!=nCommon+nDiff) {
  cout << "Does it make sense that there are " << nTotal
    << " words in the combined lexicon?\n";
}
cout << endl;
if (constitution<=declaration) {
  cout << "Are all Constitution words in the Declaration of Independence?\n";
} else {
  cout << 100.0*nCommon/nConst
    << "% of Constitution words are in the Declaration of Independence.\n";
  string uncommonWord = exactlyOne[0];
  if (constitution.contains(uncommonWord)) {
    cout << "\"" << uncommonWord << "\" is one that is not.\n";
  }
}
if (constitution>=declaration) {
  cout << "Are all Declaration of Independence words in the Constitution?\n";
} else {
  cout << 100.0*both.size()/nDecl
    << "% of Declaration of Independence words are in the Constitution.\n";
  string uncommonWord = exactlyOne[nDiff-1];
  if (declaration.contains(uncommonWord)) {
    cout << "\"" << uncommonWord << "\" is one that is not.\n";
  }
}
cout << endl;
Lexicon preamble("preamble.txt");
if (preamble<constitution) {
  cout << "The Constitution's preamble contains " << 100.0*preamble.size()/nConst
    << "% of the distinct words \nin the Constitution and no others.\n";
} else {
  cout << "How can the preamble contain words not in the full Constitution?\n";
}
if (constitution>preamble) {
  cout << "The strict subset relationship remains true if we flip\n"
    << "the operator and args even though it's a different function call.\n";
} else {
  cout << "Flipping the operator and args shouldn't change the answer.\n";
}
cout << endl;
Lexicon prescramble("prescramble.txt");
if (preamble==prescramble) {
  cout << "Scrambling the words of the preamble gives an equivalent lexicon,";
  if ((preamble | prescramble) != preamble) {
    cout << " but why would the union of these things be non equivalent?\n";
  } else {
    cout << "\nwhich is equivalent to the union of the two.\n";
  }
} else {
  cout << "Whoops, scrambling words shouldn't break equivalence.\n";
}
cout << endl;  
}

void annaKarenina() {
  ifstream file("anna_karenina.txt");
  string token;
  size_t nRead = 0;
  while (file >> token) nRead++;
  file.close();
  cout << "\nAnna Karenina is " << nRead << " words (with repetition).\n";

  Lexicon akLex("anna_karenina.txt");
  size_t n = akLex.size();
  if (n<Lexicon::CAPACITY) {
    cout << "It contains " << n << " distinct words.\n";
  } else {
    cout << "The number of distinct words reaches our class's capacity.\n\n";
  }
}

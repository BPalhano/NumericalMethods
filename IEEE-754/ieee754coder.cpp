#include <bits/stdc++.h>
using namespace std;

string IEEE_builter(float read){

  if(read == 0){

    return "0000000000000000000000000000000";
  }
  bool isnegative = false;
  // Create a Union named Floating Point IEEE-754;
  union FloatingPointIEEE754 {

  // Inside of this Union, create a variable to get the values of mantissa,
     // exponent aind sign of a float, this varable represent a cocatenate         //value of all binary codes of mantissa and exponent, the sign is             // represented in a literally way;
  int i;
  // reserv in the union the same position memory for a float, this is will be
  // our input;
  float f;
  }number;
  
  number.f = read;
  if(number.f < 0){
    isnegative = true;
    number.f = number.f * (-1);
  }
  
  string mirrorbin = ""; // initialize a empty string;
  while (number.i > 0){ // then, walk around the number in binary form
    
    if(number.i & 1){ 
      mirrorbin += "1";
    }
    else{
      mirrorbin += "0";
    }

    number.i >>= 1;
  } // and save a mirrored copy of binary.

  if(isnegative){
    mirrorbin += "1";
  }
  else{
    mirrorbin += "0";
  }
  
  string bin = mirrorbin; // then, initialize the output with this mirrored copy,

  for(int i = 0; i < (bin.length()); i++){ // and mirror the mirrored copy.
    bin[i] = mirrorbin[mirrorbin.length() - 1 -i];
  }

  return bin;
  
}


int main(void) { // test instance;

  string bin = IEEE_builter(-121233.123);
  // print in IEEE-754 standard in string mode;
  cout << bin << endl;

  return 0;
}

/* templeitizar a função para por os parâmetros.
   sugestão: invés de fazer o codificador do jeito que foi feito, entrar com o
   número de bits do expoente e da mantissa, escrever a função que converte o número inserido para qualquer composição dada, desde que caiba.
   com uma função, fazer todas as precisões (de 8 as 126 bits). */

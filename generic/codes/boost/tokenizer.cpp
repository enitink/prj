// simple_example_1.cpp
#include<iostream>
#include<boost/tokenizer.hpp>
#include<string>

int main(){
   using namespace std;
   using namespace boost;
   string s = "This is a test. To write tokenzier for.";
   char_separator<char> sep(".");
   tokenizer<char_separator<char> > tok(s,sep);
   for(tokenizer<char_separator<char> >::iterator beg=tok.begin(); beg!=tok.end();++beg){
       cout << *beg << "\n";
   }
}

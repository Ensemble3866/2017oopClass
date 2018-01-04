#include <iostream>
#include "parser.h"
#include "scanner.h"
using namespace std;

int main(int argc, char **argv)
{
  string input, context = "";
  Parser * p;
  while(true){
    do{
        if(context == "")
            cout << "?- ";
        else cout << "|  ";
        getline(cin, input);
        if(input != ""){
        while(input[0] == ' '){
            input = input.substr(1, input.size() - 1);
        }
        context += input;
        }
    }while(input == "" || context.back() != '.');
    if(context == "halt.") break;

    Scanner s(context);
    Parser p(s);
    p.buildExpression();
    Exp * e = p.getExpressionTree();
    e->evaluate();
    string result = e->text() + '.';

    cout << result << endl;
    context = "";
  };
}
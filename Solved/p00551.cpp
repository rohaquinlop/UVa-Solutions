#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int i, pos;
    string line, simb;
    bool error;

    while( getline(cin, line) ){
        error = false;
        stack<string> pila;
        pos = 0;
        for(i = 0; i < line.size(); i++){
            pos++;
            //Verificando si son simbolos que abren
            if( line[i] == '(' && line[i+1] == '*' ){
                pila.push( "(*" );
                i++;
            }else if( line[i] == '(' && line[i+1] != '*' ){
                pila.push( "(" );
            }else if( line[i] == '[' ){
                pila.push( "[" );
            }else if( line[i] == '{' ){
                pila.push( "{" );
            }else if( line[i] == '<' ){
                pila.push( "<" );
            }else{
                //Verificando si son simbolos que cierran
                if( line[i] == '*' && line[i+1] == ')' ){
                    if( !pila.empty() ){
                        simb = pila.top();
                        if( simb == "(*" ){
                            pila.pop();
                            i++;
                        }else{
	                        error = true;
	                        break;
	                    }
                    }else{
                        error = true;
                        break;
                    }
                }else if( line[i] == ')' ){
                    if( !pila.empty() ){
                        simb = pila.top();
                        if( simb == "(" ){
                            pila.pop();
                        }else{
	                        error = true;
	                        break;
	                    }
                    }else{
                        error = true;
                        break;
                    }
                }else if( line[i] == ']' ){
                    if( !pila.empty() ){
                        simb = pila.top();
                        if( simb == "[" ){
                            pila.pop();
                        }else{
	                        error = true;
	                        break;
	                    }
                    }else{
                        error = true;
                        break;
                    }
                }else if( line[i] == '}' ){
                    if( !pila.empty() ){
                        simb = pila.top();
                        if( simb == "{" ){
                            pila.pop();
                        }else{
	                        error = true;
	                        break;
	                    }
                    }else{
                        error = true;
                        break;
                    }
                }else if( line[i] == '>' ){
                    if( !pila.empty() ){
                        simb = pila.top();
                        if( simb == "<" ){
                            pila.pop();
                        }else{
	                        error = true;
	                        break;
	                    }
                    }else{
                        error = true;
                        break;
                    }
                }
            }
        }

        if( error ){
            printf("NO %d\n", pos);
        }else if( !pila.empty() ){
        	printf("NO %d\n", pos+1);
        }else{
        	printf("YES\n");
        }

    }

    return 0;
}

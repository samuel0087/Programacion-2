
# include<iostream>
# include<cstdlib>

using namespace std;

bool esNumero(char c) {
  if (c >= '0' && c <= '9') {
    return true;
  } else {
    return false;
  }
}

int main(){
    char op;
    cin>>op;
    if(esNumero(op)) cout<<"es numero"<<endl;
    else cout<<"no es numero"<<endl;

	system("pause");
	return 0;
}


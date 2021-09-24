#include<bits/stdc++.h>
using namespace std;

int i=0,f=0,l;

string s;

void X(){

    if(s[i]=='b'){
        i++;
        f = 1;
    }
    else{
        f = 0;
        return;
    }

    if(s[i]=='b'){
        i++;
        f = 1;
        if(i!=l-1) X();
    }
    else if(s[i]=='c'){
        i++;
        f = 1;
        if(i!=l-1) X();
    }
    else{
        f = 0;
        return;
    }

}

void A(){

    if(s[i]=='a'){
        i++;
        f = 1;
    }
    else return;

    if(i!=l-1){
        X();
    }

    if(i==l-1 && f){
        if(s[i]=='d'){
            f = 1;
            i++;
            return;
        }
        else{
            f = 0;
            return;
        }
    }

}

int main(){

    freopen("i2.txt","r",stdin);
    freopen("o2.txt","w",stdout);
    while(getline(cin,s)){



        f = 0;
        i = 0;

        l = s.size();

        A();

        if(l==i && f){
            cout<<"valid\n";
        }
        else{
            cout<<"invalid\n";
        }

    }

}


#include<bits/stdc++.h>
using namespace std;

int i=0,f=0,l;

string st;

void A() {
    if (st[i] == 'a') {
        i++;
        f=1;
    }
    else {
        f=0;
        return;
    }
    if (i<l-1) A();
}

void B() {
    if (st[i] == 'b') {
        i++;
        f=1;
        return;
    }
    else {
        f=0;
        return;
    }
}

void S() {
    if (st[i] == 'b'){
        i++;
        f = 1;
        return;
    }
    else {
        A();
        if (f) { B(); return;}
    }
}

int main(){

    freopen("i1.txt","r",stdin);
    freopen("o1.txt","w",stdout);

    while(getline(cin,st)){

        f = 0;
        i = 0;

        l = st.size();

        S();

        if(l==i && f){
            cout<<"valid\n";
        }
        else{
            cout<<"invalid\n";
        }
    }

}

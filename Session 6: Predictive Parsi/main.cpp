#include<bits/stdc++.h>
using namespace std;

vector<string>sp,ke,ri;
map<string,string>mp,mpp;
string ans;

bool isTERMINAL(char a){
    if(a>='A' && a<='Z') return true;
    return false;
}

void FIRST(string key){

    string val = mp[key];

    if(isTERMINAL(val[0])){
        string p = "";
        p += val[0];
        FIRST(p);
    }
    else{
        ans += val[0];
        ans += ",";
        int flag = 0;
        for(int i=0;i<val.size();i++){
            if(val[i]=='|'){
                flag = 1;
                continue;
            }
            if(flag){
                ans += val[i];
            }
        }

    }

}

void FOLLOW(string key,int z){

    int flag = 0;

    for(int i=0;i<ri.size();i++){
        if (ri[i].find(key) != string::npos) {
            if(key.size()==1){
                for(int j=0;j<ri[i].size();j++){
                    if(ri[i][j]==key[0]){
                        if(j+1<ri.size() && ri[i][j+1]!='\''){
                            flag = 1;
                            if(isTERMINAL(ri[i][j+1])==false){
                                if(z==0)ans += "$,";
                                ans += ri[i][j+1];
                            }
                            else{
                                string g = ri[i];
                                g.erase(0,1);
                                FIRST(g);
                                if(z==0)ans += "$,";
                                FOLLOW(mpp[ri[i]],1);

                            }

                            break;
                        }
                    }
                }
            }
            else{
                flag = 1;

                for(int j=0;j+1<ri[i].size();j++){
                    if(ri[i][j]==key[0] && ri[i][j+1]==key[1]){
                        if(j+2>=ri[i].size()){
                            FOLLOW(mpp[ri[i]],1);
                            if(z==0)ans += ",$";
                        }
                        else{

                        }
                    }
                }
                break;
            }
        }
        if(flag) break;
    }


}



string remove_space(string s){

    string p="";

    for(int i=0;i<s.size();i++){
        if(s[i]!=' ') p = p + s[i];
    }

    return p;

}



int main(){

    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string s;

    while(getline(cin,s)){
        sp.push_back(remove_space(s));
    }

    for(int i=0;i<sp.size();i++){
        int flag = 0;

        string key="",val="";

        for(int j=0;j<sp[i].size();j++){
            if(sp[i][j]=='='){
                flag = 1;
                continue;
            }

            if(flag==0) key += sp[i][j];
            else val += sp[i][j];
        }

        mp[key] = val;
        ke.push_back(key);
    }

    cerr<<"FIRST: \n\n";
    cout<<"FIRST: \n\n";

    for(int i=0;i<ke.size();i++){
        ans = "";
        FIRST(ke[i]);
        cerr<<"FIRST("<<ke[i]<<")"<<" = {"<<ans<<"}\n";
        cout<<"FIRST("<<ke[i]<<")"<<" = {"<<ans<<"}\n";
    }

    for(int i=0;i<ke.size();i++){

        string val = mp[ke[i]];
        string v = "";

        for(int j=0;j<val.size();j++){
            if(val[j]=='|') break;
            v += val[j];
        }

        mp[ke[i]] = v;
        mpp[v] = ke[i];
        ri.push_back(v);
    }

    cerr<<"\nFOLLOW: \n\n";
    cout<<"\nFOLLOW: \n\n";


    for(int i=0;i<ke.size();i++){
        ans = "";

        FOLLOW(ke[i],0);
        cerr<<"FOLLOW("<<ke[i]<<")"<<" = {"<<ans<<"}\n";
        cout<<"FOLLOW("<<ke[i]<<")"<<" = {"<<ans<<"}\n";
    }


}

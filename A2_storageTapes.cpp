#include<bits/stdc++.h>
using namespace std;

//partition function for quick sort
int Partition(vector<int> &a,int L,int R){
    //swap a random element
    swap(a[R],a[L+rand()%(R-L+1)]);
    int ptr=L;
    for(int i=L;i<R;i++){
        if(a[i]<a[R]){
            swap(a[ptr],a[i]);
            ptr++;
        }
    }

    /*for(int i=L;i<=R;i++){
    cout<<a[i]<<" ";
    }cout<<endl;*/
    swap(a[R],a[ptr]); return ptr;
}

//quick sort for sorting
void Qsort(vector<int> &a,int L,int R){
    if(L<R){
        int pi=Partition(a,L,R);
        Qsort(a,L,pi-1);
        Qsort(a,pi+1,R);
    }
}

//horizontal storage on tapes
void store_hor(vector<int> L,vector<int> T){
    cout<<"--HORIZONTAL FILLING--"<<endl;
    int Ti=0;
    int Li=0;
    while(Ti<T.size()){
        int sum=0;
        vector<int> temp;
        cout<<"Tape "<<Ti+1<<":";
        while(true){
            if(Li==L.size()){
                break;
            }
            if(sum+L[Li]<=T[Ti]){
                temp.push_back(L[Li]); sum+=L[Li];
                Li++;
            }
            else{
                Ti++;
                break;
            }
        }

        for(auto x:temp){
            cout<<x<<" ";
        }

        int Time=0;
        for(int i=0;i<temp.size();i++){
            Time+=temp[i]*(temp.size()-i);
        }
        cout<<" MRT:";
        if(temp.size())
            cout<<((double)Time)/(temp.size())<<endl;
        else
            cout<<0<<endl;

        if(Li==L.size()){
            break;
        }
    }
}

//vertical storage on tapes
void store_ver(vector<int> L,vector<int> T){ 
    //cout<<"--VERTICAL FILLING--"<<endl;
    int Ti=0;
    int Li=0;
    vector<vector<int>> temp(100);
    int c=0;
    int pass=0;
    while(Li<L.size()){
        if(pass/2==T.size()){
            break;
        }
        if(T[c%(T.size())]>=L[Li]){
            T[c%(T.size())]-=L[Li];
            temp[c%T.size()].push_back(L[Li]);
            Li++;
            c++;
            pass=0;
        }
        else if(T[c%(T.size())]<L[Li]){
            c++;
            pass++;
        }
    }

    for(int i=0;i<T.size();i++){
        cout<<"Tape "<<i+1<<":";
        for(int j=0;j<temp[i].size();j++){
            cout<<temp[i][j]<<" "; 
        }

        int Time=0;
        for(int j=0;j<temp[i].size();j++){
            Time+=temp[i][j]*(temp[i].size()-j);
        }
        cout<<" MRT:";
        if(temp[i].size())
            cout<<((double)Time)/(temp[i].size())<<endl;
        else
        cout<<0<<endl;
    }
}

//Driver code
int main(){
    srand(time(0));

    //Input
    cout<<"Enter the number of programs: ";
    int n;
    cin>>n;

    //Length of programs
    vector<int> L(n);
    cout<<"Enter the lengths of programs: "<<endl;
    for(int i=0;i<n;i++){ cout<<"L"<<i+1<<":";
    cin>>L[i];
    }

    //sort according to length of programs
    Qsort(L,0,L.size()-1);

    //Number of tapes.
    cout<<"Enter the number of tapes: ";
    int m;
    cin>>m;

    //Capacity of tapes.
    vector<int> T(m);
    cout<<"Enter the lengths of tapes: "<<endl;
    for(int i=0;i<m;i++){
    cout<<"L"<<i+1<<":";
    cin>>T[i];
    }

    //store_hor(L,T);
    store_ver(L,T);
}
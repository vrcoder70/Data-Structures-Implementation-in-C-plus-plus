#include"Number.h"
using namespace std;

int Number::Counter(int NUM){
    int x=NUM;
    int Count=0;
    while(x!=0){
        Count++;
        x=x/10;
    }
    return (Count);
}

void Number::GetName(char* NAME){
   strcmp(Name,NAME);
   cout<<"Enter Number in 4-3-3 Digits System"<<endl;
 try{
   cout<<"First 4 Digits of Number:- ";
   cin>>Num1;
   int i=Counter(Num1);
   if(i!=4)
    throw Num1;
   cout<<"Middle 3 Digits of Number:- ";
   cin>>Num2;
   int j=Counter(Num2);
   if(j!=3)
    throw Num2;
   cout<<"Last 3 Digits of Number:- ";
   cin>>Num3;
   int k=Counter(Num3);
   if(k!=3)
    throw Num3;
 }
 catch(int e){
     cout<<"You Didn't Follow the 4-3-3 Digit Pattern"<<endl;
     cout<<"Re-enter Full detail again"<<endl;
     GetName(NAME);
 }
}

void Number::GetData(){
   cout<<"Enter Name:- ";
   cin.ignore();
   cin.getline(Name,29);
   cout<<"Enter Number in 4-3-3 Digits System"<<endl;
   try{
   cout<<"First 4 Digits of Number:- ";
   cin>>Num1;
   int i=Counter(Num1);
   if(i!=4)
    throw Num1;
   cout<<"Middle 3 Digits of Number:- ";
   cin>>Num2;
   int j=Counter(Num2);
   if(j!=3)
    throw Num2;
   cout<<"Last 3 Digits of Number:- ";
   cin>>Num3;
   int k=Counter(Num3);
   if(k!=3)
    throw Num3;
 }
 catch(int e){
     cout<<"You Didn't Follow the 4-3-3 Digit Pattern"<<endl;
     cout<<"Re-enter Full detail again"<<endl;
     GetData();
 }
}

void Number::ShowData(){
    cout<<Name<<" :- 91-"<<Num1<<"-"<<Num2<<"-"<<Num3<<endl;
}

void Number::Enter(){
    ofstream fout;
        fout.open("Phone.dat",ios::app|ios::binary);
     if(this->Num1!=0 && this->Num2!=0 && this->Num3!=0)
        fout.write((char*)this,sizeof(*this));
        fout.close();

}

void Number::Read(){
    ifstream fin;
    fin.open("Phone.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"Don't Have any contacts in your Phone library";
    else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            ShowData();
            fin.read((char*)this,sizeof(*this));
        }
    }
fin.close();
}

int Number::Search(char *name){
    ifstream fin; int Counter=0;
    fin.open("Phone.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"Don't Have any Contacts in your Phone Library";
    else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            if(!strcmp(this->Name,name)){
                Counter++;
                ShowData();
            }
            fin.read((char*)this,sizeof(*this));
        }
    }
    fin.close();
    if(Counter==0){
        cout<<"You have no Any contact of this Name"<<endl;
        cout<<"Do you want save Number on this name? 1 for Yes and Any for No";
        int l; cin>>l;
        if(l==1){
            GetData();
            Enter();
        }
        else
            cout<<"Thank You For Using My Software,Have Nice Day."<<endl;
    }
}

int Number::SearchNumber(int number){
    ifstream fin; int Count=0;
    fin.open("Phone.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"Don't Have any Contacts in your Phone Library";
    else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            if(this->Num1==number||this->Num2==number||this->Num3==number){
                Count++;
                ShowData();
            }
            fin.read((char*)this,sizeof(*this));
        }
    }
    fin.close();
    if(Count==0){
        cout<<"No Digit matches with above One"<<endl;
        cout<<"Do you want save Number? 1 for Yes and Any for No";
        int m; cin>>m;
        if(m==1){
            this->GetData();
            this->Enter();
        }
        else
            cout<<"Thank You For Using My Software,Have Nice Day."<<endl;
    }
}

void Number::Delete(char *name){
    ifstream fin;
    ofstream fout;
    fin.open("Phone.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"Error";
    else{
    fout.open("Temp.dat",ios::out|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof()){
        if(strcmp(Name,name))
            fout.write((char*)this,sizeof(*this));
        fin.read((char*)this,sizeof(*this));
    }
    fin.close();
    fout.close();
    remove("Phone.dat");
    rename("Temp.dat","Phone.dat");
    }
}

void Number::DeleteNumber(int number){
    ifstream fin;
    ofstream fout;
    fin.open("Phone.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    fout.open("Temp.dat",ios::out|ios::binary);
    while(!fin.eof()){
        if(this->Num3!=number){
            fout.write((char*)this,sizeof(*this));
        }
        fin.read((char*)this,sizeof(*this));
    }
    fin.close();
    fout.close();
    remove("Phone.dat");
    rename("Temp.dat","Phone.dat");
}

void Number::Update(char* n){
    fstream file;
    file.open("Phone.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof()){
        if(!strcmp(Name,n)){
            GetData();
            file.seekg(file.tellp()-sizeof(*this));
            file.write((char*)this,sizeof(*this));
        }
        file.read((char*)this,sizeof(*this));
    }
    file.close();
}

int menu(){
    system("cls");
    cout<<"1:- Enter Number."<<endl<<"2:- Read Phone Library."<<endl<<"3:- Search Number."<<endl<<"4:- Delete Number."<<endl;
    cout<<"5:- Update Number detail."<<endl<<"6:- To Exit."<<endl<<"Enter Your Choice:- ";
    int Ch; cin>>Ch;
    return(Ch);
}

int main(){
    Number N;
    while(1){
        switch(menu()){
        case 1:
            system("cls");
            cout<<"You Chose:- 1"<<endl;
            N.GetData();
            N.Enter();
            cout<<"Press Enter To Continue, Thank you.";
            getch();
            break;
        case 2:
            system("cls");
            cout<<"You chose:- 2"<<endl;
            N.Read();
            cout<<"Press Enter To Continue, Thank You.";
            getch();
            break;
        case 3:
            system("cls");
            cout<<"You Chose:- 3"<<endl;
            int ch;
            while(1){
            cout<<"1:- Search by Name"<<endl<<"2:- Search by digits"<<endl;
            cout<<"Enter Your Choice:- ";
            cin>>ch;
            system("cls");
            if(ch==1){
                char FN[30];
                cout<<"Enter Name:- ";
                cin.ignore();
                cin.getline(FN,29);
                N.Search(FN);
                break;
            }
            else if(ch==2){
                int Num,m;
                while(1){
                cout<<"Enter First 4 or Middle 3 or Last 3 Digits:- ";
                cin>>Num;
                try{
                m=N.Counter(Num);
                if(m!=3 && m!=4)
                    throw Num;
                N.SearchNumber(Num);
                break;
                }
                catch(int E){
                    cout<<"You have not enter 3 or 4 Digits"<<endl;
                    cout<<"Re-enter Digits"<<endl;
                }
                }
                break;
            }
            else{
                cout<<"You Have pressed wrong Key"<<endl;
            }
            }
            cout<<"Press Enter To Continue, Thank You.";
            getch();
            break;
        case 4:
            system("cls");
            cout<<"You chose 4"<<endl;
            int CH;
            while(1){
            cout<<"1:- Delete by Name"<<endl<<"2:- Delete by digits"<<endl;
            cout<<"Enter Your Choice:- ";
            cin>>CH;
            system("cls");
            if(CH==1){
                char fn[30];
                cout<<"Enter Name:- ";
                cin.ignore();
                cin.getline(fn,29);
                N.Delete(fn);
                break;
            }
            else if(CH==2){
                int num,l;
                while(1){
                cout<<"Enter Last 3 Digits numbers:- ";
                cin>>num;
                try{
                l=N.Counter(num);
                if(l!=3)
                    throw num;
                N.DeleteNumber(num);
                break;
                }
                catch(int e){
                    cout<<"You Entered More than 3 Digits"<<endl;
                    cout<<"Re-enter Number"<<endl;
                }
                }
                break;
            }
            else
                cout<<"You have pressed wrong key"<<endl;
            }
            cout<<"Press Enter To Continue, Thank You.";
            getch();
            break;
        case 5:
            system("cls");
            char M[30];
            cout<<"You Chose 5"<<endl;
            cout<<"Enter Name To Update Detail:- ";
            cin.ignore();
            cin.getline(M,29);
            N.Update(M);
            break;
        case 6:
            system("cls");
            cout<<"Thank you for Using My Software, Have nice day Ahead."<<endl;
            return 0;
        default:
            cout<<"You have pressed wrong key Sir"<<endl;
            cout<<"Press Enter To Continue, Thank you.";
            getch();
        }
    }
}

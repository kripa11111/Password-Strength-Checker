#include<iostream>
#include<string>
using namespace std;

bool isCommonPassword(string pass){
    string commonPasswords[]={
        "123456", "password","admin","qwerty","abc123"
    };

    for (string p : commonPasswords){
        if(pass ==p)
           return true;
    }
    return false;
}

bool hasRepeatedChars(string pass){
    int count = 1;
    for(int i=1; i< pass.length(); i++){
        if(pass[i]=pass[i-1]){
            count++;
            if(count>=3){
                return true;
            }
            else{
                count = 1;
            }
        }
    }
    return false;
}


bool hasSequentialChars(string pass){
    for(int i=0; i< pass.length() -2; i++){
        if(pass[i+1] ==pass[i] + 1 &&
        pass[i+2] == pass[i + 1] + 1)
        return true;
    }
    return false;
}


void checkPassword(){
    string password;
    int score=0;
    bool hasUpper= false;
    bool hasLower= false;
    bool hasDigit= false;
    bool hasSpecial= false;

    cout<<"Enter Password:\n";
    cin>>password;

    if(isCommonPassword(password)) {
        cout<< "\nPassword Strength: WEAK";
        cout<< "\nREASON : This is a commonly used password.\n";
        return;
    }

    if(hasRepeatedChars(password)){
        cout<<"\nPassword Strength: WEAK";
        cout<<"\nREASON : Contains Repeated Characters.\n";
        return;
    }

    if(hasSequentialChars(password)){
        cout<<"\nPassword Strength: WEAK";
        cout<<"\nREASON : Contains Sequential Characters.\n";
    }

    if(password.length() >=8){
        score+= 2;
    }

    for( char ch: password){
        if(ch>='A' && ch<='Z'){
            hasUpper= true;
        }
        else if(ch>= 'a' && ch<+'z'){
            hasLower= true;
        }
        else if(ch>='0' && ch<='9'){
            hasDigit= true;
        }
        else{
            hasSpecial=true;
        }
    }

    cout<<"\nPassword Strength: ";
    if(score<=4){
        cout<<"WEAK";
    }
    else if(score>=4 && score<=7){
        cout<<"MEDIUM";
    }
    else{
        cout<<"STRONG";
    }

    cout<<"\nSuggestions: \n";
    if(password.length()<8){
        cout<<"-Increase the length to atleast 8 characters.\n";
    }
    if(!hasUpper){
        cout<<"-Add Uppercase Letters.\n";
    }
    if(!hasLower){
        cout<<"-Add Lowercase Letters.\n";
    }
    if(!hasDigit){
        cout<<"-Add Digits.\n";
    }
    if(!hasSpecial){
        cout<<"-Add Special Characters.\n";
    }
    if(password.length()>=8 && hasUpper && hasLower && hasDigit && hasSpecial){
        cout<<"-NONE-\n";
    }
}

void showRules() {
    cout<<"\n PASSWORD RULES:\n";
    cout<<"-Minimum 8 characters\n";
    cout<<"-Must contain uppercase letters\n";
    cout<<"-Must contain lowercase letters\n";
    cout<<"-Must include digits";
    cout<<"Must include special characters";
    cout<<"-Avoid common, repeated and sequential patterns\n";
}

int main(){
    int choice;
    do{
        cout<<" *PASSWORD STRENGTH CHECKER*\n";
        cout<<"1.Check Password Strength\n";
        cout<<"2.View Password Rules\n";
        cout<<"EXIT\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
               checkPassword();
               break;
            case 2:
               showRules();
               break;
            case 3:
               cout<<"Exiting Program.Stay Secure!\n";
               break;
            default:
            cout<<"Invalid Choice. Select Again.\n";
        }
    }while(choice!=3);

    return 0;
}
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){

    // converting bool to float using static_cast
    bool b = true;
    float f = static_cast<float>(b);
    cout<<"bool to float:\nb: "<<b<<"\nf: "<<f<<endl;

    //converting string to integer using stoi:
    string s = "123";
    int i = stoi(s); 
    cout<<"string to int:\ns: "<<s<<"\ni: "<<i<<endl;

    // converting string to integer using istringstream
    string s1 = "456";
    int num;
    istringstream iss(s1);
    iss>>num;
    cout<<"string to int using istringstream:\ns1: "<<s1<<"\nnum: "<<num<<endl;

    // converting integer to string using string
    int num1 = 789;
    string s2 = to_string(num1);
    cout<<"int to string:\nnum1: "<<num1<<"\ns2: "<<s2<<endl;

    // converting integer to string using ostringstream
    int num2 = 1011;
    ostringstream oss;
    oss<<num2;
    string s3 = oss.str();
    cout<<"int to string using ostringstream:\nnum2: "<<num2<<"\ns3: "<<s3<<endl;
    



    return 0;
}
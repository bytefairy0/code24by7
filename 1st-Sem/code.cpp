#include <iostream>
using namespace std;

int main(){
    // Lets play with adding and storing values if variables :)

    // Can we add bool and int?
    // int x = 3;
    // bool y = 0;

    // int z = x + y;
    // bool n = x + y;
    // cout<<"z: "<<z<<endl;
    // cout<<"n: "<<n<<endl;

    // Adding strings and int
    // string s = "Hello";
    // int a = 5;
    // int b = s + a;
    // cout<<"b: "<<b<<endl;

    // Adding two strings
    // string s1 = "Hello";
    // string s2 = "World";
    // string s3 = s1 + s2;
    // cout<<"s3: "<<s3<<endl;

    // Adding two characters
    // char c1 = 'A';
    // char c2 = 'B';
    // int c3 = c1 + c2;
    // cout<<"c3: "<<c3<<endl;

    // Storing values
    // int x = 3;
    // int y = 5;
    // int z = x + y;
    // cout<<"x: "<<x<<endl;
    // cout<<"y: "<<y<<endl;
    // cout<<"x+y: "<<z<<endl;
    // x = y;
    // cout<<"x: "<<x<<endl;
    // cout<<"y: "<<y<<endl;
    // y = y - x;
    // x = x + y;
    // cout<<"y: "<<y<<endl;
    // cout<<"x: "<<x<<endl;
    // int a = 5;
    // int b = 7;
    // cout<<"a: "<<a<<endl;
    // cout<<"b: "<<b<<endl;
    // a = b;
    // cout<<"a:"<<a<<endl;
    // cout<<"b: "<<b<<endl;
    // b = a;
    // cout<<"a: "<<a<<endl;
    // cout<<"b: "<<b<<endl;

    // Passing two variables in increment in for loop
    // int n = 1;
    // int f = 1;
    // for ( int y = 0; y < 5 ; y++ , n++) { 
    //     f++;
    //     cout << "\n";
    //     cout<<"n: "<<n<<endl;
    //     cout<<"f: "<<f<<endl;
    //     for ( int x = 0; x < n; x++) {
    //         cout << "*"; 
    //     }
    // }


    // if (4%5){
    //     cout<<"Yes";
    // }
    // else{
    //     cout<<"No";
    // }

    // int c = 1;
    // do{
    //     cout<<c<<" ";
    // } while(c++ <=4);
    // cout<<endl;

    // int c = 1;
    // while (c++ <=4){
    //     cout<<c<<" ";

    // }

    // cout<<endl;

    // cout<<(-2%2)<<endl;
    // cout<<(-2/2)<<endl;


    // string s;
    // cin>>s;

    // switch (s){
    //     case "as": 
    //         cout<<"possible";
    //         break;

    //     default:
    //         cout<<"not possible"<<endl;
    //         break;
    // }

    // for (int i = 1; i< 10; i++){
    //     int j  = 5;
    //     if (i%j){
    //         continue;
    //         cout<<i<<" ";
    //     }
    // }

    // getting remainder in two floats - Typecasting
    // float a = 10.5, b = 3.5;
    // int c = int(a) % int (b);
    // cout<<c<<endl;

    // int x = -5;
    // while (x<5);
    // x++;
    

    // int x, y;

    // x = 5;
    // y = ++x * ++x;
    // cout<<"x: "<<x<<endl;
    // cout << x << y;

    // x = 5;
    // y = x++ * ++x;
    // cout << x << y;

    int f = 8;
    int *s = &f;
    *s = 5;
    cout<<f<<endl<<*s;



    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    string text;
    cin >> text;
    size_t posicion = text.find('T');
    posicion = text.find('A', posicion);
    posicion = text.find('P', posicion);
    if (posicion != string::npos)
        cout << "S" << endl;
    else
        cout << "N" << endl;
    return 0;
}

// int main()
// {
//     char arreglo2[3] = {' ', ' ', ' '};
//     for(int i=0;i<10;i++)
//     {
//         char temp;
//         cin>>temp;
//         if(temp=='T')
//         {
//             arreglo2[0]=temp;          
//         }
//         if(arreglo2[0]=='T'&& temp=='A')
//         {
//             arreglo2[1]=temp;
//         }
//         if(arreglo2[0]=='T'&& arreglo2[1]=='A'&& temp=='P')
//         {
//             cout<<"S"<<endl;
//             return 0;
//         }
        
//     }
//     cout<<"N"<<endl;
 
//     return 0;
// }
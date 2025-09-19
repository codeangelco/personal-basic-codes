// Hacer un programa donde se lean varios numeros, y detenerse cuando se ingrese el 0, debe imprimir la respuesta a las siguientes
// preguntas. ////////Cual es el promedio de los numeros? Cual fue el numero mayor y el menor?//////// Crear un arreglo con los 5 numeros más grandes.
// Mostrar los 5 numeros más pequeños elevados al cuadrado. Y decir la cantidad de numeros que son impares y la cantidad de pares.
// [23:20]
// input/entrada
// 4 5 8 2 0 -1 7 8 92 0 6
// ouput/salida
// Promedio: 11.909090
// Mayor: 92
// Menor: -1
// arr = 92, 8, 6, 8, 7.
// menores: 1, 0, 0, 4, 16
// Pares: 8
// [23:20]
// Impares: 3
#include <iostream>
using namespace std;
int main(){
    int numero;
    int im=1;
    int pa=1;
    double suma=0;
    double promedio=0;
    double dnum=0;
    double numero_mayor=-2000000;
    double numero_menor=2000000;
    int impar[im];
    int par[pa];
    int arreglito[5];//me da error y no funciona el codigo pipipi
    cin>>numero;
    while (numero!=0)
    {
        suma+=numero;
        dnum++;
        im++;
        pa++;
        if(numero%2!=0)impar[im]=numero;
        if(numero%2==0)par[pa]=numero;
        if(numero>numero_mayor) numero_mayor=numero;
        if(numero<numero_menor)numero_menor=numero;
       // no logre poder hacer con un arreglo guardar los 5 mayores y menores ya que no le veo una salida logica pipipi 

        cin>>numero;
    }
    promedio=suma/dnum;
    cout<<"la suma total de los numero es: "<<suma<<endl;
    cout<<"el promedio del total de numeros ingresados es de: "<<promedio<<endl;
    cout<<"los numeros que indicaste impares son: "<<impar<<endl;
    cout<<"los numeros que indicaste pares son: "<<par<<endl;
 
    return 0;

}
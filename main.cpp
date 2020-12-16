//
//  main.cpp
//  task 7
//
//  Created by Виталий on 25.10.2020.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;
const int Q=256;





//7.3 Работает
void t3(){
    int n, i;
    cout << "\nВведите размер массива: ";
    cin >> n;
    int n1=n;
    int a[n];
    cout << "\nВведите элементы массива: ";
    for (i=0; i<n; i++) cin >> a[i];
    
    
    for (i=0; i<n; i++){
        for (int j=1; j<n-i; j++){
            if (a[i]==a[i+j]) {
                for (int q=i+j; q<n; q++) a[q]=a[q+1];
                n--;
                a[n]=0;
            }
            if (a[i]==a[i+j]) j--;
        }

    }
    cout << "\nМассив без повторяющихся элементов: ";
    for (i=0; i<n1; i++){
        cout << a[i] << " ";
    }
    
    cout << "\n\n";
}



//7.4 Работает
void t4(){
    int n, i;
    cout << "\nВведите размер массива: ";
    cin >> n;
    int a[n];
    cout << "\nВведите элементы массива: ";
    for (i=0; i<n; i++) cin >> a[i];
    int max1=a[0],max2=a[1];
    if (max2>max1){
        i=max1;
        max1=max2;
        max2=i;
    }
    for (i=1; i<n; i++) if (a[i]>max1){    //(a[i]>=max1) если max1 и max2 могут быть равны
        max2=max1;
        max1=a[i];
    }
    cout << "\nВторой наибольший элемент: "<< max2 << "\n\n";
}


//7.5 (сделать рекурсией) Вроде работает

int search(int s, int *a, int r, int l){
    int   mid = (l + r) / 2;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] == s){
            cout << "\nИндекс этого элемента в массиве: " << mid << "\n\n";
            exit(0);
        }
        if (a[mid] > s) mid = search(s,a,mid-1,l);
        else mid = search(s,a,r,mid+1);
}
    return 0;
}
    
void t5(){
    int n, i, s;
    cout << "\nВведите размер массива: ";
    cin >> n;
    int a[n];
    cout << "\nВведите элементы массива: ";
    for (i=0; i<n; i++) cin >> a[i];
    int l=0, r=n-1;
    
    cout << "\nВведите искомый элемент: ";
    cin >> s;
    search(s,a,r,l);
}


//7.6 (сделать функцией)
int* fusion(int *a, int *b, int n, int m){
    int *c = new int[n + m];
    int i = 0, j = 0;
    int numc = 0;
    while (i < n or j < m) {
        if (j == m or a[i] < b[j]){
            c[numc] = a[i];
            i++;
            numc++;
        }
        else {
            c[numc] = b[j];
            j++;
            numc++;
        }
    }
    return c;
}


void t6(){
    int n, m, i;
    cout << "\nВведите размер первого массива: ";
    cin >> n;
    int a[n];
    cout << "\nВведите элементы первого массива: ";
    for (i=0; i<n; i++) cin >> a[i];
    cout << "\nВведите размер второго массива: ";
    cin >> m;
    int b[m];
    cout << "\nВведите элементы второго массива: ";
    for (i=0; i<m; i++) cin >> b[i];
    
    int *c = fusion (a,b,n,m);
    cout << "\nПолученный массив: ";
    
    for (int i = 0; i < m + n; i++) cout << c[i] << ' ';
    cout << "\n\n";
}



void pal(char t[Q], int pr){
    int count=0;
    for (int i=0; i<(strlen(t)-pr)/2; i++){ //если символы русские, то strlen нужно поделить на 2
        if (t[i]!=t[strlen(t)-pr-2-i]) count++;
    }
    if (count==0) cout<<"\nПалиндром :)";
    else cout<<"\nНе палиндром :(";
}




void t7(){
    char t[Q];
    int i, pr=0;
    cout<<"\nВведите предложение английскими символами: ";
    fgets(t, Q, stdin);
    fgets(t, Q, stdin); //пишу два раза, так как предыдущая строка пропускается из-за cin(как я понял) (с gets была та же история) :(
    for (i=0; i<strlen(t); i++)
    if (t[i]==' '){
        pr++;
        for (int j=i+1; j<strlen(t); j++) t[j-1]=t[j];
    }
    pal(t, pr);
    cout<<"\n\n";
}














int main(){
    int x=1, m;
    while (x>0){
        cout << "Введите номер задачи: ";
        cin >> m;
        if (m==3) t3();
        if (m==4) t4();
        if (m==5) t5();
        if (m==6) t6();
        if (m==7) t7();
    }
    return 0;
}

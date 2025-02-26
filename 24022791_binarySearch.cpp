
#include<iostream>
using namespace std;

void initArray(int* a, int n);
void sortArray(int* a, int n);
int lastPosK(int* a, int n, int k);


int main(){
    int k; cout << "Nhap k: "; cin >> k;
    int n; cout << "Nhap n: "; cin >> n;
    int* a = new int[n];

    cout << "Nhap day a: "; initArray(a, n);
    sortArray(a, n);
    int posK = lastPosK(a, n, k);
    if(posK == -1) cout << "Khong ton tai k trong day" << endl;
    else cout << "So nho nhat trong day a lon hon so cho truoc k là: " << a[posK + 1] << endl;
    delete[] a;
return 0;
}

void initArray(int* a, int n){
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}
void sortArray(int* a, int n){
    int temp;
    for(int i=0; i<n-1; i++){
        bool swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}
int lastPosK(int* a, int n, int k){
     int left = 0, right = n-1;
     int posK = -1;
     while(left <= right){
         int mid = (left + right) / 2;
         if(a[mid] == k){
            posK = mid;
            left = mid + 1;
         }
         else if(a[mid] < k){
            left = mid + 1;
         }
         else{
            right = mid - 1;
         }
     }
     return posK;
}

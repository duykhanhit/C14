#include <iostream>

using namespace std;

void inputN(int &n){
	do{
		cout << "Nhap n: ";	cin >> n;
	}while(n<1 || n>50);
}

void inputArray(int a[], int n){
	for(int i = 0; i < n; i++){
		cout << "\ta[" << i << "] = ";	cin >> a[i];
	}
}

void outputArray(int a[], int n){
	for(int i = 0; i < n; i++){
		cout << "a[" << i << "] = " << a[i] << "\t";
	}
}

void revout(int a[], int n){
	for(int i = n - 1; i >= 0; i--){
		cout << "a[" << i << "] = " << a[i] << "\t";
	}
}

void findSecondMax(int a[], int n){
	int m1, m2;
	if(n > 1){
		if(a[0] > a[1]){
			m1 = a[0];
			m2 = a[1];
		}else{
			m1 = a[1];
			m2 = a[0];
		}
		
		for(int i = 2; i < n; i++){
			if(a[i] > m1){
				m1 = a[i];
			}
			if(a[i] > m2 && a[i] < m1){
				m2 = a[i];
			}
			if(m1 == m2 && a[i] < m1){
				m2 = a[i];
			}
		}
		
		if(m1 == m2){
			cout << "Cac phan tu trong mang bang nhau." << endl;
		}else{
			cout << "So lon thu 2 la: " << m2;
		}
	}else{
		cout << "Nhap 1 phan tu thi sao co so lon thu 2 -.-" << endl;
	}
}

void insertToArray(int a[], int &n, int vt, int x){
	n++;
	for(int i = n - 1; i > vt; i--){
		a[i] = a[i-1];
	}
	a[vt] = x;
}

void deleteX(int a[], int &n, int vt){
	for(int i = vt; i < n - 1; i++){
		a[i] = a[i+1];
	}
	n--;
}

void handleWithX(int a[], int &n, int x){
	int dem = 0;
	cout << "\nNhap so nguyen x: ";	cin >> x;
	for(int i = 0; i < n; i++){
		if(a[i] == x){
			dem++;
		}
	}
	
	if(dem == 0){
		cout << "Khong co phan tu nao bang " << x << endl;
	}else{
		cout << "Co " << dem << " phan tu co gia tri bang " << x << endl;
	}
	
	for(int i = 0; i < n; i++){
		if(a[i] == x ){
			insertToArray(a,n,i+1,10);
			i++;
		}
	}
	cout << "Mang sau khi chen:\n";
	outputArray(a,n);
	for(int i = 0; i < n; i++){
		if(a[i] == x){
			deleteX(a,n,i);
			i--;
		}
	}
	cout << endl << "Mang sau khi xoa:\n";
	outputArray(a,n);
}

int main()
{
	int n, a[100], x;
	inputN(n);
	inputArray(a,n);
	findSecondMax(a,n);
	handleWithX(a,n,x);
    return 0;
}

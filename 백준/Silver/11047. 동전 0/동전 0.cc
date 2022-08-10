#include <iostream>
using namespace std;
int arr[12];
int main(){
	int a,b,c=0;
	scanf("%d %d",&a,&b);
	for(int i = 1;i <= a;i++){
		scanf("%d",&arr[i]);
	}
	int i = a;
	while(b){
		while(b - arr[i] >= 0){
			b -=arr[i];
			c++;
		}
		i--;
	}	
	printf("%d",c);
}
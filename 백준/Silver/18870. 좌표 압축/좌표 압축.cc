#include <iostream>
#include <vector>
#include <algorithm> // sort, unique
using namespace std;

int N, x;
vector<int> v;
vector<int> sortV;
int main(int argc, char **argv){
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%d", &x);
        v.push_back(x); // 좌표 입력받아 저장
        sortV.push_back(x); // 정렬할 벡터
    }

    sort(sortV.begin(), sortV.end()); // 벡터 정렬 -> 선 정렬해야 중복 삭제 가능
    sortV.erase(unique(sortV.begin(), sortV.end()), sortV.end()); // 중복되는 원소 삭제
    

    for(int i=0; i<v.size(); i++){
        printf("%ld ", lower_bound(sortV.begin(), sortV.end(), v[i]) - sortV.begin());
        // 순서대로 정렬된 벡터의 인덱스를 구하여 출력
    }

    return 0;
}
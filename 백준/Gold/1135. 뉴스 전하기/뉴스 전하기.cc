#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> child[50];
int tree_dp[50];

int DP(int cur) {
	// 메모이제이션 되어있을 경우 해당 값 리턴
	if (tree_dp[cur] != - 1) return tree_dp[cur];
	// 자식 노드가 없다면(리프노드라면) 걸리는 시간이 없으므로 0을 메모이제이션하고 리턴
	if (!child[cur].size()) return tree_dp[cur] = 0;

	// 현재 노드의 각각의 자식 노드들이 자신의 자식 노드들에 뉴스를 전파하는데 걸리는 시간을 담을 벡터 변수
	vector<int> cur_child_cost;

	// 탑다운 재귀 방식으로 자식 노드들의 최소 시간을 계산, 리턴받아 cur_child_cost에 저장
	for (int i = 0; i < child[cur].size(); i++) {
		cur_child_cost.push_back(DP(child[cur][i]));
	}

	// 가장 오랜 시간이 걸리는 자식 노드부터 뉴스를 전달하기 위하여 내림차순 sort 수행
	sort(cur_child_cost.begin(), cur_child_cost.end(), greater<>());
	// 뉴스를 전하는 순서에 따라 추가적으로 소요되는 시간 더해줌
	for (int i = 0; i < cur_child_cost.size(); i++) {
		cur_child_cost[i] += i + 1;
	}

	// 현재 노드의 자식노드들 중에서 가장 오래 걸리는 시간이 최소 시간이므로 메모이제이션 하고 리턴
	return tree_dp[cur] = *max_element(cur_child_cost.begin(), cur_child_cost.end());
}

void solution() {
	int tmp;
	cin >> n;
	cin >> tmp;
	for (int i = 1; i < n; i++)
		cin >> tmp, child[tmp].push_back(i);

	for (int i = 0; i < n; i++)
		tree_dp[i] = -1;

	cout << DP(0);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solution();

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj_list;


vector<bool> visited_recur;
vector<int> answer;
vector<int> order;

int cmp(int a, int b)
{
    return order[a] < order[b];
}

//DFS (����Լ�)
void dfsRecur(int v) {
    if (visited_recur[v]) //�̹� �湮�� �����
        return;
    visited_recur[v] = true; //�湮 üũ
    answer.push_back(v);
    for (int i = 0; i < adj_list[v].size(); i++)
        dfsRecur(adj_list[v][i]);
}

int check(vector<int>& result, vector<int>& answer,int n)
{
    for (int i = 0; i < n; i++)
    {
        if (result[i] != answer[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int n,a,b;
	cin >> n;
    adj_list.assign(n + 1, vector<int>());
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
	}

    order.assign(n + 1, -1);
    vector<int> result(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> result[i]; //�Է��ڰ� ���� �����(�񱳰�)
        order[result[i]] = i;//����
    }

    for (int i = 1; i <= n; i++) //�Է��ڰ� �Է��� ������ �°� ��带 dfs�� �湮�ϸ� check
        sort(adj_list[i].begin(), adj_list[i].end(), cmp);

    visited_recur.assign(n + 1, false);
    dfsRecur(1);
    int ans = check(result, answer,n);
    cout << ans;
   
	return 0;
}
//����https://transferhwang.tistory.com/401
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

//==찾아보고 정리한 결과==//

//하노이탑은 문제를 쪼개어 볼 수 있다.

//가장 큰 원반을 목적지로 옮기기 위해서는 그 위의 원반들이 목적지와 시작지가 아닌 막대에 있어야 한다.
//그러기 위해서는 이게 또다른 작은 하노이탑 문제가 될 수 있다. (가장 큰 원반은 위의 작은 하노이탑 문제가 해결 된 뒤 목적지로 한 번 이동하면 되고 그 큰 원반 위에는 무엇이든 올라갈 수 있으므로 큰 원반 위의 원반들을 작은 하노이탑 문제로 취급할 수 있게되는 것.)

//그리고 그 작은 하노이탑 전체가 다른 막대에 존재하기 위해서는 우선적으로 그 탑의 가장 큰 원반이 새로운 목적지(다른 막대)에 가 있어야 하고,
//이를 위해서는 더 위의 작은 하노이탑이 새로운 목적지가 아닌 곳으로 이동해야 한다.

//즉, 가장 큰 원반이 목적지로 가기 위해서는, 그 위의 하노이탑이 다른 막대에 있어야 하고, 그 위의 하노이탑이 다른 막대로 가려면 그 작은 하노이탑의 가장 큰 원반이 다른 막대를 목적지로 삼아야 하는데, 이를 위해서는 더 위의 작은 하노이탑이 다른 막대에 있어야 한다.
//이를 반복하다보면 결과적으로 하나의 원반만을 이동해야 하는 순간이 오고, 이 것이 첫번 째 이동이 된다.
//그리고 이 것이 해결 됨에 따라 점차 작은 하노이탑이 커지면서 문제가 해결되어 나가고 궁극적으로 전체 하노이탑이 해결된다.

//큰 하노이탑 문제에서 목적을 달성하기 위해 작은 하노이탑 문제를 설정하고, 그 작은 하노이탑 문제를 해결하기 위해 더 작은 하노이탑 문제를 만들어나가는 top-down 방식의 접근 방식을 사용할 수 있으며, 각 단게의 하노이탑에 대해서는 문제를 해결하는 알고리즘이 같으므로 재귀적으로 문제를 해결할 수 있다. 다만 각 단계의 경우에서 목적지가 달라질 수 있으므로 재귀함수상 계산에 사용될 값이 달라질 수 있도록 매개변수를 받아 처리할 수 있다.

vector<vector<int>> answer;

void hanoi(int remain, int start, int sub, int goal)
{
    vector<int> inner(2, -1);
    
    if(remain == 1)
    {
        inner[0] = start;
        inner[1] = goal;
        
        answer.push_back(inner);
        
        return;
        
        //??
        //answer.emplace_back(2, 0);
        //answer[^1][0];
        //answer[^1][1];
        //이런 느낌 이려나?
    }
    
    //작은 하노이를 옆으로 치워두기
    hanoi(remain - 1, start, goal, sub);
    
    //큰 원판을 목표지점으로 이동하기
    inner[0] = start;
    inner[1] = goal;
    answer.push_back(inner);
    
    //작은 하노이를 목표 지점으로 같이 옮겨두기
    hanoi(remain - 1, sub, start, goal);
}

vector<vector<int>> solution(int n) {
    
    hanoi(n, 1, 2, 3);
    
    return answer;
}

//==legacy==//

/*
//단순 로직 자체는 맞을 순 있어도
//재귀가 많이 반복되면서 중간에 끊는 것으로 보임.

//==확인해본 것==
//점화식으로 가능한 최소 이동 횟수 이상이면 강제로 끊어야 하나?
//그렇다면, 그 이동 횟수를 만족하는 순간 그냥 끊으면 되는 거 아닌가?
//즉 minDepth의 비교 없이 이미 정해진 값인 것.
//아니야. 그래도 너무 깊어.

//지금 내 방식은 모든 경우의 수를 따져 보는데,
//점화식이라고 하면 특정한 규칙이 있다는 것.
//그 규칙을 따라 풀어 나간다면?

vector<stack<int>> stick;

vector<pair<int,int>> result;

int minDepth = -1;

bool dfs(int previous, int next, int depth)
{
    cout << depth << "/" << previous << "/" << next << " >> ";
    
    if(!stick[0].empty())
        cout << stick[0].top();
    cout << "-";
    if(!stick[1].empty())
        cout << stick[1].top();
    cout << "-";
    if(!stick[2].empty())
        cout << stick[2].top();
    cout << " >> ";
    
        cout << stick[0].size() << "-";
        cout << stick[1].size() << "-";
        cout << stick[2].size() << "-";
    
    cout << endl;
    
    //만약 이번 판을 옮겼을 때 minDepth보다 클 것이 자명하면 return
    //단, 같은 횟수가 없을 것이라는 것이 보장되어야 함.
    //그리고 -1은 제외임.
    if(minDepth != -1 && minDepth <= depth + 1)
    {
        return false;
    }
    if(depth > 3)
        return false;
    
    //==일단 판을 옮기자==

    //만약 시작 스틱이 비어있다면
    if(stick[previous].empty())
    {
        //옮기기 실패
        return false;
    }
    //만약 시작 스틱이 비어있지 않다면
    else
    {
        //만약 도착 스틱의 판이 비어있다면
        if(stick[next].empty())
        {
            //옮기기!
            int target = stick[previous].top();
            stick[next].push(target);
            stick[previous].pop();
        }
        //만약 도착 스틱의 판이 더 작다면
        else if(stick[next].top() < stick[previous].top())
        {
            //옮기기 실패
            return false;
        }
        //만약 도착 스틱의 판이 더 크다면
        else
        {
            //옮기기!
            int target = stick[previous].top();
            stick[next].push(target);
            stick[previous].pop();
        }
    }
    
    //==옮기기에 성공한 이후==
    
    //depth를 올린다.
    depth++;
    
    //만약 정답에 도달했다면
    if(stick[0].empty() && stick[1].empty())
    {
        //깊이도 이전보다 작은 것이 자명한 상황. (위의 depth 비교로 인해)
        //그렇다면, 기존 정답 쌍의 목록을 비워버리고 자신을 정답 쌍에 넣는다.
        result.clear();
        result.push_back(make_pair(previous, next));
        //그리고 minDepth를 갱신한다.
        minDepth = depth;
        
        return true;
    }
    
    //dfs를 재귀한다.
    //단, next에서는 출발하지 않는다.
    //pervious로 가는 것 뿐 아니라 전체를 막는 이유는, 애초에 되었다면 바로 가면 되기 때문.
    //결과가 같은 절차를 굳이 2개로 나눌 이유가 없음.
    
    //재귀 결과가 전부 깊이 만족을 못하거나 옮기는 것 자체에 실패하면 현재의 함수 결과도 실패한 것이다.
    bool innerResult = false;
    
    if(next != 0)
    {
        innerResult |= dfs(0, 1, depth);
        innerResult |= dfs(0, 2, depth);
    }
    if(next != 1)
    {
        innerResult |= dfs(1, 0, depth);
        innerResult |= dfs(1, 2, depth);
    }
    if(next != 2)
    {
        innerResult |= dfs(2, 0, depth);
        innerResult |= dfs(2, 1, depth);
    }
    
    //단 하나라도 성공한다면 현재의 루트는 살아있을 가치가 있으므로 결과에 넣는다.
    //성공은 정답에 도달했을 때 밖에 없다.
    if(innerResult)
        result.push_back(make_pair(previous, next));
    
    return innerResult;
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    //하노이탑 스틱 3개 준비
    stick.push_back(stack<int>());
    stick.push_back(stack<int>());
    stick.push_back(stack<int>());

    //1번 스틱에 크기 순으로 집어넣기
    for(int i = n; i>0; i--)
    {
        stick[0].push(i);
    }
    
    dfs(0, 1, 0);
    //dfs(0, 2, 0);
    
    for(auto each : result)
    {
        cout << each.first << "--" << each.second << endl;
    }
    
    return answer;
}

//dfs? 아니면 bfs?
//bfs는 최소 단계 찾으면 곧장 끝나고..
//n 15이하인거 보니까 재귀쪽일 듯.
*/
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    //놀이기구 비용 저장 배열
    long long temp = 0;
    
    //놀이기구 비용 계산
    for(int i = 1; i<=count; i++)
        temp += price*i;
    
    //결과값 생성
    temp - money < 0 ? answer = 0 : answer = temp - money;

    //문제유형 : 구현
    
    return answer;
}
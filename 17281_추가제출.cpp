#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> innings; //이닝
vector<int> order(10, 0); //타순
vector<bool> check(10, false); //선수 체크
int n, ans; //이닝수(입력), 최종답

//현재 배치의 점수
int calcScore() {
    int score = 0; //총 점수
    int idx = 1; //타순 저장된 order 인덱스 번호
    for (int i = 0; i < n; i++) { //i: 이닝
        vector<bool> baseman(4, 0); //각 루수마다 선수가 있는지
        int out = 0; //아웃 선수 카운트
        while (out < 3) { //아웃 3번 미만일시
            int state = innings[i][order[idx++]]; //현재 선수의 공격 상태
            if (idx == 10) //선수 수를 넘는다면
                idx = 1; //앞으로 돌아가기
            switch (state) { //케이스 분류
            case 0: //아웃인경우
                out++; //숫자 증가
                break; //빠져나가기
            case 1: //안타, 1루씩 진루
                score += baseman[3]; //3루에 있는 선수있다면 홈 도착
                for (int i = 3; i > 0; i--) //선수들 한칸씩 증가시킴
                    baseman[i] = baseman[i - 1]; //1루 진보
                baseman[1] = 1; //새로운 선수 1루에 도착
                break;//빠져나가기
            case 2: //2루타, 2루씩 진루
                score += baseman[3] + baseman[2]; //3루, 2루에 선수 있다면 홈 도착
                baseman[3] = baseman[1]; //1루 -> 3루 이동
                baseman[2] = 1; //새로운 선수 2루에 도착
                baseman[1] = 0; //초기화
                break; //빠져나가기
            case 3: //3루타, 3루씩 진루
                for (int i = 3; i > 0; i--) { //3루, 2루, 1루에 선수 있다면 홈 도착
                    score += baseman[i]; //점수 추가
                    baseman[i] = 0; //사람 초기화
                }
                baseman[3] = 1; //새로운 선수 3루에 도착
                break; //나가기
            case 4: //홈런
                for (int i = 3; i > 0; i--) { //3루, 2루, 1루에 선수 있다면 홈 도착
                    score += baseman[i]; //점수추가
                    baseman[i] = 0; //초기화
                }
                score++; //새로운 선수도 홈 바로 도착
                break; //나가기
            }
        }
    }

    return score; //점수 반환
}

//가능한 배치 모두 구하기
void array(int cnt) { //cnt: 타자순서
    if (cnt == 4) { //4번 타자는 정해져 있으므로
        array(cnt + 1);//순서 증가시키고 재귀
        return; //반환
    }
    if (cnt == 10) { //9번 타자까지 정해짐 (기저조건)
        int score = calcScore(); //점수 계산
        ans = max(ans, score); //최대값을 반환하기
        return; //반환
    }
    for (int i = 2; i <= 9; i++) { //나머지 타순 결정
        if (!check[i]) { //가능한지 check false면 if문 수행
            order[cnt] = i; //cnt번 타자: i번 선수
            check[i] = true; //i번 선수 순서 정해짐
            array(cnt + 1); //다음 타자
            check[i] = false; //false로 초기화
        }
    }
}

/**
 * 구현 + 브루트 포스, 백트래킹
 * 1. 우선 가능한 타순을 모두 구한다. (이때, 4번 타자는 항상 1번 선수여야 함) (브루트 포스, 백트래킹)
 * 2. 구한 타순에 대한 각각의 점수를 구하며 최대 점수를 갱신한다. (구현)
 */

int main() {
    //입력
    cin >> n; //이닝 입력
    innings.assign(n, vector<int>(10, 0)); //배열 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 10; j++) {
            cin >> innings[i][j]; //입력받기
        }
    }

    //연산
    order[4] = 1; //4번 타자는 1번 선수
    check[1] = true; //1번 선수는 순서 정해짐
    array(1); //타순 정하기

    //출력
    cout << ans << '\n';

    return 0;
}
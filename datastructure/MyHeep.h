//
// Created by jjangchan on 2021-12-22.
//

#ifndef MAIN_CPP_MYHEEP_H
#define MAIN_CPP_MYHEEP_H

#include <iostream>
using namespace std;

typedef char Hdata; //char 형
typedef int PriortiComp(Hdata d1, Hdata d2);

class Heap {
public:
    void HeapInit(PriortiComp pc); //생성

    void Insert(Hdata data); //삽입

    Hdata Delete(); //삭제

    bool IsEmpty() const; //비어있는지

public:
    int GetParentIDX(int idx) { return (idx - 1) / 2; } //부모 인덱스 번호 반환
    int GetL_ChildIDX(int idx) { return (idx * 2) + 1; } //자식 - 왼쪽 인덱스 반환
    int GetR_ChildIDX(int idx) { return (idx * 2) + 2; } //자식 -오른쪽 인덱스 반환
    int GetHiPriChildIDX(int idx); //자식 중 우선순위 높은 인덱스 반환

private:
    PriortiComp* m_comp;
    int m_numOfData;
    Hdata heapArr[100];
};

/*생성*/
void Heap::HeapInit(PriortiComp _pc)
{
    this->m_numOfData = 0;
    this->m_comp = _pc;	//우선순위 비교에 사용되는 함수 등록
}

/*삽입*/
void Heap::Insert(Hdata _data)
{
    int idx = m_numOfData + 1; //기존 데이터 값의 다음 자리로 초기화

    /*저장 될 위치가 루트노드가 아니라면 반복문 실행*/
    while (idx != 1) {
        int temp = m_comp(_data, heapArr[GetParentIDX(idx)]); //부모노드와 데이터 값 비교 결과

        if (temp > 0)//우선순위 비교 성공 시 자리 바뀜
        {
            heapArr[idx] = heapArr[GetParentIDX(idx)]; //부모노드를 한단계 내림
            idx = GetParentIDX(idx); //새노드를 한 레벨 올림(실제로 아니고 인덱스 값만)
        }
        else
        {
            break; //새 노드의 우선순위가 높지 않다면 탈출
        }
    }

    heapArr[idx] = _data; //해당 인덱스 값에 저장
    m_numOfData++; //값 증가
}

Hdata Heap::Delete()
{
    Hdata retData = heapArr[1]; //삭제할 노드 임시저장
    Hdata lastElem = heapArr[m_numOfData]; //해당 힙의 마지막 노드

    int parantIdx = 1;//루트의 인덱스 값
    int childIdx = 0;

    //루트 노드의 우선순위가 높은 자식 노드를 시작으로 반복 시작
    while (childIdx = GetHiPriChildIDX(parantIdx))
    {
        //마지막노드 우선순위 먼저 비교
        int temp = m_comp(lastElem, heapArr[childIdx]);

        if (temp >= 0) //마지막 노드의 우선순위가 높으면 탈출
            break;

        //우선순위가 높으니 한단계 상승
        heapArr[parantIdx] = heapArr[childIdx];
        parantIdx = childIdx;
    }

    heapArr[parantIdx] = lastElem;
    m_numOfData--;
    return retData;
}

/*비었는지 여부*/
bool Heap::IsEmpty() const
{
    return this->m_numOfData == 0 ? true : false;
}

/*자식 노드중 우선 순위 판별*/
int Heap::GetHiPriChildIDX(int idx)
{
    //자식 노드 존재 하지 않는다면
    if (GetL_ChildIDX(idx) > m_numOfData)
        return 0;
        //자식노드가 왼쪽만 있다면
    else if (GetL_ChildIDX(idx) == m_numOfData)
        return GetL_ChildIDX(idx);
        //자식노드 둘다 존재 시
    else
    {
        //비교하여 (조건에 따라) 음수라면 오른쪽노드가 높고 양수라면 왼쪽 노드가 높음.
        int temp = m_comp(heapArr[GetL_ChildIDX(idx)], heapArr[GetR_ChildIDX(idx)]);
        if (temp < 0)
            return GetR_ChildIDX(idx);
        else
            return GetL_ChildIDX(idx);
    }
}
#endif //MAIN_CPP_MYHEEP_H

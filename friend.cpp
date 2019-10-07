#include <iostream>

using namespace std;

// 템플릿 클래스라고 정의 해준다.
template <typename T>
class CNode
{
   // CLinkdeList클래스에서 이 클래스를 쓰게 해준다.
   template <typename T>
   friend class CLinkdeList;
   template <typename T>
   friend class Citerater;
private:
   CNode()
   {
      m_pPrev = nullptr;
      m_pNext = nullptr;
   }

   ~CNode()
   {
   }

private:
   // 데이터를 저장한다.
   T m_Data;
   // 다음 노드를 저장한다.
   CNode<T>* m_pNext;
   // 이전 노드를 저장한다.
   CNode<T>* m_pPrev;

};

template <typename T>
class Citorater
{
   template <typename T>
   friend class CNode;

public:
   Citorater()
   {
   }

   ~Citorater()
   {
   }

private:
   typedef   CNode<T>*   PNODE;

private:
   PNODE m_pNode;

public:
   bool operator != (const Citorater<T>& itor) const
   {
      return m_pNode != itor.m_pNode;
   }
   void operator ++ (int)
   {
      m_pNode = m_pNode->m_pNext;
   }

   T& operator * ()
   {
      return m_pNode->m_Data;
   }

};

template <typename T>
class CLinkdeList
{
public:
   CLinkdeList()
   {
      m_pBigin = new NODE;
      m_pEnd = new NODE;

      // 서로 엮어준다.
      m_pBigin->m_pNext = m_pEnd;
      m_pEnd->m_pPrev = m_pBigin;

      m_iSize = 0;
   }

   ~CLinkdeList()
   {
      clear();
      delete m_pBigin;
      delete m_pEnd;
   }

private:
   typedef CNode<T> NODE;
   typedef CNode<T>* PNODE;

public:
   typedef Citorater<T> iterator;

private:
   // 비긴노드
   PNODE m_pBigin;
   // 엔드노드
   PNODE m_pEnd;
   // 노드의 개수
   int m_iSize = 0;
public:
   // 노드를 뒤에 추가한다.
   void Push_Back(const T& Data)
   {
      // 동적 메모리 할당을 해준다.
      PNODE pNode = new NODE;

      pNode->m_Data = Data;

      // End 노드의 이전 노드의 메모리주소를 저장한다.
      PNODE Prev = m_pEnd->m_pPrev;

      Prev->m_pNext = pNode;
      pNode->m_pPrev = Prev;

      pNode->m_pNext = m_pEnd;
      m_pEnd->m_pPrev = pNode;

      m_iSize++;
   }

   // 노드를 앞에 추가 해준다.
   void Push_Front(const T& Data)
   {
      PNODE pNode = new NODE;

      pNode->m_Data = Data;

      PNODE Next = m_pBigin->m_pNext;

      m_pBigin->m_pNext = pNode;
      pNode->m_pPrev = m_pBigin;

      Next->m_pPrev = pNode;
      pNode->m_pNext = Next;

      m_iSize++;
   }

   // 메모리 해제를 해준다.
   void clear()
   {
      PNODE   pNode = m_pBigin->m_pNext;

      while (pNode != m_pEnd)
      {
         PNODE   pNext = pNode->m_pNext;
         delete   pNode;
         pNode = pNext;
      }

      m_pBigin->m_pNext = m_pEnd;
      m_pEnd->m_pPrev = m_pBigin;

      m_iSize = 0;
   }

public:
   iterator bigin()   const
   {
      iterator iter;
      iter.m_pNode = m_pBigin->m_pNext;
      return iter;
   }

   iterator end() const
   {
      iterator iter;
      iter.m_pNode = m_pEnd;
      return iter;
   }

};

int main()
{
   CLinkdeList<int> ListInt;

   for (int i = 0; i < 10; i++)
   {
      // 0 ~ 9까지인 값을 가진 노드를 뒤에 추가한다.
      ListInt.Push_Back(i);
   }

   // 3인값을 가진 노드를 앞에 추가한다. 
   ListInt.Push_Front(3);


   CLinkdeList<int>::iterator   iter;
   CLinkdeList<int>::iterator   iterEnd = ListInt.end();

   // 비긴노드 다음노드부터 엔드노드 이전노드까지
   // 출력을해줘야 한다.

   for (iter = ListInt.bigin(); iter != iterEnd; iter++)
   {
      cout << *iter << endl;
   }

   return 0;
}
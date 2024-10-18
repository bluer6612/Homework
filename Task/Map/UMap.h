#pragma once


typedef int KeyType;
typedef int ValueType;

class UPair
{
public:
	KeyType first;
	ValueType second;
};

UPair Umake_pair(const KeyType& _Key, const ValueType& _Value);

// template<typename KeyType, typename ValueType>
class UMap
{
private:
	class UMapNode
	{
	public:
		UMapNode* Parent = nullptr;
		UMapNode* LeftChild = nullptr;
		UMapNode* RightChild = nullptr;
		UPair Pair;

		UMapNode* OverParent(const KeyType& _Key)
		{
			if (nullptr != Parent)
			{
				if (Parent->Pair.first > _Key)
				{
					return Parent;
				}

				return Parent->OverParent(_Key);
			}

			return nullptr;
		}

		UMapNode* NextNode()
		{
			if (nullptr == RightChild)
			{
				// 부모중에
				return OverParent(Pair.first);
			}

			return RightChild->MinNode();
		}

		UMapNode* MinNode()
		{
			if (nullptr == LeftChild)
			{
				return this;
			}

			// 꼬리재귀
			return LeftChild->MinNode();
		}

		UMapNode* MaxNode()
		{
			if (nullptr == RightChild)
			{
				return this;
			}

			// 꼬리재귀
			return RightChild->MaxNode();
		}

		UMapNode* FindNode(const KeyType& _Key)
		{
			if (this->Pair.first == _Key)
			{
				return this;
			}

			if (Pair.first > _Key)
			{
				return LeftChild->FindNode(_Key);
			}
			else 
			{
				return RightChild->FindNode(_Key);
			}

			// 의미는 
			return nullptr;
		}

		void insertNode(const UPair& _Pair)
		{
			if (Pair.first == _Pair.first)
			{
				return;
			}

			//  10            2
			if (Pair.first > _Pair.first)
			{
				if (nullptr == LeftChild)
				{
					LeftChild = new UMapNode();
					LeftChild->Parent = this;
					LeftChild->Pair = _Pair;
					return; // <= 여기서 완벽하게 종료해야한다면 return 꼭 해주세요
				}

				// Left차일드가 있다는 이야기
				LeftChild->insertNode(_Pair);
			}
			else 
			{
				if (nullptr == RightChild)
				{
					RightChild = new UMapNode();
					RightChild->Parent = this;
					RightChild->Pair = _Pair;
					return; // <= 여기서 완벽하게 종료해야한다면 return 꼭 해주세요
				}

				// Left차일드가 있다는 이야기
				RightChild->insertNode(_Pair);

			}

		}
	};

public:
	class iterator
	{
	public:
		iterator& operator++()
		{
			CurNode = CurNode->NextNode();
			return *this;
		}


		bool operator!=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		UPair* operator->()
		{
			return &CurNode->Pair;
		}

		iterator(UMapNode* _Node)
			: CurNode(_Node)
		{

		}

	private:
		UMapNode* CurNode = nullptr;
	};



public:
	iterator begin()
	{
		if (nullptr == Root)
		{
			return iterator(nullptr);
		}

		return iterator(Root->MinNode());
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	iterator Find(const KeyType& _Key)
	{
		if (nullptr == Root)
		{
			return nullptr;
		}

		UMapNode* Node = Root->FindNode(_Key);
		return iterator(Node);
	}

	void insert(const UPair& _Pair)
	{
		if (nullptr == Root)
		{
			Root = new UMapNode();
			Root->Pair = _Pair;
			return;
		}

		if (true == isRotate())
		{
			// 편향트리다
			Rotate();
		}

		Root->insertNode(_Pair);
	}


public:
	UMapNode* Root = nullptr;

	bool isRotate()
	{
		return false;
	}

	void Rotate()
	{
		if (true)
		{
			LeftRotate();
		}

		if (true)
		{
			RightRotate();
		}

		return;
	}

	void LeftRotate()	{	}

	void RightRotate()	{	}
};


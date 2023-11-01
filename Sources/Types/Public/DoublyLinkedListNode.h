#pragma once

template <class ElementType>
class DoublyLinkedListNode
{
/* ------------------------------- Functions -------------------------------- */
public:
	DoublyLinkedListNode(): Next(GetThis()), Prev(GetThis()) { }

	inline void Reset() { Next = Prev = GetThis(); }

	inline bool IsInList() const { return Next != GetThis(); }

	inline ElementType* GetNext() const { return Next; }

	inline ElementType* GetPrev() const { return Prev; }

	inline void Remove()
	{
		static_cast<NodeType*>(Next)->Prev = Prev;
		static_cast<NodeType*>(Prev)->Next = Next;
		Next = Prev = GetThis();
	}

	inline void InsertAfter(ElementType* newPrev)
	{
		ElementType* newNext = static_cast<NodeType*>(newPrev)->Next;
		Next = newNext;
		Prev = newPrev;
		static_cast<NodeType*>(newNext)->Prev = GetThis();
		static_cast<NodeType*>(newPrev)->Next = GetThis();
	}

	inline void InsertBefore(ElementType* newNext)
	{
		ElementType* newPrev = static_cast<NodeType*>(newNext)->Prev;
		Next = newNext;
		Prev = newPrev;
		static_cast<NodeType*>(newNext)->Prev = GetThis();
		static_cast<NodeType*>(newPrev)->Next = GetThis();
	}

protected:
	inline ElementType* GetThis() 
	{ 
		return static_cast<ElementType*>(this);
	}

	inline const ElementType* GetThis() const 
	{ 
		return static_cast<const ElementType*>(this);
	}

private:

/* --------------------------------- Members -------------------------------- */
public:
	using NodeType = DoublyLinkedListNode<ElementType>;

protected:
	ElementType* Next;
	ElementType* Prev;

private:
};

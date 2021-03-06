/**
*	@author Adam Soelter
*	@date	Feb 15, 2019
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : root_(nullptr), size_(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(size_ == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	//Fixed
	return size_;
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* walker = root_;
	bool isFound	= false;

	/** TODO 
		Fix this method
	*/
	for(int i = 0; i < size_; ++i)
	{
		if(walker->getValue() == value)
		{
			isFound = true;
			break;
		}

		walker = walker->getNext();
	}

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = root_;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		root_ = new Node<T>(value);	
	}
	else
	{
		temp = root_;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	size_++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = root_;
	root_ = new Node<T>(value);
	root_->setNext( temp );
	size_++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode		= root_;
	Node<T>* secondToLast	= nullptr;
	bool isRemoved			= false;

	//Fixed
	if(!isEmpty())
	{
		isRemoved = true;

		while(lastNode->getNext() != nullptr)
		{
			secondToLast = lastNode;
			lastNode	 = lastNode->getNext();
		}

		delete lastNode;
		secondToLast->setNext(nullptr);
		--size_;
	}

	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = root_;
		root_ = temp->getNext();
		delete temp;
		size_--;
		isRemoved = true;
	}

	return(isRemoved);
}

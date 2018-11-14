smartArray::smartArray(int s = 10)
{
    resize(s);
}

smartArray::~smartArray()
{
    deleteAll();
}

smartArray::smartArray(const smartArray<Data> &other)
{
    copy(other);
}

smartArray<Data>& operator=(const smartArray<Data> &other)
{
    if (this != &other)
    {
        deleteAll();
        copy(other);
    }
    return *this;
}

//Allows access to elements in the array
<Data> operator [](int i) const
{
    if(i < 0)
        throw OUT_OF_BOUNDS_LOW;
    if (i >= mySIZE)
        throw OUT_OF_BOUNDS_HIGH;
    return list[i];
}

<Data>& operator& [](int i)
{
    if(i < 0)
        throw OUT_OF_BOUNDS_LOW;
    if (i >= mySIZE)
        throw OUT_OF_BOUNDS_HIGH;
    return list[i];
}

int smartArray::size() const
{
    return mySize;
}

void smartArray::resize(int i = 10);
{
    if (i < 1)
        throw BAD_SIZE;
    list = new <Data>[mySize = i];
    zero();
}

void smartArray::sort()
{
    int temp;
    for(int i = 0; i < mySize; ++i)
        for(int j = 0; j < mySize; ++j)
            if(list[i] < list[j])
            {
               temp = list[i];
               list[i] = list[j];
               list[j] = temp;
            }
}

//smartArray slice(int begin, int end, int inc = 1);

void smartArray::copy(const smartArray &other)
{
    list = new <Data>[mySize = other.mySize];
    for(int i = 0; i < other.size(); ++i)
        list[i] = other[i];
}

void smartArray::deleteAll()
{
    zero();
    delete [] list;
    list = nullptr;
}

void smartArray::zero()
{
    for(int i = 0; i < mySize; ++i)
        list[i] = NULL;
}

friend
std::ostream& operator<<( std::ostream& out, const smartArray &array);

friend
std::istream& operator>>( std::istream& , const smartArray &);

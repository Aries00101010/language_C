int sumArray(int orignalArray[], int sizeArray)
{
    int sum = 0;
    for (int i = 0; i < sizeArray; i++)
    {
        sum += orignalArray[i];
    }
    return sum;
}

double averageArray(int orignalArray[], int sizeArray)
{
    double average = 0.0;

    for (int i = 0; i < sizeArray; i++)
    {
        average += orignalArray[i];
    }

    return average / sizeArray;
}

void copyArray(int orignalArray[], int copyArray[], int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
    {
        copyArray[i] = orignalArray[i];
    }
}

void maxArray (int orignalArray[], int sizeArray, int maxValue)
{
    for (int i = 0; i < sizeArray; i++)
    {
        if (orignalArray[i] > maxValue)
        {
            orignalArray[i] = 0;
        }
    }
}

void sortArray(int orignalArray[], int sizeArray)
{
    int tmp = 0;

    for (int i = (sizeArray - 1); i >= 1; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (orignalArray[j+1] < orignalArray[j])
            {
                tmp = orignalArray[j+1];
                orignalArray[j+1] = orignalArray[j];
                orignalArray[j] = tmp;
            }
        }
    }
}

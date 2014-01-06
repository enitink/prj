
void SelectionSort(int *array, int no)
{
    static int a = no;
    int temp = array[a - no];
    int i;
    int sub = a - no;

    if (no == 1)
        return;
    else
    {
        for(i = a - 1; i > a - no; --i)
            if(temp >= array[i])
            {
                sub = i;
                temp = array[i];
            }
        array[sub] = array[a - no];
        array[a - no] = temp;
        SelectionSort(array, no - 1);
    }
}

void shellsort(int *src, int size) {
    int step = size / 2;

    while (step > 0) 
    {
        for (int i = step; i < size; i ++) 
        {
            int tmp = i;
            while (tmp - step >= 0) 
            {
                if (src[tmp] < src[tmp - step]) {
                    int tarr = src[tmp];
                    src[tmp] = src[tmp - step];
                    src[tmp - step] = tarr;
                }
                tmp = tmp - step;
            }
        }
        step = step / 2;
    }
}
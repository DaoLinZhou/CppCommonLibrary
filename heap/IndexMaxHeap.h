template <typename T>
class IndexMaxHeap{
private:
    int count;
    T* data;
    int* reverse;   //反向查找
    int* indexes;
    int capacity;

public:
    // 由于是从1开始存储元素
    IndexMaxHeap(int capacity) : capacity(capacity) {
        data = new T[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];
        for(int i=0; i<=capacity; i++)
            reverse[i] = 0;
        count = 0;
    }

    virtual ~IndexMaxHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    int getCount(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    //对于用户来说, 是从0开始
    void insert(int i, T item){
        assert(count+1 <= capacity);
        assert(i+1 >= 1 && i+1 <= capacity);
        i += 1;
        /* 数据是添加在 index的位置, 如果extractMaxIndex后data[i]的元素依然留着,
           再次为它添加不会造成空间浪费, 而是覆盖原有的值 */
        data[i] = item;
        // index 是添加在最末尾
        indexes[count+1] = i;
        reverse[i] = count+1;
        count ++;
        shiftUp(count);
    }

    T extractMax(){
        assert(count > 0);
        T ret = data[indexes[1]];
        swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;    //不存在的指向0
        count --;
        shiftDown(1);
        return ret;
    }

    // 索引堆支持的特殊操作, 返回索引
    int extractMaxIndex(){
        assert(count > 0);
        int ret = indexes[1] - 1;
        swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;    //不存在的指向0
        count--;
        // 不用考虑data中的元素, 因为indexes中没有的话就无法被访问到
        shiftDown(1);
        return ret;
    }

    T getMax(){
        assert(count > 0);
        return data[indexes[1]];
    }

    // 新增函数, O(1)复杂度内判断是否包含索引i
    bool contain(int i){
        assert(i+1 >= 1 && i+1 <= capacity);
        return reverse[i+1] != 0;
    }

    // 索引堆支持的特殊操作, 通过索引获取元素
    T getItem(int index){
        assert( contain(index) );
        return data[index+1];
    }

    // 索引堆支持的特殊操作, 通过索引改变元素
    void change(int i, T newItem){
        assert( contain(i) );
        i+=1;
        data[i] = newItem;

        // 由于改变了值, 可能会导致堆的规则被破坏, 所以要尝试向上移,向下移
        // 找到indexes[j] = i, j表示data[i]在堆中的位置
        // 之后shiftUp(j), 再shiftDown(j)
//        for(int j = 1; i <= count; j++){
//            if(indexes[j] == i){
//                shiftUp(j);
//                shiftDown(j);
//                return;
//            }
//        }
        int j = reverse[i];
        shiftUp(j);
        shiftDown(j);
    }

private:
    void shiftUp(int i){
        while(i > 1 && data[indexes[i]] > data[indexes[i/2]]){
            swap(indexes[i], indexes[i/2]);
            reverse[indexes[i/2]] = i/2;
            reverse[indexes[i]] = i;
            i /= 2;
        }
    }
    void shiftDown(int i){
        while((i*2) <= count){
            int j = i*2;
            if(j+1 <= count && data[indexes[j+1]] > data[indexes[j]])
                j += 1;
            if(data[indexes[i]] >= data[indexes[j]])
                break;
            swap(indexes[j], indexes[i]);
            reverse[indexes[i]] = i;
            reverse[indexes[j]] = j;
            i = j;
        }
    }
};

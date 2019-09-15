
// 第一次参加比赛时的写法, 不是最优解, 但依然是O(n) 的复杂度

// 思路: 先计算环的总长度, 在计算顺时针从起点到终点的长度
// 如果这个长度小于总长度的一半, 则这个长度就是解
// 不然逆时针的长度(总长度减去当前长度)就是解

class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int dis1 = 0, total = 0;
        for(int i = 0; i < distance.length; i++)
            total += distance[i];

        for(int i = start; i != destination; i++){
            dis1 += distance[i];
            if(i+1 == distance.length)
                i = -1;
        }

        return dis1 < total/2 ? dis1 : total-dis1;
    }
}
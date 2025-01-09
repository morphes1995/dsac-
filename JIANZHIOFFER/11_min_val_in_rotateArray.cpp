
/**
 * 剑指 Offer 11. 旋转数组的最小数字
 * 把一个数组最开始的若干个元素(可以是0个)搬到数组的末尾，我们称之为数组的旋转。 数组可能存在 重复 元素值
 *
 */
public int minArray2(int[] numbers) {
    int l = 0;
    int r = numbers.length - 1;
    while (l <= r) {
        if(l==r){
            return numbers[l];
        }

        int mid = ((r - l) >> 1) + l;
        //右边界值比中间值大， 那[mid,right]一定是有序数组, 最小值不可能存在于[mid+1,right]中， 最小值一定在[left,mid]中
        if (numbers[r] > numbers[mid]) {
            r = mid;
        } else if (numbers[r] < numbers[mid]) {
            //右边界值比中间值小， ，右侧数组非递增， 最小值不可能存在于[left,mid]中，一定在 [mid+1,right]中
            l = mid+1;
        } else {
            // numbers[r] == numbers[mid] , 此时无法判断 左侧数组有序，还是右侧数组有序
            // 由于mid <r ， 且numbers[r] == numbers[mid]  ,因此通过缩减右边界r的值不会导致 最小值的丢失 （最小值还可以通过numbers[mid）取到
            r--;
        }
    }
    return numbers[l];
}
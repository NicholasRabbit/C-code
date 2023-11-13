# include<stdio.h>

/* 
 * 数组的初始化及其它基本特性。
 * 跟结构体一样，数组中的元素也是位于相邻的存储空间的。
 * 重点注意：C语言中编译器不会判断下标越界，int arr[5]写成arr[-1],arr[100]也不会编译报错。具体原因详见个人笔记。
 * */

//数组不能作为函数的形参或者返回值,也不可以作为形参，但是下面的当作形参不报错，是因为实际传的是数组的指针。
//int[] doSome(int a[]){
//	return 0;
//}
void arrFunction(int a[]){	
	printf("arrFunction==> %d\n",a[0]);
	return ;
}

int main(void){

	//1,声明数组变量，注意写法,Java中这种写法也可以，下面的写法也可以。
	//arr代表数组这个变量
	int arr[4];
	
	//C语言中这种写法错误，
	//int[] array; 
	
	//2,arr[i] 可以表示数组元素的值，也可以表示这位位置的存储单元本身，因此它可以做右值，也可以做左值。
	arr[0] = 12;
	arr[2] = arr[0] * 3;
	++arr[0];


	//travsersal：遍历
	//注意：C语言中不会判断下标越界，数组arr[4]中在范围内的，如果未赋值默认是0，越界的数据就还是原来的脏数据。
	//这里遍历10个元素，超过原来的4个，后面的都是脏数据！！
	int i;
	for(i = 0; i < 10; i++){ //Caution: "length" could not be used here as in Java.
		printf("%d==> %d\n",i,arr[i]);
	}
	

	//3,数组初始化的方式：
	//如果不初始化，里面都是旧数据。
	
	//3.1,数组也可以像结构体那样初始化，未赋值的元素默认0
	int arr2[5] = {1,2,3,};
	
	//3.2,也可以不指定容量，最后写不写逗号没有区别，有几个数编译器默认确定几个容量。
	//int arr3[] = {0,1,2,};   
	int arr3[] = {4,5,6}; 
	int j;
	for(j = 0; j < 10; j++){
		printf("arr3[]: %d==> %d\n",j,arr3[j]);
	}

	//4，数组越界下标赋值。
	//越界下标也能赋值，也能读取。
	arr2[6] = 737;
	printf("arr2: %d\n",arr2[6]);
	//下标写作 -1，也能读取所赋值。
	arr2[-1] = 53;
	printf("arr2[-1] = %d\n",arr2[-1]);

	//5, 数组之间不能相互赋值，因此也不能作为函数的形参或者返回值。
	//原因：
	//C语言中，数组类型当右值使用时，会自动转换为指向数组首元素的指针。而等号左边是数组类型，因此右边的指针类型不可赋值于左边。
	int a[5] = {0,1,2,3};
	//int b[5] = a;	//此行报错


	//6，数组作为函数实参时，实际传的不是数组类型，而是它的指针，类似于Java中的引用。
	int arr4[5] = {67,22};
	arrFunction(arr4);	



	return 0;
}



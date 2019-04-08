#include <iostream>
#include <omp.h>
using namespace std;
int main() {
	int i = 10;
	#pragma omp parallel firstprivate(i) num_threads(4)
	{
	cout<<"thread:"<<omp_get_thread_num() << "i="<<i<<endl;
	i=1000+omp_get_thread_num();
	}
	#pragma omp parallel
	{
	#pragma omp for lastprivate(i)
	for(i=0; i<50; ++i){}
	}
	cout<<"the end: i="<<i<<endl;
}
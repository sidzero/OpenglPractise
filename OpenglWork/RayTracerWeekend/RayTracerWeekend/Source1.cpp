//// filename: CounterType.cpp
//#include <iostream>
//using namespace std;
//
//class CounterType
//{
//private:
//	int count;
//public:
//	CounterType();           // sets the count to 0
//	CounterType(int init);   // (1) sets the count to 'init'; you may assume
//	//     'init' is non-negative.
//	int get();               // returns the current count value 
//	void set(int cnt);       // sets the counter to a count given as an argument 
//	void increment();        // increases the count by 1
//	void increment(int inc); // (2) increases the count by 'inc'; you may assume
//	//     'inc' is non-negative.
//	void decrement();        // decreases the count by 1
//	void decrement(int dec); // (3) decreases the count by 'dec' only if the resulting
//	//      value (after subtracting all of 'dec') does
//	//      NOT yield a negative number; if it does, 
//	//      prints an error message and doesn't decrement;
//	//      you may assume 'dec' is non-negative.
//	void print();            // outputs the count to cout
//};
//
//CounterType::CounterType()
//{
//	count = 0;
//}
//
//CounterType::CounterType(int init)
//{
//	count = init;
//}
//
//int CounterType::get() { return count; }
//void CounterType::set(int cnt) { count = cnt; }
//void CounterType::increment() { ++count; }
//void CounterType::decrement() { --count; }
//void CounterType::print() { cout << "counter=" << count << endl; }
//
//void CounterType::increment(int inc)
//{
//	count += inc;
//}
//
//void CounterType::decrement(int dec)
//{
//	if (dec > count)
//		cout << "ERROR: value is too large to decrement.\n";
//	else
//		count -= dec;
//}
//
////*******************************
//// Q12: CounterType - main()
////*******************************
//
//int main()
//{
//	CounterType *c1;
//
//	c1 = new CounterType();
//	
//
//	cout << "(1) c1 -- "; c1->print();
//	c1->increment();
//	c1->increment();
//	c1->increment();
//	cout << "(2) c1 -- "; c1->print();
//
//	int n;
//	cout << "Enter a value to increment: ";
//	cin >> n;
//
//	c1->increment(n);
//	cout << "(3) c1 -- "; c1->print(); cout << endl;
//
//	//------------------------------
//	CounterType *c2;
//
//	c2 = new CounterType(c1->get());
//	cout << "{4} c2 => "; c2->print();
//
//	for (int i = 0; i < 5; ++i)
//		c2->increment(2);
//
//	cout << "{5} c2 => "; c2->print();
//
//	system("pause");
//	return 0;
//}
//
///*
//(1) c1 -- counter=0
//(2) c1 -- counter=3
//Enter a value to increment: 4
//(3) c1 -- counter=7
//
//{4} c2 => counter=7
//{5} c2 => counter=17
//
//*/
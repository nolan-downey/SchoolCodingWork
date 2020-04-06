#include "../classes/LinearProbe.h"
#include "../classes/DoubleHash.h"

template<class Key, class Value>
void printStatus(const HashTable<Key, Value>&  linearHash,
				 const DoubleHash<Key, Value>& doubleHash ){
	
	std::cout << "Linear Hash Results: " << std::endl;
	std::cout << linearHash << std::endl << std::endl;
	
	std::cout << "Double Hash Results: " << std::endl;
	std::cout << doubleHash << std::endl << std::endl;
	
}

int main(){
	
	HashTable<int, int> linearHash(7);
	DoubleHash<int, int> doubleHash(7);
	
	linearHash.insert( {76, 76} );	doubleHash.insert( {76, 76} );
	linearHash.insert( {40, 40} );	doubleHash.insert( {40, 40} );
	linearHash.insert( {48, 40} );	doubleHash.insert( {48, 48} );
	
	printStatus(linearHash, doubleHash);
	
	linearHash.insert( {5, 5} );	doubleHash.insert( {5, 5} );
	linearHash.insert( {55, 55} );	doubleHash.insert( {55, 55} );

	printStatus(linearHash, doubleHash);
	
	
	HashTable<std::string, float> strLinHash(7);
	DoubleHash<std::string, float> strDblHash(7);

	strLinHash.insert( {"University of ", (float)2.7} );	
	strDblHash.insert( {"University of ", (float)2.7} );
	strLinHash.insert( {"Notre", (float)155.6} );	
	strDblHash.insert( {"Notre", (float)155.6} );
	strLinHash.insert( {"Dame", (float)155.6} );	
	strDblHash.insert( {"Dame", (float)155.6} );
	
	printStatus(strLinHash, strDblHash);
	
	strLinHash.insert( {"Fighting Irish ", (float)-3.5} );	
	strDblHash.insert( {"Fighting Irish ", (float)-3.5} );
	strLinHash.insert( {"Graduating Class of 2022 ", (float)1.2e-7} );	
	strDblHash.insert( {"Graduating Class of 2022 ", (float)1.2e-7} );
	
	strLinHash.insert( {"Computer Science and Engineering ", (float)3137} );	
	strDblHash.insert( {"Computer Science and Engineering ", (float)3137} );
	strLinHash.insert( {"CSE20312 Data Structures ", (float)1842} );
	strDblHash.insert( {"CSE20312 Data Structures ", (float)1842} );

	printStatus(strLinHash, strDblHash);
	
	return 0;
}
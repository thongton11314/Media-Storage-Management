#include <iostream>
#include <fstream>
#include <ostream>
#include "store_manager.h"
#include "bst.h"

using namespace std;

void testDrama();
void testComedy();
void testClassic();
void testBST();

int main () {

    // instantiate theater manager class
    StoreManager storeManager;

    // instantiate file stream for setting data
    ifstream customerFile("data4customers.txt"),  // customer file
             movieFile("data4movies.txt"),        // movies file
             commandFile("data4commands.txt");    // command file

    // reads all customers information from text file
    storeManager.buildCustomers(customerFile);
    cout << endl;

    // reads all movies command from text file
    storeManager.buildMovies(movieFile);
    cout << endl;

    // process all commands from file
    storeManager.processCommands(commandFile);
    cout << endl;

    //testRemove(storeManager);
    

    system("pause");
    return 0;
}

void testBST() {

    // delete parent 2 node, with right child
    cout << "Two nodes with only right child" << endl;
    BSTree<int> testtest;
    testtest.insert(new int(40));
    testtest.insert(new int(30));
    testtest.insert(new int(60));
    testtest.insert(new int(65));
    testtest.insert(new int(70));
    cout << "Before remove 40:" << endl;
    testtest.display();
    if(testtest.remove(40)) // //30 60 65 70
        cout << "PASSED test bool return" << endl;
    else
        cout << "*FAILED test bool return" << endl;
    cout << "After remove 40:" << endl;
    testtest.display();
    cout << endl;

    // delete parent 2 node, with right min left child
    cout << "Two nodes with right min left child" << endl;
    BSTree<int> testtest1;
    testtest1.insert(new int(40));
    testtest1.insert(new int(30));
    testtest1.insert(new int(60));
    testtest1.insert(new int(55));
    testtest1.insert(new int(50));
    testtest1.insert(new int(65));
    testtest1.insert(new int(70));
    cout << "Before remove 40:" << endl;
    testtest1.display();
    if (testtest1.remove(40)) // 30 60 61 62 63 64 65 70
        cout << "PASSED test bool return" << endl;
    else
        cout << "*FAILED test bool return" << endl;
    cout << "After remove 40:" << endl;
    testtest1.display();
    cout << endl;

    cout << "Test left child is null" << endl;
    BSTree<int> testtest2;
    testtest2.insert(new int(40));
    testtest2.insert(new int(30));
    testtest2.insert(new int(60));
    testtest2.insert(new int(65));
    testtest2.insert(new int(70));
    cout << "Before remove 65:" << endl;
    testtest2.display();
    cout << "After remove 65:" << endl;
    if (testtest2.remove(65)) // 30 40 60 70
        cout << "PASSED test bool return" << endl;
    else
        cout << "*FAILED test bool return" << endl;
    testtest2.display();
    cout << endl;

    cout << "Test right child is null" << endl;
    BSTree<int> testtest3;
    testtest3.insert(new int(40));
    testtest3.insert(new int(30));
    testtest3.insert(new int(60));
    testtest3.insert(new int(55));
    testtest3.insert(new int(50));
    testtest3.insert(new int(65));
    testtest3.insert(new int(70));
    cout << "Before remove 55:" << endl;
    testtest3.display();
    cout << "After remove 55:" << endl;
    if (testtest3.remove(55)) // 30 40 50 60 65 70
        cout << "PASSED test bool return" << endl;
    else
        cout << "*FAILED test bool return" << endl;
    testtest3.display();
    cout << endl;

    cout << "Test both side is null" << endl;
    BSTree<int> testtest4;
    testtest4.insert(new int(40));
    testtest4.insert(new int(30));
    testtest4.insert(new int(60));
    testtest4.insert(new int(55));
    testtest4.insert(new int(50));
    testtest4.insert(new int(65));
    testtest4.insert(new int(70));
    cout << "Before remove 50:" << endl;
    testtest4.display();
    cout << "After remove 55:" << endl;
    if (testtest4.remove(50))
        cout << "PASSED test bool return" << endl;
    else
        cout << "*FAILED test bool return" << endl;
    testtest4.display();
    cout << endl;

    cout << "Test delete root with two nodes" << endl;
    BSTree<int> testtest5;
    testtest5.insert(new int(40));
    testtest5.insert(new int(30));
    testtest5.insert(new int(60));
    testtest5.insert(new int(55));
    testtest5.insert(new int(50));
    testtest5.insert(new int(65));
    testtest5.insert(new int(70));
    cout << "Before remove 40:" << endl;
    testtest5.display();
    cout << "After remove 40:" << endl;
    if (testtest5.remove(40))
        cout << "PASSED test bool return" << endl;
    else
        cout << "*FAILED test bool return" << endl;
    testtest5.display();
    cout << endl;

    cout << "Test delete root with left node null" << endl;
    BSTree<int> testtest6;
    testtest6.insert(new int(40));
    testtest6.insert(new int(50));
    testtest6.insert(new int(65));
    testtest6.insert(new int(70));
    cout << "Before remove 40:" << endl;
    testtest6.display();
    cout << "After remove 40:" << endl;
    if (testtest6.remove(40))
        cout << "PASSED test bool return" << endl;
    else
        cout << "*FAILED test bool return" << endl;
    testtest6.display();
    cout << endl;

    cout << "Test delete root with right node null" << endl;
    BSTree<int> testtest7;
    testtest7.insert(new int(40));
    testtest7.insert(new int(30));
    testtest7.insert(new int(20));
    cout << "Before remove 40:" << endl;
    testtest7.display();
    cout << "After remove 40:" << endl;
    if (testtest7.remove(40))
        cout << "PASSED test bool return" << endl;
    else
        cout << "*FAILED test bool return" << endl;
    testtest7.display();
    cout << endl;

    cout << "Test delete root with no chillrend" << endl;
    BSTree<int> testtest8;
    testtest8.insert(new int(40));
    cout << "Before remove 40:" << endl;
    testtest8.display();
    cout << "After remove 40:" << endl;
    if (testtest8.remove(40))
        cout << "PASSED test bool return" << endl;
    else
        cout << "*FAILED test bool return" << endl;
    testtest8.display();
    cout << endl;
}

void testDrama() {
    cout << "Test drama" << endl;

    // arithmetic operator, sort by director and then title
    Media* media1 = new Drama();
    Media* media2 = new Drama();
    dynamic_cast<Drama*>(media1)->setStock(10);
    dynamic_cast<Drama*>(media2)->setStock(10);
    dynamic_cast<Drama*>(media1)->setYear(1995);
    dynamic_cast<Drama*>(media2)->setYear(1995);
    dynamic_cast<Drama*>(media1)->setTitle("AA");
    dynamic_cast<Drama*>(media2)->setTitle("AA");

    // sort director
    cout << "Test director" << endl;
    dynamic_cast<Drama*>(media1)->setDirector("AA");
    dynamic_cast<Drama*>(media2)->setDirector("BB");

    // less than
    if (*media1 < *media2)
        cout << "Comparision <:" << "\t PASSED" << endl;
    else
        cout << "Comparision <:" << "\t FAILED*" << endl;

    // less than or equal
    if (*media1 <= *media2)
        cout << "Comparision <=:" << "\t PASSED" << endl;
    else
        cout << "Comparision <=:" << "\t FAILED*" << endl;

    // greater
    if (*media2 > * media1)
        cout << "Comparision >:" << "\t PASSED" << endl;
    else
        cout << "Comparision >:" << "\t FAILED*" << endl;

    // greater or equal
    if (*media2 >= *media1)
        cout << "Comparision >=:" << "\t PASSED" << endl;
    else
        cout << "Comparision >=:" << "\t FAILED*" << endl;

    // equal
    if (*media2 != *media1)
        cout << "Comparision ==:" << "\t PASSED" << endl;
    else
        cout << "Comparision ==:" << "\t FAILED*" << endl;

    // sort title
    cout << "Test Tile" << endl;
    dynamic_cast<Drama*>(media1)->setTitle("AA");
    dynamic_cast<Drama*>(media2)->setTitle("BB");

    // less than
    if (*media1 < *media2)
        cout << "Comparision <:" << "\t PASSED" << endl;
    else
        cout << "Comparision <:" << "\t FAILED*" << endl;

    // less than or equal
    if (*media1 <= *media2)
        cout << "Comparision <=:" << "\t PASSED" << endl;
    else
        cout << "Comparision <=:" << "\t FAILED*" << endl;

    // greater
    if (*media2 > * media1)
        cout << "Comparision >:" << "\t PASSED" << endl;
    else
        cout << "Comparision >:" << "\t FAILED*" << endl;

    // greater or equal
    if (*media2 >= *media1)
        cout << "Comparision >=:" << "\t PASSED" << endl;
    else
        cout << "Comparision >=:" << "\t FAILED*" << endl;

    // sort same same
    //test all same
    cout << "Test all same" << endl;
    dynamic_cast<Drama*>(media1)->setDirector("AA");
    dynamic_cast<Drama*>(media2)->setDirector("AA");
    dynamic_cast<Drama*>(media1)->setTitle("AA");
    dynamic_cast<Drama*>(media2)->setTitle("AA");

    // less than
    if ((*media1 < *media2) == false)
        cout << "Comparision <:" << "\t PASSED" << endl;
    else
        cout << "Comparision <:" << "\t FAILED*" << endl;

    // less than or equal
    if ((*media1 <= *media2))
        cout << "Comparision <=:" << "\t PASSED" << endl;
    else
        cout << "Comparision <=:" << "\t FAILED*" << endl;

    // greater
    if ((*media2 > * media1) == false)
        cout << "Comparision >:" << "\t PASSED" << endl;
    else
        cout << "Comparision >:" << "\t FAILED*" << endl;

    // greater or equal
    if (*media2 >= *media1)
        cout << "Comparision >=:" << "\t PASSED" << endl;
    else
        cout << "Comparision >=:" << "\t FAILED*" << endl;

    // equal
    if (*media2 == *media1)
        cout << "Comparision ==:" << "\t PASSED" << endl;
    else
        cout << "Comparision ==:" << "\t FAILED*" << endl;
    delete media1;
    delete media2;
}

void testComedy() {
    cout << "Test comedy" << endl;

    // arithmetic operator, sort by title and year release
    Media* media1 = new Comedy();
    Media* media2 = new Comedy();
    dynamic_cast<Comedy*>(media1)->setStock(10);
    dynamic_cast<Comedy*>(media2)->setStock(10);
    dynamic_cast<Comedy*>(media1)->setDirector("AA");
    dynamic_cast<Comedy*>(media2)->setDirector("BB");
    dynamic_cast<Comedy*>(media1)->setYear(1995);
    dynamic_cast<Comedy*>(media2)->setYear(1995);

    // test title
    cout << "Test title" << endl;
    dynamic_cast<Comedy*>(media1)->setTitle("AA");
    dynamic_cast<Comedy*>(media2)->setTitle("BB");

    // less than
    if (*media1 < *media2)
        cout << "Comparision <:" << "\t PASSED" << endl;
    else
        cout << "Comparision <:" << "\t FAILED*" << endl;

    // less than or equal
    if (*media1 <= *media2)
        cout << "Comparision <=:" << "\t PASSED" << endl;
    else
        cout << "Comparision <=:" << "\t FAILED*" << endl;

    // greater
    if (*media2 > * media1)
        cout << "Comparision >:" << "\t PASSED" << endl;
    else
        cout << "Comparision >:" << "\t FAILED*" << endl;

    // greater or equal
    if (*media2 >= *media1)
        cout << "Comparision >=:" << "\t PASSED" << endl;
    else
        cout << "Comparision >=:" << "\t FAILED*" << endl;

    // equal
    if (*media2 != *media1)
        cout << "Comparision ==:" << "\t PASSED" << endl;
    else
        cout << "Comparision ==:" << "\t FAILED*" << endl;

    // test year release
    cout << "Test year release" << endl;
    dynamic_cast<Comedy*>(media1)->setTitle("AA");
    dynamic_cast<Comedy*>(media2)->setTitle("AA");
    dynamic_cast<Comedy*>(media1)->setYear(1995);
    dynamic_cast<Comedy*>(media2)->setYear(1996);

    // less than
    if (*media1 < *media2)
        cout << "Comparision <:" << "\t PASSED" << endl;
    else
        cout << "Comparision <:" << "\t FAILED*" << endl;

    // less than or equal
    if (*media1 <= *media2)
        cout << "Comparision <=:" << "\t PASSED" << endl;
    else
        cout << "Comparision <=:" << "\t FAILED*" << endl;

    // greater
    if (*media2 > * media1)
        cout << "Comparision >:" << "\t PASSED" << endl;
    else
        cout << "Comparision >:" << "\t FAILED*" << endl;

    // greater or equal
    if (*media2 >= *media1)
        cout << "Comparision >=:" << "\t PASSED" << endl;
    else
        cout << "Comparision >=:" << "\t FAILED*" << endl;

    // equal
    if (*media2 != *media1)
        cout << "Comparision ==:" << "\t PASSED" << endl;
    else
        cout << "Comparision ==:" << "\t FAILED*" << endl;

    //test all same
    cout << "Test all same" << endl;
    dynamic_cast<Comedy*>(media1)->setYear(1995);
    dynamic_cast<Comedy*>(media2)->setYear(1995);

    // less than
    if ((*media1 < *media2) == false)
        cout << "Comparision <:" << "\t PASSED" << endl;
    else
        cout << "Comparision <:" << "\t FAILED*" << endl;

    // less than or equal
    if ((*media1 <= *media2))
        cout << "Comparision <=:" << "\t PASSED" << endl;
    else
        cout << "Comparision <=:" << "\t FAILED*" << endl;

    // greater
    if ((*media2 > * media1) == false)
        cout << "Comparision >:" << "\t PASSED" << endl;
    else
        cout << "Comparision >:" << "\t FAILED*" << endl;

    // greater or equal
    if (*media2 >= *media1)
        cout << "Comparision >=:" << "\t PASSED" << endl;
    else
        cout << "Comparision >=:" << "\t FAILED*" << endl;

    // equal
    if (*media2 == *media1)
        cout << "Comparision ==:" << "\t PASSED" << endl;
    else
        cout << "Comparision ==:" << "\t FAILED*" << endl;
    delete media1;
    delete media2;
}

void testClassic() {
    cout << "Test Classic" << endl;

    // arithmetic operator, sort by release date and major actor
    Media* media1 = new Classic();
    Media* media2 = new Classic();
    dynamic_cast<Classic*>(media1)->setStock(10);
    dynamic_cast<Classic*>(media2)->setStock(10);
    dynamic_cast<Classic*>(media1)->setDirector("AA");
    dynamic_cast<Classic*>(media2)->setDirector("BB");
    dynamic_cast<Classic*>(media1)->setTitle("AA");
    dynamic_cast<Classic*>(media2)->setTitle("BB");
    dynamic_cast<Classic*>(media1)->setMajorActorFirst("AA");
    dynamic_cast<Classic*>(media2)->setMajorActorFirst("BB");
    dynamic_cast<Classic*>(media1)->setMajorActorLast("AA");
    dynamic_cast<Classic*>(media2)->setMajorActorLast("BB");

    // test media1's date is less\greater than media2's data
    dynamic_cast<Classic*>(media1)->setMonth(10);
    dynamic_cast<Classic*>(media2)->setMonth(10);
    dynamic_cast<Classic*>(media1)->setYear(1995);
    dynamic_cast<Classic*>(media2)->setYear(1996);
    cout << "Test media1 is less than media2" << endl;

    // less than
    if (*media1 < *media2)
        cout << "Comparision <:" << "\t PASSED" << endl;
    else
        cout << "Comparision <:" << "\t FAILED*" << endl;

    // less than or equal
    if (*media1 <= *media2)
        cout << "Comparision <=:" << "\t PASSED" << endl;
    else
        cout << "Comparision <=:" << "\t FAILED*" << endl;

    // greater
    if (*media2 > *media1)
        cout << "Comparision >:" << "\t PASSED" << endl;
    else
        cout << "Comparision >:" << "\t FAILED*" << endl;

    // greater or equal
    if (*media2 >= * media1)
        cout << "Comparision >=:" << "\t PASSED" << endl;
    else
        cout << "Comparision >=:" << "\t FAILED*" << endl;

    // equal
    if (*media2 != *media1)
        cout << "Comparision ==:" << "\t PASSED" << endl;
    else
        cout << "Comparision ==:" << "\t FAILED*" << endl;

    // test date
    dynamic_cast<Classic*>(media1)->setMonth(10);
    dynamic_cast<Classic*>(media2)->setMonth(10);
    dynamic_cast<Classic*>(media1)->setYear(1995);
    dynamic_cast<Classic*>(media2)->setYear(1995);
    cout << "Test media1, media2 differnet actor last and name, same date" << endl;

    // less than
    if (*media1 < *media2)
        cout << "Comparision <:" << "\t PASSED" << endl;
    else
        cout << "Comparision <:" << "\t FAILED*" << endl;

    // less than or equal
    if (*media1 <= *media2)
        cout << "Comparision <=:" << "\t PASSED" << endl;
    else
        cout << "Comparision <=:" << "\t FAILED*" << endl;

    // greater
    if (*media2 > * media1)
        cout << "Comparision >:" << "\t PASSED" << endl;
    else
        cout << "Comparision >:" << "\t FAILED*" << endl;

    // greater or equal
    if (*media2 >= *media1)
        cout << "Comparision >=:" << "\t PASSED" << endl;
    else
        cout << "Comparision >=:" << "\t FAILED*" << endl;

    // equal
    if (*media2 != *media1)
        cout << "Comparision ==:" << "\t PASSED" << endl;
    else
        cout << "Comparision ==:" << "\t FAILED*" << endl;

    // test same same
    dynamic_cast<Classic*>(media1)->setMajorActorFirst("AA");
    dynamic_cast<Classic*>(media2)->setMajorActorFirst("AA");
    dynamic_cast<Classic*>(media1)->setMajorActorLast("AA");
    dynamic_cast<Classic*>(media2)->setMajorActorLast("AA");
    cout << "Test all same" << endl;

    // less than
    if ((*media1 < *media2) == false)
        cout << "Comparision <:" << "\t PASSED" << endl;
    else
        cout << "Comparision <:" << "\t FAILED*" << endl;

    // less than or equal
    if (*media1 <= *media2)
        cout << "Comparision <=:" << "\t PASSED" << endl;
    else
        cout << "Comparision <=:" << "\t FAILED*" << endl;

    // greater
    if ((*media2 > * media1) == false)
        cout << "Comparision >:" << "\t PASSED" << endl;
    else
        cout << "Comparision >:" << "\t FAILED*" << endl;

    // greater or equal
    if (*media2 >= *media1)
        cout << "Comparision >=:" << "\t PASSED" << endl;
    else
        cout << "Comparision >=:" << "\t FAILED*" << endl;

    // equal
    if (*media2 == *media1)
        cout << "Comparision ==:" << "\t PASSED" << endl;
    else
        cout << "Comparision ==:" << "\t FAILED*" << endl;
    delete media1;
    delete media2;
}

/*
void testRemove(StoreManager storeManager) {
    cout << "Test remove" << endl;
    ifstream testRemove("dataTest.txt");
    storeManager.testRemove(testRemove);
    cout << endl;
}
*/
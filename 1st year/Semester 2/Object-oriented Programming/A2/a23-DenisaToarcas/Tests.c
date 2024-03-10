#include "Tests.h"
#include "domain.h"
#include "repository.h"

#include <assert.h>
#include <string.h>

void test_addMedicine(){
    repository* repo_test = createRepository();
    Medicine* medicine1_test = createMedicine("med1", 10, 10, 23.50f);
    Medicine* medicine2_test = createMedicine("med2", 20, 20, 34.50f);

    /*Test adding a new medicine to the repo*/
    assert(getSize(repo_test) == 0);
    addMedicine(repo_test, medicine1_test);
    assert(getSize(repo_test) == 1);
    assert(strcmp(getName(&repo_test->data[0]), "med1") == 0);
    assert(get_quantity(&repo_test->data[0]) == 10);
    assert(get_price(&repo_test->data[0]) == 23.50);

    /*Test adding an existing medicine to the repo*/
    addMedicine(repo_test, medicine1_test);
    assert(getSize(repo_test) == 1);
    assert(get_quantity(&repo_test->data[0]) == 20);

    /*Test adding a second medicine*/
    addMedicine(repo_test, medicine2_test);
    assert(getSize(repo_test) == 2);
    assert(strcmp(getName(&repo_test->data[1]),"med2") == 0);
}

void test_findMedicine(){
    repository* repo_test = createRepository();
    Medicine* medicine1_test = createMedicine("med1", 10, 10, 23.50f);
    Medicine* medicine2_test = createMedicine("med2", 20, 20, 34.50f);
    addMedicine(repo_test, medicine1_test);
    addMedicine(repo_test, medicine2_test);

    assert(getSize(repo_test) == 2);
    assert(findMedicine(repo_test, medicine1_test) == 0);
    assert(findMedicine(repo_test, medicine2_test) == 1);

    /*Testing findMedicine() on a medicine which is not part of our repo*/
    Medicine* medicine3_test = createMedicine("med3", 30, 30, 30);
    assert(findMedicine(repo_test, medicine3_test) == -1);
}

void test_deleteMedicine(){
    repository* repo_test = createRepository();
    Medicine* medicine1_test = createMedicine("med1", 10, 10, 23.50f);
    Medicine* medicine2_test = createMedicine("med2", 20, 20, 34.50f);
    addMedicine(repo_test, medicine1_test);
    addMedicine(repo_test, medicine2_test);
    assert(getSize(repo_test) == 2);

    /*Delete first medicine*/
    int result;
    result = deleteMedicine(repo_test, medicine1_test);
    assert(getSize(repo_test) == 1);
    assert(result == 0);        //this means that the deletion was successful;
    assert(strcmp(getName(&repo_test->data[0]), "med2") == 0);

    /*Delete a medicine that is no longer part of the repo*/
    result = deleteMedicine(repo_test, medicine1_test);
    assert(getSize(repo_test) == 1);
    assert(result == 1); //this means that the deletion was not successful;
}

void test_updateMedicine(){
    repository* repo_test = createRepository();
    Medicine* medicine1_test = createMedicine("med1", 10, 10, 23.50f);
    Medicine* medicine2_test = createMedicine("med2", 20, 20, 34.50f);
    Medicine* medicine3_test = createMedicine("med3", 30, 30, 30);
    addMedicine(repo_test, medicine1_test);
    addMedicine(repo_test, medicine2_test);

    /*Update med1 into med3*/
    int result;
    result = updateMedicine(repo_test, medicine1_test, medicine3_test);
    assert(result == 0);        //update successful;
    assert(strcmp(getName(&repo_test->data[0]), "med3") == 0);
    assert(get_quantity(&repo_test->data[0]) == 30);
    assert(get_concentration(&repo_test->data[0]) == 30);
    assert(get_price(&repo_test->data[0]) == 30);

    /*Update a medicine that is no longer part of the repo*/
    result = updateMedicine(repo_test, medicine1_test, medicine2_test);
    assert(result == 1);         //update not successful;
}
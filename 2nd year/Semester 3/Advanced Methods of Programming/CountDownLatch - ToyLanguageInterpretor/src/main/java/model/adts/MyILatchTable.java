package model.adts;

import exception.MyException;

import java.util.HashMap;

public interface MyILatchTable {
    void add(int key, int value) throws MyException;
    int getValue(int key) throws MyException;
    boolean isDefined(int key);
    int getFreeAddress();
    void setFreeAddress(int Address);
    void update(int key, int newValue) throws MyException;
    HashMap<Integer, Integer> getLatchTable();
    void setLatchTable(HashMap<Integer, Integer> LachTable);
}

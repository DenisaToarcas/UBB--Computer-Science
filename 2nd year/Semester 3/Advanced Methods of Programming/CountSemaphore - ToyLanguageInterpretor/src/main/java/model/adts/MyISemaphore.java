package model.adts;

import java.util.List;
import java.util.HashMap;

import exception.MyException;

public interface MyISemaphore {
    void add(int key, Pair<Integer, List<Integer>> value) throws MyException;
    Pair<Integer, List<Integer>> getValue(int key) throws MyException;
    boolean isDefined(int key);
    int getFreeAddress();
    void setFreeAddress(int Address);
    void update(int key, Pair<Integer, List<Integer>> value) throws MyException;
    HashMap<Integer, Pair<Integer, List<Integer>>> getToySemaphore();
    void setToySemaphore(HashMap<Integer, Pair<Integer, List<Integer>>> newToySemaphore);
}

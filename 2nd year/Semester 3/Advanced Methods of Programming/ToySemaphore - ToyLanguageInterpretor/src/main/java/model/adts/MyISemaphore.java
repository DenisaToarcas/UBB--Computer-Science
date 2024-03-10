package model.adts;

import java.util.List;
import java.util.HashMap;

import exception.MyException;

public interface MyISemaphore {
    void add(int key, Tuple<Integer, List<Integer>, Integer> value) throws MyException;
    Tuple<Integer, List<Integer>, Integer> getValue(int key) throws MyException;
    boolean isDefined(int key);
    int getFreeAddress();
    void setFreeAddress(int Address);
    void update(int key, Tuple<Integer, List<Integer>, Integer> value) throws MyException;
    HashMap<Integer, Tuple<Integer, List<Integer>, Integer>> getToySemaphore();
    void setToySemaphore(HashMap<Integer, Tuple<Integer, List<Integer>, Integer>> newToySemaphore);
}

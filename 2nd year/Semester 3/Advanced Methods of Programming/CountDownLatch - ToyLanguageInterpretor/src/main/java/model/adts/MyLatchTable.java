package model.adts;

import exception.MyException;

import java.util.HashMap;
import java.util.concurrent.atomic.AtomicInteger;

public class MyLatchTable implements MyILatchTable {
    private HashMap<Integer, Integer> latchTable;
    private int freeLocation = 0;

    public MyLatchTable()
    {
        this.latchTable = new HashMap<>();
    }

    @Override
    public synchronized String toString()
    {
        StringBuilder result = new StringBuilder();
        for (int key: this.latchTable.keySet())
        {
            result.append(key).append("-->").append(this.latchTable.get(key).toString()).append("\n");
        }

        return result.toString();
    }

    @Override
    public synchronized void add(int key, int value) throws MyException {
        if (!this.latchTable.containsKey(key))
            this.latchTable.put(key, value);
        else
            throw new MyException("The key is already contained in the LatchTable!");
    }

    @Override
    public synchronized int getValue(int key) throws MyException {
        if (this.latchTable.containsKey(key))
            return this.latchTable.get(key);
        else
            throw new MyException("Latch Table does not contain the key given!");
    }

    @Override
    public synchronized boolean isDefined(int key) {
        return this.latchTable.containsKey(key);
    }

    @Override
    public synchronized int getFreeAddress() {
        return this.freeLocation++;
    }

    @Override
    public synchronized void setFreeAddress(int Address) {
        this.freeLocation = Address;
    }

    @Override
    public synchronized void update(int key, int newValue) throws MyException {
        if (this.latchTable.containsKey(key))
            this.latchTable.replace(key, newValue);
        else
            throw new MyException("The key is not defined in the Latch Table!");
    }

    @Override
    public synchronized HashMap<Integer, Integer> getLatchTable() {
        return this.latchTable;
    }

    @Override
    public synchronized void setLatchTable(HashMap<Integer, Integer> LachTable) {
        this.latchTable = LachTable;
    }
}

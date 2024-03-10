package model.adts;

import exception.MyException;

import java.util.HashMap;
import java.util.Locale;

public class MyLock implements MyILock{
    private HashMap<Integer, Integer> lockTable;
    private int freeLocation = 0;

    public MyLock()
    {
        this.lockTable = new HashMap<>();
    }

    @Override
    public synchronized String toString()
    {
        StringBuilder result = new StringBuilder();
        for (int key: this.lockTable.keySet())
        {
            result.append(key).append("-->").append(this.lockTable.get(key).toString()).append("\n");
        }

        return result.toString();
    }

    @Override
    public synchronized void add(int key, int value) throws MyException {
        if (!this.lockTable.containsKey(key))
            this.lockTable.put(key, value);
        else
            throw new MyException("The key is already contained in the LockTable!");

    }

    @Override
    public synchronized int getValue(int key) throws MyException {
        if (this.lockTable.containsKey(key))
            return this.lockTable.get(key);
        else
            throw new MyException("Lock Table does not contain the key given!");

    }

    @Override
    public synchronized boolean isDefined(int key) {
        return this.lockTable.containsKey(key);
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
        if (this.lockTable.containsKey(key))
            this.lockTable.replace(key, newValue);
        else
            throw new MyException("The key is not defined in the Lock Table!");
    }

    @Override
    public synchronized HashMap<Integer, Integer> getLock() {
        return this.lockTable;
    }

    @Override
    public synchronized void setLock(HashMap<Integer, Integer> Lock) {
        this.lockTable = Lock;
    }
}

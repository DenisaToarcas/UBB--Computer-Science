package model.adts;

import exception.MyException;

import java.util.HashMap;
import java.util.List;

public class MySemaphore implements MyISemaphore{
    private HashMap<Integer, Pair<Integer, List<Integer>>> toySemaphoreTable;
    private int freeLocation = 0;

    public MySemaphore()
    {
        this.toySemaphoreTable = new HashMap<>();
    }

    @Override
    public synchronized String toString()
    {
        StringBuilder result = new StringBuilder();
        for (int key: this.toySemaphoreTable.keySet())
        {
            result.append(key).append("-->").append(this.toySemaphoreTable.get(key).toString()).append("\n");
        }

        return result.toString();
    }

    @Override
    public synchronized void add(int key, Pair<Integer, List<Integer>> value) throws MyException {
         if (!this.toySemaphoreTable.containsKey(key))
             this.toySemaphoreTable.put(key, value);
         else
             throw new MyException("Toy Semaphore table already contains the key!");
    }

    @Override
    public synchronized Pair<Integer, List<Integer>> getValue(int key) throws MyException {
        if (this.toySemaphoreTable.containsKey(key))
            return this.toySemaphoreTable.get(key);
        else
            throw new MyException("Toy semaphore doesn't contain the key!");
    }

    @Override
    public synchronized boolean isDefined(int key) {
        return this.toySemaphoreTable.containsKey(key);
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
    public synchronized void update(int key, Pair<Integer, List<Integer>> value) throws MyException {
        if (this.toySemaphoreTable.containsKey(key))
            this.toySemaphoreTable.replace(key, value);
        else
            throw new MyException("The key is not defined in the ToySemaphore!");
    }

    @Override
    public synchronized HashMap<Integer, Pair<Integer, List<Integer>>> getToySemaphore() {
        return this.toySemaphoreTable;
    }

    @Override
    public synchronized void setToySemaphore(HashMap<Integer, Pair<Integer, List<Integer>>> newToySemaphore) {
        this.toySemaphoreTable = newToySemaphore;
    }
}

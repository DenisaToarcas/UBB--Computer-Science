package model.adts;

import exception.MyException;
import javafx.util.Pair;
import model.statements.IStmt;

import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

public class MyProcTable implements MyIProcTable{
    private HashMap<String, Pair<List<String>, IStmt>> procTable;

    public MyProcTable()
    {
        this.procTable = new HashMap<String, Pair<List<String>, IStmt>>();
    }

    @Override
    public synchronized String toString()
    {
        StringBuilder result = new StringBuilder();
        for(String key: this.procTable.keySet())
            result.append(key).append("-->").append(this.procTable.get(key).toString()).append("\n");

        return result.toString();
    }

    @Override
    public synchronized void add(String key, Pair<List<String>, IStmt> value) {
        this.procTable.put(key, value);
    }

    @Override
    public synchronized Pair<List<String>, IStmt> getValue(String key) throws MyException {
       if (this.procTable.containsKey(key))
           return this.procTable.get(key);
       else
           throw new MyException("Key is not defined in the ProcTable!");
    }

    @Override
    public synchronized boolean isDefined(String key) {
        return this.procTable.containsKey(key);
    }

    @Override
    public synchronized void update(String key, Pair<List<String>, IStmt> newValue) throws MyException {
        if (this.procTable.containsKey(key))
            this.procTable.replace(key, newValue);
        else
            throw new MyException("The key is not defined in the ProcTable!");
    }

    @Override
    public synchronized HashMap<String, Pair<List<String>, IStmt>> getContent() {
        return this.procTable;
    }
}
